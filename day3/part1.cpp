#include <bits/stdc++.h>

#include <fstream>
#include <map>
#include <set>
using namespace std;

int main() {
    fstream file;
    file.open("puzzleinput.txt", ios::in);

    string line;
    int count = 0;

    while (getline(file, line)) {
        int len = line.size();

        set<char> first_half;
        set<char> second_half;
        vector<char> dupes;

        for (int i = 0; i < len / 2; i++) {
            first_half.insert(line[i]);
        }
        for (int i = 0; i < len / 2; i++) {
            second_half.insert(line[i + (len / 2)]);
        }
        set_intersection(first_half.begin(), first_half.end(),
                         second_half.begin(), second_half.end(),
                         front_inserter(dupes));

        for (auto &value : dupes) {
            cout << value << endl;
            if (islower(value)) {
                count += int(value) - 'a' +
                         1;  // if dup is 'a' then 'a' - 'a' + 1 = 1
            } else {
                count += int(value) - 'A' +
                         27;  // if dup is 'a' then 'A' - 'A' + 27 = 27
            }
        }
    }
    cout << count << endl;
}