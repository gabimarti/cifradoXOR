/* 
	cifrado-archivo-xor.c
	
	Programa que lee un fichero binario o de texto de disco y cifra su 
	contenido usando operaciones XOR con una clave proporcionada.
	
	Formato:
	
		cifrado-archivo-xor.exe <archivo_a_cifrar> <clave> <archivo_destino>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ayuda(char *programa, char *msg);
int cifrado_xor(char *archivo_origen, char *clave, char *archivo_destino);

int cifrado_xor(char *archivo_origen, char *clave, char *archivo_destino) {
	FILE *forigen, *fdestino;
	int contador = 0;
	char byte;
	int long_clave = strlen(clave);
	
	if ((forigen=fopen(archivo_origen, "rb")) == NULL) {
		printf("No puedo abrir el archivo origen %s\n", archivo_origen);
		return 0;
	} 
	
	if ((fdestino=fopen(archivo_destino, "wb")) == NULL) {
		printf("No puedo abrir el archivo destino %s\n", archivo_destino);
		return 0;
	}  
	
	contador = 0;
	while(fread(&byte, sizeof(byte), 1, forigen) == 1) {
		byte = byte ^ clave[contador % long_clave];				
		if (!fwrite(&byte, sizeof(byte), 1, fdestino)) {
			printf("Error escribiendo el byte %d\n", contador);	
		}	
		contador++;
	} 
	
	if (fclose(fdestino)) {
		printf("Error cerrando archivo destino %s\n", archivo_destino);
	}	
	
	if (fclose(forigen)) {
		printf("Error cerrando archivo origen %s\n", archivo_origen);
	}	
	
	return 1;
}

void ayuda(char *programa, char *msg) {
	printf("\nPrograma que cifra el contenido de un archivo.\n"); 
	printf("\n");
	printf("\nERROR: %s\n\n", msg);
	printf("\nFormato de uso:\n\n");
	printf("\t%s <archivo_a_cifrar> <clave> <arhivo_destino>\n\n\n", programa);
	return;
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		ayuda(argv[0], "No se ha pasado el nombre de archivo a cifrar.");
		return 2;
	}
	
	if (argc < 3) {
		ayuda(argv[0], "No se ha pasado la clave de cifrado.");
		return 3;
	}
	
	if (argc < 4) {
		ayuda(argv[0], "No se ha pasado el nombre de archivo destino.");
		return 4;
	}
	
	if (!cifrado_xor(argv[1], argv[2], argv[3])) {
		printf("\nNo se ha podido des/cifrar el archivo %s\n", argv[1]);
		return 1;
	}

 	return 0;
}
