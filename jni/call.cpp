#include <stdio.h>
#include <stdint.h>

int call_function(void *addr, int argc, void *argv){
	__asm(
			"push {r0-r14}\n\t"
			"mov r5, %[argc]\n\t"
			"mov r6, %[argv]\n\t"
			"mov r7, %[addr]\n\t"
			"sub sp, #400\n\t"
			"cmp r5, #4\n\t"
			"ble arg_4\n\t"
			"sub r8, r5, #4\n\t"
			"add sp, r8 ,ASL #2\n\t"
			"b more_arg\n\t"
		"load_arg:"
			"sub r5, r5, #1\n\t"
			"mov r9, r5, ASL #2\n\t"
			"ldr r0, [r6, r9]\n\t"
			"bx lr\n\t"
		"more_arg:\n\t"
			"cmp r5, #5\n\t"
			"blt arg_4\n\t"
			"bl load_arg\n\t"
			"push {r0}\n\t"
			"b more_arg\n\t"
		"arg_4:\n\t"
			"cmp r5, #4\n\t"
			"blt arg_3\n\t"
			"bl load_arg\n\t"
			"mov r3, r0\n\t"
		"arg_3:\n\t"
			"cmp r5, #3\n\t"
			"blt arg_2\n\t"
			"bl load_arg\n\t"
			"mov r2, r0\n\t"
		"arg_2:\n\t"
			"cmp r5, #2\n\t"
			"blt arg_1\n\t"
			"bl load_arg\n\t"
			"mov r1, r0\n\t"
		"arg_1:\n\t"
			"cmp r5, #1\n\t"
			"blt call_addr\n\t"
			"bl load_arg\n\t"
		"call_addr:\n\t"
			"blx r7\n\t"
			"add sp, #400\n\t"
			"str r0, [sp]\n\t"
			"pop {r0-r13, pc}"
			:
			: [argc] "r" (argc), [argv] "r" (argv), [addr] "r" (addr)
		);
}

int add(int p1, int p2, int p3, int p4, int p5, int p6)
{
	int ret=0;
	
	for (int i=0; i<p1 ; i++)
	{
		ret+=i;
	}
	
	for (int j=p3; j>p2; j--)
	{
		ret+=j;
	}
	
	return ret+p4+p5+p6;
}