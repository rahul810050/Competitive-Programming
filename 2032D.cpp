#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int query(int i, int j) {
    // Replace this logic with the actual logic of your query function.
    return (i + j) % 3; // This is just a placeholder; modify as needed.
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);

        int flag = 0;
        vector<int> s;
        vector<int> ans(n + 1, 0);

        for (int i = 2; i <= n; ++i) {
            if (!flag) {
                int x = query(i, 1);
                if (x == -1) {
                    return 0;
                }

                s.push_back(i);

                if (x == 0) {
                    flag = 1;
                    ans[i] = 1;
                }
            } else {
                while (!s.empty()) {
                    int x = s[0];
                    s.erase(s.begin());

                    int y = query(i, x);
                    if (y == 0) {
                        ans[i] = x;
                        s.push_back(i);
                        break;
                    }
                }
            }
        }

        printf("! ");
        for (int i = 1; i <= n; ++i) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
