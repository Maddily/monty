#include "monty.h"

int main(int argc , char *argv[])
{
	FILE *file;
	size_t length = 0;
	char *line = NULL;
	char *filename = argv[1];
	ssize_t read;
	int line_number = 1;

	if (argc < 2) /*to do: add a check for recieving more than 2 arguments*/
		/*suggested: if (argc != 2)*/
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &length, file)) != -1)
	{
		/*process file*/
		line_number++;
	}
	free(line);
	fclose(file);
	return (0);
}

int process_file(int line_number, char *filename)
{
	/*search for opcode*/
		/*create an array with opcode and function*/
	/*implement opcode function*/
		/* in seperate files to reduce line count*/
		/* If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE*/
	/*return to main, free memory and close file*/

}
