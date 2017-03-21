#include <bits/stdc++.h>
using namespace std;
 
const int N = 10005;
vector<int> adj[N][2];
int comp[N] , vis[N];
int t , n , m , vis_id , cc;
vector<int> stk;
bool valid;
 
void dfs(int u , int flag , int c = 0){
    vis[u] = vis_id;
    if(flag)
        comp[u] = c;
    else
        stk.push_back(u);
 
    for(int nxt : adj[u][flag])
        if(vis[nxt] != vis_id)
            dfs(nxt , flag , c);
}
 
 
void solve(int u = 0){
    vis[u] = 1;
    for(int nxt : adj[u][0]){
        if(vis[nxt] == 0)
            solve(nxt);
        else if(vis[nxt] == 2)
            valid = false;
    }
    vis[u] = 2;
}
 
 
int main()
{
    scanf("%d",&t);
    while(t--){
        valid = true;
        cc = 0;
        stk.clear();
        scanf("%d%d",&n,&m);
        int a , b;
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d",&a,&b);
            adj[a][0].push_back(b);
            adj[b][1].push_back(a);
        }
 
        vis_id++;
        for(int i = 0 ; i < n ; i++)
            if(vis[i] != vis_id)
                dfs(i,0);
 
        reverse(stk.begin(),stk.end());
 
        vis_id++;
        for(int i : stk)
            if(vis[i] != vis_id){
                ++cc;
                dfs(i,1,cc);
            }
 
 
        if(cc > 1)puts("NO");
        else{
            memset(vis,0,sizeof vis);
            vis_id = 0;
            solve();
            if(valid)puts("YES");
            else puts("NO");
        }
 
        for(int i = 0 ; i < n ; i++)
            adj[i][0].clear() , adj[i][1].clear();
 
    }
 
 
 
    return 0;
}
