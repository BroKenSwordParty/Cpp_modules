#include <iostream>
#include <string>
#include <locale>
#include <stdio.h>

int main(int argc, char **argv)
{
    int i = 0;
    
    if (argc == 1)
        std::cout << "LOUD AND UNBEARABLE FEEDBACK NOISE" << std::endl;
    else
    {
        while (argv[++i])
        {
            while (*argv[i])
            {
                std::cout << (char)toupper(*argv[i]);
                ++argv[i];
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}