#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>

std::string whitelist = "0123456789";

int main()
    {
        std::string str;
        bool flag = false;
        bool have_minus = false;

        for(auto iter = std::istreambuf_iterator<char>(std::cin);iter != std::istreambuf_iterator<char>();++iter)
            {
                if(std::find(std::begin(whitelist),std::end(whitelist),*iter)!=std::end(whitelist))
                    {
                        if (have_minus)
                            {
                                str +='-'; 
                                have_minus = false;
                            }
                        str+=*iter; 
                        flag=true;
                    }
                else
                    {
                        if ((*iter == '-') && (!have_minus))
                            {
                                have_minus=true;
                            }
                        if (have_minus && (*iter != '-'))
                            {
                                have_minus = false;
                            } 
                        if (flag)
                            {
                                str += ' ';
                                flag = false;
                            }  
                    }
                
                if((std::find(std::begin(whitelist),std::end(whitelist),*iter)==std::end(whitelist)))
                    {
                        
                        
                    }
            }
        std::stringstream ss(str);
        long long sum=0;
        for(double number;ss>>number;sum+=number);
        std::cout<<sum;
        return 0;
    }