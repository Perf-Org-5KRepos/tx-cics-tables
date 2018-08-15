/*
 * IBM Internal Use Only           T J C Ward       28 September 1993
 *
 * This is prototype code. It is supplies 'as is', and no responsibility
 * is accepted for completeness or correctness.
 *
 */

typedef struct
{
   int k0;
   int k1 ;
   short k2 ;
} dbkeys ;

#include <table_create.h>
#include <stdio.h>
static void dbi ( PAC_TABLE_WRITER *c, int k0 , int k1, short k2 , char * d )
{
   dbkeys dbk ;
   int r1 ;

   dbk.k0 = k0 ;
   dbk.k1 = k1 ;
   dbk.k2 = k2 ;

   EXEC_PAC_WRITE_TABLE
      TABLE(c)
      RIDFLD(&dbk)
      HASH_FUNCTION(rid_hash)
      FLENGTH(strlen(d)+1)
      FROM(d)
      RESP(r1)
   END_EXEC_PAC_WRITE_TABLE ;
}

int main(void) {
   PAC_TABLE_WRITER c ;
   int r0, r1, r2 ;
   int key = 1 ;
   char data [ 100 ] ;
   int count ;

   r0 = table_open( &c, "abcde", sizeof(dbkeys) ) ;

   dbi(&c, 9,8611,1, "key_1") ;
   dbi(&c, 9,8611,2, "key_2") ;
   dbi(&c, 9,8611,3, "key_3") ;
   dbi(&c, 9,8621,1, "key_4") ;
   dbi(&c, 9,8631,1, "key_5") ;
   dbi(&c, 9,8631,2, "key_6") ;
   dbi(&c, 9,8641,1, "key_7") ;
   dbi(&c, 9,8641,2, "key_8") ;
   dbi(&c, 9,8641,3, "key_9") ;
   dbi(&c, 9,8641,4, "key_a") ;
   dbi(&c, 9,8641,5, "key_b") ;

   r2 = table_close ( &c ) ;

   printf("Responses %i %i\n",
                 r0, r2
                 ) ;
   return 0 ;


}
