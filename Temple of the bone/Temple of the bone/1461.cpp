//
//  1461.cpp
//  Temple of the bone
//
//  Created by chenmeiqi on 2019/4/16.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
using namespace std;
char maze[7][7];        // 保存地图信息
int n,m,t;          // 地图大小为n*m，从起点到终点能否恰好t秒
int go[][2]={               // 四个方向行走坐标差
    1,0,
    -1,0,
    0,1,
    0,-1
};
bool flag;          // 是否成功
void DFS(int x,int y,int res_t){        // 递归形式的深度优先搜索
    int nx,ny;
    for(int i=0;i<4;i++){       // 枚举四个相邻位置
        nx=x+go[i][0];
        ny=y+go[i][1];          // 计算其坐标
        if(nx<0||nx>=n||ny<0||ny>=m){           // 坐标在地图外
            continue;
        }
        if (maze[nx][ny]=='X') {            // 该位置为墙
            continue;
        }
        if(maze[nx][ny]=='D'){          // 该位置为门
            if(res_t+1==t){         // 所用时间恰好为t
                flag=true;          // 搜索成功
                return;     // 返回
            }
            else{           // 否则该状态的后续状态不可能为答案（经过的点不能再经过）
                continue;
            }
        }
        maze[nx][ny]='X';       // 该状态扩展而来的后续状态中，该位置都不能被经过，直接修改该位置为墙
        DFS(nx,ny,res_t+1);     // 递归z扩展该状态，所用时间递增
        maze[nx][ny]='.';       // 若其后续状态全部遍历完毕，则退回上层状态，将因为要搜索其后续状态而改成墙的位置，改回普通位置
        if (flag) {     // 假如已经成功，则直接返回，停止搜索
            return;
        }
    }
}
int main(int argc, const char * argv[]) {
    int sx,sy;
    int dx,dy;
    string s;
    while(cin>>n>>m>>t){
        if(n==0&&m==0&&t==0){
            break;
        }
        for(int i = 0; i < n; i++)
        {
            cin>>s;
            for(int j = 0; j < m; j++)
            {
                maze[i][j]=s[j];
                if(maze[i][j]=='S'){            // 找到起点位置
                    sx=i;
                    sy=j;
                }
                if(maze[i][j]=='D'){            // 找到终点位置
                    dx=i;
                    dy=j;
                }
            }
        }
        flag=false;
        if (((sx+sy)%2+t%2)%2 == (dx+dy)%2 ) {      // 判断S与D的奇偶关系是否与t符合，若不符合直接跳过搜索
            maze[sx][sy]='X';       // 将起点标记为墙
            DFS(sx,sy,0);           // 递归扩展初始状态
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
