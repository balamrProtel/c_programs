/*

This problem was asked by Epic.

The "look and say" sequence is defined as follows: beginning with the term 1, each subsequent term visually describes the digits appearing in the previous term. The first few terms are as follows:

1
11
21
1211
111221
As an example, the fourth term is 1211, since the third term consists of one 2 and one 1.

Given an integer N, print the Nth term of this sequence.


*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/* if the size of N goes beyond 14 the size of generated sequence will increase exponentially */
#define N 12

int main()
{
	int idx1, idx2, idx3, bytes, freq= 0;

	char seq[N*5] = {0}, sub_seq[N*5] = {0};
	
	char digit, *ptr=sub_seq;

	printf(" Look and Say Sequence Problem \n");

	seq[0]='1'; /* store the first number in the sequence */

	for( idx1 = 0; idx1 < N; idx1++)
	{
		/* Take each element in the seq and compare it with the other elements
		Break the loop if they are different 
		if they are same , increase the frequence */
		ptr = sub_seq;
		for( idx2 = 0; seq[idx2] != 0; idx2++)
		{
			freq = 1;
			for (idx3 = idx2+1; seq[idx3] !=0; idx3++)
			{
				if( seq[idx2] == seq[idx3] )
				{
					freq++;
				}
				else
				{
					break;
				}
			}
			/* Generate the Visual Sequence by first printing the 
			freq and then the digit */
			digit=seq[idx2];
			bytes = sprintf(ptr, "%d",freq);
			ptr += bytes;
			bytes = sprintf(ptr, "%c", digit);
			ptr += bytes;

			idx2 = idx3-1;
		}
		/* print the generated sequence */
		printf("%s\n", sub_seq);
		/* reset the seq and seb_seq for the next iteration */
		memset(seq, 0, N*5);
		memcpy(seq, sub_seq,N*5);
		memset(sub_seq, 0, N*5);
	}
	return 0;

}

