#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string former, mid, behind;
struct node
{
    ll l, r;
    char val;
} tree[30];
ll cnt = 0;

ll formermid(string pre, string in)
{
    cnt++;
    ll root = cnt;
    char k = pre[0];
    tree[root].val = k;
    size_t g = in.find(k);
    if (g != string::npos)
    {
        string in_left = in.substr(0, g);
        string in_right = in.substr(g + 1);
        string pre_left = pre.substr(1, g);
        string pre_right = pre.substr(g + 1);
        if (!pre_left.empty() && !in_left.empty())
        {
            tree[root].l = formermid(pre_left, in_left);
        }
        if (!pre_right.empty() && !in_right.empty())
        {
            tree[root].r = formermid(pre_right, in_right);
        }
    }
    return root;
}

void printbehind(ll root)
{
    if (root == 0) return;
    if (tree[root].l) printbehind(tree[root].l); 
    if (tree[root].r) printbehind(tree[root].r);
    cout << tree[root].val;  
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

    cin >> former >> mid;
    ll root = formermid(former, mid);
    printbehind(root);
    cout << endl;
    cout << treeHeight(root);

    return 0;
}