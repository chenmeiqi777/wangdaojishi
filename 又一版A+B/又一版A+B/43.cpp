//
//  43.cpp
//  又一版A+B
//
//  Created by chenmeiqi on 2019/3/19.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <array>
#include <cmath>
using namespace std;
/*
 在本例中，虽然题面明确了输入数据将在 int 范围内 (<=2^31-1)，但是两个int数字的和可能超过 int 所能表示的最大值，出现溢出。
 为了避免这种情况，我们采用 long long 来表示两个 int 数的和(代码中两个数 字也用 long long 保存)。
 */

// 进制转换，每一位保存在数组里
array<int, 11> hexadecimal_conversion(long long x,int hex){
    int i=0;
    array<int, 11> a={0};           // 初始化，当传进来的数为 0 时确保返回的是一个 0 数组
    while (x>0) {
        a[i]=(x%hex+hex)%hex;
        x/=hex;
        i++;
    }
    return a;
}

int main(int argc, const char * argv[]) {
    int n;  // 进制
    long long a,b;
    array<int, 11>M={0};
    int index=0;
    while(true){
        cin>>n;
        if(n==0)break;
        cin>>a>>b;
        a=a+b;          // 采用 long long 来表示两个 int 数的和
        M=hexadecimal_conversion(a,n);
        for(int i=10;i>=0;i--){             // 11 位长度，下标最后一个是 10 不是 11！！
            if(M[i]!=0){
                index=i;                        // 找到第一个不为 0 的数
                break;
            }
        }
        for (int i=index; i>=0; i--) {          // 输出进制数
            cout<<M[i];
        }
        cout<<endl;
    }
    return 0;
}
