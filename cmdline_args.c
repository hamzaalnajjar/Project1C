// cmdline_args.c: demonstrates how main() receives command line
// arguments in the argv[] array and the number of arguments is
// conveyed in argc.  Try running this program with various numbers
// kinds of command line arguments like the following examples
//
// > gcc cmdline_args.c
// > ./a.out
// There are 1 command line arguments
// arg 0: './a.out'
// > ./a.out apple banana peach
// There are 4 command line arguments
// arg 0: './a.out'
// arg 1: 'apple'
// arg 2: 'banana'
// arg 3: 'peach'
// > ./a.out apple "hello world" "buh bye now"
// There are 4 command line arguments
// arg 0: './a.out'
// arg 1: 'apple'
// arg 2: 'hello world'
// arg 3: 'buh bye now'


#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

  int theoption = 0;
  printf("There are %d command line arguments\n",argc);
  for(int i=0; i<argc; i++){
    printf("arg %d: '%s'\n",i,argv[i]);
    if( strcmp(argv[i],"--theoption")==0 ){
      printf("arg %d is --theoption, turning on theoption\n",i);
      theoption = 1;
    }

  }

  if(theoption){
    printf("The option was set: HURRAY!\n");
  }
  return 0;
}
