#include "functions.h"
#include <cmath>

double LenghtM(const std::vector<std::vector<double>>& A, const int n) {
    double lenght = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            lenght += A[i][j] * A[i][j];
        }
    }
    return lenght;
}

double Length(const std::vector<double>& a, const int n) {
    double lenght = 0;
    for (int i = 0; i < n; ++i) {
        lenght += a[i]*a[i];
    }
    return lenght;
}

double Sum(const std::vector<double>& a, const int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    return sum;
}

double Trace(const std::vector<std::vector<double>>& A, const int n) {
    double trace = 0;
    for (int i = 0; i < n; ++i) {
        trace += A[i][i];
    }
    return trace;
}

double Norm1(const std::vector<std::vector<double>>& A, const std::vector<double>& x, const int n) {
    double trace_A = 0.0, sum_x = 0.0;
    trace_A = Trace(A, n);
    sum_x = Sum(x, n);
    return std::fabs(trace_A - sum_x);
}

double Norm2(const std::vector<std::vector<double>>& A, const std::vector<double>& x, const int n) {
    double lenght_A = 0.0, lenght_x = 0.0;
    lenght_A = LenghtM(A, n);
    lenght_x = Length(x, n);
    return std::fabs(lenght_A - lenght_x);
}