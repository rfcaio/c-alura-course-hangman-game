#include <stdio.h>
#include <string.h>

int main () {
  char secret[20], shot, shots[26];
  int tries = 0;

  sprintf(secret, "Cyrax");

  do {
    printf("\n***** ");
    for (int i = 0; i < strlen(secret); i++) {
      int found = 0;
      for (int j = 0; j < tries; j++) {
        if (shots[j] == secret[i]) {
          found = 1;
          break;
        }
      }
      found == 1 ? printf(" %c  ", secret[i]) : printf(" _  ");
    }
    printf("\n\n");
    printf("***** (%d) ENTER A LETTER ", tries + 1);
    scanf(" %c", &shot);
    shots[tries] = shot;
    tries++;
  } while (1);
}
