#include "colours.h"

void writing(FILE *todolist) {
  int i = 0;
  while (i == 0) {
  if (todolist != NULL) {
  int choice;
  char note[1000];
  printf("Colour?, 1. Red, 2. Blue, 3. Green, 4. Yellow, 5. Purple, 6. White\n");
  scanf("%i", &choice);
  
  printf("Write it and press enter!\n");
  scanf("%s", note);
  switch(choice) {
    case 1: 
      fprintf(todolist, "\nⵣ%s",note);
      break;
    case 2:
      fprintf(todolist, "\nⵥ%s",note);
      break;
    case 3:
      fprintf(todolist, "\nⵔ%s",note);
      break;
    case 4:
      fprintf(todolist, "\nⵙ%s",note);
      break;
    case 5:
      fprintf(todolist, "\nⴴ%s",note);
      break;
    default:
      fprintf(todolist, "\nⴳ%s",note);
      break;
    } 
  } else {
    FILE *todolist = fopen("todolist.txt", "w");
    fprintf(todolist, "hi");
    continue;
  }
  break;
  }
  fclose(todolist);
  main();
}
// ⵣ = Red
// ⵥ = Blue
// ⵙ = Yellow
// ⵔ = Green
// ⴴ = Purple
// ⴳ = White 
