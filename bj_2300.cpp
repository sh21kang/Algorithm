#include <iostream>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int main(){

    int N;
    pair<int ,int> a[100];
    int A[100][2];
    int d[100] ={0};
    cin >> N;

    for(int i =0 ; i< N ; i++){
        cin >> a[i].X>> a[i].Y;
        if(a[i].Y< 0){
            a[i].Y = - a[i].Y;
        }
    }
    
    sort(a, a + N);
    d[0] = a[0].Y * 2;
    for(int i = 1; i< N;i ++){
        int max_h  = a[i].Y;
        d[i] = d[i - 1] + a[i].Y * 2;

        for(int j = i-1; j>= 0 ; j--){
            max_h = max(max_h, a[j].Y );
            if(j >0 ){
                d[i] = min(d[i], max(max_h*2 , a[i].X - a[j].X) + d[j-1]);
            }else{
                d[i] = min(d[i], max(max_h*2 , a[i].X - a[j].X));
            }
        }

    }
    cout << endl;
    cout << d[N-1];


    return 0;

}