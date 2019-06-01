#include<iostream>
using namespace std;

int main(){
    int N;
    int a[100];
    int d[100] ={0};
    cin >> N;

    for (int i=0 ; i< N; i++){
        cin >> a[i];
    }

    // d[i] = a[0] , a[1] ... a[i] 까지 수열이 있을때, a[i]를 포함하는 가장 긴 증가하는 수열의 합
    for(int i=0 ; i< N; i++){
        d[i] =1;
        for(int j =0 ; j< i; j++){
            if(a[j]< a[i] && d[i] < d[j]+1){
                d[i] = d[j] +1;
            }
        }
    }
    int ans= 0;
    for(int i =0 ; i < N; i++){
        if(ans < d[i]){
            ans = d[i];
        }
    }
    cout << endl;
    cout << N - ans;
    

    return 0;
}