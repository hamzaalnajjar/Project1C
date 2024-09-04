#include "banlet.h"

int main(int argc, char *argv[]){
  if(argc < 2){
    printf("usage: %s '<text>'\n",argv[0]);
    printf("       %s '<text>' --fontfile <fontfile>\n",argv[0]);
    printf("       %s --textfile <textfile>\n",argv[0]);
    printf("       %s --textfile <textfile> --fontfile <fontfile>\n",argv[0]);
    printf("Arguments can appear in any order only one of <text> or <textfile> can be used\n");
    printf("\n");
    printf("Note: In some shells, embedded newline \\n characters, require\n");
    printf("the syntax $'text' as in\n");
    printf("        %s $'HELLO\\nWORLD\\n!!!'\n",argv[0]);
    printf("to be treated correctly. This is NOT necessary on grace.umd.edu\n");
    printf("This is NOT necessary on grace.umd.edu where the syntax\n");
    printf("        %s 'HELLO\\nWORLD\\n!!!'\n",argv[0]);
    printf("will behave correctly to embed newlines due to tcsh being used.\n");
    return 1;
  }

  char *text = NULL;
  int use_textfile = 0;
  font_t *font = &font_standard;

  for(int i = 1; i < argc; i++){
    if(strcmp(argv[i], "--fontfile") == 0 && i + 1 < argc){
      font = font_load(argv[++i]);
      if(font == NULL){
        fprintf(stderr, "Error loading font file '%s'\n", argv[i]);
        return 1;
      }
    } else if(strcmp(argv[i], "--textfile") == 0 && i + 1 < argc){
      text = slurp_file(argv[++i]);
      if(text == NULL){
        fprintf(stderr, "Error loading text file '%s'\n", argv[i]);
        return 1;
      }
      use_textfile = 1;
    } else {
      text = argv[i];
    }
  }

  if(text == NULL){
    fprintf(stderr, "Error: No text to print.\n");
    return 1;
  }

  print_fontified(text, font);

  if(use_textfile && text != NULL){
    free(text);
  }
  if(font != &font_standard){
    font_free(font);
  }

  return 0;
}
