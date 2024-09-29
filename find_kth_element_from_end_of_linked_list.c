/*

Given the head of a linked list and the number k, Your task is to find the kth node from the end. If k is more than the number of nodes, then the output should be -1.

Examples

Input: LinkedList: 1->2->3->4->5->6->7->8->9, k = 2
Output: 8
Explanation: The given linked list is 1->2->3->4->5->6->7->8->9. The 2nd node from end is 8.


Input: LinkedList: 10->5->100->5, k = 5
Output: -1
Explanation: The given linked list is 10->5->100->5. Since 'k' is more than the number of nodes, the output is -1.


1. define an array of size K.
2. store the node address when you traverse in the array, 
3. define a Kth pointer always points the current Kth element from the end.
4. When the end of list is hit return the Kthe element
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct __node
{
	int data;
	struct __node * next;
}sNode, *pNode;

pNode createNode( int data )
{
	pNode pCurNode = ( pNode ) malloc ( sizeof( sNode ));

	if( pCurNode == NULL ) return NULL;

	pCurNode->data = data;
	pCurNode->next = NULL;

	return pCurNode;
}



void displayList( pNode head )
{
	while ( head != NULL )
	{
		printf("%d->", head->data);
		head = head->next;
	}

	printf("NULL\n");
}

pNode findKthElement( pNode head, int k)
{
	int i, kth;
	pNode nodes[k] ;
	pNode pCur = NULL;

	pCur = head;
	i = 0;
	kth = 0;
	while( pCur != NULL )
	{
		nodes[kth] = pCur;
		i++;
		kth = i%k; /* Store the K modulo of total nodes count in Kth element */
		pCur = pCur->next;
	} 

	if( i < k )
	{
		return NULL;
	}
	else
	{
		printf("success\n");
		return nodes[kth];
	}
}


int main()
{
	int k=10;
	
	pNode head = createNode(1);
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	head->next->next->next->next = createNode(5);
	head->next->next->next->next->next = createNode(6);
	head->next->next->next->next->next->next = createNode(7);
	head->next->next->next->next->next->next->next = createNode(8);
	head->next->next->next->next->next->next->next->next = createNode(9);

	displayList(head);

	pNode KthNode = findKthElement( head, k);
	
	if( KthNode != NULL )
	{
		printf(" Kth Node is %d\n", KthNode->data);
	}
	else
	{
		printf("size of the list is lesser than K \n"); 
	}

	return 0;
}
