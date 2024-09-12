#include <bits/stdc++.h>
using namespace std;
 
struct TreeNode {
    char data;
    struct TreeNode* firstChild;
    struct TreeNode* nextSibling;
 
TreeNode(char val)
{
    data = val;
    firstChild = NULL;
    firstChild = NULL;
}

};

int main()
{
 
    /*create root*/
    struct TreeNode* root = new TreeNode('A');

    root->firstChild = new TreeNode('B');
    root->nextSibling = new TreeNode('C');
    root->nextSibling->nextSibling = new TreeNode('D');
    root->nextSibling->nextSibling->firstChild =new TreeNode('H');
	root->nextSibling->nextSibling->nextSibling=new TreeNode('E');
 	root->nextSibling->nextSibling->nextSibling->firstChild=new TreeNode('I');
 	root->nextSibling->nextSibling->nextSibling->firstChild->nextSibling=new TreeNode('J');
    return 0;
}
