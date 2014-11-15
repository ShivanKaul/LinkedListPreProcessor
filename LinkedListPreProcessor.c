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

node *head_node;

void add_node(char *word) {
	node *curnode = (node *)malloc(sizeof(node));
	curnode->word = NULL;
	curnode = head_node;
	printf("curnode should be null: %s\n", curnode->word);
	while(curnode->next != NULL) {
		//		x->next->prev = x;
		curnode = curnode->next;
		printf("curnode should be h1: %s\n", curnode->word);
		printf("headnode points to node that should have value h1: %s\n", head_node->next->word);
	}
	node *new_node = (node *)malloc(sizeof(node));
	new_node->word = (char *)malloc(sizeof(MAX_LENGTH_WORD));
	strcpy(new_node->word, word);
	new_node->next = NULL;
	curnode->next = new_node;

	//	while (x->prev != NULL) {
	//		x = x->prev;
	//	}
}


int main () {
	char exit[] = "***END***";

	// define a node
	node *linked_list = (node *)malloc(sizeof(node));
	linked_list->word = (char *)malloc(sizeof(MAX_LENGTH_WORD));
	linked_list->next = NULL;

	head_node = (node *)malloc(sizeof(node));
	head_node->word = (char *)malloc(sizeof(MAX_LENGTH_WORD));
	head_node->next = NULL;


	printf("Welcome to the infinite string storage program.\n");
	printf("Please input a single word: \n");
	char *input;
	input = malloc(MAX_LENGTH_WORD);
	fgets(input, MAX_LENGTH_WORD, stdin);
	//	char data[MAX_LENGTH_WORD] = strtok(input, " ");
	char *data = strtok(input, " ");
	printf("data: %s\n", data);
	strcpy(linked_list->word, data);
	printf("word is: %s\n", linked_list->word);
	linked_list->word[strlen(linked_list->word)-1]='\0';

	head_node->next = linked_list;
	printf("first time, headnode points to node that has value: %s\n", head_node->next->word);


	printf("Please input a single word: \n");
	//	input = malloc(MAX_LENGTH_WORD);
	fgets(input, MAX_LENGTH_WORD, stdin);
	//	char data[MAX_LENGTH_WORD] = strtok(input, " ");
	data = strtok(input, " ");
	data[strlen(data)-1]='\0';
	printf("word is: %s\n", data);
	while(strcmp(data, exit) != 0) {
		add_node(data);
		printf("headnode: %s\n", head_node->word);
		printf("Please input a single word: \n");
		fgets(input, MAX_LENGTH_WORD, stdin);
		data = strtok(input, " ");
		data[strlen(data)-1]='\0';
		printf("word is: %s\n", data);
	}

	// Print everything
	while (head_node->next != NULL) {
		printf("%s\n", head_node->next->word);
		head_node = head_node->next;
	}

	//	linked_list->next = malloc(sizeof(node));
	//	linked_list->word = malloc(MAX_LENGTH_WORD);

	//	node *head_node = (node *)malloc(sizeof(node));
	//	head_node->next = malloc(sizeof(node));
	//	head_node->word = malloc(MAX_LENGTH_WORD);

	//	node *cur_node = (node *) malloc(sizeof(node));
	//	cur_node->next = malloc(sizeof(node));
	//	cur_node->word = malloc(MAX_LENGTH_WORD);

	/*
	 * Node headnode
	 * Node curnode
	 * Node nextnode
	 *
	 * headnode.next = curnode
	 * curnode.data = blah
	 * curnode.next = newnode
	 * curnode = newnode
	 */


	//	head_node->next = linked_list;
	//	head_node->word = "head node";

	//	char exit[] = "***END***";
	//	printf("Welcome to the infinite string storage program.\n");
	//	printf("Please input a single word: \n");
	//	char *input;
	//	input = malloc(MAX_LENGTH_WORD);
	//	fgets(input, MAX_LENGTH_WORD, stdin);
	//	//	char data[MAX_LENGTH_WORD] = strtok(input, " ");
	//	linked_list->word = strtok(input, " ");
	//	printf("word is: %s\n", linked_list->word);
	//	linked_list->word[strlen(linked_list->word)-1]='\0';
	//	head_node = linked_list;
	//	//	linked_list->next = cur_node;
	//	cur_node = linked_list;
	//	//	linked_list = cur_node->next;
	//	//	linked_list->next = realloc(linked_list->next, sizeof(node));
	//	//	linked_list->word = realloc(linked_list->word, MAX_LENGTH_WORD);
	//	//	linked_list = realloc(linked_list, sizeof(node));
	//	printf("reached here\n");
	//	while (strcmp(linked_list->word, exit) != 0) {
	//		//		linked_list = linked_list->next;
	//		//
	//		//		linked_list = (node *)malloc(sizeof(node));
	//		printf("head node has contents: %s\n", head_node->word);
	//		printf("cur node has contents: %s\n", cur_node->word);
	//		printf("linked list has contents: %s\n", linked_list->word);
	//
	//		printf("Please input a single word: \n");
	//		//		input = realloc(input, MAX_LENGTH_WORD);
	//		fgets(input, MAX_LENGTH_WORD, stdin);
	//		linked_list->word = strtok(input, " ");
	//		printf("word is: %s\n", linked_list->word);
	//		linked_list->word[strlen(linked_list->word)-1]='\0';
	//		cur_node->next = linked_list;
	//		cur_node = linked_list;
	//		//		cur_node = linked_list;
	//		//		linked_list = linked_list->next;
	//	}
	//	//	head_node = cur_node;
	//	printf("head node has contents: %s\n", head_node->word);

	// Now, print out all the words
	//	while (strcmp(head_node->word, exit) != 0) {
	//		printf("%s\n", head_node->word);
	//		head_node = head_node->next;
	//	}

	return EXIT_SUCCESS;
}
