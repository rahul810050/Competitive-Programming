// Solution by Cocane

#include<bits/stdc++.h>

#define ll long long
#define loop(i, n) for(int i = 0; i < n; i++)
#define loop1(i, n) for(int i = 1; i <= n; i++)
#define reverseLoop(i, n) for(int i = n-1; i >= 0; i--)
#define firstElement first
#define secondElement second
#define allElements(x) (x).begin(),(x).end()
#define halfElements(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
#define append push_back
#define removeLast pop_back
#define readInput(a) for(auto &item: a) cin >> item
#define printOutput(ans) cout<<ans<<endl
#define yesNo(a) cout<< (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> intVector;
typedef vector<ll> longLongVector;
typedef double decimal;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n;
        cin >> n;

        intVector arr(n);
        bool isSorted = true;

        loop(i, n) {
            cin >> arr[i];
            if (arr[i] != i + 1) {
                isSorted = false;
            }
        }

        if (isSorted) {
            printOutput(n);
            continue;
        }

        bool hasMatchingIndex = false;
        loop(i, n) {
            if (arr[i] == i + 1) {
                hasMatchingIndex = true;
                break;
            }
        }

        if (hasMatchingIndex) {
            printOutput(n - 1);
        } else {
            printOutput(n - 2);
        }
    }

    return 0;
}
