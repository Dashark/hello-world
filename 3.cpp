#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
struct infor{
	int b;
	int cost;
};
vector<infor>map[20001];
int vis[20001];
int dist[20001];
int n,m;
const long long inf = 2147483647;

void dijkstra(int node){
	for(int i=0;i<map[node].size();i++){
		infor a = map[node][i];//把邻接节点的信息取出来进行操作，方法跟上述方法一致
		if(dist[a.b] > dist[node] + a.cost){
			dist[a.b] = dist[node] + a.cost;
		}
	}
	int Min = 0x7f7f7f7f;
	int mini = -1;
	for(int i=1;i<=n;i++){
		if(vis[i]==0 && dist[i]<Min){
			Min = dist[i];
			mini = i;
		}
	}
	if(mini == -1) return ;
	vis[mini] = 1;
	dijkstra(mini);
}

int main(){
	int begin;
	cin >> n >> m >> begin;
	memset(vis,0,sizeof(vis));
	memset(dist,0x7f7f7f7f,sizeof(dist));
	for(int i=0;i<10009;i++) map[i].clear();
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		infor node;//存储邻接节点信息
		node.b = b;
		node.cost = c;
		map[a].push_back(node);//建立邻接表
	}
	vis[begin] = 1;
	dist[begin] = 0;
	dijkstra(begin);
	for(int i=1;i<=n;i++){
		if(dist[i]==0x7f7f7f7f) cout << inf << " ";
		else cout << dist[i] << " ";
	}
	return 0;
}
