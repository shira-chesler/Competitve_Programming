# include <iostream>
# include <vector>
# include <algorithm>
# include <utility>

using namespace std;

int main()
{
	int target, n_ints, temp_int;
	vector<pair<int, int>> values_N_locs;
	cin >> n_ints >> target;
	for (int i = 0; i < n_ints; i++)
	{
		cin >> temp_int;
		values_N_locs.push_back(make_pair(temp_int, i+1));
	}

	auto comp = [](pair<int, int> a, pair
		<int, int> b) {
			return a.first < b.first;
		};

	sort(values_N_locs.begin(), values_N_locs.end(), comp);
	int front = 0, rear = n_ints - 1;
	while (front < rear)
	{
		if (values_N_locs[front].first + values_N_locs[rear].first == target)
		{
			cout << values_N_locs[front].second << " " << values_N_locs[rear].second;
			return 0;
		}
		else if (values_N_locs[front].first + values_N_locs[rear].first > target)
		{
			rear--;
		}
		else
		{
			front++;
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}