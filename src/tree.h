#ifndef TREE
#define TREE
enum EXPRESSION
{
  NAME,
  TYPE,
  OR,
  AND,
  PRINT,
  EXEC,
  EXEC_DIR,
  PO,
  PC,
  NOT,
  NONE,
  ERROR
};
enum TYPE
{
  BLOCK,
  CHAR,
  DIREC,
  REG,
  SYM,
  PIPE,
  SOCK,
  ERROR_TYPE
};
struct expr{
    enum EXPRESSION expr;
    enum TYPE type;
    char **arg;
    char *func;
};
struct tree{
    struct tree *left;
    struct tree *right;
    struct expr *data;
};
#endif
