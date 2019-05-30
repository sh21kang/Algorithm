#include <iostream>

#include <algorithm>
using namespace std;
#define MAX 2000
int dp[MAX][MAX];

int leftc[3]= {3, 2, 5}, rightc[3]= {2, 4, 1}, cnt;

int DP(int a, int b) {
	if (a == cnt || b == cnt) return 0;
	if (dp[a][b] != -1) return dp[a][b];
	dp[a][b] = max(DP(a + 1, b), DP(a + 1, b + 1));
	if (leftc[a] > rightc[b]) dp[a][b] = max(dp[a][b], DP(a, b + 1) + rightc[b]);
	return dp[a][b];
}


int main(){

    

    memset(dp, -1, sizeof dp);
    cnt  = sizeof(leftc)/sizeof(int);

    int ans = DP(0,0);

   cout << ans;
    return 0 ;

}