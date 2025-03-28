#include <bits/stdc++.h>
using namespace std;

vector<int> maxVal; // Lưu giá trị lớn nhất tại mỗi node của cây
vector<int> v; // Mảng dữ liệu đầu vào

void buildSegmentTree(int id, int l, int r) {
    if (l == r) {
        maxVal[id] = v[l]; // Gán giá trị từ mảng nguồn
        return;
    }
    int m = (l + r) / 2;
    buildSegmentTree(id * 2, l, m);
    buildSegmentTree(id * 2 + 1, m + 1, r);
    maxVal[id] = max(maxVal[id * 2], maxVal[id * 2 + 1]);
}

int getmax(int id, int l, int r, int i, int j) {
    if (r < i || l > j) return INT_MIN; // Không giao nhau
    if (i <= l && r <= j) return maxVal[id]; // Đoạn con nằm hoàn toàn trong đoạn cần tìm

    int m = (l + r) / 2;
    int maxL = getmax(id * 2, l, m, i, j);
    int maxR = getmax(id * 2 + 1, m + 1, r, i, j);
    return max(maxL, maxR);
}

void update(int id, int l, int r, int index, int val) {
    if (index < l || index > r) return;
    if (l == r) {
        maxVal[id] = val;
        return;
    }
    int m = (l + r) / 2;
    update(id * 2, l, m, index, val);
    update(id * 2 + 1, m + 1, r, index, val);
    maxVal[id] = max(maxVal[id * 2], maxVal[id * 2 + 1]);
}

int main() {
    int n;
    cin >> n;
    v.resize(n + 1);
    maxVal.resize(4 * n, INT_MIN); // Khởi tạo cây phân đoạn

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    buildSegmentTree(1, 1, n); // Xây dựng cây phân đoạn

    int query;
    cin >> query;
    while (query--) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        if (s == "get-max") {
            cout << getmax(1, 1, n, a, b) << endl;
        } else if (s == "update") {
            update(1, 1, n, a, b);
        }
    }
    return 0;
}
