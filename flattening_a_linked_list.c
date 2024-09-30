/*

Given a Linked List, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked lists is in sorted order.
Flatten the Link List so all the nodes appear in a single level while maintaining the sorted order.

Note: The flattened list will be printed using the bottom pointer instead of the next pointer. Look at the printList() function in the driver code for more clarity.

Input:

5->10->19->28
|   |   |   |
7  20  22  35
|       |   |
8      50  40
|           |
30         45

Output:

5->7->8->10->19->20->22->28->30->35->40->45

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct __node
{
	int data;
	struct __node * next;
	struct __node * bottom;
}sNode, *pNode;


pNode createNode(int data)
{
	pNode pCur = (pNode) malloc (sizeof(sNode));

	if( pCur == NULL) return NULL;

	pCur->data = data;
	pCur->next = NULL;
	pCur->bottom = NULL;

	return pCur;
}

void displayList(pNode head)
{
	pNode pCur = head;
	while( pCur != NULL )
	{

		printf("%d->",pCur->data);
		pCur = pCur->bottom;

		if( pCur  == NULL )
		{
			pCur = head->next;
			head = head->next;
		}
	}
	printf("NULL\n");
}

int insertNode( pNode after, pNode pCur)
{
	if( after == NULL || pCur == NULL )
		return -1;
	
	printf(" Insert %d after %d\n", pCur->data, after->data);
	pNode pTemp = after->bottom;
	//printf("Temp %d, ", pTemp->data);
	after->bottom = pCur;
	//printf("pCur %d,", pCur->data);
	pCur->bottom = pTemp;
	//printf("pCur->bottom %d\n", pCur->bottom->data);
	pCur->next = NULL;
	return 0;
}

int flattenList(pNode pHead)
{
	int cnt = 0;
	pNode subList[10] = {0};
	pNode pPrev = NULL;
	pNode pCur = pHead;
	pNode pCurSubHead = NULL;
	pNode pCurSub= NULL;
	pNode pTemp = NULL;

	while( pCur != NULL )
	{
		/* Store all the sublist heads */
		subList[cnt] = pCur;
		pCur = pCur->next;
		cnt++;
	}
	/*Take the SubList */

	cnt = 1;
	while( subList[cnt] != NULL )
	{
		pCurSubHead = subList[cnt];
		pHead->next = pCurSubHead->next;

		while( pCurSubHead != NULL )
		{
			pCur = pHead;/* Head of the main list from which the traversal is done every time */
			pCurSub = pCurSubHead; /* Head of the sublist which is getting flattened */
			/* Store the pCurSub->bottom because you will lose the bottom link of the subList once the 
				insert of the pCurSub is done
				For example , if you have moved node 10 which is the head of the second sublist, the link
				to node 20 will be lost. 
			*/
			pCurSubHead = pCurSub->bottom;

			printf("\n\n");
			if( pCur)
				printf(" pCur = %d,", pCur->data);
			if(pCurSub)
				printf("pCurSub= %d,",pCurSub->data);
			if(pCurSubHead)
				printf(" pCurSubHead =%d\n",  pCurSubHead->data);
			while( pCur != NULL )
			{
				if( pCur->data > pCurSub->data )
				{
					insertNode( pPrev, pCurSub);
					printf("pCurSub = %d, pCur = %d, pPrev=%d\n", pCurSub->data, pCur->data, pPrev->data);
					break;
				}
				{
					pPrev = pCur;
					pCur=pCur->bottom;
				}
			}
			/* You hit where the end of the Flattened List but still other nodes which are greater than
			 	the pCur exist, So link them to pPrev->bottom 
			*/
			if( pCur == NULL )
				pPrev->bottom = pCurSub;
		}
		cnt++;
	}
}

int main()
{
	pNode pHead = (pNode ) malloc (sizeof( sNode));	

	/* Creation of the first SubList */
	pHead = createNode(5);
	pHead->bottom = createNode(7);
	pHead->bottom->bottom = createNode(8);
	pHead->bottom->bottom->bottom = createNode(30);

	/* Creation of the Second SubList */
	pHead->next = createNode(10);
	pHead->next->bottom = createNode(20);


	/* Creation of the Third SubList */
	pHead->next->next = createNode(19);
	pHead->next->next->bottom = createNode(22);
	pHead->next->next->bottom->bottom = createNode(50);

	/*Creation of the Fourth SubList */
	pHead->next->next->next = createNode(28);
	pHead->next->next->next->bottom = createNode(35);
	pHead->next->next->next->bottom->bottom = createNode(40);
	pHead->next->next->next->bottom->bottom->bottom = createNode(45);

	displayList(pHead);

	flattenList(pHead);
	displayList(pHead);

}

