/* File: kalmpr.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MINNUM 2100000000
#define MAXNUM 2101000000
#define MAXK 5
#define COMPUTATIONS 20

int main()
{  int semprime, kprime,n,temp,countdivs,divisor,y,z,x,i;
   long curtime;

   printf("Checking numbers in [%d,%d]\n\n", MINNUM, MAXNUM);
   semprime=0; /* count semprime*/
   kprime=0; /*count k-almost prime*/  

   for (n=MINNUM; n<= MAXNUM; n++){ 
      temp=n; /*Copy n and use temp for divison*/
      countdivs=0; /*count the divisors of n*/
      for(divisor=2; divisor * divisor <= temp; divisor++){ /*Checking for divisor until the square root of n*/
            while (temp % divisor ==0){ /* Divide the temp with the divisor as many times as possible*/
                temp= temp / divisor;
                countdivs++;
            }
        }
        if (temp!=1){ /* After the consecutive divisions,temp will either 1 or a prime number*/
            countdivs++;
        }
        if (countdivs==2){ /*It's a semiprime number*/
            if ((temp!=1) && (temp - divisor+1 < 0.01* temp)){ /*Divisor-1 keeps the 1st divisor and temp keeps the 2nd if temp!= 1 */
                printf("%d * %d = %d is a  an interesting semiprime\n",divisor-1,temp, n);
            }
            semprime++;
            kprime++;
        }
        else if ((countdivs>2) & (countdivs <=MAXK)){
            kprime++;
        }
    }

    printf("\n");
    printf("Found %d k-almost prime mumbers (2 <= k <= %d)\n",kprime, MAXK);
    printf("Found %d semiprimes\n\n",semprime);
    curtime = time(NULL);
    srand((unsigned int) curtime); /* Seed for random number generator */
    printf("Current time is %ld\n\n",curtime);
    printf("Checking 20 random numbers\n\n");

    for (i=0 ; i < COMPUTATIONS; i++){
       y=rand();   /* Select 1st number */
       z=rand();  /* Select 2nd number*/
       x = ((y % 32768) + 1) * ((z % 32768) + 1) + 1;
       temp=x;
       countdivs=0;
       divisor=2; 

        for(divisor=2; divisor * divisor <= temp; divisor++){ /* Divide the temp with the divisor as many times as possible*/
            while (temp % divisor ==0){   /* Divide the temp with the divisor as many times as possible*/
                temp= temp / divisor;
                countdivs++;
            }
        }
        if (temp!=1){ /* After the consecutive divisions,temp will either 1 or a prime number*/
            countdivs++;
        }
        printf("%10d is a %d-almost prime number\n",x,countdivs);
    }
}