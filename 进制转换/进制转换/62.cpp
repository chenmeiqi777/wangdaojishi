//
//  62.cpp
//  进制转换
//
//  Created by chenmeiqi on 2019/4/1.
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
    
    
    bigInteger operator + (const bigInteger & B) const{
        bigInteger res={0};
        bool ifCarry=false; // 是否进位
        int carry=0;        // 进位值
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
    
    
    bigInteger operator / (int x)const{
        bigInteger res={0};
        int reminder=0;        // 余数
        res.size =size;
        for (int i=res.size-1; i>=0; i--) {        // 逐个相除
            res.digit[i]=(digit[i]+reminder*10000)/x;
            reminder=(digit[i]+reminder*10000)%x;
        }
        if(res.size==1 && digit[0]<x){              // 被除数小于 x
            res.digit[0]=0;
        }
        if(res.size>1 && digit[res.size-1]<x){      // 最高位有余数，位数 -1
            res.digit[res.size-1]=0;
            res.size--;
        }
        return res;
    }
    
    int operator % (int x)const{
        bigInteger res={0};
        int reminder=0;        // 余数
        res.size =size;
        for (int i=res.size-1; i>=0; i--) {        // 逐个相除
            res.digit[i]=(digit[i]+reminder*10000)/x;
            reminder=(digit[i]+reminder*10000)%x;
        }
        return reminder;
    }

    
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
    int hex_in=0;           // 转前进制
    int hex_out=0;          // 转后进制
    string n;               // 转前进制数
    int temp;               // 暂存每位数
    bigInteger A={0};       // hex_in 的几次方
    bigInteger R={0};       // 转换成的 10 进制数
    string res="";
    while (cin>>hex_in>>hex_out>>n) {
        A=stringToBigInt("1");              // A 初始化为 1
        for(int i=n.length()-1;i>=0;i--){               // 这里注意用 int 而不是 unsigned long ， 否则 i-- 永远 >=0
            if(n[i] >='A' && n[i]<='Z'){            // 利用 ascii 码转换
                temp=(int)n[i]-55;
            }
            else{
                temp=n[i]-'0';
            }
            R=A*temp+R;
            A=A*hex_in;
        }
        
        while (R.out()!="0") {
            res=to_string(R%hex_out)+res;
            R=R/hex_out;
        }
        cout<<res<<endl;
    }
    return 0;
}
