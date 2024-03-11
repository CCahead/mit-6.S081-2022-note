#include <iostream>
#include<vector>
using namespace std;

int sum(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/10;
    }
    return sum;
    }

int dfs(int x,int y,int m,int n,int k,vector<vector<int>> &visited){
    if(x<0||y<0||x>m-1||y>n-1||visited[x][y]||(sum(x)+sum(y)>k)){
        return 0;
    }
    visited[x][y]=1;
    return 1+dfs(x+1,y,m,n,k,visited)+dfs(x-1,y,m,n,k,visited)+
    dfs(x,y+1,m,n,k,visited)+dfs(x,y-1,m,n,k,visited);

}

int main() {
    int a=4, b=5, k=7 ;
    // while (cin >> a >> b>>k) { // 注意 while 处理多个 case
        vector<vector<int>> visited(a,vector(b,0));
        int res=dfs(0,0,a,b,k,visited);
        cout << res<< endl;
    }
// }