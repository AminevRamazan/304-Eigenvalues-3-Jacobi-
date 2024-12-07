#include <iostream>
#include <chrono>
#include "matrix_io.h"
#include "jacobi.h"
#include "functions.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 5 || argc > 6) {
        cerr << "Usage: " << argv[0] << " n m eps k filename" << endl;
        return EXIT_FAILURE;
    }

    int n = stoi(argv[1]);       // Размерность матрицы
    int m = stoi(argv[2]);       // Количество выводимых значений
    double eps = stod(argv[3]);  // точность нахожденияточность нахождения собственных значений
    int k = stoi(argv[4]);       // Номер формулы или 0 для чтения из файла

    if (m > n) {
        std::cerr << "Ошибка: Количество выводимых значений больше размерности матрицы " << std::endl;
        return 0;
    }

    int err = 0;
    vector<vector<double>> A;
    vector<double> x;
    A.resize(n, vector<double>(n));

    // Инициализация матрицы
    if (k == 0) {
        string filename = argv[5];   // Имя файла
        err = readMatrixFromFile(filename, A, n);
        if (!err) {
            std::cerr << "Ошибка: Не удалось открыть файл " << filename << std::endl;
            return err;
        }
    }
    else {
        initializeMatrix(A, k, n);
    }

    cout << "Исходная матрица A:" << endl;
    printMatrix(A, m);

    // Запуск таймера
    auto start = chrono::high_resolution_clock::now();

    // Решение системы методом Гаусса
    err = jacobi(A, x, n, eps);
    if (!err) {
        std::cerr << "Ошибка: Матрица вырождена " << std::endl;
        return err;
    }

    // Остановка таймера
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    // Вывод решения
    cout << "Решение x:" << endl;
    printVector(x, m);

    // Вычисление и вывод нормы невязки
    double norm1 = Norm1(A, x, n);
    cout << "Норма невязки в первом инварианте: " << scientific << norm1 << endl;

    // Вычисление и вывод нормы погрешности
    double norm2 = Norm2(A, x, n);
    cout << "Норма невязки во втором инварианте: " << scientific << norm2 << endl;

    // Вывод времени выполнения
    cout << "Время решения: " << elapsed.count() << " секунд" << endl;

    return 0;
}
