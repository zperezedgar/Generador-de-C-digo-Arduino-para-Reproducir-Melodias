#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********************************************
*											*
*				FUNCIONES					*
*											*
*********************************************/


//*******************************PROTOTIPOS DE FUNCIONES*********************************//
float duracion_tone(int velocidad_reproduccion, char nota);	
unsigned int frecuencia(int frec_original, float num_tonos_cambiar);
void error(char *texto_con_error);
void imprime_codigo_arduino(FILE *archivo_arduino, int tonos_a_cambiar, float duracion);



//Funcion para solicitar una cancion
char *pidecancion(char *nombre)
{
	memset(nombre,'\0', sizeof(nombre)); //Limpiamos cadena cancion
	printf("*Introduzca el Nombre de la Cancion que desea Digitalizar\n");
	gets(nombre);
	strcat(nombre,".txt"); //Agregamos extension del archivo
	return nombre;
}

//Funcion para verificar que existe el archivo de la cancion solicitada
void existefichero(FILE *archivo)
{
	if(archivo==NULL)
    printf("\nLa Cancion solicitada no se encuentra!\n");
}

//Funcion para elegir el tiempo de reproduccion
int tiempo()
{
	int tiempo_velocidad;
	printf("\n*Ingrese el tiempo al que quiere reproducir la Cancion en BPM\n");
	scanf("%i", &tiempo_velocidad);
	return tiempo_velocidad;
}

//Funcion para elegir el tono de reproduccion
float transportar()
{
	int cambiar;
	int num_tonos=0;
	
	printf("\n*Desea cambiar el Tono de la cancion?\n1:\tSi\n2:\tNo\n");
	scanf("%i", &cambiar);
	
	if(cambiar==1)
	{	
		printf("\n*Ingrese cuantos Tonos quiere transportar la Cancion\n");
		printf("(Ingrese un multiplo de 0.5 con o sin signo)\n");
		scanf("%i", &num_tonos);
	}
	
	return num_tonos;
}

//Funcion para crear la melodia para arduino
void melodia(FILE *archivo_cancion, FILE *archivo_arduino, int vel_reproduccion, float cambiar_tonos)
{
	char caracteristicas_nota[4];
	
	struct propiedades_nota
	{	
		char octava[1];	
		char nota[1];	
		char tiempo[1];
	};
	
	struct propiedades_nota con_alteracion;
	struct propiedades_nota sin_alteracion;
	
	
	fputs("void setup() {\n}\n\nvoid loop() {\n", archivo_arduino);
	
	while(!feof(archivo_cancion))
	{
		memset(caracteristicas_nota,'\0', sizeof(caracteristicas_nota)); //Limpiamos cadena buffer
		fscanf(archivo_cancion, "%s", caracteristicas_nota);	//leemos un renglon del archivo con la cancion 
		
		
		//********************************************************************//
					//**Caso en que la nota es un silencio**//
		//********************************************************************//
		if(caracteristicas_nota[0]=='S')
		{
			fprintf(archivo_arduino,"delay(%f);\n", duracion_tone(vel_reproduccion, caracteristicas_nota[1]));
		}
		else
		{
			//********************************************************************//
			//**Caso en el que la nota ingresada no tiene alteracion (sostenido)**//
			//********************************************************************//
			if(caracteristicas_nota[3]=='.')	
			{
				sin_alteracion.nota[0]=caracteristicas_nota[0];
				sin_alteracion.octava[0]=caracteristicas_nota[1];
				sin_alteracion.tiempo[0]= caracteristicas_nota[2];
				
				
				switch(sin_alteracion.nota[0])
				{
					case 'A':
						{
							imprime_codigo_arduino(archivo_arduino, frecuencia((int)(A*pow(2,atoi(sin_alteracion.octava)-1)), cambiar_tonos), duracion_tone(vel_reproduccion, sin_alteracion.tiempo[0]));
							switch(sin_alteracion.octava[0])
							{
								case'1':
									break;
								case'2':
									break;
								case'3':
									break;
								case'4':
									break;
								case'5':
									break;
								case'6':
									break;
								case'7':
									break;
								deafult:
									{
										error(caracteristicas_nota);
									}break;
							}
						}break;
						
					case 'B':
						{
							imprime_codigo_arduino(archivo_arduino, frecuencia((int)(B*pow(2,atoi(sin_alteracion.octava)-1)), cambiar_tonos), duracion_tone(vel_reproduccion, sin_alteracion.tiempo[0]));
					  		switch(sin_alteracion.octava[0])
							{
								case'0':
									break;
								case'1':
									break;
								case'2':
									break;
								case'3':
									break;
								case'4':
									break;
								case'5':
									break;
								case'6':
									break;
								case'7':
									break;
								default:
									{
										error(caracteristicas_nota);
									}break;
							}
						}break;
						
					case 'C':
						{
							imprime_codigo_arduino(archivo_arduino, frecuencia((int)(C*pow(2,atoi(sin_alteracion.octava)-1)), cambiar_tonos), duracion_tone(vel_reproduccion, sin_alteracion.tiempo[0]));
							switch(sin_alteracion.octava[0])
							{
								case'1':
									break;
								case'2':
									break;
								case'3':
									break;
								case'4':
									break;
								case'5':
									break;
								case'6':
									break;
								case'7':
									break;
								case'8':
									break;
								default:
									{
										error(caracteristicas_nota);
									}break;
							}
						}break;
						
					case 'D':
						{
							imprime_codigo_arduino(archivo_arduino, frecuencia((int)(D*pow(2,atoi(sin_alteracion.octava)-1)), cambiar_tonos), duracion_tone(vel_reproduccion, sin_alteracion.tiempo[0]));
							switch(sin_alteracion.octava[0])
							{
								case'1':
									break;
								case'2':
									break;
								case'3':
									break;
								case'4':
									break;
								case'5':
									break;
								case'6':
									break;
								case'7':
									break;
								case'8':
									break;
								default:
									{
										error(caracteristicas_nota);
									}break;
							}
						}break;
						
					case 'E':
						{
							imprime_codigo_arduino(archivo_arduino, frecuencia((int)(E*pow(2,atoi(sin_alteracion.octava)-1)), cambiar_tonos), duracion_tone(vel_reproduccion, sin_alteracion.tiempo[0]));
							switch(sin_alteracion.octava[0])
							{
								case'1':
									break;
								case'2':
									break;
								case'3':
									break;
								case'4':
									break;
								case'5':
									break;
								case'6':
									break;
								case'7':
									break;
								default:
									{
										error(caracteristicas_nota);
									}break;
							}
						}break;
						
					case 'F':
						{
							imprime_codigo_arduino(archivo_arduino, frecuencia((int)(F*pow(2,atoi(sin_alteracion.octava)-1)), cambiar_tonos), duracion_tone(vel_reproduccion, sin_alteracion.tiempo[0]));
							switch(sin_alteracion.octava[0])
							{
								case'1':
									break;
								case'2':
									break;
								case'3':
									break;
								case'4':
									break;
								case'5':
									{
									}break;
								case'6':
									break;
								case'7':
									break;
								default:
									{
										error(caracteristicas_nota);
									}break;
							}
						}break;
						
					case 'G':
						{
							imprime_codigo_arduino(archivo_arduino, frecuencia((int)(G*pow(2,atoi(sin_alteracion.octava)-1)), cambiar_tonos), duracion_tone(vel_reproduccion, sin_alteracion.tiempo[0]));
							switch(sin_alteracion.octava[0])
							{
								case'1':
									break;
								case'2':
									break;
								case'3':
									break;
								case'4':
									break;
								case'5':
									break;
								case'6':
									break;
								case'7':
									break;
								default:
									{
										error(caracteristicas_nota);
									}break;
							}
						}break;
						
					default:
						{
							printf("\n**Error de Sintaxis detectado!:-> %s", caracteristicas_nota);
						}break;
				}
			
			//separamos las notas para distinguirlas, usamos 95% del valor original de la nota//
			fprintf(archivo_arduino,"delay(%i);\n", (int)(duracion_tone(vel_reproduccion, caracteristicas_nota[2])*0.95));	//parte entera
			fprintf(archivo_arduino,"delayMicroseconds(%i);\n", (int)((duracion_tone(vel_reproduccion, caracteristicas_nota[2])*0.95)-(int)(duracion_tone(vel_reproduccion, caracteristicas_nota[2])*0.95)));	//parte decimal
			}
			
			//********************************************************************//
			//**Caso en el que la nota ingresada Si tiene alteracion (sostenido)**//
			//********************************************************************//
			else
			{
				con_alteracion.nota[0]=caracteristicas_nota[0];
				con_alteracion.octava[0]=caracteristicas_nota[2];
				con_alteracion.tiempo[0]= caracteristicas_nota[3];
				
				switch(con_alteracion.nota[0])
				{
					
					case 'A':
						{
							imprime_codigo_arduino(archivo_arduino, frecuencia((int)(AS*pow(2,atoi(con_alteracion.octava)-1)), cambiar_tonos), duracion_tone(vel_reproduccion, con_alteracion.tiempo[0]));
							switch(con_alteracion.octava[0])
							{
								case'1':
									break;
								case'2':
									break;
								case'3':
									break;
								case'4':
									break;
								case'5':
									break;
								case'6':
									break;
								case'7':
									break;
								default:
									{
										error(caracteristicas_nota);
									}break;
							}
						}break;
						
					case 'C':
						{
							imprime_codigo_arduino(archivo_arduino, frecuencia((int)(CS*pow(2,atoi(con_alteracion.octava)-1)), cambiar_tonos), duracion_tone(vel_reproduccion, con_alteracion.tiempo[0]));
							switch(con_alteracion.octava[0])
							{
								case'1':
									break;
								case'2':
									break;
								case'3':
									break;
								case'4':
									break;
								case'5':
									break;
								case'6':
									break;
								case'7':
									break;
								case'8':
									break;
								default:
									{
										error(caracteristicas_nota);
									}break;
							}
						}break;
						
					case 'D':
						{
							imprime_codigo_arduino(archivo_arduino, frecuencia((int)(DS*pow(2,atoi(con_alteracion.octava)-1)), cambiar_tonos), duracion_tone(vel_reproduccion, con_alteracion.tiempo[0]));
							switch(con_alteracion.octava[0])
							{
								case'1':
									break;
								case'2':
									break;
								case'3':
									break;
								case'4':
									break;
								case'5':
									break;
								case'6':
									break;
								case'7':
									break;
								case'8':
									break;
								default:
									{
										error(caracteristicas_nota);
									}break;
							}
						}break;
						
					case 'F':
						{
							imprime_codigo_arduino(archivo_arduino, frecuencia((int)(FS*pow(2,atoi(con_alteracion.octava)-1)), cambiar_tonos), duracion_tone(vel_reproduccion, con_alteracion.tiempo[0]));
							switch(con_alteracion.octava[0])
							{
								case'1':
									break;
								case'2':
									break;
								case'3':
									break;
								case'4':
									break;
								case'5':
									break;
								case'6':
									break;
								case'7':
									break;
								default:
									{
										error(caracteristicas_nota);
									}break;
							}
						}break;
						
					case 'G':
						{
							imprime_codigo_arduino(archivo_arduino, frecuencia((int)(GS*pow(2,atoi(con_alteracion.octava)-1)), cambiar_tonos), duracion_tone(vel_reproduccion, con_alteracion.tiempo[0]));
							switch(con_alteracion.octava[0])
							{
								case'1':
									break;
								case'2':
									break;
								case'3':
									break;
								case'4':
									break;
								case'5':
									break;
								case'6':
									break;
								case'7':
									break;
								default:
									{
										error(caracteristicas_nota);
									}break;
							}
						}break;
					default:
						{
							error(caracteristicas_nota);
						}break;
				}
			
			//separamos las notas para distinguirlas, usamos 95% del valor original de la nota//
			fprintf(archivo_arduino,"delay(%i);\n", (int)(duracion_tone(vel_reproduccion, caracteristicas_nota[3])*0.95));	//parte entera
			fprintf(archivo_arduino,"delayMicroseconds(%i);\n", (int)((duracion_tone(vel_reproduccion, caracteristicas_nota[3])*0.95)-(int)(duracion_tone(vel_reproduccion, caracteristicas_nota[3])*0.95)));	//parte decimal
			}
			
			fprintf(archivo_arduino,"noTone(%i);\n", pin);	
		}
	}
	
	fprintf(archivo_arduino,"\ndelay(%i);\n}", 3000);
}

//Funcion para calcular la duracion a partir del tipo de nota, en milisegundos
float duracion_tone(int velocidad_reproduccion, char nota)
{
	float duracion_miliseg;
	float duracion_nota;
	
	switch(nota)
	{							//silencio de:
		case 'n': duracion_nota=1;	//negra
				  break;
		case 'b': duracion_nota=2;	//blaca
				  break;
		case 'r': duracion_nota=4;	//redonda
				  break;
		case 'c': duracion_nota=0.5;	//corchea
				  break;				
		case 's': duracion_nota=0.25;	//semicorchea
				  break;
		case 'f': duracion_nota=0.125;	//fusa
				  break;
		case 'e': duracion_nota=0.0625;	//semifusa
				  break;
		case 'g': duracion_nota=0.03125;	//garrapatea
				  break;
		case 't': duracion_nota=0.333333;	//tresillo de negra
				  break;
		case 'i': duracion_nota=0.166666;	//seisillo
				  break;
		case 'a': duracion_nota=0.166666;	//tresillo de corchea
				  break;
		case 'd': duracion_nota=0.083333;	//tresillo de semicorchea
				  break;
		case 'h': duracion_nota= 0.0625;	//Tresillo de 3/8
				  break;
		default: printf("\n**Error de Sintaxis en duracion de nota detectado!:-> %c", nota);
				 break;
	}
	
	duracion_miliseg=(60/(float)velocidad_reproduccion)*duracion_nota*1000;
	return duracion_miliseg;
}

//Funcion para calcular la frecuencia de la nota 
unsigned int frecuencia(int frec_original, float num_tonos_cambiar)
{
	unsigned int frecuencia_transportada=frec_original + num_tonos_cambiar*4;
	return frecuencia_transportada;
}

//despliega mensaje si se encuentra error
void error(char *texto_con_error)
{
	printf("\n**Error de Sintaxis detectado!:-> %s", texto_con_error);
}

//Funcion para imprimir el codigo arduino de una nota en el .ino
void imprime_codigo_arduino(FILE *archivo_arduino, int tonos_a_cambiar, float duracion)
{
	fprintf(archivo_arduino,"tone(%i, %i , %f);\n", pin, tonos_a_cambiar, duracion);
}

//Funcion para salir del programa o continuar
int final()
{
	int opcion;
	
	printf("\n**Su Archivo ha sido Exportado con Exito!\n");
	printf("\n**Ingrese 1 para Cambiar Opciones.\n**Ingrese Cualquier Otro Numero para SALIR\n");
	scanf("%i", &opcion);
	fflush(stdin);
	return opcion;
}
