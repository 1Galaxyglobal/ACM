
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct node
{
    ll left, right, val;
}tree[1000001];
void printformer(ll root)
{
    cout << tree[root].val << ' ';
    if(root == 0) return;
    if(tree[root].left) printformer(tree[root].left);
    if(tree[root].right) printformer(tree[root].right);
}
void printmid(ll root)
{
    if(root == 0) return;
    if(tree[root].left) printmid(tree[root].left);
    cout << tree[root].val << ' ';
    if(tree[root].right) printmid(tree[root].right);
}
void printbehind(ll root)
{
    if(root == 0) return;
    if(tree[root].left) printbehind(tree[root].left);
    if(tree[root].right) printbehind(tree[root].right);
    cout << tree[root].val << ' ';
}
int main()
{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        ll a, b;
        cin >> a >> b;
        tree[i].val = i;
        tree[i].left = a;
        tree[i].right = b;
    }
    printformer(1);
    cout << '\n';
    printmid(1);
    cout << '\n';
    printbehind(1);
    return 0;
}