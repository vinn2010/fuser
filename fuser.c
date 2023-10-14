#include <stdio.h>

// the first arg is the number of arguements pasted
// to the function
int main(int argc, char **argv) {
  printf("%d\n", argc);
  printf("%s\n", argv[1]);
  printf("%s\n", argv[2]);
  printf("%s\n", argv[3]);
  printf("%s\n", argv[4]);
  return 0;
}
