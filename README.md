Для сборки использовать команду make

Запуск осуществляется при помощи команды ./spectrum n m eps k filename, где

n – размерность матрицы,
m – количество выводимых значений в матрице,
eps - точность нахождения собственных значений,
k – задает номер формулы для инициализации матрицы, должен быть равен 0 при вводе матрицы из файла
filename – имя файла, откуда надо прочитать матрицу. Этот аргумент отсутствует, если k! = 0.
Файлы:

functions - подсчет норм
jacobi -  метод вращений Якоби с циклическим выбором обнуляемого элемента
matrix_io - чтение, вывод и заполнение матрицы с помощью формулы