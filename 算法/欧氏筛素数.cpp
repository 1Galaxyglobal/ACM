#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll isPrime[100000010];
ll Prime[8000010], cnt = 0;
void GetPrime(ll n)
{
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[1] = 0;
	
	for(ll i = 2; i <= n; i++)
	{
		if(isPrime[i])
        {
            cnt++;
            Prime[cnt] = i; 
        }
		for(ll j = 1; j <= cnt && i*Prime[j] <= n; j++) 
		{
			isPrime[i*Prime[j]] = 0;
			if(i % Prime[j] == 0)
				break; 
		}
	}
}

ll main()
{
	ll n, q;
	cin >> n >> q;
	GetPrime(n);
	while (q--)
	{
		ll k;
		cin >> k;
        cout << Prime[k] << '\n';
	}
	return 0;
}

