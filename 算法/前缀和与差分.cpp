#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
ll n1,n,m;
ll l,r;
ll l1,r1,l2,r2;
ll l3,r3;
ll value,ba;
ll l4,l5,r4,r5;
vector<ll> a(n1),sum1(n1),sumd1(n1,0);
vector<vector<ll>> vec(n + 1, vector<ll>(m + 1)),sum(n + 1 ,vector<ll>(m + 1));
vector<vector<ll>> cpy(n + 1, vector<ll>(m + 1,0));
void solve_onesum()
{
    cin >> n1;
    for(ll i = 0; i < n1; i++) cin >> a[i];
    sum1[0] = a[0];
    for(ll i = 1; i < n1; i++) {
        sum1[i] = sum1[i-1] + a[i];
    }
    cin >> l >> r;
    if(l == 0) cout << sum1[r] << endl;
    else cout << sum1[r] - sum1[l-1] << endl;
}
void solve_twosum()
{
    cin >> n >> m;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0 ; j < m; j++) {
            cin >> vec[i][j];
        }
    }
    sum[0][0]=vec[0][0];
    for(ll i = 1; i < n; i++) sum[i][0] = sum[i - 1][0] + vec[i][0];
    for(ll j = 1; j < m; j++) sum[0][j] = sum[0][j - 1] + vec[0][j];
    for(ll i = 1; i < n; i++) {
        for(ll j = 1; j < m; j++) {
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] + vec[i][j] - sum[i - 1][j - 1];
        }
    }
    cin >> l1 >> r1 >> l2 >> r2;
    if(l1 == 0 && r1 == 0) cout << sum[l2][r2];
    else if(l1 == 0) cout << sum[l2][r2] - sum[l2][r1 - 1];
    else if(r1 == 0) cout << sum[l2][r2] - sum[l1 - 1][r2]; 
    else cout << sum[l1 - 1][r1 - 1] + sum[l2][r2] -sum[l2][r1 - 1] - sum[l1 - 1][r2];
}
void solve_onediv()
{
    solve_onesum();
    vector<ll> d(n);
    d[0] = a[0];
    for(ll i = 1; i < n1; i++) {
        d[i] = a[i] - a[i - 1];
    }
    cin >> l3 >> r3;
    cin >> value;
    d[l3] += value;
    d[r3 + 1] -= value;
    sumd1[0] = d[0];
    for(ll i = 1; i < n1; i++) sumd1[i] = sumd1[i-1] + d[i];
    for(ll i = 0; i < n1; i++) cout << sumd1[i] << ' ';
    cout << endl;
}
void solve_twodiv()
{
    solve_twosum();
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cpy[i][j] = 0;
        }
    }
    cin >> l4 >> r4 >> l5 >> r5;
    cin >> ba;
    cpy[l4][r4] += ba;
    cpy[l5 + 1][r5 + 1] += ba;
    cpy[l4][r5 + 1] -= ba;
    cpy[l5 + 1][r4] -= ba;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            vec[i][j] += cpy[i][j];
        }
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    ll t;
    cin>>t;
    while(t--)
    {
        solve_onediv();
        solve_twodiv();
    }
    return 0;
}