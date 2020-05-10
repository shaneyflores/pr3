//****************************************************
// test.c
// AUTHOR: Shaney Flores  
// COURSE: CMPSCI2750-002
//
// DESCRIPTION: Test program for linked list functions
//****************************************************
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
int main()
{

	int option, value; 
	Node * lnlist = NULL; // must initialize it to NULL  
	bool done = false; //boolean to terminate 

	do {

		printf("\e[1;1H\e[2J"); //clear screen

		// display menu and ask for selection
		printf("\nLINKED LIST OPERATIONS\nMenu Selection:\n");
		printf("-------------------------\n");
		printf("[1] Insert head\n");
		printf("[2] Insert tail\n");
		printf("[3] Delete a node\n");
		printf("[4] Delete all\n");
		printf("[5] Display\n");
		printf("[6] Exit\n");
		printf("-------------------------\n");
		printf("Please select an operation: ");
		scanf("%d", &option);

		//printf("You selected operation number %d \n", option); //line for debugging
		
		// validate input
		while( option > 6 || option < 1) {
			printf("[Invalid selection] Please select an operation: ");
			scanf("%d", &option);
		} 

		// ask for integer if menu option 1, 2, or 3 selected
		if(option == 1 || option == 2 || option == 3) {
			printf("Enter a single integer: ");
			scanf("%d", &value);
		}

		// call functions
		switch(option) {
			case 1: { //Insert head
				lnlist = List_insert(lnlist, value);
				break; }
			case 2: { //Insert tail
				lnlist = List_insert_last(lnlist, value);
				break; }
			case 3: { //Delete node
				lnlist = List_delete(lnlist, value);
				break; } 
			case 4: { //Delete all
				List_destroy(lnlist);
				break; }
			case 5: {  //Display
				List_print(lnlist);
				break; }
			case 6: { //Exit
				done = true;
				break; }
		}

		if(option != 6) {
			printf("Press [ENTER] to continue.");
			getchar();
			getchar();
		}

	} while(!done);


	return EXIT_SUCCESS;
}