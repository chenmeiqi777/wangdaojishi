//
//  30.cpp
//  哈夫曼树
//
//  Created by chenmeiqi on 2019/3/14.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//

// 为了绕过对堆的实现，我们使用标准模板库中的相应的标准模板——优先队列。
// 利用语句 priority_queue<int> Q;
// 建立一个保存元素为 int 的堆 Q，但是请特别注意这样建立的堆其默认为大顶堆，
// 即我们从堆顶取得的元素为整个堆中最大的元素。而在求哈夫曼树中，我 们恰恰需要取得堆中最小的元素，于是我们使用如下语句定义一个小顶堆:
// priority_queue<int , vector<int> , greater<int> > Q;

/*
 1.将所有结点放入集合 K。
 2.若集合 K 中剩余结点大于 2 个，则取出其中权值最小的两个结点，构造他 们同时为某个新节点的左右儿子，该新节点是他们共同的双亲结点，设定它的权 值为其两个儿子结点的权值和。并将该父亲结点放入集合 K。重复步骤 2 或 3。
 3.若集合 K 中仅剩余一个结点，该结点即为构造出的哈夫曼树数的根结点， 所有构造得到的中间结点(即哈夫曼树上非叶子结点)的权值和即为该哈夫曼树 的带权路径和。
 */

#include <iostream>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    int n=0;
    int value=0;
    priority_queue<int,vector<int>,greater<int>> Q; //建立一个小顶堆
    int small_1,small_2;
    int result;
    cin>>n;
    int n_count=n;
    while(n_count--){   //输入n个叶子结点权值
        cin>>value;
        Q.push(value);      //将权值放入堆中
    }
    result=0;
    while (Q.size()>1) {
        small_1=Q.top();
        Q.pop();
        small_2=Q.top();
        Q.pop();            //取出堆中两个最小元素,他们为同一个结点的左右儿子,且该双亲结点的权值为它们的和
        Q.push(small_1+small_2);        //将该双亲结点的权值放回堆中(越小的数被加的次数越多)
        result+=small_1+small_2;
    }
    cout << result <<endl;
    return 0;
}
