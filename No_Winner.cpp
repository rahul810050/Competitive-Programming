#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    
    while (T--) {
        int A, B, C, M;
        cin >> A >> B >> C >> M;

				int f = 0;
        
    int minA = A;
    int maxA = A + M;
    int minB = B;
    int maxB = B + M;
    int minC = C;
    int maxC = C + M;
    
    if (maxA >= minB && minA <= maxB) f = 1;
    if (maxA >= minC && minA <= maxC) f = 1;
    if (maxB >= minC && minB <= maxC) f = 1;

		if(f ==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;


    }
    
    return 0;
}
