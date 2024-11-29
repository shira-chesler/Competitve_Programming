//הוגש במקור בחשבון הקודם ב2024-11-04 15:41:21
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<long> vect(26, 0);
    int odd_char_pos;
    char cur_char;
    while(true)
    {
        cur_char = getchar();
        if (cur_char == '\n')
        {
            break;
        }
        vect[cur_char - 'A']++;
    }
    int num_of_odds = 0;
    for(int i=0; i < 26; i++)
    {
        if (vect[i] % 2 != 0) 
        {
            num_of_odds++;
            odd_char_pos = i;
        }
    }
    if (num_of_odds == 0)
    {
        for(int i=0; i < 26; i++)
        {
            if (vect[i] == 0) continue;
            long num_on_this_side = vect[i]/2;
            vect[i] = num_on_this_side;
            for (int j=0; j<num_on_this_side; j++)
            {
                cout << (char)('A'+ i);
            }
        }
        for(int i=25; i>=0; i--)
        {
            for(int j=0; j<vect[i]; j++)
            {
                cout << (char)('A'+ i);
            }
        }
    }
    else if (num_of_odds == 1)
    {
        for(int i=0; i < 26; i++)
        {
            if (i == odd_char_pos) continue;
            if (vect[i] == 0) continue;
            long num_on_this_side = vect[i]/2;
            vect[i] = num_on_this_side;
            for (int j=0; j<num_on_this_side; j++)
            {
                cout << (char)('A'+ i);
            }
        }
        for (int i=0; i<vect[odd_char_pos]; i++)
        {
            cout << (char)('A'+ odd_char_pos);
        }
        for(int i=25; i>=0; i--)
        {
            if (i == odd_char_pos) continue;
            for(int j=0; j<vect[i]; j++)
            {
                cout << (char)('A'+ i);
            }
        }
    }
    else
    {
        cout << "NO SOLUTION";
    }
}