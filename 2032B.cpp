#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        long long n, k;
        scanf("%lld %lld", &n, &k);

        long long mx_x = (1 < n) ? (k - 1) : (n * k);
        bool found = false;
        long long pos[1000]; // Allocate enough space for positions
        long long m = 0;
        int pos_size = 0;

        for (long long x = 1; x <= mx_x; x++) {
            long long tmp = k - 1 - x; // Fixed initialization of tmp

            if (tmp < 0) {
                continue;
            }

            long long tv = (tmp % 2 == 0) ? 0 : 1;
            long long mn_p = (k - 1 - x < n - k - x) ? (k - 1 - x) : (n - k - x);

            if (tv > mn_p) {
                continue;
            }

            long long cm = 1 + 2 * x;
            long long l = k - tv - 1;
            long long r = n - k * tv;

            if (l < x || r < x) {
                continue;
            }

            long long pos_lst[1000];
            int pos_lst_size = 0;
            long long p = 1;

            for (long long i = 1; i <= x - 1; i++) {
                pos_lst[pos_lst_size++] = p;
                p += 1;
            }

            if (x > 0) {
                pos_lst[pos_lst_size++] = p;
                p += (l - (x - 1));
            }

            pos_lst[pos_lst_size++] = p;
            p += (2 * tv + 1);

            for (long long i = 1; i <= x - 1; i++) {
                pos_lst[pos_lst_size++] = p;
            }

            p += 1;

            if (x > 0) {
                pos_lst[pos_lst_size++] = p;
                p += (r - (x - 1));
            }

            if (p - 1 == n) { // Changed '=' to '=='
                m = cm;
                for (int i = 0; i < pos_lst_size; i++) {
                    pos[i] = pos_lst[i];
                }
                pos_size = pos_lst_size;
                found = true;
            }
            break; // Ensure this break is intended; might exit the loop too early
        }

        if (found) {
            printf("%lld\n", m);
            for (int i = 0; i < pos_size; i++) {
                printf("%lld%s", pos[i], (i < pos_size - 1) ? " " : "\n");
            }
            continue;
        }

        long long to = (n - 1) / 2;
        if (to == k - 1) {
            printf("1\n1\n");
            continue;
        }

        printf("-1\n");
    }

    return 0;
}
