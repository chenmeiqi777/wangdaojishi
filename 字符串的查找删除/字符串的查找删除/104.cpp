//
//  104.cpp
//  字符串的查找删除
//
//  Created by chenmeiqi on 2019/5/4.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    string s;
    string in;
    string tmp;
    cin>>s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);        // 转小写
    getchar();          // 处理一溜在输入缓冲的换行符
    while (getline(cin,in)) {       // 读取包含空格的一整行
        tmp=in;         // 保存一个输入
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);      // 将其转小写
        size_t pos=tmp.find(s);         // 取特定字符串
        while (pos>=0&&pos<=tmp.size()) {
            tmp=tmp.erase(pos,s.size());
            in=in.erase(pos,s.size());
            pos=tmp.find(s);
        }
        size_t npos=in.find(" ");           // 去空格
        while (npos>=0&&npos<=in.size()) {
            in=in.erase(npos,1);
            npos=in.find(s);
        }
        
        cout<<in<<endl;     // 最后输出的大小写要跟输入一致

    }
    return 0;
}
