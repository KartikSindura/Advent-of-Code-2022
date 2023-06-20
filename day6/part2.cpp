#include <bits/stdc++.h>

#include <fstream>
#include <set>
using namespace std;

int main() {
    fstream file;
    file.open("puzzleinput.txt", ios::in);
    string line;
    getline(file, line);

    for (int i = 0; i < line.size(); i++) {
        set<char> check;
        for (int j = 0; j < 14; j++) {
            check.insert(line[j+i]);
        }
        if (check.size() == 14) {
            cout << i + 14;
            break;
        }
    }

}