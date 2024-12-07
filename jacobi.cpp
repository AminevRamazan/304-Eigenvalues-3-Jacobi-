#include "jacobi.h"
#include <cmath>
#include <algorithm>
#define SQ2 0.707106781186547461715


int jacobi(const std::vector<std::vector<double>>& A, std::vector<double>& z, const int n, const double eps) {
    z.resize(n);
    std::vector<std::vector<double>> A_copy = A;

    double sigma = 0;
    for (int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            sigma += 2 * A_copy[i][j] * A_copy[i][j];
        }
    }

    int k = 0;
    while (sigma >= eps) {


        if (k == n*n-1)
            k = 0;
        if ((k / n) == k % n)
            k++;
        int i = k / n;
        int j = k % n;
        

        double x = -2*A_copy[i][j];
        double y = A_copy[i][i] - A_copy[j][j];
        double c = SQ2, s = SQ2;
        if(fabs(y) >= 1e-100) {
            c = SQ2 * std::sqrt((1 + std::fabs(y) / std::sqrt(x * x + y * y)));
            s = 0.5 * (x * y > 0 ? 1.0 : -1.0) * std::fabs(x) / (c * std::sqrt(x * x + y * y));
        }


        std::vector<double> b, d;
        b.resize(n); // i
        d.resize(n); // j
        for (int m = 0; m < n; ++m) {
            if(m != i && m != j) {
                b[m] = c * A_copy[i][m] - s * A_copy[j][m];
                d[m] = s * A_copy[i][m] + c * A_copy[j][m];
            }
        }
        b[i] = c * c * A_copy[i][i] + s * s * A_copy[j][j] + x * c * s;
        d[j] = c * c * A_copy[j][j] + s * s * A_copy[i][i] - x * c * s;
        b[j] = 0;
        d[i] = b[j];
        for (int m = 0; m < n; ++m) {
            A_copy[i][m] = b[m];
            A_copy[m][i] = b[m];
            A_copy[j][m] = d[m];
            A_copy[m][j] = d[m];
        }


        sigma = 0;
        for (int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                sigma += 2 * A_copy[i][j] * A_copy[i][j];
            }
        }
        k++;
    }

    for (int m = 0; m < n; ++m) {
            z[m] = A_copy[m][m];
        }

    return 1;
}
