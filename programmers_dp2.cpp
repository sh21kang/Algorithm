#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100][100] ={0};
void init(int m, int n,vector<vector<int>> puddles){
    for(int i =0 ; i< n; i++){
        for(int j =0 ; j< m; j++){
            dp[i][j] = 0;
        }
    }

    dp[0][0]=1;
    for(int i =1 ; i< m;i++){
        vector<int> v{ 1 , i+1 };
        if(find(puddles.begin(), puddles.end(),v) != puddles.end() || dp[0][i-1]==0){
                dp[0][i] = 0;
        }else{
            dp[0][i] = 1;
        }
        
    }
    for(int i =1 ; i< n;i++){
        vector<int> v{ i+1,1 };
        if(find(puddles.begin(), puddles.end(),v) != puddles.end()|| dp[i-1][0]==0){
                dp[i][0] = 0;
        }else{
            dp[i][0] = 1;
        }
    }
    
    
    
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    init(m, n,puddles);
   
    for(int i =1 ; i< n; i++){
        for(int j =1; j< m; j++){
            vector<int> v{ i+1,j+1 };
            if(find(puddles.begin(), puddles.end(),v) != puddles.end()){
                dp[i][j] = 0;
            }else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1]%1000000007;
            }
        }
    }
     
    answer = dp[n-1][m-1] ;
    cout << answer;
    return answer;
}