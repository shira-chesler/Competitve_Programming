#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int apps, apartments, diff;
    cin >> apps >> apartments >> diff;
    vector<int> desired, exists;
    int tmp;
    for (int i=0; i < apps; i++)
    {
        cin >> tmp;
        desired.push_back(tmp);
    }
    for (int i=0; i < apartments; i++)
    {
        cin >> tmp;
        exists.push_back(tmp);
    }
    sort(desired.begin(), desired.end());
    sort(exists.begin(), exists.end());
    int des_loc=0, ex_loc=0, matched=0;
    while(des_loc < apps && ex_loc < apartments)
    {
        if (exists[ex_loc] < desired[des_loc] - diff)
        {
            ex_loc++;
        }
        else if ((exists[ex_loc] >= desired[des_loc] - diff) && (exists[ex_loc] <= desired[des_loc] + diff))
        {
            ex_loc++;
            des_loc++;
            matched++;
        }
        else // exists[ex_loc] > desired[des_loc] + diff
        {
            des_loc++;
        }
    }
    cout << matched;
}