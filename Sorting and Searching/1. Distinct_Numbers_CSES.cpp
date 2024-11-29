#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num_of_val, temp, cur;
    vector<int> nums;
    cin >> num_of_val;
    for (int i=0; i<num_of_val; i++)
    {
        cin >> temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end());
    cur = nums[0];
    int number_of_nums = 1;
    for (int i=1; i<num_of_val; i++)
    {
        if (nums[i] != cur)
        {
            number_of_nums++;
        }
        cur = nums[i];
    }
    cout << number_of_nums;
}