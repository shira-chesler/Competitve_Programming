# include <iostream>
# include <vector>
# include <utility>
# include <algorithm>

using namespace std;

int main()
{
	int n_ints, rounds = 1, tmp;
	vector<pair<int,int>> ints;
	cin >> n_ints;
	for (int i = 0; i < n_ints; i++)
	{
		cin >> tmp;
		ints.push_back(make_pair(tmp, i));
	}
	
	auto comp = [](pair<int, int> a, pair
		<int, int> b) {
			return a.first < b.first;
		};

	sort(ints.begin(), ints.end(), comp);
	for (int i = 1; i < n_ints; i++)
	{
		if (ints[i].second < ints[i - 1].second)
		{
			rounds++;
		}
	}
	cout << rounds;
}