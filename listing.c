#include "colours.h"

// Tafigh characters are written into the file to rate the importance of the issue!
int read_unicode(FILE *file, char *buffer) {
    int length = 1;
    buffer[0] = fgetc(file);

    if ((unsigned char)buffer[0] >= 0xF0) length = 4;
    else if ((unsigned char)buffer[0] >= 0xE0) length = 3;
    else if ((unsigned char)buffer[0] >= 0xC0) length = 2;

    for (int i = 1; i < length; i++) {
        buffer[i] = fgetc(file);
    }
    buffer[length] = '\0';

    return length;
}

void listing(FILE *todolist) {
    printf("\e[1;1H\e[2J");
    char c, c2;
    char unicode[5];
    int number = 1;
    bool empty = false;
    printf("%i. ", number);
    c = fgetc(todolist);
    if (c == EOF)  {
      fputs("TODOLIST!", todolist); 
    }
    ungetc(c,todolist);
    while ((c = fgetc(todolist)) != EOF) {
        if ((unsigned char)c >= 0x80) {
            ungetc(c, todolist);
            read_unicode(todolist, unicode);
            if (strcmp(unicode, "\u2D63") == 0) {   // ⵣ
                printf("%s", cred); 
            } 
            else if (strcmp(unicode, "\u2D65") == 0) { // ⵥ
                printf("%s", cblue);
            } 
            else if (strcmp(unicode, "\u2D59") == 0) { // ⵙ
                printf("%s", cyellow);
            } 
            else if (strcmp(unicode, "\u2D54") == 0) { // ⵔ
                printf("%s", cgreen);
            } 
            else if (strcmp(unicode, "\u2D34") == 0) { // ⴴ
                printf("%s", cpurple);
            } 
            else if (strcmp(unicode, "\u2D33") == 0) { // ⴳ
                printf("%s", cwhite);
        //etcetera
            } else {
                printf("%s", unicode);
            }
        } else {
            putchar(c);
        }
        
        c2 = fgetc(todolist);
        if (c == '\n' && c2 != EOF) {
            number++;
            printf("%i. ", number);
        }
        if (c2 != EOF) {
            ungetc(c2, todolist);
        }
    }
}

