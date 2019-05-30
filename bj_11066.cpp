#include <iostream>
#include <limits.h>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int a[500];
int dp[500][500];
int sum[500];
int DP(int tx, int ty) {
    if (dp[tx][ty] != 0x3f3f3f3f)
        return dp[tx][ty];
 
    if (tx == ty)
        return 0;
 
    if (tx + 1 == ty)
        return dp[tx][ty] = a[tx] + a[ty];
 
    for (int mid = tx; mid < ty; ++mid) {
        int left = DP(tx, mid);
        int right = DP(mid + 1, ty);
        dp[tx][ty] = min(dp[tx][ty], left + right);
    }
 
    return dp[tx][ty] += sum[ty] - sum[tx - 1];
}

int main(){
    
    cin >> N;

    

    for(int i =1; i<= N; i++){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
   memset(dp, 0x3f, sizeof(dp));
    
    // for (int d = 1; d < N; ++d) {
    //         for (int tx = 1; tx + d <= N; ++tx) {
    //             int ty = tx + d;
    //             dp[tx][ty] = INT_MAX;
 
    //             for (int mid = tx; mid < ty; ++mid)
    //                 dp[tx][ty] =
    //                     min(dp[tx][ty], dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
    //         }
    //     }
    // cout << dp[1][N];
    cout << DP(1, N);
    return 0;

}