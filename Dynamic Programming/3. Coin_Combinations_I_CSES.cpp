# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

long coinComb(vector<int> coins, int target)
{
	long mod = (long) 1e9 + 7;
	vector<long> combins(target + 1, 0);
	int size = (int) coins.size();
	for (int i = 0; i < size; i++)
	{
		if (coins[i] > target) continue;
		combins[coins[i]] = 1;
	}

	for (int i = 1; i < target + 1; i++)
	{
		for (int j = 0; j < size && coins[j] <= i; j++)
		{
			combins[i] = (combins[i] + combins[i - coins[j]]) % mod;
		}
	}

	return combins[target];
}

int main()
{
	int n, target, tmp;
	cin >> n >> target;
	vector<int> coins;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		coins.push_back(tmp);
	}

	sort(coins.begin(), coins.end());

	cout << coinComb(coins, target);
}