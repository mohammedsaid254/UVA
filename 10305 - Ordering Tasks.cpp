#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> adj[N];
int vis[N] , vis_id;
vector<int> top;
int n , m;


void dfs(int c){
    vis[c] = vis_id;
    for(int nxt : adj[c])
        if(vis[nxt] != vis_id)
            dfs(nxt);
    top.push_back(c);
}

int main()
{
    while(true){
        scanf("%d%d",&n,&m);
        if(!n && !m)break;
        for(int i = 1 ; i <= n ; i++)
            adj[i].clear();

        int a , b;
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
        }

        vis_id++;
        for(int i = 1 ; i <= n ; i++)
            if(vis[i] != vis_id)
                dfs(i);
        reverse(top.begin() , top.end());
        for(int i = 0 ; i < n ; i++)
            printf("%d%c",top[i]," \n"[i == n-1]);

        top.clear();
    }

    return 0;
}
