#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <unistd.h>

#define INPUT_SIZE 65536

int main (void) {
//	const char *s = "Rosetta code";
	char s[INPUT_SIZE];
	read(STDIN_FILENO, s, INPUT_SIZE);
	unsigned char *d = SHA256(s, strlen(s), 0);
/*
	int i;
	for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
		printf("%02x", d[i]);
	putchar('\n');
*/
	return 0;
}
