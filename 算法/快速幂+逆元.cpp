#include<bits/stdc++.h>
using namespace std;
using ll = long long ;

// 快速幂计算 (a^b) % mod
ll fast_pow(ll a, ll b, ll mod) 
{
    ll res = 1;
    while (b > 0) 
    {
        if (b & 1) res = (res * a) % mod;//b 是否为奇数
        a = (a * a) % mod;
        b >>= 1; // b = b / 2;
    }
    return res;
}
ll inv_fermat(ll a, ll mod)
{
    return fast_pow(a, mod - 2, mod);
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
ll n;//矩阵大小
ll ans[1001][1001];//最终矩阵 A矩阵的k次方
ll mod, k; //A矩阵的k次方
ll a1[1001][1001];//矩阵每个位置的数
inline void Fastpower_Matrix1(){  //快速幂里的第一个乘法式子子ans=ans*a
	ll c[105][105] = {0};
	for(ll k = 0; k < n; k++){
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < n; j++){
				c[i][j] = (c[i][j] + ans[i][k] * a1[k][j]) % mod; //注意1e9+7
			}
		}
	}	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			ans[i][j] = c[i][j];
		}
	}
}
inline void Fastpower_Matrix2(){//快速幂里的第而个乘法式子子a=a*a
	ll c[105][105]={0};
	for(ll k = 0; k < n; k++){
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < n; j++){
				c[i][j] = (c[i][j] + a1[i][k] * a1[k][j]) % mod;
			}
		}
	}	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			a1[i][j] = c[i][j];
		}
	}
}

int main() 
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    ll a, mod; // 3 在模 11 下的逆元
    cin >> a >> mod;
    cout << inv_fermat(a, mod) << endl; // 输出 4 (因为 3*4 ≡ 1 mod 11)
    //矩阵快速幂
    for(ll i = 0; i < n; i++) ans[i][i] = 1; // 初始化为单位阵
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < n; j++)
        {
            cin >> a1[i][j];
        }
    }
    while(k)
    {
        if(k & 1)  Fastpower_Matrix1();
        Fastpower_Matrix2();
        k >>= 1;
    }
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < n; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

