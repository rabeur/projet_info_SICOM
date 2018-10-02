#ifndef _LEXEM
#define _LEXEM



typedef struct lex {
  enum {
      COMMENT,
      NL,
      SYMBOLE,
      DIRECTIVE,
      VAL_DECIMAL,
      REGISTRE,
      COMA,
      STRING,
      VAL_HEXA,
      ERROR,
      FT,
      GUIL,
      PARENTO,
      PARENTC,
      DOT,
      EMPTY
         } type;
  char content[512];
  int lign;
  char error[512];
} LEXEM;

#endif
