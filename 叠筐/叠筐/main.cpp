//
//  main.cpp
//  叠筐
//
//  Created by chenmeiqi on 2019/2/25.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <cmath>

//另一类排版题，它所要求的图形不具有显著的规律性或者规律性较 难直接应用到输出当中。为了解决此类问题，我们需要了解排版题常用的另一种方法:先完成排版，再进行输出。

int main(int argc, const char * argv[]) {
    using namespace std;
    int n=0;
    char inner,outer=' ';
    char print[80][80]={""};
    
    cin>>n>>inner>>outer;

    for(int t=0;t<(n+1)/2;t++){         // 绘制对称的行，呈一个沙漏型
        for(int s=t;s<n-t;s++){     // 每次少两边的两个 （t~n-t=n-2t,t每次+1，说明每次少两个）
            if(t==0||t%2==0) print[t][s]= print[n-1-t][s]=outer;    // 偶数行是外框花色字符
            else print[t][s]=print[n-1-t][s]=inner;     // 奇数行是内框花色字符
        }
    }
    
    for(int t=0;t<(n+1)/2;t++){     // 绘制对称的列，补全整个排版
        for(int s=t;s<n-t;s++){
            if(t==0||t%2==0)print[s][t]=print[s][n-1-t]=outer;

            else print[s][t]=print[s][n-1-t]=inner;
        }
    }
    //  别忘了挖空四角
    print[0][0]=print[0][n-1]=print[n-1][0]=print[n-1][n-1]=' ';
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<print[i][j];
        }
        cout<<endl;
    }

    return 0;
}
