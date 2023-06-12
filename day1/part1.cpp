#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
    fstream file;
    file.open("puzzleinput.txt", ios::in);

    string x;
    int count = 0;
    vector<int> arr;

    while (getline(file, x)) {
        if (x != "") {
            count += stoi(x);
        } else {
            arr.push_back(count);
            count = 0;
        }
        if (file.eof()) {
            arr.push_back(count);
        }
    }
    int max = *max_element(arr.begin(), arr.end());
    cout << max;
}