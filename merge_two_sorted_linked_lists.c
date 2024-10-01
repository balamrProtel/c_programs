/*

Merge two sorted linked lists

Given two sorted linked lists consisting of nodes respectively. The task is to merge both lists and return the head of the merged list.

Examples:

Input: 

LinkedList1: 5->10->15->40, 
LinkedList2: 2->3->20

Output: 2->3->5->10->15->20->40


Input: 

LinkedList1: 1->1, 
LinkedList2: 2->4

Output: 1->1->2->4
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

pNode mergeTwoSortedLists( pNode pList1, pNode pList2)
{
	pNode pCur1 = NULL;
	pNode pCur2 = NULL;
	pNode pPrev = NULL;
	pNode pTemp = NULL;
	pNode pMerge = NULL;
	pNode pNext1= NULL;

	pCur1 =  pList1;
	pMerge = pList2;

	/* Take each node in the first list and insert into the right place in the second list.
	   pMerge will point to the head of the Merged List
	   pCur2 will hold the current node in the second linked list similarly pCur1 for List 1
	   pPrev will keep track of the previous node in the list 2. 
	*/
	while( pCur1 != NULL )
	{	
		pNext1 = pCur1->next;/* Once the Insertion operation is done, we will lose the track of pCur1->next, so store it for next iteration */

		pCur2 =  pMerge;

		while( pCur2 != NULL )
		{
			/* if pCur1 data is less than or equal to pCur2 , that is the right spot to insert into list2*/
			if( pCur1->data <= pCur2->data )
			{
				if( pPrev != NULL )
				{
					/* pCur1 Insert operation */
					pTemp = pPrev->next;
					pPrev->next = pCur1;
					pCur1->next = pTemp; 
				}
				else
				{
					/* Boundary condition - if pCur1 is lesser than the first element of list 2, pPrev will be NULL */
					pCur1->next = pCur2;
					pMerge = pCur1;/* pCur1 becomes the head of the Merged List */
				}
				break;
			}
			pPrev = pCur2;
			pCur2 = pCur2->next; /* Run the List 2 Loop */
		}
		if( pCur2 == NULL ) /* reached end of list */
		{
			pPrev->next = pCur1;/* link the last node as pCur1 */	
		}
		pCur1 = pNext1;/* Run the first loop */
	}
	return pMerge;	

	
}

int main()
{
	pNode pMerge = NULL;
	/* Linked List 1 */
	pNode pHead1 = createNode(5);
	pHead1->next = createNode(10);
	pHead1->next->next = createNode(15);
	pHead1->next->next->next = createNode(40);
	/* Linked List 2 */
	pNode pHead2 = createNode(2);
	pHead2->next = createNode(3);
	pHead2->next->next = createNode(20);

	printList(pHead1);
	printList(pHead2);

	pMerge= mergeTwoSortedLists(pHead1, pHead2);

	printf("Merged List \n");
	printList( pMerge);
}
