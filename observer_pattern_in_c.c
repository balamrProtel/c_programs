/*
This program to show how observer design pattern can be emulated in C

Subject : This is the topic where objects are interested to get notified.

Object : Observers who are interested in the subject 

Temperature can be subject to which the Observers are interested. Any change in Temperature 
will notify all the observers who are registered with the subject

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_OBS 10

typedef void (*observer_callback_fn_t) ( int temp );


typedef struct 
{
	char name[50];
	observer_callback_fn_t changed_cb;
	
}Observer;


typedef struct 
{
	int temperature;
	int no_of_observers;
	/* Observers List */
	Observer *observer_list[MAX_OBS];

}Subject;


/* Implement Subject methods */
void subject_int( Subject * pSub)
{
	if( pSub == NULL )
	{
		printf(" Cannot Initiate Subject : NULL\n");
		return;
	}

	pSub->no_of_observers = 0;
	pSub->temperature = 0;
	
	for( int i = 0; i < MAX_OBS; i++)
	{
		pSub->observer_list[i] = 0;
	}
}

void subject_attach( Subject *pSub, Observer *pObj)
{
	if( pSub->no_of_observers < MAX_OBS )
	{
		pSub->observer_list[pSub->no_of_observers++] = pObj;
		printf("%s is attached\n", pObj->name);
		return;
	}

	printf("Max no of Observers reached\n");
	
}

void subject_detach( Subject *pSub, Observer *pObj)
{
	for( int i = 0; i < pSub->no_of_observers; i++)
	{
		if( pSub->observer_list[i] == pObj)
		{
			for( int j = i; j < pSub->no_of_observers-1; j++)
			{
				pSub->observer_list[j] = pSub->observer_list[j+1];	
			}
			pSub->no_of_observers--;
			printf(" %s observer detached\n", pObj->name);
			return;
		}

	}

	printf("Observer Not Found\n");
}

void notify_observers( Subject * pSub)
{
	for( int i = 0; i < pSub->no_of_observers; i++)
	{
		pSub->observer_list[i]->changed_cb(pSub->temperature);
	}

}
void subject_set_temp( Subject* pSub, int temp )
{
	pSub->temperature = temp;
		
	printf(" New Temperature updated %d : notify observers\n", temp);
	notify_observers(pSub);
}

/* Implement Observer Callbacks */

void observer_display_temperature( int new_temp)
{
	printf(" Display : New Temperature %d displayed\n", new_temp);
}
void observer_logger_temperature( int new_temp)
{
	printf(" Logger : New Temperature %d Logged\n", new_temp);
}


int main()
{

	Subject sub;

	subject_int( &sub);
	
	Observer displayer = {"Display", observer_display_temperature };
	Observer logger    = {"Logger", observer_logger_temperature };

	subject_attach( &sub, &displayer);
	subject_attach( &sub, &logger);

	subject_set_temp(&sub,50);
	
}
