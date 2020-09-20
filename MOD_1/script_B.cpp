#include <iostream>
#include <string>
#include <iterator>
#include <regex>


/* Test
set_size 5
pop
push 1
push 2
push 3
push 4
push 5
print
push 6
pop
push 6
print
*/
std::regex command_type_1 ("(set_size)"
                            "([\\d]+)");
std::regex command_type_2 ("(push)"
                            "([\\S]+)");
std::regex command_type_3 ("(pop)");
std::regex command_type_4 ("(print)");


class Stack
    {
        std::string *array = nullptr;
        size_t size = 0u;
        size_t top = 0u;
public:
        Stack(const Stack &obj)
            {
                size = obj.size;
                
                delete[] array;
                array = obj.array;
            }
        Stack(Stack &&obj)
            {
                size = obj.size;
                obj.size = 0u;
                
                delete[] array;
                array = obj.array;
                obj.array = nullptr;   
            }
        Stack& operator=(Stack &&obj)
            {
                size = obj.size;
                obj.size = 0u;
                
                delete[] array;
                array = obj.array;
                obj.array = nullptr; 

                return *this;
            }

        Stack& operator=(const Stack &obj)
            {
                size = obj.size;
                delete[] array;
                array = obj.array;  

                return *this; 
            }

        Stack(size_t temp)
            {
                size = temp;
                array = new std::string[temp];
            }

        Stack(int temp)
            {
                size = abs(temp);
                array = new std::string[size];
            }

        ~Stack()
            {
                size = 0u;  
                if(array != nullptr)
                    {
                        delete[] array;
                    }
                 
            }

        void push(std::string str)
            {
                if(top + 1u > size)
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
                if(top == 0u)
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
               for(size_t index = 0u; index <= top; ++index)
                    {
                        std::cout<<array[index]<<" ";   
                    }
                std::cout<<"\n";
            }

        void init(size_t count)
            {
                if(array ==nullptr)
                    {
                        size = count;
                        array = new std::string[count];
                    } 
            }

    };  

int main()
    {
        std::string buffer = "";
        std::string str = "";
        size_t matches = 0u;
        size_t string_counter = 0u;
        bool is_error = false;
        std::cmatch result;

        Stack *stack=nullptr;

        std::istreambuf_iterator<char> eos;
        std::istreambuf_iterator<char> input_data(std::cin.rdbuf());

        // Проходимся по буфферу ввода
        std::cout<<str;
        for (auto index = input_data;index!=eos;index++)
            {
                if (*index == '\n') // Если получаем конец строки
                    {
                        ++string_counter; // Увеличиваем счётчик
                        if(buffer.empty()) // Если пустая строка
                            {
                                continue; // Пропускаем
                            }
                        if (string_counter == 1) // Если это первая строка, то проверяем только на set_size
                            {
                                if(std::regex_match(buffer.c_str(), result, command_type_1))
                                    {
                                        int size = std::stoi(result[result.size()-1u].str());
                                        stack = new Stack(size);
                                    }
                                else
                                    {
                                        is_error = true;
                                        std::cout << "error";
                                        break; 
                                    }
                                buffer.clear();
                                ++string_counter;
                                continue;
                            }
                        if (std::regex_match(buffer.c_str(), result, command_type_1))
                            {
                                is_error = true;
                                std::cout<<"error";
                            }
                        if (std::regex_match(buffer.c_str(), result, command_type_2))
                            {
                                stack->push(result[result.size()-1u]);
                            }
                        if (std::regex_match(buffer.c_str(), result, command_type_3))
                            {
                               stack->pop();
                            }
                        if (std::regex_match(buffer.c_str(), result, command_type_3))
                            { 
                                stack->print();
                            }
                        buffer.clear();
                    }
                else
                    {
                        if(*index != ' ')
                            {
                                buffer += *index; 
                            }
                        
                    }
            }
        return 0;
    }