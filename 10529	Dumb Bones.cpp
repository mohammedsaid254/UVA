#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
double dp[N];

int main()
{
    int n;
    while(~scanf("%d",&n)){
        if(!n)return 0;
        double pl , pr , p;
        cin >> pl >> pr;
        p = 1 - pl - pr;
        dp[0] = 0;
        dp[1] = 1/p;
        int pre = 0;
        for(int i = 2 ; i <= n ; i++){
            dp[i] = 1e30;
            for(int l = pre ; l < i ; l++){
                int r = i - l - 1;
                double cur = dp[l] + dp[r] + (1 + dp[l] * pl + dp[r] * pr) / p;
                if(cur <= dp[i]){
                    dp[i] = cur;
                    pre = l;
                }
            }
        }

        printf("%.2f\n",dp[n]);
    }


    return 0;
}

