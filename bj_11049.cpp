#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>

using namespace std;

int arr[500][2];
int dp[500][500];

int DP(int start, int end){
    if(start ==end)
    return 0;

    int &ret = dp[start][end];
    if(ret != -1)
        return ret;
    int mm = INT_MAX;
    for (int k = start; k < end; ++k)
            mm = min(mm, DP(start, k) + DP(k + 1, end) + arr[k][0] * arr[k][1] * arr[end][1]);
    return ret = mm;

}

int main(){
    int N;
    cin >> N;
    for(int i =0 ; i< N ;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    memset(dp, -1, sizeof(dp));


    cout << DP(0,N-1);



    return 0;


}