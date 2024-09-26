/*

Create a linked list like below

1->2->3->4->5->6

write a program to split the list as group of 3 nodes and reverse them


*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct __list
{
	int data;
	struct __list * next;
}sNode, *pNode;


pNode createNode( int data )
{
	pNode pCur = (pNode) malloc ( sizeof( sNode));
	if( pCur == NULL )
	{
		return NULL;
	}

	pCur->data = data;
	pCur->next = NULL;

	return pCur;

	
}

pNode splitLinkedList( pNode head, int group)
{

	int cnt = 0,k, i = 0;
	int head_stored = 0;
	pNode aTail[4] = {0}, aHead[4]={0};
	pNode pTail = NULL;
	pNode pCur = head;
	pNode pPrev = NULL;
	pNode pNext = NULL;
	pNode pThis = head;
	pNode rHead = NULL;
	int nodescnt = 0;
	
	while( pCur != NULL )
	{ 
		/*Store the First Node in the revers list as Tail to connect to the next segment*/
		pTail = pCur;
		for ( cnt =0; cnt < group ; cnt++ )
		{
			/* Reverse the node */
			pNext = pCur->next; /* Get the next node */
			pCur->next = pPrev;	
			pPrev = pCur;
			pCur = pNext;
		}
		aHead[i] = pPrev;
		aTail[i] = pTail;
		if (pTail) printf("Tail = %d, ", pTail->data);
		if (aHead[i]) printf("Head  = %d \n", aHead[i]->data);
		i++;
	}

	nodescnt = (i)*group;
	printf( "nodes cnt %d\n", nodescnt);
	for(  k= 0, i = 0; i < nodescnt; k++,i=i+group )
	{
		aTail[k]->next = aHead[k+1];
	}
	return aHead[0];
}
void printList( pNode head )
{
	pNode pCur = head;
	while( pCur != NULL )
	{
		printf("%d->",pCur->data);
		pCur = pCur->next;
	}
	printf("NULL\n");
}
int main()
{

	pNode rHead = NULL;
	/* Create the sample list */
	pNode head = createNode(1);
	head->next = createNode(2);
	head->next->next  = createNode(3);
	head->next->next->next  = createNode(4);
	head->next->next->next->next  = createNode(5);
	head->next->next->next->next->next  = createNode(6);
	head->next->next->next->next->next->next  = createNode(7);
	head->next->next->next->next->next->next->next  = createNode(8);
	head->next->next->next->next->next->next->next->next  = createNode(9);
	
	printList(head);

	rHead = splitLinkedList( head, 3);	

	printList(rHead);
}

