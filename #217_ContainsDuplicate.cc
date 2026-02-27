class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> numMap;
        for (int num : nums) {
            numMap[num]++;
        }
        for (auto item : numMap) {
            if (item.second > 1) {
                return true;
            }
        }
        return false;
    }
};