#include <stdio.h>

using namespace std;

#define MAX_S_SIZE 101

int main(void) {
  char s[101];
  scanf("%50[^\n]s", s);
  printf("Thank you, %s, and farewell!\n", s);
  return 0;
}
