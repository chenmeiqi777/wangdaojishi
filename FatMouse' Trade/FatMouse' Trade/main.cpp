//
//  main.cpp
//  FatMouse' Trade
//
//  Created by chenmeiqi on 2019/3/4.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
struct fPerJ{
    float j;
    float f;
    float fPerj;
    bool operator <(const fPerJ& a)const{               // 重载运算符
        return fPerj<a.fPerj;
    }
}buf[1000];


int main(int argc, const char * argv[]) {
    int n=0;
    float m=0;
    float number=0;
    int i=0;
    int index=0;
    
    cin>>n>>m;
    int n_count=n;
    while (n_count--) {
        cin>>buf[i].j>>buf[i].f;
        i++;
    }
    
    for(int k=0;k<n;k++){           // 计算j性价比
        buf[k].fPerj=buf[k].f/buf[k].j;
    }
    sort(buf, buf+n);       // 按性价比从高到低排序（每个物品花的钱越少，性价比越高）
    
    while(m>0){         // 钱数>0
        if((m-buf[index].fPerj)<=0) break;      // 每次买一个（不一定全部买完）
        while (buf[index].j>0) {            // 性价比最高的还有剩余
                number++;
                m-=buf[index].fPerj;
                buf[index].j--;
        }
        index++;
    }
    cout << setprecision(3)<<number<<endl;          // 保留三位小数
    return 0;
}
