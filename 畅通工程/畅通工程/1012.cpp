//
//  1012.cpp
//  畅通工程
//
//  Created by chenmeiqi on 2019/4/2.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
using namespace std;
int Tree[1000];
int findRoot(int x){
    int temp=x;
    int ret;
    while (Tree[x]!=0){
        x=Tree[x];        // 若当前结点为非根结点则一直查找其双亲结点
    }
    ret=x;    //  根结点编号
    x=temp;        // 再做一次从结点x到根结点的遍历
    while(Tree[x]!=0){
        int t=Tree[x];
        Tree[x]=ret;
        x=t;                // 遍历过程中将这些结点的双亲结点都设为已经查找得到的根结点编号
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    int n,m;
    int temp_m;
    int city_1,city_2;
    while (cin>>n) {
        if(n==0){
            break;
        }
        cin>>m;
        for(int i=0;i<1000;i++){        // 初始化
            Tree[i]=0;
        }
        int res=0;
        temp_m=m;
        while (temp_m--) {
            cin>>city_1>>city_2;
            city_1=findRoot(city_1);        // 找到第一个城市的根结点
            city_2=findRoot(city_2);        // 找到第二个城市的根结点
            if (city_1!=city_2) {           // 不相等就合并根结点
                Tree[city_1]=city_2;
            }
        }
        for (int j=1; j<=n; j++) {
            if (Tree[j]==0) {
                res++;
            }
        }
        res-=1;                 // 减1就是连通分量的值
        cout<<res<<endl;
    }
    return 0;
}
