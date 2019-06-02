#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int N;
int a[100];
int d[100][100];

int solve(int start, int end){
    int &ret = d[start][end];
    if(ret != -1 ){
        return ret;
    }
    if(start >= end){
        if((N-(end-start))%2){
            return ret =a[start];
        }else{
            return  0;
        }
    
    }

    if((N-(end-start))%2){
        ret = max(solve(start+1, end)+ a[start], solve(start, end-1)+a[end]);
    }
    else{
        ret = min(solve(start+1, end), solve(start, end-1));
    }   
    return ret;
}


int main(){
    cin >> N;
    for(int i =0 ; i< N; i++){
        cin >> a[i];
    }   
    memset(d, -1, sizeof d);

    int ans = solve(0, N-1);

    cout << ans;
    
    return 0;
}