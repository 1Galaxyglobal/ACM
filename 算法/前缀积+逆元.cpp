#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const ll MOD = 1054 * 1054 + 185 * 185;  // MOD = 1125721
// 快速幂求逆元
ll mod_pow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
// 求逆元（费马小定理，要求MOD是质数）
ll mod_inv(ll x, ll mod) {
    return mod_pow(x, mod - 2, mod);
}
// 递推求逆元
vector<ll> get_inv(ll n, ll p) {
    vector<ll> inv(n + 1);
    inv[1] = 1;
    for (ll i = 2; i <= n; i++) {
        inv[i] = p - p / i * inv[p % i] % p;
    }
    return inv;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1, 0), sump(n + 1, 0);
    
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= MOD; 
        if(i == 1) {
            sump[i] = a[i];
        } else {
            sump[i] = sump[i - 1] * a[i] % MOD;
        }
    }
    
    ll ans = 0;
    while(q--)
    {
        ll l, r;
        cin >> l >> r;
        
        ll val;
        if(l != 1) 
        {
            ll inv = mod_inv(sump[l - 1], MOD);
            val = sump[r] * inv % MOD;
        } else {
            val = sump[r];
        }
        ans = ans ^ val; 
    }
    
    cout << ans;
    return 0;
}