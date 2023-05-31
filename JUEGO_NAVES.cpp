#include<stdio.h>
#include<stdlib.h>
#include<windows.h> 
#include<conio.h>

#define ARRIBA      72
#define ABAJO       80
#define DERECHA     77
#define IZQUIERDA   75
#define BALA 		32

typedef struct{
	int corazon;
	int puntos;
	int vidas;
} NAVE;

typedef struct {
	int x;
	int y;
	 
}AST;

int name[13][63] = {
{219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219},
{219,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,219},
{219,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,219},
{219,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,219},
{219,0,0,0,0,0,219,219,219,0,219,219,219,0,219,219,219,0,219,219,219,0,219,219,219,0,0,219,0,219,0,0,219,0,219,0,219,0,219,219,219,0,219,219,0,0,219,219,219,0,219,219,219,0,219,219,219,0,0,0,0,0,219},
{219,0,0,0,0,0,219,0,0,0,219,0,219,0,219,0,219,0,219,0,0,0,219,0,0,0,0,219,0,219,219,0,219,0,219,0,219,0,219,0,219,0,219,219,219,0,219,0,0,0,219,0,219,0,219,0,0,0,0,0,0,0,219},
{219,0,0,0,0,0,219,219,219,0,219,219,219,0,219,219,219,0,219,0,0,0,219,219,219,0,0,219,0,219,219,219,219,0,219,0,219,0,219,219,219,0,219,0,219,0,219,219,219,0,219,219,0,0,219,219,219,0,0,0,0,0,219},
{219,0,0,0,0,0,0,0,219,0,219,0,0,0,219,0,219,0,219,0,0,0,219,0,0,0,0,219,0,219,0,219,219,0,219,219,219,0,219,0,219,0,219,219,219,0,219,0,0,0,219,0,219,0,0,0,219,0,0,0,0,0,219},
{219,0,0,0,0,0,219,219,219,0,219,0,0,0,219,0,219,0,219,219,219,0,219,219,219,0,0,219,0,219,0,0,219,0,0,219,0,0,219,0,219,0,219,219,0,0,219,219,219,0,219,0,219,0,219,219,219,0,0,0,0,0,219},
{219,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,219},
{219,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,219},
{219,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,219},
{219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219}
};
void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
 }
void consola(){
 		
  SMALL_RECT rect;
  COORD coord;
  coord.X = 120; // Definiendo X y
  coord.Y = 50;  // Y para el tamaño del búfer.

  rect.Top = 0;
  rect.Left = 0;
  rect.Bottom = coord.Y-1; // Altura para ventana
  rect.Right = coord.X-1;  // Ancho para ventana

  HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleScreenBufferSize(hwnd, coord);       // Establece tamaño del búfer
  SetConsoleWindowInfo(hwnd, TRUE, &rect); 
 	
 }
void Ocultarcursor(){
    HANDLE hCon;  
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);  
 	CONSOLE_CURSOR_INFO cci;
 	cci.dwSize = 2;
 	cci.bVisible = FALSE;
 	
 	SetConsoleCursorInfo(hCon, &cci);
 
 }
 
void titulo();
void menu();
void NAVE_PINTAR (int x, int y);
void NAVE_BORRAR (int x, int y);
void LIMITES_MAP ();
void SALUD (NAVE *nave);
void MORIR (NAVE *nave,int x, int y);
void VIDAS (NAVE *nave);
void PUNTOS();
void AST_PINTAR (int _x, int _y);
void AST_MOVER(int _x, int _y);

 
 

// ---------------

int main(){
	
	
	NAVE nave;
	bool GAME_OVER = false;
	int x = 50 , y = 25 ; //Posicion de la nave
	int _x = 10 , _y = 4 ;// Posicion asteroides
	
	nave.corazon= 3;
	nave.vidas =  3;	


 	LIMITES_MAP ();
 	
 	
    while(!GAME_OVER){
    	consola();
    	Ocultarcursor();
    	AST_PINTAR (_x,_y);
		AST_MOVER(_x,_y);
		NAVE_PINTAR(x,y);
		SALUD(&nave);
		VIDAS(&nave);
		PUNTOS();	
		
		if( kbhit()) {	
			char tecla = getch();		
		
			NAVE_BORRAR(x,y);
			
			
			
 			if(tecla == ARRIBA     &&   y > 4  ) y--;
			if(tecla == IZQUIERDA  &&   x > 3  ) x--;
			if(tecla == DERECHA    &&   x < 95 ) x++;
			if(tecla == ABAJO      &&   y < 30 ) y++;	
			//if(tecla == BALA) 
			if(tecla == 99 ) nave.corazon--;	
			SALUD(&nave);
			VIDAS(&nave);	
			MORIR(&nave,x,y);
			PUNTOS();
		}
		
		gotoxy(_x,_y); printf(" ");
		_y++;
		if(_y > 32){
			_x = rand() % 96 + 4;
			_y = 4;
		}	
    	gotoxy(105,2); printf("%d",_y);
	    AST_PINTAR(_x,_y);
		Sleep(50);
		
	}
	
	return 0;
}
 
void titulo(){
	int i, j; 

	for( i = 0 ; i < 13; i ++){
 		for( j = 0 ; j < 63 ; j ++){
 			gotoxy(j+25,i+3);
			printf("%c",name[i][j]);			
		 }
		 gotoxy(j+25,i+3);
		 printf("\n");
	 }	
	 printf("\n\n");
	 system("pause");
	 
}
void menu(){
 	int op=0;
	 	
 	printf("\n\t\tMENU");
 	printf("\n\t1.PLAY");
 	printf("\n\t2.INSTRUCCIONES");
 	printf("\n\t3.SALIR");
 	printf("\n\n\tOpcion: ");
 	
 	scanf("%d",&op);
 	
 	switch(op){
 		case 1:
 			system("cls");
 			//map();
 			break;
 		case 2:
 			break;
 		case 3:
 			break;
	 }
	
 }
void NAVE_PINTAR (int x, int y){
 	
 		gotoxy(x,y);printf("  %c",30);
		gotoxy(x,y+1);printf(" %c%c%c",40,207,41);
		gotoxy(x,y+2);printf("%c%c %c%c",30,190,190,30);
 }
void NAVE_BORRAR(int x, int y){
 	gotoxy(x,y);  printf("     ");
	gotoxy(x,y+1);printf("     ");
	gotoxy(x,y+2);printf("     ");
 }
void SALUD (NAVE *nave){
	int corazones = nave->corazon ;
	gotoxy(83,2);printf("SALUD :");
 	gotoxy(90,2);printf("    ");
 	for(int i = 0; i < corazones ; i ++){
 		gotoxy(90+i,2);printf("%c",3);
	 }
	 nave->corazon = corazones; 
 }
void VIDAS (NAVE *nave){
	
	int vida = nave->vidas ;
	
	gotoxy(73,2);printf("VIDAS: %d",vida);
 	

	 nave->vidas = vida; 
 }
void MORIR (NAVE *nave,int x, int y){
 	int corazones = nave->corazon ;
 	int vida = nave->vidas;
 
 	if(corazones == 0) {
 		
		NAVE_BORRAR(x,y);
 		gotoxy(x,y);  printf("  **  ");
		gotoxy(x,y+1);printf(" ****  ");
		gotoxy(x,y+2);printf("  **  ");
		
		Sleep(400);
		
		NAVE_BORRAR(x,y);
		gotoxy(x,y);  printf("* ** *");
		gotoxy(x,y+1);printf(" **** ");
		gotoxy(x,y+2);printf("* ** *");
		
		
		Sleep(400);
		NAVE_BORRAR(x,y);
		
		if ( vida > 0){
			vida -- ;
			nave->vidas = vida;
			corazones = 3;
			nave->corazon = corazones;
		}
		else if( vida == 0){
			printf("Se murio ");
		}
	 }
 
 }
void PUNTOS(){
 	int puntos=0;
 	
 	gotoxy(5,2);printf("PUNTOS:  %d",puntos);
 	
 }
void LIMITES_MAP (){
 	
	 int i,j;
	 
	 for(i=2;i<100;i++){	
	 	gotoxy(i,3);printf("%c",205);
	 	gotoxy(i,33);printf("%c",205);
	 }
	 for(j=4;j<33;j++){	
	 	gotoxy(2,j);printf("%c",186);
	 	gotoxy(100,j);printf("%c",186);
	 }
	 gotoxy(2,3);printf("%c",201);
	 gotoxy(2,33);printf("%c",200);
	 gotoxy(100,3);printf("%c",187);
	 gotoxy(100,33);printf("%c",188);
	 
 }
void AST_PINTAR (int _x, int _y){
	gotoxy(_x,_y); printf("%c",79);
}
void AST_MOVER(int _x, int _y){
	

	
		


	    
	
}
 	
 
	

	

