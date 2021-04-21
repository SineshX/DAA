/*
****************************************
Problem:  Coin Change
****************************************
Name   :   Sinesh Kumar
Roll No:   1917286
Design and Analysis of Algorithms
B.tech CSE, 4th SEM
IKGPTU MOhali-1
Date   :   20-04-2021
****************************************
****************************************
*/
/// Greedy

//		It shows that how many ways we can Get n Taka 
//    (Example: 15)
//		5*3, 10+5*2, 2*5+5

#include <stdio.h>
#define N 5
int main()
{
	int i,j, n;
	int coin[N]={1,2,5,10,20};

	while(scanf("%d",&n) != EOF){
		int dp[1000]={0};
		dp[0]=1;				// initially Let 1
	
		for( i=0; i< N; i++)		// here N is coin no
			for(j= coin[i] ; j<=n ; j++)
				dp[j] += dp[ j- coin[i] ];

		printf(" = %d\n", dp[ n] );

	}

	return 0;
}