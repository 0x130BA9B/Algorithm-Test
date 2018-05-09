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

//ǰ���������������ӡ
void preTraverse(node* T)
{
    if(T)
    {
        cout<<T->data<<" ";
        preTraverse(T->lchild);
        preTraverse(T->rchild);
    }
}
//�����������������ӡ
void midTraverse(node* T)
{
    if(T)
    {
        midTraverse(T->lchild);
        cout<<T->data<<" ";
        midTraverse(T->rchild);
    }
}
//������������������ӡ
void postTraverse(node* T)
{
    if(T)
    {
        postTraverse(T->lchild);
        postTraverse(T->rchild);
        cout<<T->data<<" ";
    }
}

void InorderStack(node* T)//�ǵݹ��������������
{
	stack<node*>S;
	node* p=T;
	while(p||!S.empty())
	{
		if(p)//�ӵ�ǰ���p�������ߵ�ͷֹͣ
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

int  Degree(node* T)//�������������ȣ��ݹ鷨��
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
��������еĽڵ����
�ݹ�ⷨ��
1�����������Ϊ�գ��ڵ�ĸ���Ϊ0
2�������������Ϊ�գ��������ڵ�ĸ��� = �������ڵ����+�������ڵ�ĸ���+1��
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

int  Leaf(node* T)//��������Ҷ�������ݹ鷨��
{
	if(T==NULL)
		return 0;
	else if(T->rchild==NULL&&T->lchild==NULL)
		return 1;
	else return Leaf(T->lchild)+Leaf(T->rchild);

}

void QueueTraverse(node* T)//�ö��ж������Ĳ�α���
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
		if(q->lchild)//���������
			Q.push(q->lchild);
		if(q->rchild)//���������
			Q.push(q->rchild);
	}
}

int main() {

   return 0;
}


