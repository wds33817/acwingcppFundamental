
整数二分：二分本质不是单调性，如果有单调性，就可以二分；
                      但是可以二分的题目，不一定非得有单调性。

#include<iostream>

using namespace std;

const int N = 100010;
int n, m;
int q[N];


int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    while (m--) {
        int x;
        scanf("%d", &x);
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (q[mid] >= x) r = mid;
            else l = mid + 1;
        }
        if (q[l] != x) cout << "-1 -1" << endl;
        else {
          cout << l << ' ';
          int l = 0, r = n - 1;
          while (l < r) {
            int mid = l + r + 1 >> 1;
            if (q[mid] <= x) l = mid;
            else r = mid - 1;
          }
          cout << l << endl;
        }
        
      
    }  

return 0;
}






使用二分查找方法来计算一个非负实数的平方根的C++程序
  #include<iostream>

using namespace std;

int main() {
    double x;
    cin >> x;
    
    double l = 0, r = x;
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid >= x) r = mid;
        else l = mid;
    }
    printf("%lf\n", l);
    return 0;
}


二分查找模板：
// [l, r]  divided into [l, mid]  and  [mid + 1, r]
int bsearch_1(int l, int r) {
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid)) r = mid;
    else l = mid + 1;
  }
  return l;
}


// [l, r] divided into [l, mid - 1]   and  [mid, r] 
int bsearch_2(int l, int r) {
  while (l < r) {
    int mid = l + r + 1 >> 1;
    if (check(mid)) l = mid;
    else r = mid - 1;
  }
  return l;
}





