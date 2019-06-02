#include <iostream>
using namespace std;
#define IMPOSSIBLE -987654321
int N ,K;
int b[100][4];
int w[100][2];
int d[5][10000];
int dp(int state, int tim){
    if(state==N){
      return 0;
    }
    if(tim <= 0){
        return IMPOSSIBLE;
    }

    int &ret = d[state][tim];
    if(ret!= -1){
        return ret;
    }
    ret = IMPOSSIBLE;
    if( tim - b[state][0] >=0   &&   dp(state +1, tim - b[state][0]) != IMPOSSIBLE){
        ret = max(ret,dp(state +1, tim - b[state][0] ) + b[state][1]);
    }
    if( tim - w[state][0] >=0   &&   dp(state +1, tim - w[state][0]) != IMPOSSIBLE){
        ret = max(ret,dp(state +1, tim - w[state][0] ) + w[state][1]);
    }

   return ret;

}

int main(){
    cin >> N >> K;


    for(int i =0 ; i< N;i++){
        cin >> w[i][0] >>w[i][1] >>b[i][0] >>b[i][1];
    }

    memset(d, -1, sizeof d);
    int ans = dp(0, K);

    
    cout << ans;

    

    return 0; 
}