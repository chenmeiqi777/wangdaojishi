//
//  61.cpp
//  N的阶层
//
//  Created by chenmeiqi on 2019/3/31.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
unsigned long max_len;
struct bigInteger{              // 大数结构
    int digit[1000];
    int size;
    string  out(){
        unsigned long temp;
        string res="";
        string s;
        for (int i=size-1; i>=0; i--) {
            s=to_string(digit[i]);            // int 转 string
            temp=res.length();                  // 结果字符串长度
            if(i!=size-1){                  // 最高位不补 0
                for (unsigned long len=s.length(); len<4; len++) {              // 其余位不够 4 位补 0
                    if(temp+1==max_len){            // 结果字符串长度将等于最大位数，不再补 0（针对最低位）
                        break;
                    }
                    else{                           // 补 0
                        s="0"+s;
                        temp++;
                    }
                }
            }
            res+=s;                 // 结果字符串拼接
        }
        return res;
    };
    bigInteger operator * (int x) const{
        bigInteger res={0};
        bool ifCarry=false; // 是否进位
        int carry=0;        // 进位
        int index=0;        // 在第几位进位
        res.size =size;
        for (int i=0; i<res.size; i++) {        // 逐个相乘
            res.digit[i]=x*digit[i]+carry;
            if(res.digit[i]>9999){
                index=i;
                ifCarry=true;
            }
            carry=res.digit[i]/10000;
            res.digit[i]=res.digit[i]%10000;
        }
        if(ifCarry && index==res.size-1){      // 有进位且进位后大于原来位数
            res.digit[res.size]=carry;
            res.size++;
        }
        return res;
    };
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
    int n;
    string str_n;
    bigInteger A;
    while (cin>>n) {
        str_n=to_string(n);
        A=stringToBigInt(str_n);            // 构造高精度整数
        for (int i=n-1; i>0; i--) {         // 阶乘
            A=A*i;
            max_len=A.out().length();       // 得到 A 的长度
        }
        cout<<A.out()<<endl;
    }
    return 0;
}
