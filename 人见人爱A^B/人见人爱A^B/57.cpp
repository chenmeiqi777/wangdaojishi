//
//  57.cpp
//  人见人爱A^B
//
//  Created by chenmeiqi on 2019/3/29.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include<iostream>
#include<array>
#include <cmath>
using namespace std;

array<int,15> biResult(int x){
    array<int,15> a={0};
    int index=0;
    while (x>0) {                              // 10 进制数转 对应第二个进制数
        a[index]=x%2;
        x/=2;
        index++;
    }
    
    return a;
}

int main(void){
    int a,b;
    array<int,15> bi_number;        // 对 b 转换二进制数 （b<10000<2^14,15位足矣）
    while(cin>>a>>b){
        a=a%1000;           // 可以先取后三位数
        int res=1;
        if(a==0 && b==0){           // a=0 且 b=0 时结束
            break;
        }
        bi_number=biResult(b);
        for(int i=0;i<15;i++){
            if(bi_number[i]==1){        // b 分解到的二进制数
                res*=a;                 // 最终结果累乘 a
                res=res%1000;           // 求其后三位数
            }
            a*=a;                       // a 每次自称
            a%=1000;                    // 求其后三位数
        }
        cout<<res<<endl;
    }
    return 0;
}
