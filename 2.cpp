#include<iostream>
#include<cstring>
using namespace std;
int map[10005][10005];
long long dist[20001];
int vis[20001];
int n,m;
int begin,end;
const long long inf = 2147483647;
void dijkstra(int node){
	for(int i=1;i<=n;i++){
		if(vis[i]==0 && dist[i]>dist[node]+map[node][i]){
			dist[i] = dist[node] + map[node][i];
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
	if(mini == -1) return;
	vis[mini] = 1;
	dijkstra(mini);
}
int main(){
	cin >> n >> m;
	cin >> begin;
	memset(map,0x7f7f7f7f,sizeof(map));
	memset(vis,0,sizeof(vis));
	memset(dist,0x7f7f7f7f,sizeof(dist));
	for(int i=0;i<m;i++){
		int a,b;
		int c;
		cin >> a >> b >> c;
		if(!map[a][b]) map[a][b] = c;
		else{
			map[a][b] = min(map[a][b],c); 
		}
	}
	dist[begin] = 0;
	vis[begin] = 1;
	dijkstra(begin);
	for(int i=1;i<=n;i++){
		if(vis[i]==0) cout << inf << " ";
		else cout << dist[i] << ' '; 
	}
	return 0;
}
