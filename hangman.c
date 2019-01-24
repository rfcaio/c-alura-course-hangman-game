#include <stdio.h>
#include <string.h>

void choose_your_destiny (char* secret_word) {
  sprintf(secret_word, "scorpion");
}

int is_correct_attempt (char* attempted_letters, char letter, int attempts) {
  for (int i = 0; i < attempts; i++) {
    if (attempted_letters[i] == letter) {
      return 1;
    }
  }
  return 0;
}

void show_score (char* secret_word, char* attempted_letters, int attempts) {
  printf("\n***** ");
  for (int i = 0; i < strlen(secret_word); i++) {
    is_correct_attempt(attempted_letters, secret_word[i], attempts) == 1 ? printf(" %c  ", secret_word[i]) : printf(" _  ");
  }
}

void show_intro () {
  printf("\n*****\n");
  printf("***** WELCOME TO HANGMAN GAME\n");
  printf("*****\n\n");
}

void try_a_letter (char* attempted_letters, int* attempts) {
  char letter;
  printf("\n\n");
  printf("***** (%d) ENTER A LETTER ", (*attempts) + 1);
  scanf(" %c", &letter);
  attempted_letters[(*attempts)] = letter;
  (*attempts)++;
}

int main () {
  char secret_word[20], attempted_letters[26];
  int attempts = 0;
  choose_your_destiny(secret_word);
  show_intro();
  do {
    show_score(secret_word, attempted_letters, attempts);
    try_a_letter(attempted_letters, &attempts);
  } while (1);
}
