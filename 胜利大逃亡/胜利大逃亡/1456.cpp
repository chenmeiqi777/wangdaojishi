//
//  1456.cpp
//  胜利大逃亡
//
//  Created by chenmeiqi on 2019/4/11.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
struct N{               // 状态结构体
    int x,y,z;
    int t;
};
bool mark[50][50][50];      // 标记数组
int maze[50][50][50];       // 保存立方体信息
queue<N> Q;             // 队列，队列中的元素为状态
int go[][3]={           // 坐标变换数组，由坐标(x,y,z)扩展得到的新坐标均可通过（x+go[i][0],y+go[i][1],z+go[i][2]）得到
    1,0,0,
    -1,0,0,
    0,1,0,
    0,-1,0,
    0,0,1,
    0,0,-1
};
int BFS(int a, int b, int c){       // 广度优先搜索，返回其最少耗时
    int res;
    while(!Q.empty()){      // 当队列中仍有元素可以扩展时循环
        N now=Q.front();        // 得到队头状态
        Q.pop();                // 从队列中弹出队头状态
        for(int i=0;i<6;i++){           // 依次扩展其六个相邻节点
            int nx=now.x+go[i][0];
            int ny=now.y+go[i][1];
            int nz=now.z+go[i][2];
            if(nx<0||nx>=a||ny<0||ny>=b||nz<0||nz>=c){      // 新坐标在立方体外，丢弃
                continue;
            }
            if(mark[nx][ny][nz]==true){         // 该位置为墙
                continue;
            }
            if(maze[nx][ny][nz]==1){        // 包含该坐标的状态已经被得到过
                continue;
            }
            N n;        // 新的状态
            n.x=nx;
            n.y=ny;
            n.z=nz;
            n.t=now.t+1;        // 新状态耗时
            mark[nx][ny][nz]=true;      // 标记该坐标
            Q.push(n);          // 将该状态放入队列
            if(nx==a-1&&ny==b-1&&nz==c-1){          // 该坐标即为终点
                return n.t;
            }
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    int k;
    int a,b,c,T;
    cin>>k;
    while(k--){
        cin>>a>>b>>c>>T;
        for(int  i = 0; i < a; i++)
        {
            for(int  j = 0; j < b; j++)
            {
                for(int k = 0; k < c; k++){
                    cin>>maze[i][j][k];         // 输入立方体信息
                    mark[i][j][k]=false;            // 初始化标记数组
                }
            }
            
        }
        while(!Q.empty()){      // 清空队列
            Q.pop();
        }
        mark[0][0][0]=true;     // 标记起点
        N tmp;
        tmp.x=tmp.y=tmp.z=0;
        tmp.t=0;                // 初始状态
        Q.push(tmp);
        int res=BFS(a,b,c);         // 广度优先搜索
        if(res<=T){             // 所需时间符合条件
            cout<<res<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    
    return 0;
}
