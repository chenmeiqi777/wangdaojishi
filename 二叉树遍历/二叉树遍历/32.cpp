//
//  32.cpp
//  二叉树遍历
//
//  Created by chenmeiqi on 2019/3/15.
//  Copyright © 2019年 chenmeiqi. All rights reserved.
//


/* 思路：由前序遍历结果的首个元素为 X 可知，原树必是由 X 为根结点。在中序遍历中，遍历结果 ADGXFE 以 X 为界分为两个子串。其中第一个子串 ADG 为 X 的左子树的中序遍历结果，第二个子串 FE 为 X 的右子树的中序遍历结果。这样我们知道 X 的左子树具有 3 个元素，X 的右子树具有 2 个元素。根据元素的数量我们同样可以得知，在先序遍历中去除根结点 X 后剩余的串 DAGFE 中，前 3 个字符 DAG 为 X 的左子树的前序遍历结果，后 2 个字符 FE 为 X 的右子树的前 序遍历结果。
    同样的对于确定的左子树前序遍历结果 DAG 和中序遍历结果 ADG 重复以上确定过程，可知 D 为该子树根结点，其左儿子为 A，右儿子为 G。
    X 的右子树前序遍历结果 FE 和中序遍历结果 FE 同样可以确定该子树以 F 为根节点，其左儿子不存在，右儿子为 E。
*/

/*
 在本例代码中我们并没有动态的申请内存空间，并在程序结束时释放这些空间。而是使用了静态数组，利用分配数组元素给相应的结点实现内存分配。这是对内存分配较为简单的实现方法，若读者对动态的申请和释放内存没有把握，或者对何时何地释放内存抱有疑惑，建议使用该较为保险的方法。
 */

#include <iostream>
using namespace std;
struct Node{
    Node* lchild;       // 左孩子
    Node* rchild;       // 右孩子
    char data;         // 字符信息
}Tree[26];
int idx;
Node* create(){
    Tree[idx].lchild=Tree[idx].rchild=NULL;     // 初始化左右孩子为空
    idx++;
    return &Tree[idx];          // 返回指针
}

Node* build(string pre,string in){
    string left_pre,    // 前序遍历中根结点的左子树顺序
    right_pre,        // 前序遍历中根结点的右子树顺序
    before_in,       // 中序遍历中根结点的左子树顺序
    after_in;        // 中序遍历中根结点的左子树顺序
    
    Node * node=create();
    node->data=pre[0];
    
    int i=0;
    for(;i<=in.length();i++){           // 找到根结点在中序遍历中的index
        if(in[i]==pre[0]) break;
    }
    before_in=in.substr(0,i);
    after_in=in.substr(i+1,in.length());
    left_pre=pre.substr(1,i);
    right_pre=pre.substr(i+1,pre.length());

    if(i!=0) node->lchild=build(left_pre,before_in);            // 替换pre和in，对左子树进行
    if(i!=in.length()-1)node->rchild=build(right_pre,after_in);         // length-1 不是length。。

    
    return node;
}

void postOrder(Node *T) { //后序遍历
    if (T -> lchild != NULL) { //若左子树不为空
        postOrder(T -> lchild); //递归遍历其左子树
    }
    if (T -> rchild != NULL) { //若右子树不为空
        postOrder(T -> rchild); //递归遍历其右子树
        
    }
    cout<<T -> data; //遍历该结点,输出其字符信息
    
}


int main(int argc, const char * argv[]) {
    string pre,     // 前序
    in;      // 中序
    
    cin>>pre>>in;
    
    idx=0;
    Node* T =build(pre,in);
    postOrder(T); //后序遍历
    
    cout << "\n";
    return 0;
}
