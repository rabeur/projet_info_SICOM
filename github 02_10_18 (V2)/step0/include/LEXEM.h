#ifndef _LEXEM
#define _LEXEM



typedef struct lex {
  enum {[COMMENT], [NL], [SYMBOLE], [DIRECTIVE], [VAL_DECIMAL],
      [SYMBOLE], [REGISTRE], [VIRGULE],[STRING], [VAL_HEXA], [ERROR],[FT], [GUIL]} type;
  char content[512];
  int lign;
  char error[512];
} LEXEM;

#endif
