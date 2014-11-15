/*
 ============================================================================
 Name        : LinkedListPreProcessor.c
 Author      : Shivan Kaul Sahib
 Version     : 1.0
 Description : Q3 on assignment 3 for COMP 206
 ============================================================================
 */
/*
 * The include files
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * Definitions
 */
#define MAX_LENGTH_WORD 20
#define ENGLISH
#define KASHMIRI

/*
 * Global structures
 */
typedef struct NODE {
	//	char word[MAX_LENGTH_WORD];
	char *word;
	struct NODE *next;
} node;

int main () {
	// define a node
	node *linked_list = malloc(sizeof(node));
	linked_list->next = malloc(sizeof(node));
	linked_list->word = malloc(MAX_LENGTH_WORD);

	node *head_node = malloc(sizeof(node));
	head_node->next = malloc(sizeof(node));
	head_node->word = malloc(MAX_LENGTH_WORD);

	head_node->next = linked_list;

	char exit[] = "***END***";
	printf("Welcome to the infinite string storage program.\n");
	printf("Please input a single word: \n");
	char *input;
	input = malloc(MAX_LENGTH_WORD);
	fgets(input, MAX_LENGTH_WORD, stdin);
	linked_list->word = strtok(input, " ");
	printf("word is: %s\n", linked_list->word);
	linked_list->word[strlen(linked_list->word)-1]='\0';
	//	linked_list->next = realloc(linked_list->next, sizeof(node));
	//	linked_list->word = realloc(linked_list->word, MAX_LENGTH_WORD);
	//	linked_list = realloc(linked_list, sizeof(node));
	printf("reached here\n");
	while (strcmp(linked_list->word, exit) != 0) {
		linked_list = linked_list->next;

		linked_list = malloc(sizeof(node));
		linked_list->next = malloc(sizeof(node));
		linked_list->word = malloc(MAX_LENGTH_WORD);

		printf("Please input a single word: \n");
		input = realloc(input, MAX_LENGTH_WORD);
		fgets(input, MAX_LENGTH_WORD, stdin);
		linked_list->word = strtok(input, " ");
		printf("word is: %s\n", linked_list->word);
		linked_list->word[strlen(linked_list->word)-1]='\0';
		//		linked_list = linked_list->next;
	}

	// Now, print out all the words

	return EXIT_SUCCESS;
}
