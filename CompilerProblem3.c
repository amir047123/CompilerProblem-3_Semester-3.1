#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char* word) {
    char keywords[][20] = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while"
    };
    
    int totalKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < totalKeywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1; // It's a keyword
        }
    }

    return 0; // Not a keyword
}

int isIdentifier(char* word) {
    if (!isalpha(word[0]) && word[0] != '_') {
        return 0; // Doesn't start with a letter or underscore
    }

    for (int i = 1; i < strlen(word); i++) {
        if (!isalnum(word[i]) && word[i] != '_') {
            return 0; // Contains invalid characters
        }
    }

    return 1; // It's an identifier
}

int isOperator(char* word) {
    char operators[][5] = {
        "+", "-", "*", "/", "%", "=", "==", "!=", "<", ">", "<=", ">="
    };

    int totalOperators = sizeof(operators) / sizeof(operators[0]);

    for (int i = 0; i < totalOperators; i++) {
        if (strcmp(word, operators[i]) == 0) {
            return 1; // It's an operator
        }
    }

    return 0; // Not an operator
}

int isConstant(char* word) {
    int len = strlen(word);

    for (int i = 0; i < len; i++) {
        if (!isdigit(word[i]) && word[i] != '.' && word[i] != '-') {
            return 0; // Contains invalid characters
        }
    }

    return 1; // It's a constant
}

int main() {
    char input[100];

    printf("Enter a word: ");
    scanf("%s", input);

    if (isKeyword(input)) {
        printf("Output: Keyword\n");
    } else if (isIdentifier(input)) {
        printf("Output: Identifier\n");
    } else if (isOperator(input)) {
        printf("Output: Operator\n");
    } else if (isConstant(input)) {
        printf("Output: Constant\n");
    } else {
        printf("Output: Undefined\n");
    }

    return 0;
}
