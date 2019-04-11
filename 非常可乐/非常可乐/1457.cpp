//
//  1457.cpp
//  非常可乐
//
//  Created by chenmeiqi on 2019/4/11.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <queue>
#define S 101
using namespace std;
struct N            // 状态结构体
{
    int s,n,m;          // 每个杯子中可乐的体积
    int t;          // d得到该体积组倾倒次数
};
int mark[S][S][S];      // 对体积组(x,y,z)进行标记，即只有第一次得到包含体积组(x,y,z)的状态为有效状态，其余的舍去
queue<N> Q;     // 队列
void AtoB(int &a,int sa,int &b,int sb){     // 倾倒函数，由容积为sa的杯子倒往容积为sb的杯子，其中引用参数a和b，初始时为原始杯子中可乐的体积，当函数调用完毕后，为各自杯中可乐的新体积
    if(sb-b>=a){            // 若a可以全部倒到b中
        b+=a;
        a=0;
    }
    else{       // 否则
        a-=sb-b;
        b=sb;
    }
}
int BFS(int s, int n, int m ){
    while(!Q.empty()){          // 当队列非空时，重复循环
        N now =Q.front();       // 拿出队头状态
        Q.pop();        // 弹出队头状态
        
        int a,b,c;      // a,b,c临时保存三个杯子中可乐体积
        
        a=now.s;
        b=now.n;
        c=now.m;
        AtoB(a,s,b,n);          // 由a倒向b
        if(mark[a][b][c]==false){       // 若该体积组尚未出现
            mark[a][b][c]=true;     // 标记该体积组
            N tmp;
            tmp.s=a;
            tmp.n=b;
            tmp.m=c;
            tmp.t=now.t+1;          // 生成新的状态
            if(a==s/2 && b==s/2){           // 若该状态已经为平分状态，则直接返回该状态的耗时
                return tmp.t;
            }
            if(a==s/2 && c==s/2){
                return tmp.t;
            }
            if(b==s/2 && c==s/2){
                return tmp.t;
            }
            Q.push(tmp);            // d否则放入队列
        }
        
        a=now.s;                // 重置 a,b,c 为未倾倒前的体积
        b=now.n;
        c=now.m;
        AtoB(b,n,a,s);          // 由b倒向a
        if(mark[a][b][c]==false){
            mark[a][b][c]=true;
            N tmp;
            tmp.s=a;
            tmp.n=b;
            tmp.m=c;
            tmp.t=now.t+1;
            if(a==s/2 && b==s/2){
                return tmp.t;
            }
            if(a==s/2 && c==s/2){
                return tmp.t;
            }
            if(b==s/2 && c==s/2){
                return tmp.t;
            }
            Q.push(tmp);
        }
        
        a=now.s;
        b=now.n;
        c=now.m;
        AtoB(a,s,c,m);       // 由a倒向c
        if(mark[a][b][c]==false){
            mark[a][b][c]=true;
            N tmp;
            tmp.s=a;
            tmp.n=b;
            tmp.m=c;
            tmp.t=now.t+1;
            if(a==s/2 && b==s/2){
                return tmp.t;
            }
            if(a==s/2 && c==s/2){
                return tmp.t;
            }
            if(b==s/2 && c==s/2){
                return tmp.t;
            }
            Q.push(tmp);
        }
        
        a=now.s;
        b=now.n;
        c=now.m;
        AtoB(c,m,a,s);           // 由c倒向a
        if(mark[a][b][c]==false){
            mark[a][b][c]=true;
            N tmp;
            tmp.s=a;
            tmp.n=b;
            tmp.m=c;
            tmp.t=now.t+1;
            if(a==s/2 && b==s/2){
                return tmp.t;
            }
            if(a==s/2 && c==s/2){
                return tmp.t;
            }
            if(b==s/2 && c==s/2){
                return tmp.t;
            }
            Q.push(tmp);
        }
        
        a=now.s;
        b=now.n;
        c=now.m;
        AtoB(b,n,c,m);              // 由b倒向c
        if(mark[a][b][c]==false){
            mark[a][b][c]=true;
            N tmp;
            tmp.s=a;
            tmp.n=b;
            tmp.m=c;
            tmp.t=now.t+1;
            if(a==s/2 && b==s/2){
                return tmp.t;
            }
            if(a==s/2 && c==s/2){
                return tmp.t;
            }
            if(b==s/2 && c==s/2){
                return tmp.t;
            }
            Q.push(tmp);
        }
        
        a=now.s;
        b=now.n;
        c=now.m;
        AtoB(c,m,b,n);           // 由c倒向b
        if(mark[a][b][c]==false){
            mark[a][b][c]=true;
            N tmp;
            tmp.s=a;
            tmp.n=b;
            tmp.m=c;
            tmp.t=now.t+1;
            if(a==s/2 && b==s/2){
                return tmp.t;
            }
            if(a==s/2 && c==s/2){
                return tmp.t;
            }
            if(b==s/2 && c==s/2){
                return tmp.t;
            }
            Q.push(tmp);
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    int s,n,m;
    while(cin>>s>>n>>m){
        if(s==0&&n==0&&m==0){
            break;
        }
        if (s%2==1) {               // 若s为奇数则不可能平分，直接输出NO
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0;i<s;i++){               // 初始化状态
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < m; k++)
                {
                    mark[i][j][k]=false;
                }
            }
        }
        
        while(!Q.empty()){          // 清空队列中状态
            Q.pop();
        }
        
        N begin;            // 初始时状态
        begin.s=s;
        begin.n=begin.m=begin.t=0;
        mark[s][0][0]=true;
        Q.push(begin);    // 将初始状态放入队列
        
        int res=BFS(s,n,m);         // 广度优先搜索
        if(res==-1){            // 若为-1输出NO
            cout<<"NO"<<endl;;
        }
        else{                   // 否则输出答案
            cout<<res<<endl;
        }
    }
    return 0;
}
