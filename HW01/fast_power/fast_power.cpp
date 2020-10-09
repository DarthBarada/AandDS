#include "fast_power.hpp"

std::string to_binary_string(unsigned long long n)
    {
        std::string result;
        do
        {
            result = std::to_string(n % 2) + result;
            n = n / 2;
        } while (n > 0);
        return result;
    }

unsigned long long power(unsigned long long num,unsigned long long pow)
    {
        unsigned long long res=1;
        for(unsigned long long i = 0; i < pow;++i)
            {
                res = res*num;
            }
        return res;
    }

unsigned long long fast_power(unsigned long long num,unsigned long long pow)
    {
        unsigned long long _res = 1;
        std::string bin_n = to_binary_string(pow);
        for (int index = 0; index + 1 < int(bin_n.size()); ++index)
            {
                _res = power((_res * power(num,(bin_n.at(index)-'0'))),2);
            }
        return _res * power(num,(bin_n.back()-'0'));
    }