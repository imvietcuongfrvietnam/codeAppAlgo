#include <map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main() {
    map<string, int> wordCount;
    string line;

    while (getline(cin, line)) {
        stringstream ss(line);
        string word;

        while (ss >> word) { // Sửa lỗi nhập từ stringstream
            wordCount[word]++;
        }
    }

    for (auto it = wordCount.begin(); it != wordCount.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
