# include <iostream>
# include <vector>
# include <set>

using namespace std;

set<int> digitsInNum(int num)
{
	int tmp;
	set<int> digits;

	while (true)
	{
		if (num == 0) break;
		tmp = num % 10;
		num = num / 10;
		if (tmp == 0) continue;
		digits.insert(tmp);
	}

	return digits;
}

int minNumSteps(int num)
{
	vector<int> dp(num + 1, 1);
	
	if (num == 0)
	{
		return 0;
	}
	if (num / 10 == 0)
	{
		return 1;
	}

	dp[0] = 0;
	set<int> digits, tmp;
	for (int i = 10; i < num + 1; i++)
	{
		digits = digitsInNum(i);
		for (int digit : digits)
		{
			tmp.insert(dp[i - digit] + 1);
		}
		dp[i] = *tmp.begin();
		tmp.clear();
	}

	return dp[num];
}

int main()
{
	int num;
	cin >> num;

	cout << minNumSteps(num);
	return 0;
}