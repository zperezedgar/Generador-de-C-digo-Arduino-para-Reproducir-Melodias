///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////															///////////////////////////////
///////////////////////////   Generador de Código Arduino para Reproducir Melodias      ///////////////////////////////
///////////////////////////																///////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/************************************************************************************************************************
INSTRUCCIONES:
-Se limita el tipo de compas a los de la forma n/4, donde n=1,2,3,4, etc
-las notas son leídas de un archivo de texto donde son colocados de manera descendente
-Las notas se ingresan el en el siguiente formato: XS#y    , donde
X (en mayuscula) puede ser A,B,C,D,E,F,G y representan una nota en el sistema americano
S representa una alteracion (sostenido)
# (entero) representa el numero de octava que puede ser desde B0 hasta DS8
y (en minuscula) representa el tiempo de duración de dicha nota que puede ser
	b blanca
	r redonda
	n negra
	c corchea
	s semicorchea
	f fusa
	e semifusa
	t tresillo
	i seisillo
	g garrapatea
	a tresillo de corchea
	d tresillo de semicorchea
-En caso de que la nota no presente alteracion el formato es el siguiente: X#y.   , donde
donde las reglas son las mismas que las anteriores, lo unico es que se debe agregar un punto al final de los caracteres
 -El formato para un silencio es: Sy..      ,donde
S (mayuscula) indica que se trata de un silencio 
y (en minuscula) representa la duracion del silencio (mismas reglas que con las notas)
*************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "notas.h"
#include "fxnotas.h"


char c_cancion[80]; //Cadena para guardar el nombre de la cancion 
FILE* fichero;	//Archivo con la canción en caracteres
FILE* fichero2;	//Archivo para Arduino
volatile int i_velocidad; //Velocidad de reproduccion en BPM
volatile float f_tono;	//Tono de la cancion
volatile int i_trabajar=1;	//Variable para continuar la ejecución del programa

int main(int argc, char *argv[]) 
{
	system("color 0a");
	system("title Generador de Codigo Arduino para Melodias");
	
	do
	{	
		printf("---------------------------------------------------\n");
		printf("BIENVENIDO AL DIGITALIZADOR DE PARTITURAS MUSICALES\n");
		printf("---------------------------------------------------\n\n");	
		
		do
		{
			//Solicitamos cancion y abrimos el archivo
			fichero=fopen(pidecancion(c_cancion),"rt");
			//Verificamosque el archivo solicitado exista o no
			existefichero(fichero);
		}while(fichero==NULL);
		
		//Abrimos archivo para Arduino
		fichero2=fopen("Melodia-Arduino.ino","wt");
		
		
		/*************************************************************************/
		i_velocidad=tiempo(); //elegimos el tiempo de reproduccion
		f_tono=transportar();	//elegimos el tono de reproduccion
		melodia(fichero, fichero2, i_velocidad, f_tono);	//creamos la melodia
		/***************************************************************************/
		
		
		//Cerramos Archivos
		fclose(fichero);
		fclose(fichero2);
		
		//Preguntamnos si se vuelve a ejecutar el programa o no
		i_trabajar=final(); 
		
		system("cls");
	} while(i_trabajar==1);
	
	printf("Hasta la Proxima!\n");
	
	system("PAUSE");
	return 0;
}
