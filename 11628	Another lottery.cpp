#include <bits/stdc++.h>
using namespace std;


const int N = 10005;
const int M = 32;
int v[N][M];
int n , m;



int main()
{
    while(scanf("%d%d",&n,&m) == 2){
        if(!n && !m)return 0;

        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                scanf("%d",&v[i][j]);

        long long tot = 0;
        for(int i = 0 ; i < n ; i++)
            tot += v[i][m-1];
        for(int i = 0 ; i < n ; i++){
            long long g = __gcd(1LL * v[i][m-1] , tot);
            printf("%d /",(v[i][m-1]/g));
            printf(" %lld\n",tot/g);
        }
    }


    return 0;
}
