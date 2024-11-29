# include <iostream>
# include <vector>

using namespace std;

int main()
{
	int n_ints, tmp;
	long max_sum, cur_sum;
	vector<int> arr;
	cin >> n_ints;
	for (int i = 0; i < n_ints; i++)
	{
		cin >> tmp;
		arr.push_back(tmp);
	}

	cur_sum = arr[0];
	max_sum = arr[0];

	for (int i = 1; i < n_ints; i++)
	{
		if (cur_sum > max_sum)
		{
			max_sum = cur_sum;
		}
		if (cur_sum < 0 && arr[i] > cur_sum)
		{
			cur_sum = arr[i];
		}
		else if (arr[i] + cur_sum > 0)
		{
			cur_sum += arr[i];
		}
		else if (cur_sum > 0)
		{
			cur_sum = arr[i];
		}
	}
	if (cur_sum > max_sum)
	{
		max_sum = cur_sum;
	}
	cout << max_sum;
}