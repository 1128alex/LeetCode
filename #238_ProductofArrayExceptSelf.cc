// Products of Array Except Self
// Solved 
// Medium
// Company Tags
// Hints
// Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].

// Each product is guaranteed to fit in a 32-bit integer.

// Follow-up: Could you solve it in 
// O
// (
// n
// )
// O(n) time without using the division operation?

// Example 1:

// Input: nums = [1,2,4,6]

// Output: [48,24,12,8]
// Example 2:

// Input: nums = [-1,0,1,2,3]

// Output: [0,-6,0,0,0]

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        for (int i = 0; i < nums.size(); i++) {
            int temp = 1;
            for (int j = 0; j < nums.size(); j++) {
                if (i != j) {
                    temp *= nums.at(j);
                }
            }
            output.emplace_back(temp);
        }
        return output;
    }
};
