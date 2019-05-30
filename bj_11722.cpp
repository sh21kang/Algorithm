#include<iostream>
#define MAX 1000
using namespace std;

int main(){
    int N;
    int map[MAX];
    int dp[MAX] = {0};
    cin >> N;
    for(int i =0 ; i< N; i++){
        cin >> map[i];
    }

    for(int i =0; i<N; i++){
        dp[i] =1;
        for(int j=0; j< i; j++){
            if(map[j] > map[i] && dp[i] < dp[j]+1){
                dp[i] = dp[j]+1;
            }
        }
    }

    cout << dp[N-1];


    return 0;
}