#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Hàm hoán đổi hai kí tự trong chuỗi
void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

// Subtask 1: Duyệt qua từng lần hoán đổi
string solveSubtask1(string S, int k) {
    int n = S.size();
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            for (int l = j + 1; l < n; ++l) {
                if (S[l] > S[j]) {
                    swap(S[j], S[l]);
                    goto nextIteration; // Chuyển sang lần hoán đổi tiếp theo
                }
            }
        }
        nextIteration:;
    }
    return S;
}

// Subtask 2: Sắp xếp và xây dựng dãy kết quả
string solveSubtask2(string S, int k) {
    int n = S.size();
    sort(S.begin(), S.end(), greater<char>()); // Sắp xếp giảm dần

    string result = "";
    int left = 0; // Vị trí bắt đầu của đoạn chưa được đưa lên đầu
    for (int i = 0; i < n; ++i) {
        if (k >= i - left) { // Đủ số lần hoán đổi để đưa S[i] lên đầu
            result = S[i] + result;
            k -= (i - left);
            left++;
        } else {
            result += S[i];
        }
    }
    return result;
}

int main() {
    int k;
    string S;
    cin >> k >> S;

    if (k <= 10) {
        cout << solveSubtask1(S, k) << endl;
    } else {
        cout << solveSubtask2(S, k) << endl;
    }

    return 0;
}
