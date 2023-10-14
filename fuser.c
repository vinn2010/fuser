#include <stdio.h>
#include <sys/stat.h>

// the first arg is the number of arguements pasted
// to the function

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define CLEAR "\x1B[0m"

struct stat info;

int main(int argc, char **argv) {

  if(argc < 2 ) {
    //fprintf = allows string concat
    //must has stderr first
    fprintf(stderr, RED "Error: " CLEAR "provide a file\n" );
    printf("Usage: fuser <file>\n");
    return 1;
  }

  if(argc > 2) {
    fprintf(stderr, RED "Error: " CLEAR "Too many arguements\n" );
    printf("Usage: fuser <file>\n");
    return 1;
  }

  char *file = argv[1];
  //  getpwuid(file);

  printf("%s", file);
  return 0;
}
