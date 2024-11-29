//הוגש במקור בחשבון הקודם ב2024-11-04 12:21:45
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long longest_seq = 0, cur_seq = 1;
    char cur_char, prev_char = 'N';
    while(true)
    {
        cur_char = getchar();
        if (cur_char == '\n')
        {
            break;
        }
        if (prev_char == cur_char)
        {
            cur_seq++;
            prev_char = cur_char;
        }
        else
        {
            if (cur_seq > longest_seq)
            {
                longest_seq = cur_seq;
            }
            cur_seq = 1;
            prev_char = cur_char;
        }
        if (cur_seq > longest_seq)
        {
            longest_seq = cur_seq;
        }
    }
    cout << longest_seq;
}