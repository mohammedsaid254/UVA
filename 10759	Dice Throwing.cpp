#include <bits/stdc++.h>
using namespace std;

const int N = 26;
const int X = 155;
unsigned long long dp[N][X];
int vis[N][X];
int n , x , vis_id;

unsigned long long solve(int idx = 0 , int sum = 0){
    if(sum > x)sum = x;
    if(idx == n)return sum == x;
    unsigned long long &ret = dp[idx][sum];
    if(vis[idx][sum] == vis_id)return ret;
    vis[idx][sum] = vis_id;
    ret = 0;
    for(int i = 1 ; i <= 6 ; i++){
        ret += solve(idx+1 , sum + i);
    }
    return ret;
}

unsigned long long power(long long x , int p){
    if(p == 0)return 1;
    unsigned long long e = 1;
    if(p&1) e = x;
    unsigned long long ret = power(x , p/2);
    return ret * ret * e;
}


int main()
{
    while(~scanf("%d%d",&n,&x)){
        vis_id++;
        if(!n && !x)return 0;
        unsigned long long num = solve();
        unsigned long long den = power(6,n);
        unsigned long long g = __gcd(num , den);
        num /= g , den /= g;
        if(num == 0)puts("0");
        else if(num == den)puts("1");
        else cout << num << "/" << den << endl;
    }


    return 0;
}
