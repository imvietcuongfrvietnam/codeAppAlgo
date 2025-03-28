#include <bits/stdc++.h>
using namespace std;

vector<int> fibo;
vector<int> mark;
int n;
long long total = 0;
int dequi(int k) {
    if (k < 3) return fibo[k - 1]; // Trả về giá trị đã có sẵn

    if (mark[k-1]) return fibo[k-1]; // Nếu đã đánh dấu, trả về kết quả

    fibo[k-1] = dequi(k - 1) + dequi(k - 2) + dequi(k - 3);
    mark[k-1] = 1; // Đánh dấu đã tính

    return fibo[k-1];
}

int main() {
    cin >> n;

    // Cấp phát bộ nhớ đúng cách
    fibo.resize(n, 0);
    mark.resize(n, 0);

    // Khởi tạo các giá trị đầu tiên
    fibo[0] = 0;
    fibo[1] = 0;
    fibo[2] = 1;
    mark[0] = mark[1] = mark[2] = 1;

    // Gọi hàm đệ quy để tính giá trị
    dequi(n);

    // Xuất kết quả
    for (int i = 0; i <= n-1; i++) {
        cout << fibo[i] << " ";
        total+=fibo[i];
    }
    cout<<total;
}
