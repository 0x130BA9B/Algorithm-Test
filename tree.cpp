#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include<stack>
#include<queue>
using namespace std;


typedef struct node{
    char data;
    node*   lchild;
    node*   rchild;
};

void builtTree(node* &T){
    char c;
    cin>>c;
    if(c=='#')
        T=NULL;
    else
    {
        T=new node;
        T->data=c;
        builtTree(T->lchild);
        builtTree(T->rchild);
    }
}

//前序遍历二叉树并打印
void preTraverse(node* T)
{
    if(T)
    {
        cout<<T->data<<" ";
        preTraverse(T->lchild);
        preTraverse(T->rchild);
    }
}
//中序遍历二叉树并打印
void midTraverse(node* T)
{
    if(T)
    {
        midTraverse(T->lchild);
        cout<<T->data<<" ";
        midTraverse(T->rchild);
    }
}
//后续遍历二叉树并打印
void postTraverse(node* T)
{
    if(T)
    {
        postTraverse(T->lchild);
        postTraverse(T->rchild);
        cout<<T->data<<" ";
    }
}

void InorderStack(node* T)//非递归中序遍历二叉树
{
	stack<node*>S;
	node* p=T;
	while(p||!S.empty())
	{
		if(p)//从当前结点p，向左走到头停止
		{
			S.push(p);
			p=p->lchild;
		}
		else {
			p=S.top();
			cout<<p->data<<" ";
			S.pop();
			p=p->rchild;
		}
	}
}

int  Degree(node* T)//先序二叉树的深度，递归法：
{
	int max,h1,h2;
	if(T)
	{
		h1=Degree(T->lchild);
		h2=Degree(T->rchild);
		max=h1>h2?h1:h2;
		return max+1;
	}
	else return 0;

}

/*
求二叉数中的节点个数
递归解法：
1：如果二叉树为空，节点的个数为0
2：如果二叉树不为空，二叉树节点的个数 = 左子树节点个数+右子树节点的个数+1；
*/
int GetNodeCount(node* T)
{
    if (T == NULL)
        return 0;

    int LeftNum  =  GetNodeCount(T->lchild);
    int RightNum =  GetNodeCount(T->rchild);
    int ret = LeftNum+RightNum+1;
    return ret;

}

int  Leaf(node* T)//二叉树的叶子数，递归法：
{
	if(T==NULL)
		return 0;
	else if(T->rchild==NULL&&T->lchild==NULL)
		return 1;
	else return Leaf(T->lchild)+Leaf(T->rchild);

}

void QueueTraverse(node* T)//用队列二叉树的层次遍历
{
	queue<node*>Q;
	node* p;
	p=T;
	Q.push(p);
	while(!Q.empty())
	{
		node* q=Q.front();
		cout<<q->data<<" ";
		Q.pop();
		if(q->lchild)//左子树入队
			Q.push(q->lchild);
		if(q->rchild)//右子树入队
			Q.push(q->rchild);
	}
}

int main() {

   return 0;
}


