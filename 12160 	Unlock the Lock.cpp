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

const int N = 10000;
int dist[N];
int l , u , r;
int rv[15];


int main()
{
    int cases = 1;
    while(true){
        scanf("%d%d%d",&l,&u,&r);
        if(!l && !u && !r)break;

        loop(i,r)
            scanf("%d",&rv[i]);

        fill(dist , dist + N , INF);
        queue<int> q;
        dist[l] = 0;
        q.push(l);

        while(!q.empty()){
            int v = q.front();
            if(v == u)break;
            q.pop();
            loop(i,r){
                int x = v + rv[i];
                if(x >= N)
                    x -= N;
                if(dist[x] == INF){
                    dist[x] = dist[v] + 1;
                    q.push(x);
                }
            }
        }

        if(dist[u] == INF)
            printf("Case %d: Permanently Locked\n",cases++);
        else
            printf("Case %d: %d\n",cases++,dist[u]);

    }

    return 0;
}
