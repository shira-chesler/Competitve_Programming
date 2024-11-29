// הוגש במקור בחשבון הקודם ב2024-11-04 10:37:40	
#include <iostream>
#include <string>

int main()
{
    long x;
    std::cin >> x;
    std::string output = std::to_string(x);
    while (x != 1){
        if (x % 2 == 0)
        {
            x = x/2;
            output = output + " " + std::to_string(x);
        }
        else
        {
            x = x*3 + 1;
            output = output + " " + std::to_string(x);
        }
    }
    std::cout << output;
}