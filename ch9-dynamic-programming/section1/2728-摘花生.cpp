// http://noi.openjudge.cn/ch0206/2728/
#include<bits/stdc++.h>
using namespace std;
int f[102][102], a[102][102];
int T,M,N;
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &M, &N);
        for (int i=1;i<=M;++i) {
            for (int j=1;j<=N;++j) scanf("%d", &a[i][j]);
        }
        memset(f,0,sizeof f);
        f[1][1] = a[1][1];
        for (int i=1;i<=M;++i)
            for (int j=1;j<=N;++j) {
                for (int k=0;k<2;++k) {
                    int ni=i+(k^1),nj=j+k;
                    if (ni > M || nj > N) continue;
                    f[ni][nj] = max(f[ni][nj], a[ni][nj] + f[i][j]);
                    //cout<<"ni:"<<ni<<" nj:"<<nj<<" f:"<<f[ni][nj]<<endl;
                }
            }
        printf("%d\n",f[M][N]);
    }
    return 0;
}
