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

const int N = 1e5 + 5;
int p[N] , w[N];
int n;
char str[55] , str2[55];
map<string,int> m;

int f(int u){
    if(u == p[u])return u;
    return p[u] = f(p[u]);
}

bool is_connected(int a , int b){
    return f(a) == f(b);
}

int connect(int a , int b){
    a = f(a);
    b = f(b);
    if(a == b)return w[a];
    if(w[a] < w[b])swap(a,b);
    w[a] += w[b];
    p[b] = a;
    return w[a];
}

void init(){
    for(int i = 0 ; i < N ; i++)
        p[i] = i , w[i] = 1;
}



int main()
{

#ifndef ONLINE_JUDGE
	//freopen("in.in", "r", stdin);
	//freopen("out.in", "w", stdout);
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#endif
    int t , r , id;
    scanf("%d",&t);
    while(t--){
        id = 1;
        init();
        m.clear();

        scanf("%d",&r);
        loop(i,r){
            scanf("%s%s",str,str2);
            string a = string(str) , b = string(str2);
            if(!m[a])m[a] = id++;
            if(!m[b])m[b] = id++;
            printf("%d\n",connect(m[a],m[b]));
        }
    }



    return 0;
}
