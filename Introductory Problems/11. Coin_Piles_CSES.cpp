//הוגש במקור בחשבון הקודם ב2024-11-04 15:18:01
#include <iostream>

using namespace std;

// let's say we have x coins on pile c and y coins on pile d.
// let a and b be the number of moves in each of the piles in order to make them 0.
// then

//x - 2a -1b = 0
//y - 1a - 2b = 0

//b = x - 2a

//y = a + 2(x -2a)
//y = a + 2x -4a
//y = -3a + 2x
//a = (-y + 2x) / 3

//and so, if a is an int and b > 0, there is a  solution

int main()
{
    double num_of_tests, pile_c, pile_d;
    cin >> num_of_tests;
    while(num_of_tests > 0)
    {
        cin >> pile_c;
        cin >> pile_d;
        long cropped = (-pile_d + 2*pile_c)/3;
        if(((-pile_d + 2*pile_c)/3 > cropped) || (pile_c - 2*cropped) < 0 || ((-pile_d + 2*pile_c)/3) < 0)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
        num_of_tests--;
    }
}