#include<iostream>
#include <unordered_set>

using namespace std;

const int N = 10010;
int n;

int a[N], s[N];

// bool check(int i, int j, int a[]) {
//     unordered_set<int> seen;
//     for (int k = i; k <= j; k++) {
//         if (seen.find(a[k]) != seen.end()) {
//             return true;
//         }
//         seen.insert(a[k]);
//     }
//     return false;
// }

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int res = 0;
    for (int i = 0, j = 0; i < n; i++) { //枚举 i

        // 核心代码 开数组滑动窗口
        s[a[i]]++;
        while (s[a[i]] > 1) {
            s[a[j]] --;
            j++;
        }

        res = max(res, i - j + 1);
        
    }
    printf("%d", res);
    return 0;
}
