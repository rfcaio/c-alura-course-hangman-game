#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "hangman.h"

void choose_your_destiny (char* secret_word) {
  FILE* f = fopen("fighters.txt", "r");
  if (f == 0) {
    printf("***** SORRY, FIGHTERS NOT LOADED.\n");
    exit(1);
  }
  int quantity_of_fighters;
  fscanf(f, "%d", &quantity_of_fighters);
  srand(time(0));
  int randomic_number = rand() % quantity_of_fighters;
  for (int i = 0; i <= randomic_number; i++) {
    fscanf(f, "%s", secret_word);
  }
  fclose(f);
}

int has_hanged (char* secret_word, char* attempted_letters, int attempts) {
  int errors = 0;
  for (int i = 0; i < attempts; i++) {
    int exists = 0;
    for (int j = 0; j < strlen(secret_word); j++) {
      if (attempted_letters[i] == secret_word[j]) {
        exists = 1;
        break;
      }
    }
    if (!exists) {
      errors++;
    }
  }
  return errors > 5;
}

int has_win (char* secret_word, char* attempted_letters, int attempts) {
  for (int i = 0; i < strlen(secret_word); i++) {
    if (!is_correct_attempt(attempted_letters, secret_word[i], attempts)) {
      return 0;
    }
  }
  return 1;
}

int is_correct_attempt (char* attempted_letters, char letter, int attempts) {
  for (int i = 0; i < attempts; i++) {
    if (attempted_letters[i] == letter) {
      return 1;
    }
  }
  return 0;
}

void show_intro () {
  printf("\n*****\n");
  printf("***** WELCOME TO HANGMAN GAME\n");
  printf("*****\n\n");
}

void show_score (char* secret_word, char* attempted_letters, int attempts) {
  printf("\n***** ");
  for (int i = 0; i < strlen(secret_word); i++) {
    is_correct_attempt(attempted_letters, secret_word[i], attempts) == 1 ? printf(" %c  ", secret_word[i]) : printf(" _  ");
  }
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
  } while (!has_win(secret_word, attempted_letters, attempts) && !has_hanged(secret_word, attempted_letters, attempts));
}
