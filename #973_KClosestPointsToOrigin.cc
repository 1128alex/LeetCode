class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        vector<pair<int, int>> idx;
        for (int i = 0; i < points.size(); ++i) {
            int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            idx.push_back({dis, i});
        }
        sort(idx.begin(), idx.end(), [](auto &a, auto &b){
            return a.first < b.first;
        });

        for (int i = 0; i < k; i++) {
            res.push_back(points[idx[i].second]);
        }
        return res;
    }
};