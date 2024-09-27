/*

Given two singly linked lists, return the point where two linked lists intersect.

                                          5
                                         /
                                4       6
                                 \     /
                                  1   1
                                   \ /
                                    8    
                                    |
                                    4
                                    |
                                    5
From the above image, it is clearly seen that the common part is 8->4->5 whose starting point is 8.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct __node
{
	int data;
	struct __node * next;
} sNode, *pNode;


pNode createNode( int data )
{
	pNode thisNode = (pNode ) malloc ( sizeof ( sNode ));
	
	if( thisNode == NULL ) return NULL;

	thisNode->data = data;
	thisNode->next = NULL;
	return thisNode;	
}           

void displayList( pNode  pCurNode )
{

	while( pCurNode != NULL )
	{
		printf( "%d->", pCurNode->data);
		pCurNode = pCurNode->next;
	}
	printf("NULL\n");
}

pNode findIntersecion( pNode h1, pNode h2)
{
	pNode ph1Cur = h1;
	pNode ph2Cur = h2;

	/* Take each node from the first linked list 
		and check for the intersection point in the second list
	*/
	while( ph1Cur != NULL )
	{
		ph2Cur = h2;
		while( ph2Cur != NULL )
		{
			if( ph1Cur == ph2Cur) return ph2Cur;
			ph2Cur = ph2Cur->next;
		}
		ph1Cur = ph1Cur->next;
	}
	return NULL;/* Failure case - No intersection */
}

int main()
{
	pNode commonNode = NULL;
	/* Create List 1 */
	pNode head1 = createNode(4);
	head1->next = createNode(1);
	pNode interNode = createNode(8);
	head1->next->next = interNode;
	head1->next->next->next = createNode(4);
	head1->next->next->next->next = createNode(5);

	/* Create List 2*/
	pNode head2 = createNode(5); 
	head2->next = createNode(6);
	head2->next->next = createNode(1);
	head2->next->next->next  = interNode;

	displayList(head1);
	displayList(head2);

	commonNode = findIntersecion( head1, head2 );

	if( commonNode == NULL )
	{
		printf(" There is no intersection point \n");
	}
	else
	{
		printf(" Intersection is at Node %d\n", commonNode->data );
		displayList( commonNode );
	}
	
	return 0;
}

