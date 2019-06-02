#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int str[100];
int inl[100];
int pnt[100];
int dp[100][100];
bool visited[100];
int solve(int st,int in){
    int &ret = dp[st][in];
   
    if(ret != -1)
        return ret;
    
    ret = 0;
	int pn = 0;
	vector<int> Q;
	for(int i = 0; i < N; i++){
        if(str[i] <= st || inl[i] <= in){
            ret++;
            if(!visited[i]){
                visited[i] = true;
                pn += pnt[i];
                Q.push_back(i);
            }
        }
	}


        for(int i =0; i<= pn; i++ ){
            ret = max(solve(st+i, in+pn-i), ret);
        }
  
    for(int q : Q)
        visited[q] = false;



    return ret;
}


int main(){

    cin >> N;
    for(int i=0; i< N; i++){
        cin >> str[i] >> inl[i] >> pnt[i];
    }
    memset(dp, -1, sizeof dp);
    
    int ans  = solve(1,1);

    cout <<ans;

    return 0;

}