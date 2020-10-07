#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 102, K = 13;

int n, k;
pair<pair<int, int>, int> b[N];

vector<pair<int, int> > g[N];

int dp[N][N];
int q[N];
int ndp[N];

bool c[N];
void dfs(int x, int p, int u)
{
    q[x] = 1;
    dp[x][0] = 0;
    dp[x][1] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (h == p)
            continue;
        if (!(u & (1 << g[x][i].se)))
            c[h] = false;
        else
            c[h] = true;
        dfs(h, x, u);
        for (int i = 0; i <= q[x] + q[h]; ++i)
            ndp[i] = 0;
        for (int q1 = 0; q1 <= q[x]; ++q1)
        {
            for (int q2 = 0; q2 <= q[h]; ++q2)
            {
                if (q2)
                    ndp[q1 + q2] += dp[x][q1] * dp[h][q2];
                else
                {
                    if ((u & (1 << g[x][i].se)))
                        ndp[q1 + q2] += dp[x][q1];
                }
            }
        }
        for (int i = 0; i <= q[x] + q[h]; ++i)
            dp[x][i] = ndp[i];
        q[x] += q[h];
    }
}

int ans[N][(1 << K)];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int x = 1; x <= n; ++x)
        g[x].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        --z;
        b[i] = m_p(m_p(x, y), z);
        g[x].push_back(m_p(y, z));
        g[y].push_back(m_p(x, z));
    }
    for (int u = 0; u < (1 << k); ++u)
    {
        for (int q = 1; q <= n; ++q)
            ans[q][u] = 0;

        c[1] = true;
        dfs(1, 1, u);
        for (int x = 1; x <= n; ++x)
        {
            if (c[x])
            {
                for (int i = 1; i <= q[x]; ++i)
                {
                    ans[i][u] += dp[x][i];
                }
            }
        }
    }

    /*for (int q = 1; q <= n; ++q)
    {
        for (int x = 0; x < (1 << k); ++x)
        {
            printf("%d ", ans[q][x]);
        }
        printf("\n");
    }
    return;*/

    for (int q = 1; q <= n; ++q)
    {
        for (int i = 0; i < k; ++i)
        {
            for (int x = 0; x < (1 << k); ++x)
            {
                if ((x & (1 << i)))
                    ans[q][x] -= ans[q][(x ^ (1 << i))];
            }
        }
    }

    for (int q = 1; q <= n; ++q)
    {
        for (int x = 0; x < (1 << k); ++x)
        {
            if (ans[q][x])
                printf("1");
            else
                printf("0");
        }
        printf("\n");
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
