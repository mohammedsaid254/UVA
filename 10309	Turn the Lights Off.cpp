#include <bits/stdc++.h>

using namespace std;

const int N = 12;
char str[N][N], input[N][N];
char name[N * N * N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


bool valid(int x, int y) {
    return x >= 0 && x < 10 && y >= 0 && y < 10;
}

void change(char &c) {
    c = (c == '#') ? 'O' : '#';
}

void click(int x, int y) {
    change(str[x][y]);
    for (int i = 0; i < 4; ++i) {
        if (valid(x + dx[i], y + dy[i]))
            change(str[x + dx[i]][y + dy[i]]);
    }
}

bool done() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (str[i][j] != '#')
                return false;
        }
    }
    return true;
}

int simulate() {
    int ret = 0;
    for (int i = 1; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (str[i - 1][j] != '#') {
                ret++;
                click(i, j);
            }
        }
    }
    return done() ? ret : 10000;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    //freopen("out.in", "w", stdout);
#endif
    while (true) {
        scanf("%s", name);
        if (!strcmp(name, "end"))break;
        printf("%s", name);
        for (int i = 0; i < 10; ++i) {
            scanf("%s", input[i]);
        }
        int ans = 1000;
        for (int msk = 0; msk < (1 << 10); ++msk) {
            memcpy(str, input, sizeof str);
            int cur = 0;
            for (int j = 0; j < 10; ++j) {
                if (msk & (1 << j)) {
                    cur++;
                    click(0, j);
                }
            }
            ans = min(ans, cur + simulate());
        }
        printf(" %d\n",ans);
    }
    return 0;
}
