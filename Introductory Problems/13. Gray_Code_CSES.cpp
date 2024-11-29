#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void print_code(vector<bool>, int);

int main()
{
    int n;
    cin >> n;
    std::vector<bool> code(n, false);
    std::vector<int> changed_before(n, 0);
    print_code(code, n);
    for(unsigned int i=1; i < pow(2, n); i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == pow(2,j) || changed_before[j] == pow(2,j+1))
            {
                code[j] = !code[j];
                changed_before[j] = 1;
            }
            else if(i > pow(2,j))
            {
                changed_before[j]++;
            }
        }
        cout << "\n";
        print_code(code, n);
    }
}

void print_code(vector<bool> code, int size)
{
    for(int i=0; i<size; i++)
    {
        cout << code[i];
    }
}
