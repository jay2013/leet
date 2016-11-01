/* ******************************************************************
 * title: Number of Islands
 * url: https://leetcode.com/problems/number-of-islands/
 * date: Tue Nov  1 22:02:16 CST 2016
 * description: 求一个由0，1构成的网格中联通的1有几坨。
 * general idea: 广度优先搜索即可。
 * tags: bfs
 *******************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> > &grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        int sp = 0;
        vector<vector<int> > visit = vector<vector<int> >(n, vector<int>(m, 0));
        
        queue<pair<int, int> >qu;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(visit[i][j] || grid[i][j] == '0') continue;
                while(!qu.empty()) qu.pop();
                qu.push(make_pair(i, j));
                ++ sp;
                visit[i][j] = 1;
                while(!qu.empty()) {
                    pair<int, int> top = qu.front();
                    int i = top.first;
                    int j = top.second;
                    qu.pop();
                    // up
                    if(i > 0 && (grid[i - 1][j] == '1') && !visit[i - 1][j]) {
                        qu.push(make_pair(i - 1, j));
                        visit[i - 1][j] = 1;
                    }
                    // right
                    if(j < m - 1 && (grid[i][j + 1] == '1') && !visit[i][j + 1]) {
                        qu.push(make_pair(i, j + 1));
                        visit[i][j + 1] = 1;
                    }
                    // bottom
                    if(i < n - 1 && (grid[i + 1][j] == '1') && !visit[i + 1][j]) {
                        qu.push(make_pair(i + 1, j));
                        visit[i + 1][j] = 1;
                    }
                    // left
                    if(j > 0 && (grid[i][j - 1] == '1') && !visit[i][j - 1]) {
                        qu.push(make_pair(i, j - 1));
                        visit[i][j - 1] = 1;
                    }
                }
            }
        }
        return sp;
    }    
};

int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    vector<vector<char> > grid;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        vector<char> vc;
        char tmp;
        for(int j = 0; j < m; ++j) {
            cin >> tmp;
            vc.push_back(tmp);
        }
        grid.push_back(vc);
    }
    for(size_t i = 0; i < grid.size(); ++i) {
        for(size_t j = 0; j < grid[i].size(); ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    Solution s;
    cout << s.numIslands(grid) << endl;
    return 0;
}
