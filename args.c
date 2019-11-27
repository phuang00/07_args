#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char ** parse_args( char * line ){
  int i = 0;
  char * curr = line;
  char ** tokens = malloc(6 * sizeof(curr));
  while (curr != NULL){
    tokens[i] = strsep(&curr, " ");
    i++;
  }
  tokens[i] = NULL;
  return tokens;
}

int main() {
  char line[100] = "ls -a -l";
  printf("Command to be parsed: %s\n", line);
  char ** args = parse_args(line);
  printf("Command parsed, about to run command ...\n");
  execvp(args[0], args);
  return 0;
}
