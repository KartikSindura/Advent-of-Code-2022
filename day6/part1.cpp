#include <bits/stdc++.h>

#include <fstream>
#include <set>
using namespace std;

bool check(char &a, char &b, char &c, char &d) {
    set<char> checkers;
    checkers.insert({a, b, c, d});
    if (checkers.size() == 4) {
        return true;
    }
    return false;
}

int main() {
    fstream file;
    file.open("puzzleinput.txt", ios::in);
    string line;
    getline(file, line);

    for (int i = 0; i < line.size(); i++) {
        if (check(line[i], line[i + 1], line[i + 2], line[i + 3])) {
            cout << i + 4;
            break;
        }
    }
}