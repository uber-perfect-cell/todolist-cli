void linedeletion(FILE *todolist) {

  FILE *temp =fopen(".temp_todolist.txt", "w");
  char lineLength[2048];
  int lineDelete= 0;
  int currentLine = 0;

  printf("Task to delete? \n"); 
  scanf("%i", &lineDelete);

  bool reading = true;

  if (temp == NULL) {
    printf("Troubles writing or deleting data in the folder. Make sure write acces is granted!");
  }

  do {
    fgets(lineLength, 2048, todolist);
    
    if(feof(todolist)) {
      reading = false;
    } else if (currentLine != lineDelete) {
      fputs(lineLength, temp);
    }
    currentLine++;
  } while(reading);

    
  fclose(temp);
  fclose(todolist);

  remove("todolist.txt");
  rename(".temp-todolist.txt", "todolist.txt");
  main();
}
