#include<bits/stdc++.h>
using namespace std;
struct student
{
	int id,chin,total;
};
bool temp(student c,student b)
{
	if (c.total != b.total)
		return c.total > b.total;
	if (c.chin != b.chin)
		return c.chin > b.chin;
	return c.id < b.id;
}
int main()
{
	vector<student>vec;
	for(int j=0;j<3;j++)
	{
		cin>>vec[j].id>>vec[j].total>>vec[j].chin;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vec[i].id = i + 1;
		cin >> vec[i].total >> vec[i].chin;
	}
	sort(vec.begin(),vec.end(),temp);
	for (int i = 0; i < n; i++)
	{
		cout << vec[i].id << " " << vec[i].total;
	}
	return 0;
}