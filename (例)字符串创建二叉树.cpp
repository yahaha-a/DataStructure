#include <iostream>
#include <string>

using namespace std;

typedef struct Node
{
    char data;
    struct Node* lchild;
    struct Node* rchild;
}BTNode;

void createTree(BTNode*& root, char* arry)
{
    root = NULL;
    BTNode* cur = NULL;
    BTNode* stk[100];
    int top = -1;
    int flag = 0;
    while (*arry != '\0')
    {
        switch (*arry)
        {
        case '(':
            top++;
            stk[top] = cur;
            flag = 1;
            break;

        case ')':
            top--;
            break;

        case ',':
            flag = 2;
            break;

        default:
            cur = (BTNode*)malloc(sizeof(BTNode));
            cur->lchild = cur->rchild = NULL;
            cur->data = *arry;
            if (root == NULL)
                root = cur;
            if (flag == 1)
                stk[top]->lchild = cur;
            else if (flag == 2)
                stk[top]->rchild = cur;
            flag = 0;

            break;
        }
        arry++;
    }
}

void preorder(BTNode* p)
{
    if (!p)
        return;
    cout << p->data << " ";
    preorder(p->lchild);
    preorder(p->rchild);
}



int main()
{
    BTNode* root;
    char arry[100] = "A(B(D,G),C(H,F))";
    createTree(root, arry);
    preorder(root);
    return 0;
}