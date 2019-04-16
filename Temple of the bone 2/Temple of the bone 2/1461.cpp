//
//  1461.cpp
//  Temple of the bone 2
//
//  Created by chenmeiqi on 2019/4/16.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
struct N{
    int x;
    int y;
    int t;
};
stack<N> S;
int go[][2]={
    1,0,
    -1,0,
    0,1,
    0,-1,
};
char maze[7][7];
int n,m,t;
bool flag;
void DFS(){
    int nx,ny;
    while (!S.empty()) {
        N now=S.top();
        S.pop();
        for (int i=0; i<4; i++) {
            nx=now.x+go[i][0];
            ny=now.y+go[i][1];
            if (nx<0||nx>=n||ny<0||ny>=m) {
                continue;
            }
            if (maze[nx][ny]=='X') {
                continue;
            }
            if (maze[nx][ny]=='D' && now.t+1==t) {
                flag=true;
                return;
            }
            maze[nx][ny]='X';
            N tmp;
            tmp.x=nx;
            tmp.y=ny;
            tmp.t=now.t+1;
            S.push(tmp);
        }
    }
};
int main(int argc, const char * argv[]) {
    string s;
    int sx,sy;
    int dx,dy;
    while (cin>>n>>m>>t) {
        flag=false;
        if (n==0 && m==0 && t==0) {
            break;
        }
        for (int i=0; i<n; i++) {
            cin>>s;
            for (int j=0; j<m; j++) {
                maze[i][j]=s[j];
                if (s[j]=='S') {
                    sx=i;
                    sy=j;
                }
                if(s[j]=='D'){
                    dx=i;
                    dy=j;
                }
            }
        }
        while (!S.empty()) {
            S.pop();
        }
        maze[sx][sy]='X';
        N begin;
        begin.x=sx;
        begin.y=sy;
        begin.t=0;
        S.push(begin);
        if(((sx+sy)%2 + t%2)%2 ==(dx+dy)%2){
            DFS();
        }
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
