# include <iostream>
# include <vector>

using namespace std;

long diceCombination(int n)
{
	long modulo = (long) 1e9 + 7;
	vector<long> dp(n+1,0);

	dp[0] = 1;

	for (int i = 1; i < n+1; i++)
	{
		for (int j = 1; j <= 6 && j <= i; j++)
		{
			dp[i] = (dp[i] + dp[i - j]) % modulo;
		}
	}

	return dp[n];
}


int main()
{
	int n;
	cin >> n;
	cout << diceCombination(n);
	return 0;
}
