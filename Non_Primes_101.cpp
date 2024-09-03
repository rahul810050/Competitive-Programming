#include <bits/stdc++.h>

using namespace std;

const int MAX_SUM = 200;
bool isPrime[MAX_SUM + 1];

void sieve() {
    fill(isPrime, isPrime + MAX_SUM + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX_SUM; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX_SUM; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();  
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        vector<int> freq(101, 0);

        for (int i = 0; i < N; i++) {
            cin >> A[i];
            freq[A[i]]++;
        }
        
        bool found = false;

        // Check if there's a non-prime sum with a duplicate value
        for (int i = 1; i <= 100; i++) {
            if (freq[i] > 1 && !isPrime[2 * i]) {
                for (int j = 0; j < N; j++) {
                    if (A[j] == i) {
                        for (int k = j + 1; k < N; k++) {
                            if (A[k] == i) {
                                cout << j + 1 << " " << k + 1 << endl;
                                found = true;
                                break;
                            }
                        }
                        if (found) break;
                    }
                }
            }
            if (found) break;
        }

        // Check for non-prime sums between different values
        if (!found) {
            for (int i = 1; i <= 100 && !found; i++) {
                if (freq[i] > 0) {
                    for (int j = i + 1; j <= 100; j++) {
                        if (freq[j] > 0 && !isPrime[i + j]) {
                            int idx1 = -1, idx2 = -1;
                            for (int k = 0; k < N; k++) {
                                if (A[k] == i && idx1 == -1) idx1 = k + 1;
                                if (A[k] == j && idx2 == -1) idx2 = k + 1;
                                if (idx1 != -1 && idx2 != -1) break;
                            }
                            cout << idx1 << " " << idx2 << endl;
                            found = true;
                            break;
                        }
                    }
                }
            }
        }

        if (!found) {
            cout << "-1" << endl;
        }
    }

    return 0;
}
