#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define BUF_SIZE 1024

bool is_vowel(char C) {
	char c = tolower(C);
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int copy_non_vowels (int num_chars, char* in_buf, char* out_buf) {
	int non_vowel = 0;
	for (int i = 0; i < num_chars; i++) {
		if(!is_vowel(in_buf[i])) {
			out_buf[non_vowel] = in_buf[i];
			non_vowel++;
		}
	}
	return non_vowel;
}

void disemvowel (FILE* inputFile, FILE* outputFile) {
	char *in_buffer = (char*)calloc(BUF_SIZE, sizeof(char));
	char *out_buffer = (char*)calloc(BUF_SIZE, sizeof(char));
	int read = 0;
	do { 
		
		read = fread(in_buffer, sizeof(char), BUF_SIZE, inputFile);
		int non_vowels = copy_non_vowels(read, in_buffer, out_buffer);
		fwrite(out_buffer, sizeof(char), non_vowels, outputFile);
	} while(read == BUF_SIZE);
	free(in_buffer);
	free(out_buffer);
	
}

int main (int argc, char *argv[]) {

	FILE *inputFile;
	FILE *outputFile;
	
	if(argc >= 2) {
		inputFile = fopen(argv[1], "r+");
	} else {
		inputFile = stdin;
	}

	if (argc >= 3) {
		outputFile = fopen(argv[2], "w+");
	} else {
		outputFile = stdout;
	}
	disemvowel(inputFile, outputFile);

	if(argc >= 2) {
		fclose(inputFile);
	}
	if(argc >= 3) {
		fclose(outputFile);
	}
	return 0;
}
