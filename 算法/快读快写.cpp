#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
inline ll read() 
{
    ll w = 1;
    ll s = 0;
    char c = getchar();
    while (c < '0' || c > '9') 
    {
        if (c == '-') w = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') 
    {
        s = s * 10 + (c - '0');
        c = getchar();
    }
    return w * s;
}
void write(ll x) 
{
    if (x < 0) 
    {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
int main()
{
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(0);
    
    return 0;
}