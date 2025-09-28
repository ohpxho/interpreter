#include "../include/scanner.h"
#include "../include/token.h"
#include "../lib/ut/utarray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_prompt(void);
void run_file(const char *path);
void run(const char *source);
void error(int line, char *message);
void report(int line, const char *where, char *message);

int main(int argc, char *argv[]) {
  if (argc > 2) {
    printf("Usage: %s [path]\n", argv[0]);
    return 1;
  } else if (argc == 2) {
    run_file(argv[1]);
  } else {
    run_prompt();
  }
  return 0;
}

// TODO: make this shit run
void run(const char *source) {
  UT_array *tokens;
  UT_icd token_icd = {sizeof(Token), NULL, NULL, NULL};

  utarray_new(tokens, &token_icd);

  Scanner scanner = {.source = source, .tokens = tokens};

  scanTokens(&scanner);

  Token *p = NULL;
  
  while((p = (Token *)utarray_next(scanner.tokens, p))) {
    printf("%s\n", tokenToString(p));
  }
  
  utarray_free(tokens);
}

void run_file(const char *path) {
  FILE *file = fopen(path, "rb");
  if (!file) {
    fprintf(stderr, "Could not open file \"%s\".\n", path);
    exit(1);
  }

  fseek(file, 0L, SEEK_END);   // set the file position at the end of the stream
  long fileSize = ftell(file); // get the position
  rewind(file);                // take the position of the file at the beginning
  char *buffer = (char *)malloc(fileSize + 1);
  if (!buffer) {
    fprintf(stderr, "Not enough memory to read \"%s\".\n", path);
    exit(1);
  }

  size_t bytesRead = fread(buffer, 1, fileSize, file);
  buffer[bytesRead] = '\0';

  fclose(file);

  run(buffer);
  free(buffer);
}

void run_prompt(void) {
  char line[1024];

  for (;;) {
    printf("> ");
    if (fgets(line, sizeof(line), stdin) == NULL)
      break;
    run(line);
  }
}

void error(int line, char *message) { report(line, "", message); }

void report(int line, const char *where, char *message) {
  printf("[line: %d ] Error %s: %s", line, where, message);
}
