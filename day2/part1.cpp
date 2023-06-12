#include <bits/stdc++.h>

#include <fstream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

int main() {
    fstream file;
    file.open("puzzleinput.txt");
    string line;
    int count = 0;

    map<char, int> score = {{'X', 1}, {'Y', 2}, {'Z', 3},
                            {'w', 6}, {'l', 0}, {'d', 3}};

    while (getline(file, line)) {
        if ((line[2] == 'X' && line[0] == 'C') ||
            (line[2] == 'Y' && line[0] == 'A') ||
            (line[2] == 'Z' && line[0] == 'B')) {
            count += score['w'] + score[line[2]];
        } else if ((line[2] == 'X' && line[0] == 'B') ||
                   (line[2] == 'Y' && line[0] == 'C') ||
                   (line[2] == 'Z' && line[0] == 'A')) {
            count += score['l'] + score[line[2]];
        } else {
            count += score['d'] + score[line[2]];
        }
        if (file.eof() || line == "") {
            break;
        }
    }
    cout << count;
}