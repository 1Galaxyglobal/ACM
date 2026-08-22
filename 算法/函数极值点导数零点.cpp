/*
给出一个 N 次函数，保证在范围 [l,r] 内存在一点 x，
使得 [l,x] 上单调增，[x,r] 上单调减。试求出 x 的值。
输入一个正整数 N 和两个实数 l,r，含义如题目描述所示。
第二行包含 N+1 个实数，从高到低依次表示该 N 次函数各项的系数。
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const double EPS = 1e-5;
double fast_pow(double a, ll b) {
    double ans = 1.0;
    while(b) {
        if(b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
double cal(const vector<double>& coef, double x, ll n) 
{
    double result = 0.0;
    for(ll i = 1; i <= n; i++) 
    { 
        result += coef[i] * i * fast_pow(x, i - 1);
    }
    return result;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(5);
    ll n;
    double l, r;
    cin >> n >> l >> r;
    vector<double> coef(n + 1, 0); 
    for(ll i = n; i >= 0; i--) 
    {
        cin >> coef[i];
    }
    double L = l, R = r;
    while(R - L > EPS) 
    {
        double mid = (L + R) / 2;
        double der = cal(coef, mid, n);
        if(der > 0) 
        {
            L = mid;
        } 
        else 
        {   
            R = mid;
        }
    }
    cout << (L + R) / 2 << endl;
    return 0;
}
// 法2
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
double l, r;
vector<double> coef;

// 计算函数值 f(x)
double f(double x) {
    double res = 0;
    for (int i = 0; i <= n; i++) {
        res = res * x + coef[i];
    }
    return res;
}

// 计算导数值 f'(x)
double df(double x) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        res = res * x + coef[i] * (n - i);
    }
    return res;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(10);
    
    cin >> n >> l >> r;
    coef.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> coef[i];  // 从高次到低次输入
    }
    
    // 二分查找导数为0的点
    double L = l, R = r;
    const double EPS = 1e-8;
    
    while (R - L > EPS) {
        double mid = (L + R) / 2;
        if (df(mid) > 0) {
            L = mid;  // 导数大于0，函数递增，极值点在右侧
        } else {
            R = mid;  // 导数小于0，函数递减，极值点在左侧
        }
    }
    
    cout << (L + R) / 2 << endl;
    return 0;
}