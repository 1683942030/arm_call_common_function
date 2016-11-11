#include <stdio.h>
#include "call.h"

extern "C" int main(int argc, char *argv[])
{
	getchar();
	
	printf("old add ret %d\n", add(7, 8, 100, 1, 2, 3));
	
	int ret = 0;
	int params[] = {7, 8, 100, 1, 2, 3};
	ret = call_function((void *)add, 6, params);
	printf("new add ret %d\n", ret);
	
	return 0;
}