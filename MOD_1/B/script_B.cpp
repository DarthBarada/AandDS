#include <iostream>
#include <string>
#include <iterator>
#include <regex>
#include <vector>

std::regex command_type_1 ("(set_size )"
                            "([\\d]+)");
std::regex command_type_2 ("(push )"
                            "([\\S]+)");
std::regex command_type_3 ("(pop)");
std::regex command_type_4 ("(print)");
std::regex command_empty ("([\\s]*)");

class Stack
    {
        std::string *array = nullptr;
        int size = 0;
        int top = 0;
public:
        Stack(int temp)
            {
                if (temp > 0)
                    {
                        size = temp;
                        array = new std::string[temp];
                    }
                else
                    {
                        std::cout << "error\n";
                    }       
            }

        ~Stack()
            {
                size = 0;  
                top = 0;
                if(array != nullptr)
                    {
                        delete[] array;
                    }
                 
            }

        void push(std::string str)
            {
                if(top + 1 > size)
                    {
                        std::cout<<"overflow\n";
                    }
                else
                    {
                        array[top] = str;
                        ++top;   
                    }   
            }

        void pop()
            {
                if(top == 0)
                    {
                        std::cout<<"underflow\n";
                    }   
                else
                    {                   
                        --top;
                        std::cout<<array[top]<<"\n";
                    }
            }

        void print()
            {
                if (top!=0)
                    {
                        for(int index = 0; index < top; index++)
                            {
                                std::cout << array[index]<<" ";        
                            }
                    }
                else
                    {
                        std::cout<<"empty";
                    }
                std::cout<<std::endl;
            }
    };  
/*
*   prepare_commands - Функция для парсинга комманд в вектор
*/
void prepare_commands(std::vector<std::string>&vec,std::istreambuf_iterator<char> first,std::istreambuf_iterator<char>last)
    {
        std::string buffer="";
        for (;first!=last;++first)
                {
                    if (*first=='\n')
                        {
                            vec.push_back(buffer);
                            buffer.clear();
                        }
                    else
                        {
                            buffer+=*first;
                        }
                }
    }

int main()
    {
        size_t string_counter = 0u;
        std::cmatch result;

        Stack *stack=nullptr; 
        std::istreambuf_iterator<char> eos;
        std::istreambuf_iterator<char> input_data(std::cin);

        std::vector<std::string> commands{};

        // Проходимся по буфферу ввода
        prepare_commands(commands,input_data,eos);

        for (size_t i=0;i<commands.size();++i)
            {
                if (string_counter == 0u) // Если это первая строка, то проверяем только на set_size
                    {
                        if(std::regex_match(commands.at(i).c_str(), result, command_type_1))
                            {
                                stack = new Stack(std::stoi(result[result.size()-1u].str()));
                            }
                        else
                            {
                                std::cout << "error\n"; 
                            }
                        ++string_counter;
                        continue;
                    }
                if (std::regex_match(commands.at(i).c_str(), result, command_type_1))
                    {
                        std::cout<<"error\n";
                        continue;
                    }
                if (std::regex_match(commands.at(i).c_str(), result, command_type_2))
                    {
                        stack->push(result[result.size()-1u]);
                        continue;
                    }
                if (std::regex_match(commands.at(i).c_str(), result, command_type_3))
                    {
                         stack->pop();
                         continue;
                    }
                if (std::regex_match(commands.at(i).c_str(), result, command_type_4))
                    { 
                         stack->print();
                         continue;
                    }
                if(std::regex_match(commands.at(i).c_str(),result,command_empty)) // Если пустая строка
                    {
                        continue; // Пропускаем
                    }
                else
                    {
                        std::cout<<"error\n";
                    }     
            }
        delete stack;
        return 0;
    }
