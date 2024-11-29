#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

//welp, appreantly upper_bound is a function that exists for multiset... oops XD

int main()
{
    int n_tickets, n_customers, tmp;
    multiset<int> prices;
    vector<int> max_prices;
    cin >> n_tickets >> n_customers;
    for (int i=0; i < n_tickets; i++)
    {
        cin >> tmp;
        prices.insert(tmp);
    }
    for (int i=0; i < n_customers; i++)
    {
        cin >> tmp;
        max_prices.push_back(tmp);
    }
    
    for (int i = 0; i < n_customers; i++)
    {
        auto ticket_price = prices.upper_bound(max_prices[i]);
        if (ticket_price == prices.begin())
        {
            cout << "-1";
        }
        else
        {
            ticket_price--; //upper bound gives the value that bounds the one we want
            cout << (*ticket_price);
            prices.erase(ticket_price);
        }
        if (i != n_customers - 1)
        {
            cout << endl;
        }
    }
}

