# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>

using namespace std;

int main()
{
	int n_lengths, tmp;
	long min_cost = 0;
	vector<int> sticks;
	cin >> n_lengths;
	for (int i = 0; i < n_lengths; i++)
	{
		cin >> tmp;
		sticks.push_back(tmp);
	}
	sort(sticks.begin(), sticks.end());
	if (n_lengths % 2 == 1)
	{
		int mid = n_lengths / 2;
		int mid_stick = sticks[mid];
		for (int i = 0; i < n_lengths; i++)
		{
			min_cost += (long)abs(mid_stick - sticks[i]);
		}
	}
	else
	{
		int mid1 = (n_lengths / 2) - 1, mid2 = (n_lengths / 2);
		int mid_stick1 = sticks[mid1], mid_stick2 = sticks[mid2];
		long cost1 = 0, cost2 = 0;
		for (int i = 0; i < mid1; i++)
		{
			cost1 += (long)abs(mid_stick1 - sticks[i]);
			cost2 += (long)abs(mid_stick2 - sticks[n_lengths - 1 - i]);
		}
		min_cost = cost1 + cost2 + (n_lengths - mid2) * (mid_stick2 - mid_stick1);
	}
	cout << min_cost;
	return 0;
}