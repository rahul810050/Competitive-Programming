// BIT MASKING 
  // 0. apple
	// 1. orange
	// 2. banana
	// 3. kiwi
	// using bit masking we can represent the array in bits...we set all the bits which a person has
	// 1st person. [2,3] 1100
	// 2nd person. [0,1, 3] 1011
	// 3rd person. [1,2,3] 1110

	// then we can easily find which person is having same fruits by just doing AND between their bits

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int people;
//     cin >> people;
//     vector<long long> v(people);  // Use long long for bitmask

//     for (int i = 0; i < people; i++) {
//         int fruits;
//         cin >> fruits;
//         long long fruitMask = 0;
//         for (int j = 0; j < fruits; j++) {
//             int fruitIndex;
//             cin >> fruitIndex;
//             fruitMask |= (1LL << fruitIndex);  // Use 1LL to avoid 32-bit overflow
//         }
//         v[i] = fruitMask;
//     }

//     int mxComn = 0;
//     for (int i = 0; i < people - 1; i++) {
//         for (int j = i + 1; j < people; j++) {
//             int common = __builtin_popcountll(v[i] & v[j]);
//             mxComn = max(mxComn, common);
//         }
//     }

//     cout << mxComn << endl;
//     return 0;
// }





// workers and workdays problem

#include<bits/stdc++.h>
using namespace std;
int main(){
    int workers;
    cin>>workers;
    vector<long long> masks(workers);
    for(int i = 0; i < workers; i++){
        int workdays; cin>>workdays;
        long long mask = 0;
        for(int j = 0; j < workdays; j++){
            int day; cin>>day;
            mask |= (1LL << day);
        }
        masks[i] = mask;
    }

    int mxCommonDays = 0;

    for(int i = 0; i < workers; i++){
        for(int j = i+1; j < workers; j++){
            int common = __builtin_popcountll(masks[i] & masks[j]);
            mxCommonDays = max(mxCommonDays, common);
        }
    }
    cout<<mxCommonDays<<endl;

}

