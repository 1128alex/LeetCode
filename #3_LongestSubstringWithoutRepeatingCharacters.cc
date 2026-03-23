class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string temp;
        int max = 0;
        int cnt = 0;
        for (char c : s) {
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i] == c) {
                    temp = temp.substr(i + 1);
                }
            }
            temp = temp + c;
            if (temp.size() > max) {
                max = temp.size();
            }
        }
        return max;
    }
};