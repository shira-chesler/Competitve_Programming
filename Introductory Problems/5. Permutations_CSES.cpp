//הוגש במקור בחשבון הקודם ב2024-11-04 13:00:09
#include <iostream> 

// only 2, 3 doen not have a beautifeul perm. Other than that - we can do all odds then all evens
using namespace std;

int main()
{
    long num;
    cin >> num;
    if (num == 2 || num ==3)
    {
        cout << "NO SOLUTION";
    }
    else if (num == 4)
    {
        cout << "2 4 1 3";
    }
    else
    {
        cout << 1;
        long run_num = 3;
        while (run_num <= num)
        {
            cout << " ";
            cout << run_num;
            run_num += 2;
        }
        run_num = 2;
        while (run_num <= num)
        {
            cout << " ";
            cout << run_num;
            run_num += 2;
        }
    }
}