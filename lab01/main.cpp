#include <iostream>
#include <string>
#include <chrono>

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
        for(int i = 0; i < pow;i++)
            {
                res = res*num;
            }
        return res;
    }

int main() {

    unsigned long long m = 0,n = 0;
    unsigned long long _res = 1;

    std::cout<<"m^n\n";
    std::cout<<"Enter m: ";
    std::cin>>m;
    std::cout<<"Enter n: ";
    std::cin>>n;

    auto startTime = std::chrono::steady_clock::now();
    std::string bin_n = to_binary_string(n);
    for (int index = 0; index + 1 < int(bin_n.size()); ++index)
        {
            _res = power((_res * power(m,(bin_n.at(index)-'0'))),2);
        }
    _res = _res * power(m,(bin_n.back()-'0'));
    auto endTime = std::chrono::steady_clock::now();

    std::cout<<"Result = "<<_res;
    std::cout<<"\nTime remaining = "<<std::chrono::duration_cast<std::chrono::nanoseconds>(endTime-startTime).count()<<" ns";

    return 0;
}