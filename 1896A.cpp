#include <iostream>
#include <algorithm>
using namespace std;

int countOccurrence(int n, string grid[], string word)
{
    int count = 0, len = word.length();
    int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int dir = 0; dir < 8; dir++)
            {
                int k, x = i, y = j;
                for (k = 0; k < len; k++, x += dx[dir], y += dy[dir])
                    if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != word[k])
                        break;
                if (k == len) count++;
            }

    return count;
}

int main()
{
    int n;
    cin >> n;
    string grid[n];
    for (int i = 0; i < n; i++) cin >> grid[i];
    string word;
    cin >> word;
    cout << countOccurrence(n, grid, word);
    return 0;
}
