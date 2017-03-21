#include <bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int i = 0;i < int(n);i++)
#define rloop(i,n) for(int i = int(n);i >= 0;i--)
#define range(i,a,b) for(int i = int(a);i <= int(b);i++)
#define INF	1e9
#define SZ(c) int(c.size())
#define ALL(c) c.begin(), c.end()
#define RALL(c) c.rbegin(), c.rend()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 30005;
vi adj[N];
int vis[N] , vis_id;
int t , n  , m;
int cnt , ans;

void dfs(int u){
    cnt++;
    vis[u] = vis_id;
    for(int nxt : adj[u])
        if(vis[nxt] != vis_id)
            dfs(nxt);
}

int main()
{
    scanf("%d",&t);
    while(t--){
        ans = 0;
        scanf("%d%d",&n,&m);
        int a , b;
        loop(i,m){
            scanf("%d%d",&a,&b);
            adj[a].pb(b);
            adj[b].pb(a);
        }

        vis_id++;

        loop(i,n)
            if(vis[i+1] != vis_id){
                cnt = 0;
                dfs(i+1);
                ans = max(ans,cnt);
            }

        printf("%d\n",ans);

        loop(i,n+2)
            adj[i].clear();
    }

    return 0;
}
