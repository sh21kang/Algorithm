#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string a;
int dp[100][100];

int solve(int start , int end){

    int &ret = dp[start][end];

    if(ret != -1){
        return ret;
    }
    if(start >= end){
        return 0;
    }

    if((a[start] == 'a' && a[end] == 't') || (a[start] == 'g' && a[end] == 'c')){
        ret = solve(start+1, end-1) + 2;
    }

    for(int i =start ; i< end; i++){
        ret = max(ret, solve(start, i) + solve(i+1, end));
    }

    return ret;
}

int main(){
    //cin >> a;
    a= "acattgagtc";
    
    memset(dp, -1, sizeof dp);


    int ans = solve(0, a.size()-1);
    cout << ans;
    return 0;
}