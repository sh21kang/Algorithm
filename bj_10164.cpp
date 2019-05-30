#include <iostream>

using namespace std;
int N ,M ,K;

int n, m;
int dp[16][16] ={0};
int main(){
    cin >> N >> M >> K;

    n = K /M;
    m = K % M -1;

    for(int i =0 ; i<= n; i++){
        for(int j =0; j<=m; j++){
            if(i==0 || j==0 ){
                dp[i][j] = 1;
            }else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    for(int i =n ; i< N; i++){
        for(int j =m; j<M; j++){
            if(i==n || j==m ){
                dp[i][j] = dp[n][m];
            }else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    cout << dp[N-1][M-1];


    return 0;
}