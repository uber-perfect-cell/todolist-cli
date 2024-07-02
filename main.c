//system headers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "colours.h"

//values
char option[10]; 


//files
#include "listing.c"
#include "writing.c"
#include "deletion.c"

int main() {
  printf("%shi\n%s", cred, cwhite);
  printf("%shi\n%s", cred, cwhite);
  FILE *todolist = fopen("todolist.txt", "r+");
  if (todolist == NULL) {
    printf("%stodolist.txt not found, creating it\n", cyellow);
    system("touch todolist.txt"); 
    int succes = system("touch todolist.txt");
  } else {
    printf("%stodolist.txt found\n", cgreen);
  }
  printf("\e[1;1H\e[2J");
  printf("View list now?\n");
  scanf("%4s", &option);
  if (strcmp(option, "view") == 0) {
    listing(todolist);
  }
    printf("%s\nPress Enter key to quit, Type d to remove lines, Type a to add new lines!\n", cwhite);
  fflush(stdout); 
  int ch;
  while ((ch = getchar()) != '\n'); 
  while (1) {
    ch = getchar();
      if (ch == 'd') {
        linedeletion(todolist);
      } else if (ch == 'a') {
        writing(todolist);
      } else if (ch == '\n') {
        printf("%s", cwhite);
        break;         
      }
  }

    fclose(todolist);
    return 0;
}
