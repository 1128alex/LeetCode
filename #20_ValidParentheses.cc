// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

// Example 1:

// Input: s = "()"

// Output: true

// Example 2:

// Input: s = "()[]{}"

// Output: true

// Example 3:

// Input: s = "(]"

// Output: false

// Example 4:

// Input: s = "([])"

// Output: true

#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (char character : s)
        {
            if (character == '{' || character == '(' || character == '[')
            {
                stk.push(character);
            }
            else
            {
                if (stk.empty())
                    return false;
                if (!stk.empty())
                {
                    if (character == '}' && stk.top() == '{')
                        stk.pop();
                    else if (character == ')' && stk.top() == '(')
                        stk.pop();
                    else if (character == ']' && stk.top() == '[')
                        stk.pop();
                    else
                        return false;
                }
            }
        }
        if (stk.empty())
            return true;
        else
            return false;
    }
};