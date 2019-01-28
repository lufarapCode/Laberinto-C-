#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib> 
#include <conio.h>

void Intro();
void Sonido();
void gotoxy(int x, int y);
void Tiempo();
void OcultarCursor();
int  mapa[100][50];
void Laberinto();
void Limites();
int  Movimiento_Flechas();

#define ARRIBA     72										// FLECHAS									
#define IZQUIERDA  75
#define DERECHA    77
#define ABAJO      80
#define SALIR      114
#define NUEVO      110
#define TIEMPO     116
	
using namespace std;

int main(){
    // funcion que se encuentra en la libreria time.h
	clock_t tiempo;    
	tiempo=clock();
    
	system("color 4F");
	
	Intro();
	OcultarCursor();
	
	gotoxy(9,2);
    cout<<"ENTRADA";
    gotoxy(62,40);
    cout<<"SALIDA";
    
    gotoxy(62,4);
    cout<<"SALIDA";
    
    gotoxy(63,25);
    cout<<"Presiona R para salir"<<endl;
    gotoxy(63,28);
    cout<<"Presiona N para un"<<endl; 
    gotoxy(63,29);
    cout<<"nuevo laberinto"<<endl;
    system("color 3");
    
    
    Limites();
	Laberinto();
	Movimiento_Flechas();
	
	
    
 
return 0;

}
 // FUNCION GOTOXY
void gotoxy(int x, int y){
	COORD coord;
	coord. X=x;
	coord. Y=y;
	HANDLE hstdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleCursorPosition(hstdOut, coord);
}

   // ESTA FUNCION PERMITE OCULTAR EL CURSOR
void OcultarCursor(){
	
	HANDLE consol;                               
    consol = GetStdHandle(STD_OUTPUT_HANDLE); 
	  
	 CONSOLE_CURSOR_INFO  ocultar;      																		// esta estructura tiene dos parametros
	 ocultar.dwSize = 5;                 																		//DWsIZE VARIABLE DE TIPO ENTERO, EL NUMERO MUSTRA EL ESTILO QUE TENDRA EL CURSOR 
	 ocultar.bVisible = FALSE;            																		// EN CASO QUE SEA VERDADERO EL CURSOR SE MOSTRARA Y SI ES FALSO NO
     SetConsoleCursorInfo(consol, &ocultar );      																			// se encuentra en la biblioteca wiows.h 
	 																													// el primero es el handle y el segundo el nombre que le demos a la estructura y tiene que ser por referencia "&" para que pueda acceder a los datos y modificarlo						
}

 // INTRO DEL JUEGO
void Intro(){
	
//char soundfile[] ="C:\Intro.wav";                                     
//cout<<PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC );  // esta funcion se encuentra en la libreria windows.h
 
 cout<<"       "<<endl;
 cout<<"       "<<endl;
 cout<<"       "<<endl;
 cout<<"       "<<endl;
 cout<<"       ________________________________________________________________"<<endl;
 cout<<"      *                                                                * "<<endl;                                                                         
 cout<<"      |                                                                |"<<endl; 
 cout<<"      |                  ESCUELA POLITECNICA NACIONAL                  |" <<endl;
 cout<<"      |                                                                | "<<endl;  
 cout<<"      |                                                                |"<<endl;
 cout<<"      |          *******************************************           |"<<endl;
 cout<<"      |          *                                         *           |"<<endl;
 cout<<"      |          *      ******     ******     **    *      *           |"<<endl;
 cout<<"      |          *      *          *     *    * *   *      *           |"<<endl;
 cout<<"      |          *      ***        ******     *  *  *      *           |"<<endl;
 cout<<"      |          *      *          *          *   * *      *           |"<<endl;
 cout<<"      |          *      ******     *          *    **      *           |"<<endl;
 cout<<"      |          *                                         *           |"<<endl;
 cout<<"      |          *******************************************           |"<<endl;
 cout<<"      |                                                                |"<<endl;
 cout<<"      |                                                                |"<<endl;
 cout<<"      |                                                                |"<<endl;
 cout<<"      |                                                                |  "<<endl;    
 cout<<"      |            BIENVENIDOS AL JUEGO DEL LABERINTO!!                |"<<endl;
 cout<<"      |                                                                |"<<endl; 
 cout<<"      |                                                                |"<<endl; 
 cout<<"      |                                                                |"<<endl;
 cout<<"      |                                                                |"<<endl;
 cout<<"      |               INTEGRANTES: LUIS FALCONI                        |"<<endl; 
 cout<<"      |                                                                |"<<endl;  
 cout<<"      |                                  Y                             |"<<endl;
 cout<<"      |                                                                |"<<endl; 
 cout<<"      |                            PAUL VALLE                          |"<<endl; 
 cout<<"      |                                                                |"<<endl; 
 cout<<"      |                                                                |"<<endl;
 cout<<"      |                                                                |"<<endl;
 cout<<"      |                                                                |"<<endl;    
 cout<<"      |                                                                |"<<endl;
 cout<<"      |          Presiona cualquier tecla para empezar a jugar :)      |"<<endl;
 cout<<"      |                                                                |"<<endl;
 cout<<"      *________________________________________________________________*"<<endl;
 OcultarCursor();	
     
  getch();      
  system("cls");
    
}

int Movimiento_Flechas(){
	
	int x=9,y=4;
	gotoxy(x,y);
			
	cout<<(char) 4;
	
	// se llama a varios metodos y no basta a que se llame una vez
	// se crea un bucle con una variable logica
				
	bool Fin_del_juego= false;                                   // Cuando el juego inicia esta variable es falsa y solo se ejecuta cuando sea verdad
		while(!Fin_del_juego){                                  // Se ejecuta siempre y cuando la variable sea verdad 
			if(kbhit()){	                                // Esta funcion se encuentra en la libreria conio.h y se encarga de detectar si el usuario a presionado una tecla
					                               
			char tecla= getch();                           // Guarda la letra que se presiona y pasa el valor a la variable tecla
			gotoxy (x,y);  
			cout<<" ";                                     // el espacio borra el asterisco siguiente 
					   
			if(tecla == IZQUIERDA)                                                          // si la posicion en la que se mueve la tecla es 1 o dos podra avanzar y si es 0 no 
			if((mapa[x-1][y]==1 || mapa[x-1][y]==2) && x>8)x--;                     		// si se presiona la letra "a" se mueve una posicion a la izquierda
		
			if(tecla == DERECHA)
			if((mapa[x+1][y]==1 || mapa[x+1][y]==2) && x<60)x++; 
						                   														 	// si se presiona la letra "d" se mueve una posicion a la derecha
			if(tecla == ARRIBA) 
			if((mapa[x][y-1]==1 || mapa[x][y-1]==2)   && y>4)y--; 
					                   																// la  coordenada "y" estan invertidas y es a lo contrario
			if(tecla == ABAJO)
			if((mapa[x][y+1]==1 || mapa[x][y+1]==2)  && y<41) y++;
			
			gotoxy(x,y); cout<<(char)4;		
					
			 // Generacion de un nuevo laberinto
			 if(tecla==NUEVO){
			
			    Laberinto();
			    Limites();
				Movimiento_Flechas();
					
			    system("cls");
			    
			}
			    
			// INCLUIDA EN LA BIBLIOTECA time.h
			clock_t tiempo;           //Se inicializa una variable de tipo clock_t 
			tiempo=clock();           //Se asigna el nombre escofigo a lo que devuele la fuuncion al clock 
						
			// condicion de fin de juego
			if((x==60 && y==40) ||(x==60 && y==4)){
								
			system("cls");	
					
			gotoxy(32,15);
			cout<<"Felicidades!! "<<endl;
			gotoxy(28,16);
			cout<<"Lograste resolver el Laberinto."<<endl;
			                
			gotoxy(27,19);
			cout<<"Presiona T para conocer tu tiempo"<<endl;
			                
	        gotoxy(28,25);
			cout<<"Presiona R para salir"<<endl;
			                
			gotoxy(28,27);
			cout<<"Presiona N para un"<<endl; 
			gotoxy(28,28);
			cout<<"nuevo laberinto"<<endl;
			    
			    			
			    if(tecla==TIEMPO){
			                	
			    gotoxy(25,21);
				cout<<"Duraste :"<<float(tiempo)/CLOCKS_PER_SEC<<"SEGUNDOS. ";               // "tiempo" no contiene en si la cantidad de segundos que ha pasado, sino algo llamado "clocks"
							                                                                 // Se procede a dividir esa cantidad con una constate ya definida que se encuentra en la libreria time.h 
				}
				tiempo=clock()-tiempo;                                                       // Al momento de que la condicion se cumpla, se asigna el tiempo actual de la computadora menos el tiempo del inicio del temporizador  
							
			}
				// condicion de Fin de juego	
			if(tecla==SALIR){
				Fin_del_juego=true;
			}
			            
			Sleep(30);                                      // detiene la ejecucion del programa por 30 milesegundo para dar un descanso al procesador
		}
			  
	 }
}

void Laberinto(){
		
	srand(time(NULL));
	for(int i=9;i<61;i++){
		for(int j=4;j<41;j++){
			mapa[i][j]=rand()%3;    //Numeros randomicos del 0 al 3
			
			
			if(mapa[i][j]==0){
				gotoxy(i,j);
				cout<<(char) 219;  // codico ascci de un "bloque"(pared)
			}else{
				                
				gotoxy(i,j);
				cout<<" ";	
			}
		}
	
	}
	
}
void Limites(){

	for(int i=9; i<62; i++){    // limites del laberinto
		gotoxy(i,3);            
		cout<<(char)205;        // codigo ascii "doble barra" horizontal
		gotoxy(i,41);
		cout<<(char)205;
		}
	for(int j=4; j<41; j++){
		gotoxy(8,j);       
		cout<<(char)186;        // codigo ascii "doble barra" vertical
		gotoxy(61,j);
		cout<<(char)186;
		
	}
	  gotoxy(8,3);
	  cout<<(char)201;            // codigo ascii "diagonal superior izquierda"
	  gotoxy(61,3);
	  cout<<(char)187;            // codigo ascii "diagonal inferior derecha"
	  gotoxy(8,41);
	  cout<<(char)200;            //codigo ascii "diagonal inferior izquierda"  
	  gotoxy(61,41);
	  cout<<(char)188;            // codigo ascii "diagonal superior derecha"
	  
	}  





