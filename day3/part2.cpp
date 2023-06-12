#include <bits/stdc++.h>

#include <fstream>
#include <map>
#include <set>
using namespace std;

int main() {
    fstream file;
    file.open("puzzleinput.txt", ios::in);

    string line1, line2, line3;
    int count = 0;

    while (getline(file, line1) && getline(file, line2) &&
           getline(file, line3)) {
            
        set<char> first_line;
        set<char> second_line;
        set<char> third_line;
        vector<char> dupes, final_dupes;

        for (int i = 0; i < line1.size(); i++) {
            first_line.insert(line1[i]);
        }
        for (int i = 0; i < line2.size(); i++) {
            second_line.insert(line2[i]);
        }
        for (int i = 0; i < line3.size(); i++) {
            third_line.insert(line3[i]);
        }
        set_intersection(first_line.begin(), first_line.end(),
                         second_line.begin(), second_line.end(),
                         back_inserter(dupes));
        set_intersection(dupes.begin(), dupes.end(), third_line.begin(),
                         third_line.end(), back_inserter(final_dupes));

        for (auto &value : final_dupes) {
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