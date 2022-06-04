/* 
	cifrado-cadena-xor.c
	
	Programa de ejemplo de cifrado XOR de una cadena
	usando otra cadena para cifrar.
*/

#include <stdio.h>
#include <string.h>

void cifrado_xor(char *cadena, char *clave, int long_cadena, int long_clave);
void imprime_cadena(char *cadena, int long_cadena);

// Cifrado y descifrado XOR
void cifrado_xor(char *cadena, char *clave, int long_cadena, int long_clave) {
	for (int pos = 0; pos < long_cadena; pos++) {
		cadena[pos] = cadena[pos] ^ clave[pos % long_clave];	
	}
}

// Imprime la cadena caracter a caracter en ASCII y debajo en hexadecimal
void imprime_cadena(char *cadena, int long_cadena) {
	for (int pos = 0; pos < long_cadena; pos++) {
		if (cadena[pos] >= 32 && cadena[pos] <= 126) {
			printf(" %c ", cadena[pos]);
		} else {
			printf(" . ");		// Evita imprimir caracteres que pueden ser problemáticos
		}
	}
	printf("\n");
	for (int pos = 0; pos < long_cadena; pos++) {
		printf("%02x ", cadena[pos]);	
	}
	printf("\n");
}

// Main
int main (int argc,char *argv[]) {
	char cadena_texto[] = "ESTAMOS FRENTE A UN GRAVE PROBLEMA";
	char clave[] = "barcelona";
	int long_cadena = strlen(cadena_texto);
	int long_clave = strlen(clave);

	printf("Texto original: %s\n", cadena_texto);
	printf(" Clave cifrado: %s\n\n", clave);
	
	printf("\nCadena cifrada:\n");
	cifrado_xor(cadena_texto, clave, long_cadena, long_clave);				// Cifra la cadena
	imprime_cadena(cadena_texto, long_cadena);
		
	printf("\nCadena descifrada:\n");	
	cifrado_xor(cadena_texto, clave, long_cadena, long_clave);				// Descifra la cadena
	imprime_cadena(cadena_texto, long_cadena);
		
 	return 0;
}
