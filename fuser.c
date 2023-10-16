#include <stdio.h>
#include <unistd.h> // for access function

#include <sys/stat.h> // stat(function)
#include <pwd.h>

// the first arg is the number of arguements pasted
// to the function
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define CLEAR "\x1B[0m"

int main(int argc, char **argv) {

  char *file;
  file = argv[1];

  if(argc < 2 ) {
    //fprintf = allows string concat
    //must has stderr first
    fprintf(stderr, RED "Error: " CLEAR "provide a file\n" );
    printf("Usage: fuser <file>\n");
    return 1;
  }

  if(argc > 2) {
    printf("%sError:%s Too many arguements\n", RED, CLEAR );
    printf("Usage: fuser <file>\n");
    return 1;
  }

  // access comes from unistd.h
  // it checks if the file exists
  if(access(file, F_OK) == -1) {
    // fprintf allows for string concat
    fprintf(stderr, RED "Error: " CLEAR "the file" RED " '%s' " CLEAR "does not exist", argv[1]);
    return 1;
  }

  struct stat st;

  // file and address of the st stat struct
  // the stat function gets unix info about the file
  // and passes it to the stat struct
  stat(file, &st);
  // st returns numericl values that represent the user info.
  // eg - st.st_uid = 1001 for vinn
  // to convert it we need pwd.h
  // which provides the struct passwd

  struct passwd *user = getpwuid(st.st_uid);
  // user is now a struct with decoded user info

  printf("%s", user->pw_name);
  // pw_name is one of the members of the passwd struct

  //lets also add the group
  return 0;
}





