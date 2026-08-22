#include<bits/stdc++.h>
using namespace std;
int maxn=100;
//仅限于正数的加乘除
string Add(string A,string B)
{
    int a[maxn]={0},b[maxn]={0},c[maxn]={0};
    string s;
    int len=max(A.length(),B.length()); 
    for(int i=A.length()-1,j=1;i>=0;i--,j++)
    {
        a[j]=A[i]-'0';
    }
    for(int i=B.length()-1,j=1;i>=0;i--,j++)
     {
        b[j]=B[i]-'0';
     }
     for(int i=1;i<=len;i++)
    {
        c[i]+=a[i]+b[i];
        c[i+1]+=c[i]/10;
        c[i]=c[i]%10;
    }
    if(c[len+1]) len++;
    for(int i=len;i>=1;i--) 
    {
        s+=to_string(c[i]);
    }
    return s.empty() ? "0" : s;
}

string Sub(string A, string B) 
{
    // 判断结果是否为负数
    bool negative = false;
    if (A.length() < B.length() || (A.length() == B.length() && A < B)) 
    {
        swap(A, B);
        negative = true;
    }
    int a[maxn] = {0}, b[maxn] = {0}, c[maxn] = {0};
    string s;
    for (int i = A.length() - 1, j = 1; i >= 0; i--, j++)
        a[j] = A[i] - '0';
    for (int i = B.length() - 1, j = 1; i >= 0; i--, j++)
        b[j] = B[i] - '0';
    int len = A.length();
    for (int i = 1; i <= len; i++) 
    {
        c[i] += a[i] - b[i];
        if (c[i] < 0) 
        {  
            c[i] += 10;
            c[i + 1]--;
        }
    }
    while (len > 1 && c[len] == 0) len--;
    for (int i = len; i >= 1; i--)
        s += to_string(c[i]);
    if (negative && s != "0")
        s = "-" + s;// 添加负号
    return s;
}

string Time(string A,string B)
{
    int a[maxn]={0},b[maxn]={0},c[maxn]={0};   
    string s;
    for(int i=A.length()-1,j=1;i>=0;i--,j++)
     a[j]=A[i]-'0';
    for(int i=B.length()-1,j=1;i>=0;i--,j++)
     b[j]=B[i]-'0';
    for(unsigned i=1;i<=A.length();i++)
    {
        for(unsigned j=1;j<=B.length();j++)
        c[i+j-1]+=a[i]*b[j];
    }
    int len=A.length()+B.length();
     for(int i=1;i<=len;i++)
     {
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    for(;!c[len];) len--;
    for(int i=max(1,len);i>=1;i--) s+=to_string(c[i]); 
    return s.empty() ? "0" : s;
}

string divide(string A, int B) {
    int a[maxn] = {0}, c[maxn] = {0};  
    string s;
    int lenA = A.length();
    for (int i = 0; i < lenA; i++) {
        a[i + 1] = A[i] - '0';
    }
    long long current = 0;
    int lenC = 0;      
    // 模拟手工除法
    for (int i = 1; i <= lenA; i++) {
        current = current * 10 + a[i];
        if (current < B) {
            // 当前部分不够除，商位为0（除非已经有过非零商位）
            if (lenC > 0) {
                c[++lenC] = 0;
            }
        } else {
            // 计算商位
            c[++lenC] = current / B;
            current %= B;
        }
    }
    // 处理全零情况
    if (lenC == 0) return "0";
    // 转换为字符串
    for (int i = 1; i <= lenC; i++) {
        s += to_string(c[i]);
    }
    return s;
}

int main() 
{
    /*
    int n;
    cin >> n;
    string s = "0";
    vector<string> m(n + 1);
    string op="1";
    for(int j = 1; j <= n; j++) 
    {
        op=Time(op,to_string(j));
    }
    cout<<op<<endl;*/
    string x,y;
    cin >> x >> y;
    int num = stoi(y);
    cout << Add(x,y) << ' ' << Time(x,y) << ' '<< divide(x,num) << endl;
    return 0;
}