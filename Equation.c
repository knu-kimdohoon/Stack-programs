#include <stdio.h>
void Read() {
	FILE* fp = NULL;
	int c;

	fp = fopen("data.txt", "r");

	if (fp == NULL) {
		printf("Failed");
	}
	else {
		printf("Success");
	}

	while ((c = fgetc(fp)) != EOF) {
		putchar(c);
	}

	fclose(fp);
}
void main() {
	FILE* fp = NULL;
	fp = fopen("data.txt", "w");

	if (fp == NULL) {
		printf("failed");
	}
	else {
		printf("success");
	}
	fputc('h', fp);
	fputc('e', fp);
	fputc('e', fp);
	fputc('e', fp);
	fputc('s', fp);
	fputc('c', fp);

	fclose(fp);

	Read();
}