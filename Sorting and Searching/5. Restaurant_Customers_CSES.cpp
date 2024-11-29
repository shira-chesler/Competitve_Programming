# include <iostream>
# include <vector>
# include <algorithm>
# include <utility>
# include <queue>

using namespace std;

int main()
{
    vector<pair<int, int>> stay_hours;
    int n_customers, arrive_h, leave_h, max_customers=0;
    cin >> n_customers;
    
    for (int i=0; i<n_customers; i++)
    {
        cin >> arrive_h >> leave_h;
        stay_hours.push_back(make_pair(arrive_h, leave_h));
    }

    auto comp = [](pair<int, int> a, pair
                   <int,int> b) {
          if (a.first == b.first) return a.second < b.second;
          return a.first < b.first;
    };

    sort(stay_hours.begin(), stay_hours.end(), comp);
    
    priority_queue<int, vector<int>, greater<int>> leave_hs_queue;
    
    leave_hs_queue.push((1e9)+1);
    int cur_cust_num = 0;
    for(int i=0 ; i < n_customers; i++)
    {
        while (stay_hours[i].first > leave_hs_queue.top())
        {
            if (cur_cust_num > max_customers) max_customers = cur_cust_num;
            leave_hs_queue.pop();
            cur_cust_num--;
        }
        cur_cust_num++;
        leave_hs_queue.push(stay_hours[i].second);
    }
    if (cur_cust_num > max_customers) max_customers = cur_cust_num;

    cout << max_customers;

}