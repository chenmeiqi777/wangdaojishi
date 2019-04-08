//
//  1144.cpp
//  Freckles
//
//  Created by chenmeiqi on 2019/4/8.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
#define N 101
#define M 5050          // n(n-1)/2

int Tree[N];

struct Vertex{          // 顶点集（坐标）
    float x;
    float y;
}v[N];

struct Edge             // 边集
{
    int vertex_1;
    int vertex_2;
    float weight;
    bool operator < (const Edge& a) const{
        return weight<a.weight;
    }
}e[M];

float getPosition(Vertex a, Vertex b){              // 求两点间距离
    float res;
    res=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    return res;
}

int findRoot(int x){                // 并查集
    while(Tree[x]!=0){
        x=Tree[x];
    }
    return x;
}

int main(int argc, const char * argv[]) {
    int n,temp_n;
    int a,b;
    float res;
    while(cin>>n){
        res=0;
        for(int i=0;i<N;i++){
            Tree[i]=0;
        }
        temp_n=n;
        int t=0;
        while(n--){
            cin>>v[t].x>>v[t].y;
            t++;
        }
        int k=0;
        for(int i=0;i<temp_n;i++){
            for(int j=i+1;j<temp_n;j++){
                e[k].vertex_1=i;
                e[k].vertex_2=j;
                e[k].weight=getPosition(v[i],v[j]);
                 k++;
            }
        }
        sort(e,e+k);                // 注意这里数量是 k 不是 n
        for(int i=0;i<k;i++){
            a=findRoot(e[i].vertex_1);
            b=findRoot(e[i].vertex_2);
            if(a!=b){
                Tree[a]=b;
                res+=e[i].weight;
            }
        }
        cout<<setiosflags(ios::fixed)<<setprecision(2)<<res<<endl;      // 保留两位小数
    }
    
    return 0;
}
