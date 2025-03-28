#include <bits/stdc++.h>
using namespace std;

int f = INT_MAX;
int c_min = INT_MAX;
vector<int> visited;
int max_load;
vector<vector<int>> v;

void update(int kiluc) {
    f = min(f, kiluc);
}

void Try(int k, int n, int load, int start, int kiluc) {
    if (kiluc >= f) return; // Cắt tỉa nếu chi phí đã lớn hơn f

    if (k == 2 * n) { // Khi đã đi hết tất cả điểm đón và trả khách
        kiluc += v[start][0]; // Quay lại điểm xuất phát
        update(kiluc);
        return;
    }

    for (int i = 1; i <= 2 * n; i++) {
        if (visited[i] == 0) {
            if (i <= n && load == max_load) continue; // Không thể đón thêm nếu đầy tải

            // Kiểm tra nếu trả khách thì khách phải được đón trước
            if (i > n && visited[i - n] == 0) continue;

            visited[i] = 1;
            kiluc += v[start][i];

            if (kiluc + (2 * n - k) * c_min < f) { // Cắt tỉa mạnh hơn dựa vào ước lượng chi phí tối thiểu còn lại
                if (i <= n) {
                    Try(k + 1, n, load + 1, i, kiluc);
                } else {
                    Try(k + 1, n, load - 1, i, kiluc);
                }
            }

            visited[i] = 0;
            kiluc -= v[start][i];
        }
    }
}

int main() {
    int n;
    cin >> n >> max_load;

    v.resize(2 * n + 1, vector<int>(2 * n + 1));
    visited.resize(2 * n + 1, 0);

    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> v[i][j];
            if (i != j) c_min = min(c_min, v[i][j]); // Cập nhật quãng đường nhỏ nhất
        }
    }

    Try(0, n, 0, 0, 0);

    cout << f << endl;
    return 0;
}
