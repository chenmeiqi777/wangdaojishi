//
// 1459.cpp
//  Prime ring problem
//
//  Created by chenmeiqi on 2019/4/12.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
using namespace std;
int n;
int ans[17];            // 保存环中每一个被放入的数
bool mark[17];          // 标记之前已经被放入环中的数
bool isPrime(int x){            // 判断一个数是否是素数
    for(int i=2;i<x;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

void check(){
    if(isPrime(ans[n]+ans[1])==false){          // 判断最后一个数与第一个数的和是否为素数，若不是则直接返回
        return;
    }
    for(int i=1;i<=n;i++){      // 输出解，注意最后一个数字没有空格
        if(i==1){
            cout<<ans[i];
        }
        else{
            cout<<" "<<ans[i];
        }
    }
    cout<<endl;
}

void DFS(int x){        // 递归枚举，num为当前已经放入环中的数字
    if(x>1){        // 当放入的数字大于 1 个时
        if(isPrime(ans[x]+ans[x-1])==false){        // 判断最后两个数字的和是否为素数，若不是则返回继续枚举第num个数
            return;
        }
    }
    if(x==n){       // 若已经放入了n个数
        check();        // 检查输出
        return;         // 返回，继续枚举下一组解
    }
    for(int i=2;i<=n;i++){      // 放入一个数
        if(mark[i]==false){        // 若i还没有被放入环中
            mark[i]=true;       // 标记i为已经使用
            ans[x+1]=i;     // 将这个数字放入ans数组中
            DFS(x+1);       // 继续尝试放入下一个数
            mark[i]=false;      // 当回溯枚举这位数字时，将i重新标记为未使用
        }
    }
}

int main(int argc, const char * argv[]) {
    int count=0;            // 标记Case数
    while (cin>>n){
        count++;        // Case数递增
        cout<<"Case "<<count<<":"<<endl;
        for(int i=0;i<17;i++){      // 初始化标记所有数字为未被使用
            mark[i]=false;
        }
        ans[1]=1;           // 第一个数字恒定为1
        mark[1]=true;       // 标记1被使用
        DFS(1);             // 继续尝试放入下一个数字
        cout<<endl;
    }
    return 0;
}
