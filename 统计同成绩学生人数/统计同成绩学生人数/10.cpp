//
//  10.cpp
//  统计同成绩学生人数
//
//  Created by chenmeiqi on 2019/2/25.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//
//该解法利用了输入只有 0 到 100 这 101 种可能的特点。利用其与数组下标对 应的方法分别统计各分数出现的次数。初始时，我们将数组初始化为 0，代表着 每一个分数出现的次数都是 0。当开始输入分数时，我们依据输入的分数 x，累 加代表其出现次数的数组元素 Hash[x]，从而统计其重复次数。这里，我们利用 读入的分数直接作为数组下标来访问该元素，因此这个过程十分快捷。当输入完 成后，Hash 数组中就已经保存了每一个分数出现的次数。当我需要查询分数 x 出现的次数时，只需访问统计其出现次数的数组元素 Hash[x],便能得知答案。
//该解法写法简单、思路清晰。所以，在必要时使用 Hash 算法必能事半功倍。
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int N,score,index=0;
    int scores[101]={0};
    while(cin>>N && N!=0){
        while(N>0){
            cin>>score;
            scores[score]++;
            N--;
        };
        cin>>index;
        cout<<scores[index]<<endl;
    }
    return 0;
}
