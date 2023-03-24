#include <bits/stdc++.h>
using namespace std;

vector<int> size_dot;
vector<int> eatable;

// Union Find template w/ path compression and union by rank
struct UF {
    vector<int> parent;
    vector<int> rank;

    int n;
    UF (int n): n(n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }
    }

    int find(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void connect(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (rank[x] <= rank[y]) {
            parent[x] = y;
            size_dot[y] += size_dot[x];
        } else {
            parent[y] = x;
            size_dot[x] += size_dot[y];
        }
        if (rank[x] == rank[y]) {
            rank[y]++;
        }
        eatable[x] = eatable[x] | eatable[y];
        eatable[y] = eatable[x] | eatable[y];
    }

    int getSize(int x) {
        return size_dot[find(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string emp;
    std::getline(std::cin, emp);

    vector<vector<char>> maze(n, vector<char>(m));
    vector<vector<int>> idx(n, vector<int>(m, -1));
    
    int non_wall = 0;
    for (int i = 0; i < n; i++) {
        string line;
        getline(std::cin, line);
        for (int j = 0; j < m; j++) {
            maze[i][j] = line[j];
            if (maze[i][j] != 'X') {
                idx[i][j] = non_wall;
                non_wall++;

                if (maze[i][j] == '.') {
                    size_dot.push_back(1);
                } else {
                    size_dot.push_back(0);
                }

                if (maze[i][j] <= 'W' && maze[i][j] >= 'A') {
                    eatable.push_back(1);
                } else {
                    eatable.push_back(0);
                }
            }
        }
    }

    UF dsu(non_wall);

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (maze[i][j] == 'X') continue;
            if (maze[i - 1][j] != 'X') {
                dsu.connect(idx[i][j], idx[i - 1][j]);
            }
            if (maze[i][j - 1] != 'X') {
                dsu.connect(idx[i][j], idx[i][j - 1]);
            }
        }
    }

    unordered_set<int> parents;
    int res = 0;
    int nonreachable = 0;
    for (int i = 0; i < non_wall; i++) {
        if (parents.find(dsu.find(i)) == parents.end()) {
            if (eatable[dsu.find(i)] && dsu.getSize(i)) {
                res++;
            } else {
                nonreachable += dsu.getSize(i);
            }
            parents.insert(dsu.find(i));
        }
    }
    cout << res << " " << nonreachable << "\n";

    return 0;
}
