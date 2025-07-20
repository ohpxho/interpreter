#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_prompt();
void run_file(const char* path);
void run(const char *source);

typedef struct {
    char *type;
    char *lexeme;
} Token;

int main(int argc, char* argv[]) {
    if(argc > 2) {
        printf("Usage: %s [path]\n", argv[0]);
        return 1;
    } else if(argc == 2) {
        run_file(argv[1]);
    } else {
        run_prompt();
    }
    return 0;
}

int scanTokens(const char *source, Token **tokens_out) {
    *tokens_out = malloc(sizeof(Token) * 1);
    (*tokens_out)[0].type = "DUMMY_TOKEN";
    (*tokens_out)[0].lexeme = "dummy";
    return 1;  
}

void run(const char *source) {
    Token *tokens = NULL;
    int tokenCount = scanTokens(source, &tokens);

    for (int i = 0; i < tokenCount; i++) {
        printf("Token(type=%s, lexeme=%s)\n", tokens[i].type, tokens[i].lexeme);
    }

    free(tokens);  
}

void run_file(const char* path) {
    FILE *file = fopen(path, "rb");if (!file) {
        fprintf(stderr, "Could not open file \"%s\".\n", path);
        exit(1);
    }

    fseek(file, 0L, SEEK_END); //set the file position at the end of the stream
    long fileSize = ftell(file); //get the position 
    rewind(file); //take the position of the file at the beginning

    char *buffer = (char *) malloc(fileSize + 1);
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

void run_prompt() {
    char line[1024];
    
    for(;;) {
        printf("> ");
        if(fgets(line, sizeof(line), stdin) == NULL) break; 
        run(line); 
    }
}

