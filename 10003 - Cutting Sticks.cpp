#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int dp[N][N];
int mid[N][N];
int cut[N];
int stick , n;



int main()
{
    while(scanf("%d",&stick) && stick){
        scanf("%d",&n);
        for(int i = 1 ; i <= n ; i++)
            scanf("%d",&cut[i]);

        sort(cut + 1 , cut + 1 + n);
        cut[0] = 0;
        cut[n+1] = stick;

        for(int s = 0 ; s <= n+1 ; s++){
            for(int l = 0 ; l+s <= n+1 ; l++){
                int r = l + s;
                if(s < 2){
                    dp[l][r] = 0;
                    mid[l][r] = l;
                    continue;
                }

                int mleft = mid[l][r-1] , mright = mid[l+1][r];
                dp[l][r] = 2e9;
                for(int i = mleft ; i <= mright ; i++){
                    int cost = dp[l][i] + dp[i][r] + cut[r] - cut[l];
                    if(dp[l][r] > cost){
                        dp[l][r] = cost;
                        mid[l][r] = i;
                    }
                }
            }
        }

        printf("The minimum cutting is %d.\n",dp[0][n+1]);

    }


    return 0;
}
