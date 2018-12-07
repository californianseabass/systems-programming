#include "doenv.h"

extern char **environ;

int main(int argc, char *argv[]) {
  char **newEnviron;

  if (argc == 1) {
    for (int i = 0; environ[i] != NULL; i++) {
      printf("environ [%d]: %s\n", i, environ[i]);
    }
    return 0;
  }

  int environArraySize = 0;
  int additionalVarSize = 0;

  // if i is in there, we continue as we are
  if (strcmp(argv[1], "-i") != 0) {
    int i;
    for (i = 0; environ[i] != NULL; i++) { }
    environArraySize = i;
  }

  printf(" args : %d", argc);
  if (argc > 2) {
    int j;
    for (j = 3; strchr(argv[j], '=') != NULL; j++);
    additionalVarSize = j - 2;
  } else {
    additionalVarSize = 0;
  }

  if (strcmp(argv[1], "-i") != 0) { 
    int totalVariables = environArraySize + additionalVarSize;
    newEnviron = (char **) malloc(totalVariables * sizeof(char *));
    for (int i = 0; environ[i] != NULL; i++) {
      newEnviron[i] = (char *) malloc(strlen(environ[i]) * sizeof(char*));
      strcpy(newEnviron[i], environ[i]);
    }
  } else {
    printf("%d", additionalVarSize);
    newEnviron = (char **) malloc(additionalVarSize * sizeof(char *));
  }

  if (argc > 2) {
    for (int j = 2; strchr(argv[j], '=') != NULL; j++) {
      printf("%s\n", argv[j]);
      newEnviron[j] = (char*) malloc(strlen(argv[j]) * sizeof(char*));
      strcpy(newEnviron[j], argv[j]);
    }
  }

  return 0;
}
