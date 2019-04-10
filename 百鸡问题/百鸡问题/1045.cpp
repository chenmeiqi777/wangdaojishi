//
//  1045.cpp
//  百鸡问题
//
//  Created by chenmeiqi on 2019/4/10.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//


// 注意此题有前提条件就是鸡的总数量一定为100！
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    float n;
    while(cin>>n){
        for(int i=0;i<=100;i++){            // 枚举x的值
            for(int j=0;j<=100;j++){            // 枚举y的值，注意x+y<100
                if(i+j<=100 && 5*i+3*j+(1.0/3.0)*(100-i-j)<n){          // 注意是1.0/3.0,不是1/3！1/3=0   或者，等式两边同时乘以3，以避免精度损失
                    cout<<"x="<<i<<","<<"y="<<j<<","<<"z="<<100-i-j<<endl;
                }
            }
        }
    }
    return 0;
}
