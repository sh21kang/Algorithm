#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int d[100]={0};
pair<int, int> a[100];

int N;
int S;

#define H first
#define M second



int main(){
    cin >> N >>S ;

    for(int i =0; i< N; i++){
        cin >> a[i].H >> a[i].M;
    }
    sort(a, a+N );
   
    cout <<endl;
    for(int i =0 ; i< N ; i++){
        d[i] = a[i].M;

        for(int j=0; j< i; j++){ 
            if(d[i] < d[j] + a[i].M && a[i].H-a[j].H >= S ){
                d[i] = d[j] + a[i].M;
            }
        } 
    }
    cout <<endl;
    cout << d[N-1];

    return 0;
}