#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int first_idx = 0;
        int second_idx = 1;
        vector<int> result;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            first_idx = i;
            for (int j = i + 1; j < nums.size(); j++)
            {
                second_idx = j;
                if (nums.at(i) + nums.at(j) == target)
                {
                    result.emplace_back(first_idx);
                    result.emplace_back(second_idx);
                    return result;
                }
            }
        }
        result.emplace_back(first_idx);
        result.emplace_back(second_idx);
        return result;
    }
};
