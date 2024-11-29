# include <iostream>
# include <set>

// agai, apperantly multisets' upper_bound exists XD

using namespace std;

int main()
{
	int n_ints, tmp;
	multiset<int> tower_tops;

	cin >> n_ints;

	cin >> tmp;
	tower_tops.insert(tmp);

	for (int i = 1; i < n_ints; i++)
	{
		cin >> tmp;
		auto cube = tower_tops.upper_bound(tmp);
		if (cube == tower_tops.end())
		{
			tower_tops.insert(tmp);
		}
		else
		{
			tower_tops.erase(cube);
			tower_tops.insert(tmp);
		}

	}
	cout << tower_tops.size();
	return 0;
}