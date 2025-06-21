#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int cnt = 0;
        vector<int> length;
        vector<char> history;
        for (int i = 0; i < s.size(); i++)
        {
            // cout << s[i] << ": ";
            if (s.size() == 1)
            {
                return 1;
            }
            if (check_included(history, s[i]) == 1)
            {
                // cout << 1 << endl;
                length.emplace_back(cnt);
                history = modify_list(history, s[i]);
                history.emplace_back(s[i]);

                // cout << "history: ";
                // print_vector(history);

                cnt = history.size();
            }
            else
            {
                // cout << 0 << endl;
                cnt++;
                history.emplace_back(s[i]);
            }
        }
        length.emplace_back(cnt);
        return find_max(length);
    }
    bool check_included(vector<char> list, char c)
    {
        for (int i = 0; i < list.size(); i++)
        {
            if (list.at(i) == c)
            {
                return 1;
            }
        }
        return 0;
    }
    int find_max(vector<int> list)
    {
        int max = 0;
        for (int i = 0; i < list.size(); i++)
        {
            if (max < list[i])
            {
                max = list[i];
            }
        }
        return max;
    }
    vector<char> modify_list(vector<char> list, char c)
    {
        vector<char> temp;
        vector<char> result;

        // cout << "list: ";
        // print_vector(list);

        while (true)
        {
            if (list.back() == c)
            {
                break;
            }
            else
            {
                temp.emplace_back(list.back());
                list.pop_back();
            }
        }

        // cout << "temp: ";
        // print_vector(temp);

        cout << "size: " << temp.size() << endl;
        int size = temp.size();
        for (int i = 0; i < size; i++)
        {
            // cout << "i: " << i << endl;
            result.emplace_back(temp.back());
            // cout << "back: " << temp.back() << endl;
            temp.pop_back();
        }

        // cout << "temp2: ";
        // print_vector(temp);

        // cout << "result: ";
        // print_vector(result);

        return result;
    }
    // void print_vector(vector<char> list) {
    //     for (int j = 0; j < list.size(); j++) {
    //         cout << list.at(j) << ", ";
    //     }
    //     cout << endl;
    // }
};
