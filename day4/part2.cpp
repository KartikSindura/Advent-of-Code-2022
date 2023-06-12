#include <bits/stdc++.h>

#include <fstream>
#include <regex>
#include <sstream>

using namespace std;

vector<string> split(const string &s, string delim) {
    regex re(delim);
    sregex_token_iterator first{s.begin(), s.end(), re, -1}, last;
    vector<string> tokens{first, last};
    return tokens;
}

int main() {
    fstream file;
    file.open("puzzleinput.txt");
    string line;
    int count = 0;

    vector<string> parsed;

    while (getline(file, line)) {
        parsed = split(line, "[\\,-]");
        
        if (((stoi(parsed[2]) < stoi(parsed[0])) && // check for no overlapping
             (stoi(parsed[3]) < stoi(parsed[0]))) || 
            ((stoi(parsed[2]) > stoi(parsed[1])) &&
             (stoi(parsed[3]) > stoi(parsed[1])))) {
        } else {
            count++;
        }
    }
        cout << count;
}