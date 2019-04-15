//
//  6014.cpp
//  Deposit
//
//  Created by chenmeiqi on 2019/4/15.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
using namespace std;
char pos[100][100];
bool mark[100][100];
int go[][2]={
    0,1,
    0,-1,
    1,0,
    1,1,
    1,-1,
    -1,0,
    -1,1,
    -1,-1
};
int m,n;
void DFS(int x,int y){
    int nx,ny;
    for(int i = 0; i < 8; i++)
    {
        nx=x+go[i][0];
        ny=y+go[i][1];
        if(nx<0||nx>n||ny<0||ny>m){
            continue;
        }
        if(pos[nx][ny]=='*'){
            continue;
        }
        if(mark[nx][ny]==true){
            continue;
        }
        mark[nx][ny]=true;
        
        DFS(nx,ny);
    }
    return;
}
int main(int argc, const char * argv[]) {
    int count;
    while(cin>>m>>n){
        count=0;
        if(m==0){
            break;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>pos[i][j];
                mark[i][j]=false;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pos[i][j]=='@'&&mark[i][j]==false){
                    DFS(i,j);
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
}
