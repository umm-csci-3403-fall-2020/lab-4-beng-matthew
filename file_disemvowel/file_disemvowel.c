#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 1024

bool is_vowel(char C) {
	char c = tolower(C);
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int copy_non_vowels (int num_chars, char* in_buf, char* out_buf) {
	char *buffer = char[1];
	int non_vowel = 0;
	for (int i = 0; i < num_chars; i++) {
	  	fread(buffer, sizeof('char'), 1, inputFile);
		if(is_vowel(&buffer[0])) {
			fwrite(buffer, sizeof('char'), 1, outputFile);
			nonVowel++;
	 	}
	}
	free(buffer);
	fclose(in);
	return nonVowel;
}

void disemvowel (FILE* inputFile, FILE* outputFile) {

}

int main (int argc, char *argv[]) {

	FILE *inputFile = 'stdin';
	FILE *outputFile = 'stdout';

	disemvowel(inputFILE, outputFILE);

	return 0;
}
