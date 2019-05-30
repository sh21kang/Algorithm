#include <iostream>

using namespace std;
int a[100000] ; // 2 3 1
int b[100000] ; // 5 2 4

int addAll(int start, int end){
    int sum =0;
    for(int i=start; i< end; i++ ){
        sum += a[i] ;
    }
    return sum * b[start];
}

int findMinShop(int end){
    int ans = 1000000;
    int idx;
    for(int i =0 ; i< end ; i++){
        if(ans > b[i]){
            ans = b[i];
            idx = i;
        }
    }
    return idx;
}

int dp(int end){
    if(end==0){
        return 0;
    }
   int start = findMinShop(end);
   int sum = addAll(start , end);

   return sum + dp(start);


}


int main(){
    int N;
    cin >> N;

    for(int i =0 ; i< N-1; i++){
        cin >> a[i];
    }
    for(int i =0 ; i< N; i++){
        cin >> b[i];
    }
    int ans = dp(N-1);
    cout << ans;

    return 0;
}