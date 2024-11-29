#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num_kids, max_weight, cur_kid;
    vector<int> weights;
    cin >> num_kids >> max_weight;
    for (int i=0; i<num_kids; i++)
    {
        cin >> cur_kid;
        weights.push_back(cur_kid);
    }
    sort(weights.begin(), weights.end());
    int gondolas=0, start=0, end = num_kids-1;
    while( start <= end)
    {
        if(weights[start] + weights[end] <= max_weight)
        {
            start++;
            end--;
        }
        else //end would need its own gondola
        {
            end--;
        }
        gondolas++;
    }
    cout << gondolas;
}