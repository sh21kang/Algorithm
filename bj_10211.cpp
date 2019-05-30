#include <iostream>

using namespace std;

int main(){
int N;
int arr[1000];
int dp[1000][1000] ={0};
    cin >> N;
    for(int i =0 ; i< N; i++){
        cin >> arr[i];
    }

    for(int i =0 ; i< N; i++){
        for(int j =0; j<= i ; j++){
            for(int k = j; k <= i; k++){
                 dp[i][j] += arr[k];
            } 
        }
    }
    int ans =0;

    for(int i =0 ; i< N; i++){
        for(int j=0 ; j< N; j++){

        
        if(ans < dp[i][j]){
            ans = dp[i][j];
        }
        }
    }
    
    cout << ans;


    return 0;
}