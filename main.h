#ifndef main_h
#define main_h
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
int _len(char *buffer);
void _exec(char **args);
char **parse(char *buf_cpy, char *buffer);
#endif
