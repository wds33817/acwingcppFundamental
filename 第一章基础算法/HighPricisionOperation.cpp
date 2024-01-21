#include<iostream>
#include<vector>

using namespace std;
//高精度加法
const int N = 1e6 + 10;

vector<int> add(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(1);
    return C;
}

int main() {
    string a, b;
    vector<int> A, B;
    
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    
    auto C = add(A, B);
    
    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    return 0;
}



#include<iostream>
#include<vector>
//高精度减法
using namespace std;

// 判断是否A >= B
bool cmp(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] != B[i]) {
            return A[i] > B[i];
        }
    }
    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    string a, b;
    vector<int> A, B;
    
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    
    if (cmp(A, B)) {
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    }
    else {
        auto C = sub(B, A);
        printf("-");
        for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    }
    return 0;
}




'a' = 97 
'A' = 65
    

#include<iostream>
#include<vector>
//高精度乘法
using namespace std;

vector<int> mul(vector<int> &A, int b) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i++) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
} 

int main() {
    string a;
    int b;
    
    cin >> a >> b;
    
    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    auto C = mul(A, b);
    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    
    return 0;
    
}







#include<iostream>
#include<vector>
#include<algorithm>
//高精度除法
using namespace std;

vector<int> div(vector<int> &A, int b, int &r) {
    vector<int> C; // 商 
    r = 0; // 余数
    for (int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i];
        cout << A[i];
        C.push_back(r / b);
        r %= b;
    }
    // printf("\n");
    // for (int i = 0; i < C.size(); i++) {
    //     printf("%d", C[i]);
    // }
    // printf("\n");

    //printf("Start to reverse:");
    reverse(C.begin(), C.end());
    // for (int i = 0; i < C.size(); i++) {
    //     printf("%d", C[i]);
    // }
    // printf("\n");
    
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
} 

int main() {
    string a;
    int b;
    
    cin >> a >> b;
    
    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    int r;
    auto C = div(A, b, r);
    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    cout << endl << r << endl;
    
    return 0;
    
}





//ios::sync_with_stdio(false); // 不能再用scanf了，可以提高cin的读取速度。
