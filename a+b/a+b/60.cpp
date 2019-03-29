//
//  60.cpp
//  a+b
//
//  Created by chenmeiqi on 2019/3/29.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
struct bigInteger{              // 大数结构
    int digit[1000];
    int size;
};

bigInteger stringToBigInt(string s){
    bigInteger N={0};
    N.size=0;
    int s_len=s.length();
    int len=0;
    if(s_len%4!=0){             // 一个存 4 位，不足的+1
        len=s_len/4+1;
    }
    else{
        len=s_len/4;
    }
    for(int i=0;i<len;i++){
        int pos = max(0,s_len-1-4*i-3);
        for (int j=s_len-1-4*i; j>=pos; j-=1) {         // 从字符串后往前存
            N.digit[i]+=(s[j]-'0')*pow(10,s_len-4*i-j-1);           // char to int, 每次存4位，所以 -4*i
        }
        N.size=i+1;
    }
    return N;
}

int main(int argc, const char * argv[]) {
    string a,b;
    unsigned long max_len;
    unsigned long temp;
    bigInteger A;
    bigInteger B;
    while (cin>>a>>b) {
        max_len=max(a.length(),b.length());
        A=stringToBigInt(a);
        B=stringToBigInt(b);
        int size =max(A.size, B.size);
        for (int i=0; i<size; i++) {        // 逐个相加
            A.digit[i]+=B.digit[i];
        }
        A.size=size;                // 更新 A.size
        string res="";
        string s;
        for (int i=size-1; i>=0; i--) {
            s=to_string(A.digit[i]);            // int 转 string
            temp=res.length();                  // 结果字符串长度
            unsigned long len=s.length();       // 当前组数字的长度
            for (; len<4; len++) {              // 不够 4 位补 0
                if(temp+1==max_len){            // 结果字符串长度将等于最大位数，不再补 0
                    break;
                }
                else{                           // 补 0
                    s+="0";
                    temp++;
                }
            }
            res+=s;                 // 结果字符串拼接
        }
        cout<<res<<endl;
    }
    return 0;
}
