#include <vector>
#include <string>

std::string ulltosbin(unsigned long long);

class Fibbonachi
    {
        public:

        Fibbonachi()
            {
                n = 0;
                res = 0;
            }
        ~Fibbonachi()
            {
                n = 0;
                res = 0;
            }
        Fibbonachi(long long number)
            {
                n = number;
                calculate();
            }
        long long get_result()
            {
                return res;
            }

        long long calculate(long long number);

        private:

        void calculate();

        std::vector<std::vector<long long>> matpow(std::vector<std::vector<long long>>, unsigned long long);
        std::vector<std::vector<long long>> matpow2(std::vector<std::vector<long long>>);
        std::vector<std::vector<long long>> matmul(std::vector<std::vector<long long>>,std::vector<std::vector<long long>>);
        

        long long n;
        long long res;
        const std::vector<std::vector<long long>> Q{{1,1},{1,0}};
    };