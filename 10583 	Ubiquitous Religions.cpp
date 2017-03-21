#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
int n , m , a , b , ans , vis_id;
int cases = 1;
vector<int> adj[N];
int vis[N];

void dfs(int u)
{
    vis[u] = vis_id;
    for(int nxt : adj[u])
        if(vis[nxt] != vis_id)
            dfs(nxt);
}


int main()
{
    while(true){
        scanf("%d%d",&n,&m);
        if(!n&&!m)return 0;
        ans = 0;
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d",&a,&b);
            a-- , b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vis_id++;
        for(int i = 0 ; i < n ; i++)
            if(vis[i] != vis_id)
                ans++ , dfs(i);

        for(int i = 0 ; i < n ; i++)
            adj[i].clear();

        printf("Case %d: %d\n",cases++,ans);
    }

    return 0;
}
