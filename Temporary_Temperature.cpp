// coded by Cocane

#include <bits/stdc++.h>

#define ll long long
#define loop(i, n) for (int i = 0; i < n; i++)
#define loop1(i, n) for (int i = 1; i <= n; i++)
#define rloop(i, n) for (int i = n - 1; i >= 0; i--)
#define first_el first
#define second_el second
#define all_elements(x) (x).begin(), (x).end()
#define read_vector(v) for (auto &elem : v) cin >> elem
#define output(ans) cout << ans << endl

using namespace std;

typedef vector<int> int_vec;
typedef vector<ll> long_vec;

bool is_valid_config(int_vec &temperatures, int num_steps, int max_changes, int max_diff) {
    int change_count = 0;
    int current_min = temperatures[0] - max_diff;
    int current_max = temperatures[0] + max_diff;

    loop(i, num_steps) {
        int next_min = temperatures[i] - max_diff;
        int next_max = temperatures[i] + max_diff;

        if (current_max < next_min || current_min > next_max) {
            change_count++;
            current_min = next_min;
            current_max = next_max;
        } else {
            current_min = max(current_min, next_min);
            current_max = min(current_max, next_max);
        }
    }

    return change_count <= max_changes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int num_steps, max_changes;
        cin >> num_steps >> max_changes;

        int_vec recommended_temps(num_steps);
        read_vector(recommended_temps);

        int left = 0, right = 1e9, optimal_unsavoriness = 1e9;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (is_valid_config(recommended_temps, num_steps, max_changes, mid)) {
                optimal_unsavoriness = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        output(optimal_unsavoriness);
    }

    return 0;
}
