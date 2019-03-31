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
unsigned long max_len;
struct bigInteger{              // 大数结构
    int digit[1000];
    int size;
    
    void out(unsigned long max_len){
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
        cout<<res<<endl;
    };
    bigInteger operator + (const bigInteger & B) const{
        bigInteger res={0};
        bool ifCarry=false; // 是否进位
        int carry=0;        // 进位
        int index=0;        // 在第几位进位
        res.size =max(size, B.size);
        for (int i=0; i<res.size; i++) {        // 逐个相加
            res.digit[i]=B.digit[i]+digit[i]+carry;
            if(res.digit[i]>9999){
                index=i;
                ifCarry=true;
            }
            carry=res.digit[i]/10000;
            res.digit[i]=res.digit[i]%10000;
        }
        if(ifCarry && index==res.size-1){      // 有进位且进位后大于原来位数
            res.digit[res.size]=1;
            res.size++;
        }
        if(ifCarry && index==res.size-2){         // 有进位但位数不变
            max_len++;
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
    string a,b;
    bigInteger A;
    bigInteger B;
    while (cin>>a>>b) {
        max_len=max(a.length(),b.length());
        A=stringToBigInt(a);
        B=stringToBigInt(b);
        A=A+B;
        A.out(max_len);
    }
    return 0;
}
