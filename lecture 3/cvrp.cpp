#include <bits/stdc++.h>
using namespace std;

int K, Q;
int f = 0, fopt = INT_MAX;
vector<bool> visited;
vector<int> d, x, y;
vector<vector<int>> c;
vector<int> load;
int n, segment = 0, nBr = 0;
int cmin = INT_MAX;

bool checkX(int v, int k) {
    if (visited[v] && v > 0) return false;
    if (load[k] + d[v] > Q) return false;
    return true;
}

bool checkY(int v, int k) {
    if (v == 0) return true;
    if (visited[v] && v > 0) return false;
    if (load[k] + d[v] > Q) return false;
    return true;
}

void updateBest() {
    if (f < fopt) {
        fopt = f;
    }
}

void Try_X(int s, int k) {
    if (s == 0) {
        if (k < K) Try_X(y[k + 1], k + 1);
        return;
    }
    for (int v = 0; v <= n; v++) {
        if (checkX(v, k)) {
            x[s] = v;
            visited[v] = true;
            f += c[s][v];
            load[k] += d[v];
            segment++;

            if (v > 0) {
                if (f + (n + nBr - segment) * cmin < fopt)
                    Try_X(v, k);
            } else {
                if (k == K) {
                    if (segment == n + nBr) updateBest();
                } else {
                    if (f + (n + nBr - segment) * cmin < fopt)
                        Try_X(y[k + 1], k + 1);
                }
            }
            visited[v] = false;
            f -= c[s][v];
            load[k] -= d[v];
            segment--;
        }
    }
}

void Try_Y(int k) {
    int s = 0;
    if (y[k - 1] > 0) s = y[k - 1] + 1;

    for (int v = s; v <= n; v++) {
        if (checkY(v, k)) {
            y[k] = v;
            if (v > 0) segment++;

            visited[v] = true;
            f += c[0][v];
            load[k] += d[v];

            if (k < K) {
                Try_Y(k + 1);
            } else {
                nBr = segment;
                Try_X(y[1], 1);
            }

            load[k] -= d[v];
            visited[v] = false;
            f -= c[0][v];
            if (v > 0) segment--;
        }
    }
}

int main() {
    cin >> n >> K >> Q;
    d.resize(n + 1);
    x.resize(n + 1, 0);
    y.resize(n + 1, 0);
    visited.resize(n + 1, false);
    load.resize(K + 1, 0);
    c.assign(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) cin >> d[i];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> c[i][j];
            if (i != j) cmin = min(cmin, c[i][j]);
        }
    }

    Try_Y(1);
    cout << fopt << endl;
}
