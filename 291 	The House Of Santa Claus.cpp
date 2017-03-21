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

vector<vi> v;
vector<int> cur;
vector<pii> h;


void gen(int idx = 0){
    if(idx == 9){
        v.pb(cur);
        return;
    }else if(idx == 0){
        cur.pb(1);
        gen(idx+1);
        return;
    }

    range(i,1,5){
        cur.pb(i);
        gen(idx+1);
        cur.pop_back();
    }
}

pii f(int x , int y){
    return mp(min(x,y) , max(x,y));
}

bool valid(vi s){
    map<pii , int> m;
    loop(i,SZ(s)-1){
        m[f(s[i] , s[i+1])]++;
        if(m[f(s[i] , s[i+1])] > 1)return 0;
    }

    loop(i,SZ(h))
        if(!m[h[i]])
            return 0;

    return 1;
}

int main()
{
    h.pb(mp(1,2));
    h.pb(mp(1,3));
    h.pb(mp(1,5));

    h.pb(mp(2,3));
    h.pb(mp(2,5));

    h.pb(mp(3,4));
    h.pb(mp(3,5));

    h.pb(mp(4,5));

    gen();
    loop(i,SZ(v))
        if(valid(v[i])){
            loop(j,SZ(v[i]))
                printf("%d",v[i][j]);
            puts("");
        }


    return 0;
}
