//
//  44.cpp
//  数制转换
//
//  Created by chenmeiqi on 2019/3/20.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, const char * argv[]) {
    int hex_in=0;
    string number;
    int convertStringToInt[40]={0};
    int hex_out=0;
    int isNotZeroNumber=0;
    int hex_10=0;
    int a[40]={0};          //
    int index=0;

    while (cin>>hex_in) {
        cin>>number>>hex_out;
        transform(number.begin(), number.end(), number.begin(),::toupper);      // 既有C版本的toupper/tolower函数，又有STL模板函数toupper/tolower，
                                                                                // 二者存在冲突。在toupper/tolower前面加::，强制指定是C版本的
        for(int i=0;i<number.length();i++){
            if(number[i]=='A'){
                convertStringToInt[i]=10;
            }
            else if(number[i]=='B'){
                convertStringToInt[i]=11;
            }
            else if(number[i]=='C'){
                convertStringToInt[i]=12;
            }
            else if(number[i]=='D'){
                convertStringToInt[i]=13;
            }
            else if(number[i]=='E'){
                convertStringToInt[i]=14;
            }
            else if(number[i]=='F'){
                convertStringToInt[i]=15;
            }
            else{
                convertStringToInt[i]=number[i]-'0';
            }
        }
        
        for (int i=39; i>=0; i--) {             // 倒序找第一个不为 0 的 数
            if (convertStringToInt[i]!=0) {
                isNotZeroNumber=i;
                break;
            }
        }
        for (int i=isNotZeroNumber; i>=0; i--) {            // 第一个进制数转 10 进制数
            hex_10+=convertStringToInt[i]*pow(hex_in,isNotZeroNumber-i);
        }
        
        while (hex_10>0) {                              // 10 进制数转 对应第二个进制数
            a[index]=(hex_10%hex_out+hex_out)%hex_out;
            hex_10/=hex_out;
            index++;
        }
        
        for(int i=index-1;i>=0;i--){            // 倒序输出（从第一个非0的数开始）
            cout<<a[i];
        }
        
        if(index==0){           // 当输入为 0 d时的处理
            cout<<"0";
        }
        
        cout<<endl;
        
    }
    return 0;
}
