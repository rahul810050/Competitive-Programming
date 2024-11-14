// coded by cocane

#include <bits/stdc++.h>

#define ll long long
#define for_each(i, n) for(int i = 0; i < n; i++)
#define for_each1(i, n) for(int i = 1; i <= n; i++)
#define reverse_for_each(i, n) for(int i = n-1; i >= 0; i--)
#define first_element fi
#define second_element se
#define all_elements(x) (x).begin(), (x).end()
#define half_elements(x) (x).begin(), (x).begin() + (x).size()/2, (x).rbegin()
#define push_back_element pb
#define pop_back_element ppb
#define read_elements(a) for(auto &element: a) cin >> element
#define print_result(ans) cout << ans << endl
#define yes_or_no(a) cout << (a ? "YES" : "NO") << endl

using namespace std;

typedef vector<int> int_vector;
typedef vector<ll> long_long_vector;
typedef double double_type;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    cin >> test_cases;
    
    while (test_cases--) {
        int n;
        cin >> n;

        int_vector items(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> items[i];
        }

        int count_one = 0;
        for (int i = 1; i < n; i++) {
            if (items[i] == 1) {
                count_one++;
            }
        }

        int count_zero = 0;
        for (int i = 2; i <= n; i++) {
            if (items[i] == 0) {
                count_zero++;
            }
        }

        int min_count = min(count_one + count_zero, n - 1);
        int result = n + min_count;
        print_result(result);
    }
    return 0;
}
