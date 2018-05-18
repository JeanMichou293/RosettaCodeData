#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define INPUT_SIZE 65536
#define SHIFT 3

#define caesar(x) rot(SHIFT, x)
#define decaesar(x) rot((26-SHIFT)%26, x)
#define decrypt_rot(x, y) rot((26-x), y)

void rot(int c, char *str, int len)
{
	//int l = strlen(str);
	const char *alpha[2] = { "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	
	int i;
	for (i = 0; i < len; i++)
	{
		// Make sure the current character is a letter
		if (!isalpha(str[i]))
			//continue;
			;
		
		// The following is incorrect but doesn't change the execution trace
		int pos_letter = tolower(str[i]) + 1; 
		int new_pos_letter = (pos_letter + c) % 26;
		int upper = isupper(str[i]) ? 1 : 0;
		//printf("%d %d %d %d\n", pos_letter, new_pos_letter, isupper(str[i]), upper);
		str[i] = alpha[upper][new_pos_letter];
	}
}


int main()
{
	char input[INPUT_SIZE];
	int byte_cnt = read(STDIN_FILENO, input, INPUT_SIZE);
	//char str[] = "This is a top secret text message!";
	
	//printf("Original: %s\n", input);
	rot(SHIFT, input, byte_cnt);
	//caesar(input);
	//printf("Encrypted: %s\n", input);
	//decaesar(input);
	//printf("Decrypted: %s\n", input);
	//printf("Input length: %d\n", strlen(input));
	
	return 0;
}
