#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, Q;
    cin >> n >> Q;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int left = 0, right = 0, current_sum = 0, max_length = 0;

    while (right < n) {
        // Cộng phần tử mới vào current_sum
        current_sum += v[right];

        // Nếu tổng vượt quá Q, loại bỏ phần tử từ đầu (cửa sổ trượt)
        while (current_sum > Q && left <= right) {
            current_sum -= v[left];
            left++;
        }

        // Cập nhật độ dài lớn nhất của dãy con hợp lệ
        max_length = max(max_length, right - left + 1);

        // Tiếp tục mở rộng cửa sổ trượt
        right++;
    }

    cout << max_length;
    return 0;
}
