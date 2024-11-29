# include <iostream>
# include <utility>
# include <vector>
# include <algorithm>

using namespace std;

int main()
{
	int n_movies, cur_start, cur_finish, max_movies;
	cin >> n_movies;
	vector<pair<int, int>> movies;
	for (int i = 0; i < n_movies; i++)
	{
		cin >> cur_start >> cur_finish;
		movies.push_back(make_pair(cur_start, cur_finish));
	}

	auto comp = [](pair<int, int> a, pair
		<int, int> b) {
			if (a.first == b.first) return a.second < b.second;
			return a.first < b.first;
		};

	sort(movies.begin(), movies.end(), comp);

	cur_start = movies.front().first;
	cur_finish = movies.front().second;
	max_movies = 1;

	for (int i = 1; i < n_movies; i++)
	{
		if (movies[i].second < cur_finish)
		{
			cur_start = movies[i].first;
			cur_finish = movies[i].second;
		}
		else if (movies[i].first >= cur_finish)
		{
			cur_start = movies[i].first;
			cur_finish = movies[i].second;
			max_movies++;
		}
	}
	cout << max_movies;
}