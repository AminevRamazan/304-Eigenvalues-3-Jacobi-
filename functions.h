#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

double LenghtM(const std::vector<std::vector<double>>& A, const int n);
double Length(const std::vector<double>& a, const int n);
double Sum(const std::vector<double>& a, const int n);
double Trace(const std::vector<std::vector<double>>& A, const int n);
double Norm1(const std::vector<std::vector<double>>& A, const std::vector<double>& x, const int n);
double Norm2(const std::vector<std::vector<double>>& A, const std::vector<double>& x, const int n);

#endif