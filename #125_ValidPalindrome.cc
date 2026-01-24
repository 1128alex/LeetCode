// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

// Example 1:
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

// Example 2:
// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.
 
// Constraints:
// 1 <= s.length <= 2 * 105
// s consists only of printable ASCII characters.
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string s_new;
        for (char c: s) {
            if ((c >= 97 && c <= 122) || (c >= 48 && c <= 57)) {
                s_new += c;
            } else if (c >= 65 && c <= 90) {
                s_new += c + 32;
            }
        }
        // for (char c: s_new) {
        //     cout << c ;
        // }
        // cout << endl;
        for (int i = 0; i < s_new.size()/2; i++) {
            if (s_new[i] != s_new[s_new.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};