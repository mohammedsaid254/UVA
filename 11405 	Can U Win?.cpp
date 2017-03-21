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

const int N = 15;
const int M = 1<<10;
char str[N][N];
int n , t , m;
int dp[N][M];
int d[N][N];
pair<int,int> P[N];
int dis[N][N][N];
int dx[]={2,2,-2,-2,1,1,-1,-1};
int dy[]={-1,1,-1,1,-2,2,-2,2};

bool valid(int x , int y){
    if(x < 0 || x >= 8 || y < 0 || y >= 8 || str[x][y] == 'K' || str[x][y] == 'p')return 0;
    return 1;
}

int solve(int idx , int mask){
    if(mask == (1<<m)-1)return 0;
    int &ret = dp[idx][mask];
    if(~ret)return ret;
    ret = INF;
    loop(i,m){
        if(mask & (1<<i))continue;
        ret = min(ret , solve(i , mask |(1<<i)) + d[idx][i]);
    }
    return ret;
}

int main()
{

#ifndef ONLINE_JUDGE
	//freopen("in.in", "r", stdin);
	//freopen("out.in", "w", stdout);
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#endif

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        m = 0;
        loop(i,8)
            scanf("%s",str[i]);

        loop(i,8)
            loop(j,8)
                if(str[i][j] == 'P')
                    P[m++] = {i,j};

        loop(i,8)
            loop(j,8)
                if(str[i][j] == 'k')
                    P[m++] = {i,j};


        loop(k,m)
            loop(i,8)
                loop(j,8)
                    dis[k][i][j] = INF;

        loop(i,m){
            int x = P[i].fr , y = P[i].sc;
            dis[i][x][y] = 0;
            queue<pii > q;
            q.push(mp(x,y));

            while(!q.empty()){
                x = q.front().fr;
                y = q.front().sc;
                q.pop();
                loop(j,8)
                    if(valid(x + dx[j] , y + dy[j]) && dis[i][x + dx[j]][y + dy[j]] == INF){
                        dis[i][x + dx[j]][y + dy[j]] = dis[i][x][y] + 1;
                        q.push(mp(x+dx[j] , y+dy[j]));
                    }
            }
        }

        loop(i,m)
            loop(j,m)
                d[i][j] = dis[i][P[j].fr][P[j].sc];

        memset(dp,-1,sizeof dp);
        m--;
        if(solve(m , 0) <= n)
            puts("Yes");
        else
            puts("No");

    }


    return 0;
}
