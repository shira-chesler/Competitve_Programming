//הוגש במקור בחשבון הקודם ב2024-11-04 14:15:47
#include <iostream>

using namespace std;

int main()
{
    long n;
    int modulo_by = 1e9 + 7;
    int string_num = 1;
    cin >> n;
    while(n > 0)
    {
        string_num = string_num * 2;
        string_num = string_num % modulo_by;
        n--;
    }
    cout << string_num;
}