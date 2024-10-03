/*

 Left View of Binary Tree

Given a Binary Tree, return its Left view. The left view of a Binary Tree is a set of nodes visible when the tree is visited from the Left side. i
If no left view is possible, return an empty array.

Examples :

Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, 8]
          1
       /     \
     2        3
   /   \     /  \
  4     5   6    7
   \
     8   
Output: [1, 2, 4, 8]

Explanation: When we view the tree from the left side, we can only see the nodes 1, 2, 4, and 8.

*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


struct _tree_node
{
	int data;
	struct _tree_node * left;
	struct _tree_node * right;
	struct _tree_node * parent;

};


struct _tree
{
	struct _tree_node * pRoot;
	int no_of_nodes;
};


typedef struct _tree_node sTreeNode, *pTreeNode;
typedef struct _tree sTree, *pTree;

pTreeNode createTreeNode( int data )
{
	pTreeNode pCurNode = (pTreeNode) malloc (sizeof( sTreeNode));

	if( pCurNode == NULL ) return NULL;

	pCurNode->data = data;
	pCurNode->left = NULL;
	pCurNode->right = NULL;


	return pCurNode;
}

void printTreePreorder( pTreeNode pRoot)
{
	if( pRoot == NULL ) return ;
	printf("%d, ", pRoot->data );
	printTreePreorder(pRoot->left);
	printTreePreorder(pRoot->right);
}

int printLeftViewofTree( pTreeNode pRoot)
{
	if( pRoot == NULL ) return 0;
	
	printf("%d,", pRoot->data);

	/* Print the Left Child to get the Left View of the Tree
		if the Left Child is not present , then only print the right child
		Once Printed return 1 so that it does not parse the right child */
	if( printLeftViewofTree( pRoot->left) == 0)
		printLeftViewofTree( pRoot->right);
		
	return 1;
}
int main()
{
	sTree bTree;
	pTreeNode pRoot = NULL;
	printf(" Left View of Binary Tree\n");

	/* Creation of the Binary Tree */
	bTree.pRoot = createTreeNode(1);
	pRoot = bTree.pRoot;
	
	pRoot->left = createTreeNode(2);
	pRoot->right = createTreeNode(3);

	pRoot->left->left = createTreeNode(4);
	pRoot->left->right = createTreeNode(5);
	pRoot->left->left->right  = createTreeNode(8);

	pRoot->right->left = createTreeNode(6);
	pRoot->right->right = createTreeNode( 7);

	printTreePreorder( pRoot);
	printf("\n");
	
	printLeftViewofTree( pRoot);
	printf("\n");

	return 0;
}
