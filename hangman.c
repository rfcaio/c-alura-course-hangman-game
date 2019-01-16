#include <stdio.h>
#include <string.h>

void choose_your_destiny (char* secret) {
  sprintf(secret, "scorpion");
}

int is_successful_shot (char* shots, char shot, int tries) {
  for (int i = 0; i < tries; i++) {
    if (shots[i] == shot) {
      return 1;
    }
  }
  return 0;
}

void show_score (char* secret, char* shots, int tries) {
  printf("\n***** ");
  for (int i = 0; i < strlen(secret); i++) {
    is_successful_shot(shots, secret[i], tries) == 1 ? printf(" %c  ", secret[i]) : printf(" _  ");
  }
}

void show_intro () {
  printf("\n*****\n");
  printf("***** WELCOME TO HANGMAN GAME\n");
  printf("*****\n\n");
}

void take_a_shot (char* shots, int* tries) {
  char shot;
  printf("\n\n");
  printf("***** (%d) ENTER A LETTER ", (*tries) + 1);
  scanf(" %c", &shot);
  shots[(*tries)] = shot;
  (*tries)++;
}

int main () {
  char secret[20], shot, shots[26];
  int tries = 0;
  choose_your_destiny(secret);
  show_intro();
  do {
    show_score(secret, shots, tries);
    take_a_shot(shots, &tries);
  } while (1);
}
