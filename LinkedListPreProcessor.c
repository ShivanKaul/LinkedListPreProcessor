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
// Support for multiple languages
#define ENGLISH
//#define FRENCH

/*
 * Global structures
 */
typedef struct NODE {
	char *word;
	struct NODE *next;
} node;

// The head node into the linked list
node *head_node;

/* Helper function to add a node to the linked list.
 * Iterates through the list until it sees a null, creates a new node, then sets its data
 * to the word provided.
 */
void add_node(char *word) {
	node *curnode = (node *)malloc(sizeof(node));
	curnode->word = NULL;
	curnode = head_node;

	while(curnode->next != NULL) {
		curnode = curnode->next;
	}
	// found spot to add new node
	node *new_node = (node *)malloc(sizeof(node));
	new_node->word = (char *)malloc(sizeof(MAX_LENGTH_WORD));
	strcpy(new_node->word, word); // assign data
	new_node->next = NULL;
	curnode->next = new_node; // set
}

int main () {
	// string to end with
	char exit[] = "***END***";

	// define the linked list
	node *linked_list = (node *)malloc(sizeof(node));
	linked_list->word = (char *)malloc(sizeof(MAX_LENGTH_WORD));
	linked_list->next = NULL;

	// define the headnode of the linked list
	head_node = (node *)malloc(sizeof(node));
	head_node->word = (char *)malloc(sizeof(MAX_LENGTH_WORD));
	head_node->next = NULL;

	// get the first datum
#ifdef ENGLISH
	printf("Welcome to the infinite string storage program.\n");
	printf("Please input a single word: \n");
#else
	printf("Bienvenue dans le programme de stockage de chaîne infinie.\n");
	printf("Veuillez saisir un seul mot: \n");
#endif
	char *input;
	input = malloc(MAX_LENGTH_WORD);
	fgets(input, MAX_LENGTH_WORD, stdin);
	// get only the first word of the string that the user enters
	char *data = strtok(input, " ");
	// remove carriage returns
	if (data[strlen(data)-1]=='\n') {
		data[strlen(data)-1]='\0';
	}
	// set the data of the first node in our linked list
	strcpy(linked_list->word, data);

	// set the headnode to point to the first node of the linked list
	head_node->next = linked_list;

	// get the second word
#ifdef ENGLISH
	printf("Please input a single word: \n");
#else
	printf("Veuillez saisir un seul mot: \n");
#endif
	fgets(input, MAX_LENGTH_WORD, stdin);
	// again, get the first word of the string and remove carriage return
	data = strtok(input, " ");
	if (data[strlen(data)-1]=='\n') {
		data[strlen(data)-1]='\0';
	}
	while(strcmp(data, exit) != 0) {
		// add a new node to the linked list and add the data to it
		add_node(data);

		// get the next word
#ifdef ENGLISH
		printf("Please input a single word: \n");
#else
		printf("Veuillez saisir un seul mot: \n");
#endif
		fgets(input, MAX_LENGTH_WORD, stdin);
		data = strtok(input, " ");
		if (data[strlen(data)-1]=='\n') {
			data[strlen(data)-1]='\0';
		}
	}

	// Print everything
	while (head_node->next != NULL) {
		printf("%s ", head_node->next->word);
		head_node = head_node->next;
	}
	// print new line at the end
	printf("\n");
	return EXIT_SUCCESS;
}
