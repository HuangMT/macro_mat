
#include <cstdio>
#include <iterator>
#include "bug.h"
#include "reccursive_macro.h"

using namespace std;

#define _A(_m,_n,_k) double _k##_n##_m(){return 0;}
#define A(m,n,k) _A(m,n,k)
#define AAA(m,...) A(m,##__VA_ARGS__)
#define _PRINT(a,b) printf(#a)
#define PRINT(...) _PRINT(##__VA_ARGS__)





int bugmain()
{
	PRINT("a%d,%d", 2);
	system("pause");

	return 0;
}
