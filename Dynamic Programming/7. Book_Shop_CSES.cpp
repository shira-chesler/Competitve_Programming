# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int findNumPages(int maxprice, int num_books, vector<int> prices, vector<int> pages)
{
	vector<int> dp(maxprice + 1, 0);
	for (int i = 0; i < num_books; i++)
	{
		for (int j = maxprice; j > 0; j--)
		{
			if (j - prices[i] < 0) continue;
			dp[j] = max(dp[j], dp[j - prices[i]] + pages[i]);
		}
	}
	return dp[maxprice];
}

int main()
{
	int maxprice, num_books, tmp;
	cin >> num_books >> maxprice;
	vector<int> prices(num_books), pages(num_books);

	for (int i = 0; i < num_books; i++)
	{
		cin >> tmp;
		prices[i] = tmp;
	}

	for (int i = 0; i < num_books; i++)
	{
		cin >> tmp;
		pages[i] = tmp;
	}

	cout << findNumPages(maxprice, num_books, prices, pages);
	return 0;
}