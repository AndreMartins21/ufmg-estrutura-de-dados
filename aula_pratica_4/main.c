#include <stdio.h>
#include <stdlib.h>
typedef struct foo {
	int flag1; int flag2;  int size; int **buf;
} foo;
void print_buf(struct foo *s){
   printf("buf[0][0]: %d\n", s->buf[0][0]);
   s->flag1 = 1;
   s->flag2 = 2;
   free(s->buf);
}
void setup_foo(struct foo *s){
	s->flag2 = 2;
    for (int i = 0; i < 20; i++) {
        s->buf[i] = malloc(20 * sizeof(int)); // Allocate memory for 20 ints
        for (int j = 0; j < 20; j++) {
            s->buf[i][j] = 0; // Initialize each element to 0
        }
    }
}


int main(void){
   struct foo s;
   setup_foo(&s);
   print_buf(&s);
   if (s.flag1 || s.flag2)
   	printf("hey\n");
   return 0;
}
