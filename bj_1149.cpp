#include<iostream>
#define MAX 1000
using namespace std;

int N;
int map[MAX][3];
int dp[MAX][3] ={0};
int main(){
    cin >> N;

    for(int i =0; i< N; i++){
        for(int j =0 ; j< 3; j++){
            cin >> map[i][j];
        }
    }

    
    for(int i=0; i<3 ;i++){
        dp[0][i] = map[0][i];
    }

    for(int i =1; i < N ;i ++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + map[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + map[i][1];
        dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + map[i][2];
    }

    int ans = min(dp[N-1][0], dp[N-1][1]);
    ans = min(ans, dp[N-1][0]);

    cout << ans;
    return 0;
}