#ifndef _LEXEM
#define _LEXEM



typedef struct lex {
  enum {[COMMENT], [NL], [SYMBOLE], [DIRECTIVE], [VAL_DECIMAL],
    [SYMBOLE], [REGISTRE], [VIRGULE], [VAL_HEXA]} type;
  char content[512];
  int lign;
} LEXEM;

#endif
