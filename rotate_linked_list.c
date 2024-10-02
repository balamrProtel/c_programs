/*

Rotate a Linked List

Given the head of a singly linked list, the task is to rotate the left shift of the linked list by k nodes, where k is a given positive integer smaller than or equal to the length of the linked list.

Examples:

Input: linkedlist: 2->4->7->8->9 , k = 3

Output: 8->9->2->4->7


Explanation:
Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
Rotate 3: 8 -> 9 -> 2 -> 4 -> 7

*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


typedef struct __node
{
	int data;
	struct __node * next;
}sNode, *pNode;

pNode createNode( int data)
{
	pNode pCur = (pNode) malloc (sizeof ( sNode));

	if( pCur == NULL ) return NULL;

	pCur->data = data;
	pCur->next = NULL;

	return pCur;
}

void displayList( pNode pHead)
{
	while( pHead != NULL )
	{
		printf("%d->",pHead->data);
		pHead = pHead->next;
	}
	printf("NULL\n");
}

pNode rotateListLeft( pNode pHead, int k)
{
	int cnt = 0;
	pNode pTemp = NULL;
	/* Identify the Tail */	
	pNode pTail = pHead;

	while( pTail->next != NULL )
	{
		pTail = pTail->next;
	}

	while( cnt < k )
	{
		pTemp = pHead->next;
		pTail->next = pHead;
		pHead->next = NULL;
		pTail = pHead;
		pHead = pTemp;
		cnt++;
	}

	return pHead;
}

int main()
{
	pNode pRotHead = NULL;
	pNode pHead = createNode(2);
	pHead->next = createNode(4);
	pHead->next->next = createNode(7);
	pHead->next->next->next= createNode(8);
	pHead->next->next->next->next = createNode(9);
	pHead->next->next->next->next->next = createNode(6);

	displayList(pHead);

	pRotHead = rotateListLeft( pHead, 3);

	displayList( pRotHead);
	return 0;
}
