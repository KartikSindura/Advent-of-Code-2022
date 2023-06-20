#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void reverse_stack(stack<char> &S) {
    stack<char> T;
    while (!S.empty()) {
        T.push(S.top());
        S.pop();
    }
    S = T;
}

int main() {
    fstream file;
    file.open("puzzleinput.txt", ios::in);
    string s;
    int N = 0;
    vector<stack<char>> stacks;
    while (getline(file, s) && !s.empty()) {
        N = (s.length() + 1) / 4;
        if (stacks.empty()) {
            stacks = vector<stack<char>>(N);
        }

        for (int i = 1, a = 0; i < s.length(); i += 4, a++) {
            if (isalpha(s[i])) {
                stacks[a].push(s[i]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        reverse_stack(stacks[i]);
    }

    while (getline(file, s) && !s.empty()) {
        vector<string> words;
        stringstream ss(s);
        string t;
        while (ss >> t) {
            words.push_back(t);
        }
        int count = stoi(words[1]);
        int from = stoi(words[3]) - 1;
        int to = stoi(words[5]) - 1;

        for (int i = 0; i < count; i++) {
            char x = stacks[from].top();
            stacks[from].pop();
            stacks[to].push(x);
        }
    }

    string ans;
    for (int i = 0; i < N; i++) {
        if (!stacks[i].empty()) {
            ans += stacks[i].top();
        }
    }
    cout << ans << endl;
}