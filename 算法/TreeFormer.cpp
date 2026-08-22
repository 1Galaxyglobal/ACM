#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
string former, mid, behind;
struct node
{
    string val;
    ll l, r;
}tree[40];
ll cnt = 0;
ll midbehind(string mid, string behind)
{
    ll k = behind.length();
    char c = behind[k - 1];
    cnt++;
    ll root = cnt;
    tree[root].val = c;
    size_t g = mid.find(c);
    if(g != string::npos)
    {
        string mid_l = mid.substr(0, g);
        string beh_l = behind.substr(0, g);
        string mid_r = mid.substr(g + 1);//角标从 g + 1 到 k - 2
        string beh_r = behind.substr(g, k - 1 - g);
        if (!beh_l.empty() && !mid_l.empty())
        {
            tree[root].l = midbehind(mid_l, beh_l);
        }
        if (!beh_r.empty() && !mid_r.empty())
        {
            tree[root].r = midbehind(mid_r, beh_r);
        }
    }
    return root;
}

void printformer(ll root)
{
    cout << tree[root].val;
    if(root == 0) return;
    if(tree[root].l) printformer(tree[root].l);
    if(tree[root].r) printformer(tree[root].r);
}

ll treeHeight(ll root) 
{
    if (root == 0) return 0;
    ll leftHeight = treeHeight(tree[root].l);
    ll rightHeight = treeHeight(tree[root].r);
    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> mid >> behind;
    ll root = midbehind(mid, behind);
    printformer(root);
    cout << endl;
    cout << treeHeight(root);
    
    return 0;
}