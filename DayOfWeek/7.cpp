//
//  DayOfWeek.cpp
//  wangdaojishi
//
//  Created by chenmeiqi on 2019/2/25.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;
// 蔡勒公式（Zeller's congruence），是一种计算任何一日属一星期中哪一日的算法，
// 由德国数学家克里斯提安·蔡勒推算出来。

char monthName[13][20]={" ","January","February","March","April","May","June","July",
    "August","September","October","November","December"};  // 用了一个技巧使月份与下标对应
char weekName[8][20]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
// 字符串转int
int string_to_int(string str,int start,int end){
    int count=0;
    int j=end-start;
    for(int i=start;i<=end;i++){    // 0 1 2 3
        // 3 2 1 0
        count += pow(10,j)*(str[i] -'0');   // 字符转数字
        j--;
    }
    return count;
}

int main(void){
    int day=0;
    string year,month;
    int i=0;
    int monthIndex=0;
    int w;
    cin>>day>>month>>year;
    
    int y=string_to_int(year, 2, 3);
    int c=string_to_int(year, 0, 1);
    
    for(;i<=12;i++){
        if(month==monthName[i])
            break;
    }
    if(i==1||i==2){ //（m的取值范围为3至14，即在蔡勒公式中，某年的1、2月要看作上一年的13、14月来计算，比如2003年1月1日要看作2002年的13月1日来计算）
         monthIndex=i+12;
        if(y>0) y--;            // 别只改变月数忘了这里！！上一年！
        else{
            c--;
            y=99;
        }
    }
    else monthIndex=i;

    if(string_to_int(year, 0, 3)<=1582&&monthIndex<=10&&day<=4){    // 若要计算的日期是在1582年10月4日或之前的儒略历实施年代
        w=y+floor(y/4)-c+floor(26*(monthIndex+1)/10)+day+4;
    }
    else{
          w=y+floor(y/4)+floor(c/4)-2*c+floor(26*(monthIndex+1)/10)+day-1;   // floor(x)返回的是小于或等于x的最大整数
    }
    if(w<0)
        w=(w%7+7)%7;
    else
        w=w%7;
    cout<<weekName[w]<<endl;
    return 0;
}

