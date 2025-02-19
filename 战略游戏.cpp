#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=1520,inf=0x3f3f3f3f;
vector <int> e[N];
int f[N][2];
int n;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
void dfs(int x,int father){
	f[x][1]=1;
	for(int i=0;i<e[x].size();++i)
	{
		int y=e[x][i];
		if(y==father) continue;
		dfs(y,x);
		f[x][1]+=min(f[y][1],f[y][0]);
		f[x][0]+=f[y][1];
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)
	{
		int x=read()+1,cnt=read(); //程序中储存的节点编号是1~n
		while(cnt--)
		{
			int y=read()+1;
			e[x].push_back(y);
			e[y].push_back(x);
		}
	}
	dfs(1,0);
	cout<<min(f[1][1],f[1][0]);
	return 0;
}
