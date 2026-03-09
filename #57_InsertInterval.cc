class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        vector<int> temp = newInterval;
        bool tf = false;
        bool tf2 = false;
        if (intervals.size() == 0) {
            res.emplace_back(newInterval);
            return res;
        }
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval[0] > intervals[i][1]) {
                res.emplace_back(intervals[i]);
                if (i == intervals.size() - 1) {
                    res.emplace_back(newInterval);
                }
            } else if (newInterval[1] < intervals[i][0]) {
                if (!tf2) {
                    res.emplace_back(temp);
                    tf2 = true;
                }
                res.emplace_back(intervals[i]);
            } else {
                if (!tf) {
                    if ((intervals[i][0] < newInterval[0])) {
                        temp[0] = intervals[i][0];
                    } else {
                        temp[0] = newInterval[0];
                    }
                    tf = true;
                }
                if (intervals[i][1] < newInterval[1]) {
                    temp[1] = newInterval[1];
                } else {
                    temp[1] = intervals[i][1];
                }
                if (i == intervals.size() - 1) {
                    res.emplace_back(temp);
                }
            }
        }
        return res;
    }
};