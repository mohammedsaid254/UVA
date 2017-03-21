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

const int N = 500005;
vi adj[N];
int n , r , vis_id , ans , cnt;
int vis[N];
char str[55] , str2[55];
map<string,int> m;

void dfs(int u){
    cnt++;
    vis[u] = vis_id;
    for(int nxt : adj[u])
        if(vis[nxt] != vis_id)
            dfs(nxt);
}

int main()
{

#ifndef ONLINE_JUDGE
	//freopen("in.in", "r", stdin);
	//freopen("out.in", "w", stdout);
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#endif

    while(true){
        scanf("%d%d",&n,&r);
        if(!n && !r)return 0;
        for(int i = 1 ; i <= n ; i++){
            scanf("%s",str);
            string s = string(str);
            m[s] = i;
        }

        for(int i = 0 ; i < r ; i++){
            scanf("%s%s",str,str2);
            string a = string(str);
            string b = string(str2);
            int x = m[a] , y = m[b];
            adj[x].pb(y);
            adj[y].pb(x);
        }

        vis_id++;
        for(int i = 1 ; i <= n ; i++){
            if(vis[i] != vis_id){
                cnt = 0;
                dfs(i);
                ans = max(ans , cnt);
            }
        }

        printf("%d\n",ans);
        ans = 0;
        m.clear();
        for(int i = 1 ; i <= n ; i++)
            adj[i].clear();

    }


    return 0;
}
