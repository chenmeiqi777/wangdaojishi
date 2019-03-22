//
//  47.cpp
//  最大公约数
//
//  Created by chenmeiqi on 2019/3/21.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
using namespace std;
/*
 思路：若 a、b 全为0则它们的最大公约数不存在，若 a、b 其中之一为0，则它们的最大公约数为 a、b 中非0的那个； a、b 都不为0，则使新 a = b，新 b = a % b ，然后重复该过程。
 这就是欧几里得算法。
 */
int main(int argc, const char * argv[]) {
    int dividend_1=0;
    int dividend_2=0;
    int temp=0;         // 临时变量保存dividend1
    while (cin>>dividend_1>>dividend_2) {
        while (dividend_2>0) {        // dividend_2不为0时一直更新
            temp=dividend_1;
            dividend_1=dividend_2;
            dividend_2=temp%dividend_2;
        }
        cout<<dividend_1<<endl;    // dividend_2为0时dividend_1即是所求
    }
    return 0;
}
