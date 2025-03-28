#include <bits/stdc++.h>

using namespace std;

int H, W, n;
vector<int> h, w;
vector<vector<bool>> mark;
int flag = 0;

bool check(int vx, int vy, int vo, int k) {
    int wk = w[k], hk = h[k];
    if (vo == 1) swap(wk, hk);

    if (vx + wk > W || vy + hk > H) return false;

    for (int i = vx; i < vx + wk; i++) {
        for (int j = vy; j < vy + hk; j++) {
            if (!mark[i][j]) return false;
        }
    }
    return true;
}

void doMark(int vx, int vy, int vo, int k, bool val) {
    int wk = w[k], hk = h[k];
    if (vo == 1) swap(wk, hk);

    for (int i = vx; i < vx + wk; i++) {
        for (int j = vy; j < vy + hk; j++) {
            mark[i][j] = val;
        }
    }
}

void Try(int k) {
    if (k >= n) {
        flag = 1;
        return;
    }

    for (int vo = 0; vo <= 1; vo++) {
        int wk = w[k], hk = h[k];
        if (vo == 1) swap(wk, hk);

        for (int vx = 0; vx <= W - wk; vx++) {
            for (int vy = 0; vy <= H - hk; vy++) {
                if (check(vx, vy, vo, k)) {
                    doMark(vx, vy, vo, k, false);
                    Try(k + 1);
                    doMark(vx, vy, vo, k, true);
                }
                if (flag) return;
            }
        }
    }
}

int main() {
    cin >> H >> W >> n;
    h.resize(n);
    w.resize(n);
    mark.assign(W, vector<bool>(H, true));

    for (int i = 0; i < n; i++) {
        cin >> h[i] >> w[i];
    }

    Try(0);
    cout << flag;
    return 0;
}
