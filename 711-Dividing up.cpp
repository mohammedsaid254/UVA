#include <bits/stdc++.h>

using namespace std;

const int N = 7;
const int M = static_cast<const int>(2e5);
int arr[N], val[N];
int vis[N][M][2], visid;
bool dp[N][M][2];

bool solve(int idx = 1, int a = 0, int b = 0) {
    if (idx == N)return a == b;
    int diff = a - b, flag = 0;
    if (diff < 0)diff = abs(diff), flag = 1;
    if (vis[idx][diff][flag] == visid)return dp[idx][diff][flag];
    vis[idx][diff][flag] = visid;
    dp[idx][diff][flag] = false;
    for (int i = 0; i <= arr[idx]; ++i) {
        if (solve(idx + 1, a + i * idx, b + (arr[idx] - i) * idx)) {
            return (dp[idx][diff][flag] = true);
        }
    }
    return dp[idx][diff][flag];
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    //freopen("out.in", "w", stdout);
#endif
    int cases = 1;
    for (int i = 1; i < N; ++i) val[i] = 120 / i;
    while (true) {
        visid++;
        bool flag = false;
        for (int i = 1; i < N; ++i)scanf("%d", &arr[i]), flag |= arr[i];
        if (!flag)break;
        for (int j = 1; j < N; ++j) {
            while (arr[j] - 2 >= val[j])
                arr[j] -= 2;
        }
        printf("Collection #%d:\n", cases++);
        if (solve()) {
            puts("Can be divided.\n");
        } else {
            puts("Can't be divided.\n");
        }
    }

    return 0;
}
