#include <iostream>
#include <string>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        string input;
        cin >> input;
        int length = input.size();
        string result = "-1";
        bool isFound = false;

        for (int i = 0; i < length - 1; ++i) {
            if (input[i] == input[i + 1]) {
                result = input.substr(i, 2);
                isFound = true;
                break;
            }
        }

        if (!isFound) {
            for (int i = 0; i < length - 2; ++i) {
                char first = input[i];
                char second = input[i + 1];
                char third = input[i + 2];
                if (first != second && first != third && second != third) {
                    result = input.substr(i, 3);
                    break;
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}
