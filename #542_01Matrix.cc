class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        int rows = mat.size();
        int cols = mat[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }
        while (!q.empty()) {
            pair <int, int> curr = q.front();
            q.pop();
            if (rows > curr.first + 1 && mat[curr.first + 1][curr.second] == -1) {
                mat[curr.first + 1][curr.second] = mat[curr.first][curr.second] + 1;
                q.push({curr.first + 1, curr.second});
            }
            if (curr.first - 1 >= 0 && mat[curr.first - 1][curr.second] == -1) {
                mat[curr.first - 1][curr.second] = mat[curr.first][curr.second] + 1;
                q.push({curr.first - 1, curr.second});
            }
            if (cols > curr.second + 1 && mat[curr.first][curr.second + 1] == -1) {
                mat[curr.first][curr.second + 1] = mat[curr.first][curr.second] + 1;
                q.push({curr.first, curr.second + 1});
            }
            if (curr.second - 1 >= 0 && mat[curr.first][curr.second - 1] == -1) {
                mat[curr.first][curr.second - 1] = mat[curr.first][curr.second] + 1;
                q.push({curr.first, curr.second - 1});
            }
        }
        return mat;
    }
};