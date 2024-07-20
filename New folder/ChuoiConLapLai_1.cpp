#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Subtask 1: Quy hoạch động (DP)
int longestCommonSubstringDP(const string& S1, const string& S2) {
    int n = S1.size();
    int m = S2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLength = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (S1[i - 1] == S2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return maxLength;
}

// Subtask 2: Sử dụng Trie
struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

void insert(TrieNode* root, const string& key) {
    TrieNode* node = root;
    for (char ch : key) {
        int index = ch - 'A';
        if (!node->children[index]) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

int search(TrieNode* root, const string& key) {
    TrieNode* node = root;
    int length = 0;
    for (char ch : key) {
        int index = ch - 'A';
        if (!node->children[index]) {
            return length;
        }
        node = node->children[index];
        length++;
    }
    return length;
}

int longestCommonSubstringTrie(const string& S1, const string& S2) {
    TrieNode* root = new TrieNode();
    for (int i = 0; i < S1.size(); ++i) {
        insert(root, S1.substr(i));
    }

    int maxLength = 0;
    for (int i = 0; i < S2.size(); ++i) {
        maxLength = max(maxLength, search(root, S2.substr(i)));
    }

    return maxLength;
}

int main() {
    string S1, S2;
    cin >> S1 >> S2;

    int maxLength;

    // Chọn giải pháp tùy thuộc vào giới hạn của subtask
    //if (S1.size() <= 1000 && S2.size() <= 1000) {
      //  maxLength = longestCommonSubstringDP(S1, S2);
    //} else {
        maxLength = longestCommonSubstringTrie(S1, S2);
    //}

    cout << maxLength << endl;

    return 0;
}
