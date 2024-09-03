#include <iostream>
#include <string>
#include <vector>
using namespace std;

int timeToType(const string& s) {
    if (s.empty()) return 0;
    int time = 2;
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            time += 1;
        } else {
            time += 2;
        }
    }
    return time;
}

string findbestPass(const string& s) {
    int mxTime = 0;
    string bestPass;
    
    for (char c = 'a'; c <= 'z'; ++c) {
        for (size_t i = 0; i <= s.size(); ++i) {
            string newPass = s.substr(0, i) + c + s.substr(i);
            int currTime = timeToType(newPass);
            if (currTime > mxTime) {
                mxTime = currTime;
                bestPass = newPass;
            }
        }
    }
    return bestPass;
}

int main() {
    int t;
    cin >> t;
    vector<string> result;
    while (t--) {
        string s;
        cin >> s;
        result.push_back(findbestPass(s));
    }
    
    for (const string& result : result) {
        cout << result << endl;
    }
    
    return 0;
}
