
#include <stdio.h>

int main(int argc, char *argv[]) {
  // This is my first C program  in github
  printf("Hello, My name is nandu!\n");
  printf("You passed %d argument(s).\n", argc - 1);
  for (int i = 1; i < argc; ++i) {
    printf("  arg[%d] = %s\n", i, argv[i]);
  }
  return 0;
}
