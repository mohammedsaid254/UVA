#include <bits/stdc++.h>
using namespace std;

const int N = 18;
const int n = 16;
string name[N];
char str[N + N];
int p[N][N];
double ans[N][6];




int main()
{
    for(int i = 0 ; i < n ; i++){
        scanf("%s",str);
        name[i] = string(str);
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%d",&p[i][j]);
        }
    }

    for(int i = 0 ; i < n ; i++)
        ans[i][0] = p[i][i^1] / 100.0;

    for(int g = 1 , m = 4; g <= 3 ; g++ , m <<= 1){
        for(int i = 0 ; i < n ; i += m){
            for(int j = 0 ; j < m/2 ;j++){
                for(int k = m/2 ; k < m ; k++){
                    ans[i+j][g] += ans[i+j][g-1] * ans[i+k][g-1] * p[i+j][i+k] / 100;
                    ans[i+k][g] += ans[i+j][g-1] * ans[i+k][g-1] * p[i+k][i+j] / 100;
                }
            }
        }
    }



    for(int i = 0 ; i < 16 ; i++){
        printf("%-10s p=%.2f%\n",name[i].c_str(),ans[i][3]*100);
    }

    return 0;
}
