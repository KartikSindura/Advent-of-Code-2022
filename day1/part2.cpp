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
        try {
            count += stoi(x);
        } catch (std::invalid_argument) {
            arr.push_back(count);
            count = 0;
        }
        if (file.eof()) {
            arr.push_back(count);
        }
    }
    // int max = *max_element(arr.begin(), arr.end());
    int max = 0;
    sort(arr.begin(), arr.end());
    int vec_size = arr.size();
    for (int i = 1; i <= 3; i++) {
        cout << arr[vec_size - i] << endl;
        max += arr[vec_size - i];
    }

    cout << max;
}