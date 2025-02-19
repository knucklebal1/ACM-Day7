#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+5;

vector<int> edge[N];
int dis[N];

void dfs(int son,int father, int d){
	dis[son]=d;
	for(int i=0;i<edge[son].size();++i){
		if(edge[son][i]!=father){
			dfs(edge[son][i],son,d+1);
		}
	}
}
int main(){
	int n,a,b;
	cin>>n;
	for(int i=0;i<n-1;++i){
		cin>>a>>b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1,-1,0);
	int maxa=1;
	for(int i=1;i<=n;++i){//从任意节点出发，找到最远节点maxa
		if(dis[i]>dis[maxa]){
			maxa=i;
		}
	}
	dfs(maxa,-1,0);
	int maxb=1;
	for(int i=1;i<=n;++i){//从maxa出发，找到最远节点maxb
		if(dis[i]>dis[maxb]){
			maxb=i;
		}
	}
	cout<<dis[maxb];//maxa和maxb之间的路径长度即为树的直径
	return 0;
}
