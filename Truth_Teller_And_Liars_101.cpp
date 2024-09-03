#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        if (M > N) {
            cout << -1 << endl;  
        } else {
            cout << N + M << endl;  
        }
    }

    return 0;
}
