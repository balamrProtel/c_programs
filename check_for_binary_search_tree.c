/*

Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Examples:

Input:
   2
 /    \
1      3
        \
         5
Output: true 


Explanation: 
The left subtree of every node contains smaller keys and right subtree of every node contains greater. Hence, the tree is a BST.



Input:
  2
   \
    7
     \
      6
       \
        9
Output: false 



Explanation: 
Since the node with value 7 has right subtree nodes with keys less than 7, this is not a BST. 


*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


struct ds_tree_node {
	int data;
	struct ds_tree_node * left;
	struct ds_tree_node * right;
};


struct ds_tree {
	struct ds_tree_node * pRoot;
	int (*compare) (struct ds_tree_node *, struct ds_tree_node *);	
};


typedef struct ds_tree ds_tree_t;
typedef struct ds_tree_node ds_tree_node_t;


ds_tree_node_t * createTreeNode(int data )
{
	ds_tree_node_t * pCur = (ds_tree_node_t * ) malloc ( sizeof ( ds_tree_node_t ));

	if( pCur == NULL )
	{
		printf("Cannot create Tree Node \n");
		return NULL;
	}

	pCur->data = data;
	pCur->left = NULL;
	pCur->right = NULL;


	return pCur;
}


void displayBTreePreOrder( ds_tree_node_t * pRoot )
{
	if( pRoot == NULL ) return;

	printf( "%d, ", pRoot->data );
	displayBTreePreOrder( pRoot->left);
	displayBTreePreOrder( pRoot->right);
	
}

int compare_tree_nodes( ds_tree_node_t * node1, ds_tree_node_t * node2 )
{
	if( node1 == NULL || node2 == NULL )
	{
		printf(" Node is NULL, Cannot compare \n");
		return -2;
	}

	int rem = node1->data - node2->data;
	
	if( rem < 0 ) 
	{
		return -1;
	}
	else if ( rem > 0 )
	{
		return 1;
	}
	return 0;

}


int checkCurNode ( ds_tree_node_t * node)
{
	if( node == NULL )
	{
		return 0;
	}

	if( compare_tree_nodes( node, node->left ) == 0 ||
		compare_tree_nodes( node, node->left) == -1 ) 
	{
		return -1;
	}

	if( compare_tree_nodes( node->right, node) == 0 || 
		compare_tree_nodes( node->right, node) == -1 ) 
	{
		return -1;
	}

	if( checkCurNode( node->left) == -1 ) return -1;
	if( checkCurNode( node->right) == -1 ) return -1;

	return 1;
}
int checkForBinarySearchTree( ds_tree_t * p_bs_tree )
{
	if( p_bs_tree == NULL )
	{
		printf(" Binary Tree is NULL \n");
		return 0;
	}

	
	if( checkCurNode ( p_bs_tree->pRoot ) == 1 )
	{
		printf("Binary Tree is BST \n");
	}
	else
	{
		printf(" It is Not BST \n");
	}
	
}
int main()
{
	ds_tree_t bs_tree;
	ds_tree_node_t * pRoot = NULL;
	printf(" Check for Binary Search Tree \n");

	/* Binary Tree Creation */

	bs_tree.pRoot = createTreeNode(2);
	pRoot = bs_tree.pRoot;

	pRoot->left = createTreeNode(1);
	pRoot->right = createTreeNode(4);
	pRoot->right->right = createTreeNode(5);
	pRoot->right->left = createTreeNode(3);


	printf("First BTree - PreOrder \n");

	displayBTreePreOrder( pRoot);
	printf(" \n");

	checkForBinarySearchTree( &bs_tree );
}


