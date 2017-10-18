#include <bits/stdc++.h>
using namespace std;

const int N = 255;
const int INF = 2e9;
int dp[N][N];
int mid[N][N];
int f[N] , acc[N];
int n;

int nf(int idx){
    if(idx)return f[idx] - f[idx-1];
    return f[idx];
}

int main()
{
    while(~scanf("%d",&n)){
        for(int i = 0 ; i < n ;i++){
            scanf("%d",&f[i]);
            acc[i] = f[i];
            if(i)acc[i] += acc[i-1];
        }

        for(int s = 0 ; s <= n-1 ; s++){
            for(int l = 0 ; l+s <= n-1 ; l++){
                int r = l + s;
                if(s < 1){
                    dp[l][r] = 0;
                    mid[l][r] = l;
                    continue;
                }

                int mleft = mid[l][r-1] , mright = mid[l+1][r];
                dp[l][r] = INF;
                for(int m = mleft ; m <= mright ; m++){
                    int x = 0 , y = 0 , z = acc[r] - f[m];
                    if(m)x = dp[l][m-1];
                    if(m+1 <= r)y = dp[m+1][r];
                    if(l)z -= acc[l-1];

                    int cost = x + y + z;
                    if(cost < dp[l][r]){
                        dp[l][r] = cost;
                        mid[l][r] = m;
                    }
                }
            }
        }


        printf("%d\n",dp[0][n-1]);

    }




    return 0;
}
