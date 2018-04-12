#include <iostream>
#include <cmath>
#include <time.h>

#define DEBUG 1
 
using namespace std;

int main()
{
	int n, N = 1<<3;	// (00000001)=1 -> (00001000)=8
	double *X_re, *X_im, *x_re, *x_im;
	clock_t t1, t2;
	double Time;
	
	X_re = new double[N];
	X_im = new double[N];
	x_re = new double[N];
	x_im = new double[N];
	
	for (int n=0; n<N; n++){
		x_re[n] = n+1;
		x_im[n] = 0.0L;
	}
	
	// DFT
	double a, c, s, ca, sa, t;
	t1 = clock();
	for (int k=0; k<N; k++){
		X_re[k] = 0.0L;
		X_im[k] = 0.0L;
		// cos(n a) -> cos((n+1) a) = c(na)c(a) - s(na)s(a)
		// sin(n a) -> sin((n+1) a)	= s(na)c(a) + c(na)s(a)
		// recursion
		// c = cos(theta) = cos(na)
		// s = sin(theta) = sin(na)
		// ca = cos(a)
		// sa = sin(a)
		// theta = n*a; a = 2*M_PI*k/N
		a = 2*M_PI*k/N;
		ca = cos(a);
		sa = sin(a);
		c = 1.0L;	// n = 0; cos(0) = 1
		s = 0.0L;	// n = 0; sin(0) = 0
		for (int n=0; n<N; n++){
			//a = 2*M_PI*k*n/N;
			//c = cos(a);
			//s = sin(a);
			X_re[k] += x_re[n]*c + x_im[n]*s;
			X_im[k] += x_im[n]*c - x_re[n]*s;
			t = c;
			c = c*ca - s*sa;
			s = s*ca + t*sa;
		}
	}
	t2 = clock();
	Time = (t2 - t1)/(double)CLOCKS_PER_SEC;
	cout << "Time: " << Time << endl;
	
	#if DEBUG
	for (int k=0; k<N; k++){
		if(X_im[k]>0)
			cout << X_re[k] << "\t" << X_im[k] << " i" << endl;
		else
			cout << X_re[k] << "\t" << -X_im[k] << " i"<< endl;
	}
	#endif
	
	return 0;
} 
