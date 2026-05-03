class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> q;
        for (string s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int first = q.back();
                q.pop_back();
                int second = q.back();
                q.pop_back();

                if (s == "+") {
                    q.push_back(second + first);
                } else if (s == "-") {
                    q.push_back(second - first);
                } else if (s == "*") {
                    q.push_back(second * first);
                } else if (s == "/") {
                    q.push_back(second / first);
                }
            } else {
                q.push_back(stoi(s));
            }
        }
        return q[0];
        
    }
};