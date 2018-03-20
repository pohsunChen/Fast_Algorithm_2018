// Teacher's version
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main()
{
	clock_t t1, t2;				// variables for computing clocks 
	double a=1.234, b=2.456, c;
	double T1, T2;
	int i, j, k, N=100000000;

	t1 = clock();
	for(i=0;i<N;++i)
	{
		c = b;
		b = a;
		a = c;
	}
	t2 = clock();
	T1 = (t2-t1)/(double) CLOCKS_PER_SEC;
	printf("mem x 3 + 1 loop:%f\n",T1);
	printf("(a,b)=%f %f\n", a,b);

	t1 = clock();
	for(i=0;i<N;++i)
	{
		c = b;
		b = a;
		a = c;
		c = b;
		b = a;
		a = c;
	}
	t2 = clock();
	T2 = (t2-t1)/(double) CLOCKS_PER_SEC;
	printf("mem x 6 + 1 loop:%f\n",T2);
	printf("mem:%f\n",(T2-T1)/3.0);
	printf("(a,b,c)=%f %f\n", a, b,c);

	t1 = clock();
	for(i=0;i<N;++i)
	{
		a = a+b;
		b = a-b;
		a = a-b;
	}
	t2 = clock();
<<<<<<< HEAD
	
	printf("(+,-) time:%f\n",(t2-t1)/(double) CLOCKS_PER_SEC/3.0);
=======
	T1 = (t2-t1)/(double) CLOCKS_PER_SEC;
	printf("(+,-) time x 3 + 1 loop:%f\n",T1);
>>>>>>> 92e555ada53d2ba7c83601c807817aaede07f2e2
	printf("(a,b)=%f %f\n", a,b);
	t1 = clock();
	#pragma omp parallel
	for(i=0;i<N;++i)
	{
		a = a+b;
		b = a-b;
		a = a-b;
		a = a+b;
		b = a-b;
		a = a-b;
	}
	t2 = clock();
	T2 = (t2-t1)/(double) CLOCKS_PER_SEC;
	printf("(+,-) time x 6 + 1 loop:%f\n",T2);
	printf("Real (+,-) time: %f\n",(T2-T1)/3.0);	
	printf("(a,b)=%f %f\n", a,b);

	t1 = clock();
	for(i=0;i<N;++i)
	{
		a = a*b;
		b = a/b;
		a = a/b;
	}
	t2 = clock();
	T1 = (t2-t1)/(double) CLOCKS_PER_SEC;
	printf("(*,/) time x 3 + 1 loop:%f\n",T1);
	printf("(a,b)=%f %f\n", a,b);

	t1 = clock();
	for(i=0;i<N;++i)
	{
		a = a*b;
		b = a/b;
		a = a/b;
		a = a*b;
		b = a/b;
		a = a/b;
	}
	t2 = clock();
	T2 = (t2-t1)/(double) CLOCKS_PER_SEC;
	printf("(*,/) time x 6 + 1 loop:%f\n",T2);
	printf("(*,/) time:%f\n",(T2-T1)/3.0);	
	printf("(a,b)=%f %f\n", a,b);

	t1 = clock();
	for(i=0;i<N;++i)
	{
		a = sin(a);
	}
	t2 = clock();
	T1 = (t2-t1)/(double) CLOCKS_PER_SEC;
	printf("(sin) time + 1 loop:%f\n",T1);
	printf("(a,b)=%f %f\n", a,b);

	t1 = clock();
	for(i=0;i<N;++i)
	{
		a = sin(b);
		b = sin(a);
	}
	t2 = clock();
	T2 = (t2-t1)/(double) CLOCKS_PER_SEC;
	printf("(sin) time x 2 + 1 loop:%f\n",T2);
	printf("(sin) time: %f\n",T2-T1);
	printf("(a,b)=%.16e %.16e\n", a,b);

	srand(time(NULL));
	short r;

	
	#pragma omp parallel for
	t1 = clock();
	for(i=0;i<N;i++)
	{
		r = rand();
	}
	t2 = clock();
	printf("(rand) time:%f\n",(t2-t1)/(double) CLOCKS_PER_SEC);
	printf("r=%d\n", r);

<<<<<<< HEAD
<<<<<<< HEAD
	short A[1000][1000];
=======
	//short A[10000][10000];
>>>>>>> 92e555ada53d2ba7c83601c807817aaede07f2e2
=======
>>>>>>> f68111cb990cbad0b04f6d34b32d9200f6aba981
	t1 = clock();
	for(i=0;i<N;i++)
	{
		r = rand();
	}
	t2 = clock();
	printf("(rand) time:%f\n",(t2-t1)/(double) CLOCKS_PER_SEC);
<<<<<<< HEAD
<<<<<<< HEAD
	printf("r=%d\n", A[999][999]);
	
=======
	//printf("r=%d\n", A[9999][9999]);
=======
>>>>>>> f68111cb990cbad0b04f6d34b32d9200f6aba981

>>>>>>> 92e555ada53d2ba7c83601c807817aaede07f2e2
	return;
} 
