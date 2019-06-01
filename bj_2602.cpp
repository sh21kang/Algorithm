#include<iostream>
#include<string>

using namespace std;
string str;
string a[2];
string b[2];

int d[2][8] ={0};
int main(){
    
    cin >> str;
    cin >> a[0];
    cin >> a[1];
    // str = "RGS";
    // a[0] = "RINGSR";
    // a[1] = "GRGGNS";

    int siz = str.size();
    int len = a[0].size();

   
    int sum = 0;
    int flag = 0 ;
    int ans =0 ;

    for(int idx = 0 ; idx < siz; idx++){

        for(int i =0 ; i< len; i++){

            if(idx==0 ){
                if(str[idx]==a[idx%2][i])
                    d[idx%2][i]++;
            }else{
               
                if(str[idx]==a[(idx)%2][i]){
                     int tmp =0;
                    for(int j =0 ; j< i ; j++){
                        tmp  += d[(idx+1)%2][j];
                    }
                     d[idx%2][i] =tmp;
                }
               
            }
            if(ans < d[0][i]){
                ans = d[0][i];
            }
        }

    }
    sum += ans;
    memset(d, 0, sizeof d);
    ans =0 ;
    string tmp = a[0];

    a[0] = a[1];
    a[1] = tmp;
    
    for(int idx = 0 ; idx < siz; idx++){

        for(int i =0 ; i< len; i++){

            if(idx==0 ){
                if(str[idx]==a[idx%2][i])
                    d[idx%2][i]++;
            }else{
               
                if(str[idx]==a[(idx)%2][i]){
                     int tmp =0;
                    for(int j =0 ; j< i ; j++){
                        tmp  += d[(idx+1)%2][j];
                    }
                     d[idx%2][i] =tmp;
                }
               
            }
            if(ans < d[0][i]){
                ans = d[0][i];
            }
        }

    }

    sum += ans;
    cout << sum <<endl;

    


    



    return 0;
}