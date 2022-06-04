/*
	xorbyte.c
*/

#include <stdio.h>

#define B2BIF "%c%c%c%c%c%c%c%c"
#define B2BIN(byte) (byte & 0x80 ? '1' : '0'), \
                    (byte & 0x40 ? '1' : '0'), \
                    (byte & 0x20 ? '1' : '0'), \
                    (byte & 0x10 ? '1' : '0'), \
                    (byte & 0x08 ? '1' : '0'), \
                    (byte & 0x04 ? '1' : '0'), \
                    (byte & 0x02 ? '1' : '0'), \
                    (byte & 0x01 ? '1' : '0')

int main(int argc, char *argv[]) {
   char m='A';		// Mensaje
   char k='t';		// Clave
   char c=m^k;		// Cifrado (se aplica XOR sobre mensaje original usando clave k)
   char d=c^k;		// Descrifrado (misma operación de XOR usando la misma clave sobre byte cifrado)

   printf("       Mensaje (m) '%c' %02x "B2BIF"\n", m, m, B2BIN(m));
   printf("         Clave (k) '%c' %02x "B2BIF"\n", k, k, B2BIN(k));
   printf("   Cifrado m XOR k '%c' %02x "B2BIF"\n", c, c, B2BIN(c));
   printf("Descifrado c XOR k '%c' %02x "B2BIF"\n", d, d, B2BIN(d));
   return 0;
}
