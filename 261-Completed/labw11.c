#include <stdio.h>
#define BUFFER_SIZE 40

char *Gets(char *s) {
	int c;
	char *dest = s;

	while ((c = getchar()) != '\n' && c != EOF) {
		*dest++ = c;
	}
	
	if (c == EOF && dest == s) {
		return NULL;
	}
	
	*dest = '\0';
	return s;
}

int getbuf() {
	char buf[BUFFER_SIZE];
	Gets(buf);
	return 1;
}

void test() {   
	int val; 
	val = getbuf();
	printf("No exploit.  Getbuf returned 0x%x\n", val);
}

int main() {
	test();
	return 0;
}
