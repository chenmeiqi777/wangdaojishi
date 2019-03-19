//
//  39.cpp
//  特殊乘法
//
//  Created by chenmeiqi on 2019/3/19.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

// 思路1:利用字符串，较简单
// 思路2:如下。

#include <iostream>
#include<array>
using namespace std;

// 求数的位数
int getDight(int x){
    int count=0;
    while (x!=0) {
        x/=10;
        count++;
    }
    return count;
}

// 数位分解
/*
 用std::array 而不用 array 是因为数组作为参数传递或作为返回结果返回时是是传递其首地址（指针）的，、
丢失了长度信息，只在函数内部执行时有值，函数执行完毕后只保留了它的第一个值。
 */
array<int, 10> decomposition(int x){
    array<int, 10> a={0};       // 初始化，防止输入数为0
    int count=getDight(x);
    while (count--) {
        a[count]=(x%10+10)%10;
        x=x/10;
    }
    return a;
}

int main(int argc, const char * argv[]) {
    int number_1,number_2;          // 两个数
    array<int, 10> M;       // 第一个数 数位拆解得到的数组
    array<int, 10> N;       // 第二个数 数位拆解得到的数组
    int result=0;             // 特殊乘法结果
    cin>>number_1>>number_2;
    M=decomposition(number_1);
    N=decomposition(number_2);
    for(int i=0;i<getDight(number_1);i++){
        for (int j=0; j<getDight(number_2); j++) {
            result+=M[i]*N[j];          // 两两相乘后相加
        }
    }
    cout << result<<endl;
    return 0;
}
