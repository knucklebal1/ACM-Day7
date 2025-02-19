#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn = 105;
#define inf 20  
int c[maxn][maxn];
int m,n;

void floyd()
{
	int k,i,j;
	for(k=1;k<=m;k++)
	{
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(c[i][k] + c[k][j] < c[i][j])
				{
					c[i][j] = c[i][k] + c[k][j];
					
				}
			}
		}
	}
	int max_1,min_1,pos;
	min_1 = inf;
	pos = 0;
	for(i=1;i<=m;i++)
	{
		max_1 = 0;
		for(j=1;j<=m;j++)
		{
			if(c[i][j] > max_1 && i != j)
			{
				max_1 = c[i][j];
			}
		}
		if(max_1 < min_1)
		{
			min_1 = max_1;
			pos = i;
		}
	}
	if(min_1 < inf)
		cout<<pos<<" "<<min_1<<endl;
	else
		cout<<"disjoint"<<endl;
}

int main()
{
	int i,j;
	int num1,num2;
	while(cin>>m && m)
	{
		memset(c,inf,sizeof(c));
		for(i=1;i<=m;i++)
		{
			cin>>n;
			for(j=1;j<=n;j++)
			{
				cin>>num1>>num2;
				c[i][num1] = num2;
			}
		}
		for(i=1;i<=m;i++)
		{
			c[i][i] = 0;
		}
		floyd();
	}
	return 0;
}
