#include "fibbonchi_logn.hpp"

std::string ulltosbin(unsigned long long num)
    {
        std::string result;
        do
            {
                result = std::to_string(num % 2) + result;
                num = num / 2;
            } while (num > 0);
        return result;
    }

void Fibbonachi::calculate()
    {
        if (n == 0)
            res = 0;
        else if (n == 1 || n == 2)
            res = 1;
        else if (n < 0)
            {
                if(std::abs(n)%2 == 0)
                    res = -1 * calculate(std::abs(n));
                else
                    res = calculate(std::abs(n));
            }
            
        else
            res = matpow(Q,n-1).at(0).at(0);
    }

long long Fibbonachi::calculate(long long number)
    {
        if (number == 0)
            return 0;
        else if (number == 1 || number == 2)
            return 1;
        else if (number < 0)
            return ((-1)^number) * calculate(std::abs(number));

        return matpow(Q,number-1).at(0).at(0);
    }

// Функция возведения квадратной матрицы 2х2 в степень n
std::vector<std::vector<long long>> Fibbonachi::matpow(std::vector<std::vector<long long>> matrix, unsigned long long num)
    {
        if (num == 0ull)
            return {{1ll,0ll},{0ll,1ll}};
        else if (num == 1ull)
            return matrix;
        
        std::vector<std::vector<long long>> _res = {{1ll,0ll},{0ll,1ll}};
        std::string bin_n = ulltosbin(num);

        for (int index = 0; index + 1 < int(bin_n.size()); ++index)
            {
                _res = matpow2(matmul(_res, matpow(matrix,(bin_n.at(index)-'0'))));
            }

        _res = matmul(_res, matpow(matrix,(bin_n.back()-'0')));

        return _res;
    }

// Функция возведения квадратной матрицы 2х2 во вторую степень
std::vector<std::vector<long long>> Fibbonachi::matpow2(std::vector<std::vector<long long>> matrix)
    {
        std::vector<std::vector<long long>> _res = {{0,0},{0,0}};
        
        _res.at(0).at(0)= matrix.at(0).at(0)*matrix.at(0).at(0)+matrix.at(0).at(1)*matrix.at(1).at(0);
        _res.at(0).at(1)= matrix.at(0).at(0)*matrix.at(0).at(1)+matrix.at(0).at(1)*matrix.at(1).at(1);
        _res.at(1).at(0)= matrix.at(1).at(0)*matrix.at(0).at(0)+matrix.at(1).at(1)*matrix.at(1).at(0);
        _res.at(1).at(1)= matrix.at(1).at(0)*matrix.at(0).at(1)+matrix.at(1).at(1)*matrix.at(1).at(1);
        
        return _res;
    }
    
// Функция перемножения квадратных матриц 2х2
std::vector<std::vector<long long>> Fibbonachi::matmul(std::vector<std::vector<long long>> matrix_1,std::vector<std::vector<long long>> matrix_2)
    {
        std::vector<std::vector<long long>> _res = {{0,0},{0,0}};

        _res.at(0).at(0)= matrix_1.at(0).at(0)*matrix_2.at(0).at(0)+matrix_1.at(0).at(1)*matrix_2.at(1).at(0);
        _res.at(0).at(1)= matrix_1.at(0).at(0)*matrix_2.at(0).at(1)+matrix_1.at(0).at(1)*matrix_2.at(1).at(1);
        _res.at(1).at(0)= matrix_1.at(1).at(0)*matrix_2.at(0).at(0)+matrix_1.at(1).at(1)*matrix_2.at(1).at(0);
        _res.at(1).at(1)= matrix_1.at(1).at(0)*matrix_2.at(0).at(1)+matrix_1.at(1).at(1)*matrix_2.at(1).at(1);

        return _res;
    }