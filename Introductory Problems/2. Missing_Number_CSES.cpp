//הוגש במקור בחשבון הקודם ב2024-11-04 12:04:53
#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

long like_binary_search(vector<long>, long, long);

int main()
{
    long size_of_series_left, largest_num;
    cin >> largest_num;
    vector<long> vect;
    size_of_series_left = largest_num;
    long cur_num;
    while(size_of_series_left > 1)
    {
        cin >> cur_num;
        vect.push_back(cur_num);
        size_of_series_left = size_of_series_left - 1;
    }
    sort(vect.begin(), vect.end());
    if (vect[0] != 1)
    {
        cout << 1; 
    }
    else if (vect[largest_num - 2] != largest_num)
    {
        cout << largest_num;
    }
    else
    {
        cout << like_binary_search(vect, 1, largest_num-2);
    }
}

long like_binary_search(vector<long> nums_missing_one, long start, long end)
{
    if (end < start)
    {
        return start + 1;
    }
    long mid = (start + end) / 2;
    if (nums_missing_one[mid] == mid + 1)
    {
        start = mid + 1;
    }
    else // nums_missing_one[mid] <= mid
    {
        end = mid - 1;
    }
    return like_binary_search(nums_missing_one, start, end);
}
