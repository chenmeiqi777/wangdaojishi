//
//  1458.cpp
//  汉诺塔III
//
//  Created by chenmeiqi on 2019/4/12.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
using namespace std;

long long F(int x){         // 递归函数。返回值较大用 long long 类型
    if(x==1){       // 参数为1时直接返回2
        return 2;
    }
    else{
        return 3*F(x-1)+2;      // 否则递归调用
    }
}

int main(int argc, const char * argv[]) {
    int n;
    while (cin>>n){
        cout << F(n) <<endl;
    }
    return 0;
}
