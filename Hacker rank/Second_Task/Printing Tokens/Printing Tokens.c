#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];

    // Read the entire line (including spaces)
    fgets(sentence, sizeof(sentence), stdin);

    // Tokenize by spaces and print each word
    char *word = strtok(sentence, " \n");
    while (word != NULL) {
        printf("%s\n", word);
        word = strtok(NULL, " \n");
    }

    return 0;
}
