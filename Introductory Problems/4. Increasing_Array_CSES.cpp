//הוגש במקור בחשבון הקודם ב2024-11-04 12:43:07
#include <iostream> 
#include <vector>

//"If I'm smaller than my prev - make us equal"
using namespace std;

int main()
{
    long cur, prev, num_of_move = 0, num_of_nums;
    cin >> num_of_nums;
    cin >> prev;
    while(num_of_nums > 1)
    {
        num_of_nums--;
        cin >> cur;
        if (cur < prev)
        {
            num_of_move = num_of_move + (prev - cur);
        }
        else
        {
            prev = cur;
        }
    }
    cout << num_of_move;
}