//
//  98.cpp
//  Coincidence
//
//  Created by chenmeiqi on 2019/4/28.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    string n,m;
    int res[101][101];
    size_t n_len,m_len;
    while (cin>>n>>m) {
        n=' '+n;            // 方便设置初始值和下标
        m=' '+m;
        n_len=n.length();
        m_len=m.length();
        for (int i=0; i<n_len; i++) {       // 二重循环依次求得每个dp[i][j]的值
            for (int j=0; j<m_len; j++) {
                if (i==0||j==0) {               // 初始值
                    res[i][j]=0;
                }
                else if(n[i]==m[j]){        // 若当前两字符相等
                    res[i][j]=res[i-1][j-1]+1;
                }
                else{       // 若不相等
                    res[i][j]=max(res[i-1][j], res[i][j-1]);
                }
            }
        }
        cout<<res[n_len-1][m_len-1]<<endl;
    }
    return 0;
}
