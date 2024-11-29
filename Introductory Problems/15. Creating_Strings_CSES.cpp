#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <unordered_set>
#include <set>

using namespace std;

unordered_set<string> create_combinations(char[], int);

int main()
{
    string orig;
    cin >> orig;
    int abc_cnt[26] = {0};
    int len = orig.length();
    for(int i=0; i < len; i++)
    {
        abc_cnt[orig[i]-'a']++;
    }

    char orig_char_arr[len + 1];
    strcpy(orig_char_arr, orig.c_str());
    unordered_set<string> combinations = create_combinations(orig_char_arr, len);

    cout << combinations.size();
    set<string> sortedItems;

    for (auto combin : combinations) 
    {
        sortedItems.insert(combin);
    }

    for (auto combin : sortedItems) 
    {
        cout << endl << combin;
    }
}

// found the existence of next_permutation on geeks for geeks
unordered_set<string> create_combinations(char char_arr[], int len)
{
    sort(char_arr, char_arr + len);
    unordered_set<string> stringSet;
    do { 
         if (stringSet.find((string)char_arr) == stringSet.end())
         {
            stringSet.insert((string)char_arr);
         }
    } while (next_permutation(char_arr, char_arr + len));
    return stringSet;
}