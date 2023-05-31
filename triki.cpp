#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;
int i;
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
void tablero(char [3][3],char [11],char [11]);
void menu(char [3][3],char&,char [11],char [11]);
void Datos(char [3][3],char&);
void Jugador(char&);
char Ganador(char [3][3]);
void game (char [3][3],char&,char [11],char [11]);
void Reinicio(char [3][3]);
void IA (char[3][3],char&,char[11],char[11]);
void PCDatos (char[3][3],char&);

int main()
{
	system("color F1");
    //Variables     
    char Player = 'X' ;
    char Nombre   [11];
    char Nombre_2 [11];
    char numeros [3][3]={{'1','2','3'},
                         {'4','5','6'},
                         {'7','8','9'}};


    menu (numeros,Player,Nombre,Nombre_2);                                           //Funcion donde se encuentra el menu y las opciones de juego


    return 0;
}

//Tablero de Juego
void tablero (char numeros[3][3],char Nombre [11],char Nombre_2 [11])
{
	system("color F1");
    int i,j;
    int filas=3,columnas=3;

    system("cls");
    for(i=5;i<=70;i++){
			gotoxy(5+i,0);cout<<char(205);
			gotoxy(5+i,20);cout<<char(205);
		}
	for(i=0;i<=20;i++){
			gotoxy(10,0+i);cout<<char(186);
			gotoxy(75,0+i);cout<<char(186);
			
		}
	gotoxy(10,0);cout<<char(201); gotoxy(10,20);cout<<char(200);
	gotoxy(75,0);cout<<char(187); gotoxy(75,20);cout<<char(188);	
                                                                                        //Nos Muestra a los Jugadores Y Sus Respectivos Simbolos para Jugar.
    gotoxy(30,2); cout << "     Triqui";
    gotoxy(10,3); cout << "       Jugador 1: " << Nombre <<" (X)  -  Jugador 2: "<< Nombre_2 <<" (O)" << endl << endl << endl << endl;

    for(i=0;i<columnas;i++)                                                             //Se Encarga de las Columnas del Tablero.
    {
        cout<<"\t\t\t       ";cout<<"  ";                                                               
    for(j=0;j<filas;j++)                                                            //Se Encarga de las Filas del Tablero.
        {   
            cout<<numeros[i][j];                                                        //Los Numeros del Arreglo se iran Acomodando en el Orden Correspondiente Mediante 
            if(j<filas-1)                                                               //Las Columnas Junto A las FiLas se Formen.                                                                                     
            {
                cout<<" | ";                                                            //Divisiones Verticales para el Tablero.
            }
        }
        cout<<endl;                                                                     //Salto de Linea, Nos Ayuda a Comenzar los Preparativos para las Divisiones Horizontales.

    if(i<filas-1)
        {
            for (int lines=0;lines<1;lines++ )                                          //Se Encarga de las Filas del Tablero.
            {
                cout<<"\t\t\t\t--- --- ---";                                            //Divisiones Horizantales para el Tablero.
            }
            cout<<endl;
        }

    }
    return;
}

//Menu
void menu (char numeros[3][3],char& Player,char Nombre [11],char Nombre_2 [11])
{
    int opcion,Opcion2;
    char continuar = 'Y';

    Reinicio(numeros);     
	for(i=20;i<=65;i++){
			gotoxy(30+i,2);cout<<char(205);
			gotoxy(30+i,24);cout<<char(205);
		}
	for(i=2;i<=24;i++){
			gotoxy(50,0+i);cout<<char(186);
			gotoxy(95,0+i);cout<<char(186);
			
		}
	gotoxy(50,2);cout<<char(201); gotoxy(50,24);cout<<char(200);
	gotoxy(95,2);cout<<char(187); gotoxy(95,24);cout<<char(188);	
	
        
	                                                  //Resetboard Nos Colocara los Numeros del Arreglo en Orden Una Vez Finalizado la Primera Partida.
	gotoxy(55,4); cout << "         ING Electronica";
   gotoxy(55,10); cout << "            Triqui        ";
   gotoxy(58,12); cout << "Jugador 1 (X)  -  Jugador 2 (O)" << endl << endl;
    gotoxy(64,14);cout << "1)Comenzar el juego";
	gotoxy(64,16);cout<<"2)Instruciones" ;
	gotoxy(64,18);cout<<"3)Salir" ;
	gotoxy(64,20);cout<<"4)Creadores";
    gotoxy(64,22); cout << "Opcion: ";cin>>opcion;

    if (opcion==1)                                                                      //Opcion 1 Nos Lleva Directo a la Entrada del Juego.
    {   
        system("color F1");
        system("cls");  
        for(i=1;i<=70;i++){
			gotoxy(40+i,18);cout<<char(176);
			Sleep(1);
			
		}
		system("cls");
		for(i=20;i<=65;i++){
			gotoxy(30+i,6);cout<<char(205);
			gotoxy(30+i,15);cout<<char(205);
		}
	for(i=6;i<=15;i++){
			gotoxy(50,0+i);cout<<char(186);
			gotoxy(95,0+i);cout<<char(186);
			
		}
	gotoxy(50,6);cout<<char(201); gotoxy(50,15);cout<<char(200);
	gotoxy(95,6);cout<<char(187); gotoxy(95,15);cout<<char(188);
        gotoxy(55,8);cout << "Escoge un numero para comenzar a jugar";
        gotoxy(60,10);cout << "    1. Jugador vs Jugador";
		 gotoxy(60,12);cout<<"    2. Jugador vs PC";
		gotoxy(64,14);cout<<"  Opcion: ";cin>>Opcion2;
        if(Opcion2==1)
        {
        	 system("cls");  
        for(i=1;i<=70;i++){
        	system("color F1");
			gotoxy(40+i,18);cout<<char(176);
			Sleep(1);
			
		}
		system("cls");
            game (numeros,Player,Nombre,Nombre_2);
        }
        else if (Opcion2==2)
        {
        	system("cls");  
        for(i=1;i<=70;i++){
        	system("color F1");
			gotoxy(40+i,18);cout<<char(176);
			Sleep(1);
			
		}
		system("cls");
            IA (numeros,Player,Nombre,Nombre_2);
        }
    }
    else if (opcion==2)                                                                 //Opcion 2 Nos Permite Observar las Instrucciones Basicas del Juego.
    {
    	system("cls");  
        for(i=1;i<=70;i++){
			gotoxy(40+i,18);cout<<char(176);
			Sleep(1);
			
		}

        system("cls");  
        for(i=0;i<=135;i++){
			gotoxy(8+i,6);cout<<char(205);
			gotoxy(8+i,16);cout<<char(205);
		}
        gotoxy(65,8);cout<<"Instruciones: ";
        gotoxy(25,10);cout<<"Este juego es para dos jugadores, X y O, que se turnan para marcar losnespacios en una cuadricula de 3x3.";
        gotoxy(25,12);cout<<"El jugador que logre colocar tres de sus marcas en una fila horizontal, vertical o diagonal gana el juego.";
        gotoxy(10,14);cout<<"En este juego, la primera persona en jugar es X y la segunda es O. Espero que las instrucciones hayan sido utiles, ¡diviertete!\2";
        system("Pause>Null");
        system("cls");
        menu (numeros,Player,Nombre,Nombre_2);
    }
    else if (opcion==3)                                                                 //opcion 3 Salir del Juego.
    {
    	
		system("cls");
        gotoxy(55,8);cout<<"¡Gracias por su tiempo, hasta la proxima!";
        system("Pause>Null");
    }else if(opcion==4)                                                                 //opcion 3 Salir del Juego.
    {
        cout<<"\n\ncreadores\n\n";
        cout<<"Elimelec jose ricardo melo \nVladimir Sebastian Sierra\nDago Andrey Chinchilla";
        system("Pause>Null");
        system("cls");
        menu (numeros,Player,Nombre,Nombre_2);
    }                                                                               
else if ((opcion!=1)||(opcion!=2)||(opcion!=3)||(opcion!=4))                                         //Esta Opcion nos dice que mientras el usuario no aplique una de las tres opciones anteriores el programa mostrara un mensaje.
    {
        cout<<"\n\nEl numero ingresado es incorrecto, intente nuevamente";
        system("Pause>Null");
        system("cls");
        menu (numeros,Player,Nombre,Nombre_2);
    }
    
    return;
}

//Entrada de Datos por Parte de los Usuarios
void Datos(char numeros[3][3], char& Player)
{
    int Campo;

    gotoxy(20,13);cout << "Es " << Player << " turno " <<"Presione el Numero del Campo: ";cin >> Campo; //Permite que el Usuario Marque El lugar de Preferencia para Su Tirada.
    //Campo de Tiro
    if (Campo == 1)
    {
        if (numeros[0][0] == '1')
            numeros[0][0] = Player;
        else
        {
            gotoxy(20,15);cout << "El campo ya esta en uso ¡Intentalo de nuevo!" << endl;
            Datos(numeros,Player);
        }
    }
    else if (Campo == 2)
    {
        if (numeros[0][1] == '2')
            numeros[0][1] = Player;
        else
        {
            gotoxy(20,15);cout << "El campo ya esta en uso ¡Intentalo de nuevo!" << endl;
            Datos(numeros,Player);
        }
    }
    else if (Campo == 3)
    {
        if (numeros[0][2] == '3')
            numeros[0][2] = Player;
        else
        {
            gotoxy(20,15);cout << "El campo ya esta en uso ¡Intentalo de nuevo!" << endl;
            Datos(numeros,Player);
        }
    }
    else if (Campo == 4)
    {
        if (numeros[1][0] == '4')
            numeros[1][0] = Player;
        else
        {
            gotoxy(20,15);cout << "El campo ya esta en uso ¡Intentalo de nuevo!" << endl;
            Datos(numeros,Player);
        }
    }
    else if (Campo == 5)
    {
        if (numeros[1][1] == '5')
            numeros[1][1] = Player;
        else
        {
            gotoxy(20,15);cout << "El campo ya esta en uso ¡Intentalo de nuevo!" << endl;
            Datos(numeros,Player);
        }
    }
    else if (Campo == 6)
    {
        if (numeros[1][2] == '6')
            numeros[1][2] = Player;
        else
        {
            gotoxy(20,15);cout << "El campo ya esta en uso ¡Intentalo de nuevo!" << endl;
            Datos(numeros,Player);
        }
    }
    else if (Campo == 7)
    {
        if (numeros[2][0] == '7')
            numeros[2][0] = Player;
        else
        {
            gotoxy(20,15);cout << "El campo ya esta en uso ¡Intentalo de nuevo!" << endl;
            Datos(numeros,Player);
        }
    }
    else if (Campo == 8)
    {
        if (numeros[2][1] == '8')
            numeros[2][1] = Player;
        else
        {
            gotoxy(20,15);cout << "El campo ya esta en uso ¡Intentalo de nuevo!" << endl;
            Datos(numeros,Player);
        }
    }
    else if (Campo == 9)
    {
        if (numeros[2][2] == '9')
            numeros[2][2] = Player;
        else
        {
            gotoxy(20,15);cout << "El campo ya esta en uso ¡Intentalo de nuevo!" << endl;
            Datos(numeros,Player);
        }
    }
    else 
    {
        gotoxy(20,15);cout << "	El numero ingresado esta fuera de rango" << endl;
        Datos(numeros,Player);
    }
    return;
}

//Cambio de Turno
void Jugador(char& Player)
{
    if (Player == 'X')                                                                          //Mientras la Variable Player sea X al llegar aqui Pasara a Convertrise en O.
        {
            Player = 'O';
        }
    else                                                                                        //Mientras la Variable Player sea O al llegar aqui Pasara a Convertirse en X.
        {
            Player = 'X';
        }
    return;
}

//FUNCION PARA EL GANADOR
char Ganador(char numeros[3][3])
{
    //JUGADOR 1
     if (numeros[0][0] == 'X' && numeros[0][1] == 'X' && numeros[0][2] == 'X')
        return 'X';
     if (numeros[1][0] == 'X' && numeros[1][1] == 'X' && numeros[1][2] == 'X')
        return 'X';
     if (numeros[2][0] == 'X' && numeros[2][1] == 'X' && numeros[2][2] == 'X')
        return 'X';

     if (numeros[0][0] == 'X' && numeros[1][0] == 'X' && numeros[2][0] == 'X')
        return 'X';
     if (numeros[0][1] == 'X' && numeros[1][1] == 'X' && numeros[2][1] == 'X')
        return 'X';
     if (numeros[0][2] == 'X' && numeros[1][2] == 'X' && numeros[2][2] == 'X')
        return 'X';

     if (numeros[0][0] == 'X' && numeros[1][1] == 'X' && numeros[2][2] == 'X')
        return 'X';
     if (numeros[2][0] == 'X' && numeros[1][1] == 'X' && numeros[0][2] == 'X')
        return 'X';

    //JUGADOR 2
     if (numeros[0][0] == 'O' && numeros[0][1] == 'O' && numeros[0][2] == 'O')
        return 'O';
     if (numeros[1][0] == 'O' && numeros[1][1] == 'O' && numeros[1][2] == 'O')
        return 'O';
     if (numeros[2][0] == 'O' && numeros[2][1] == 'O' && numeros[2][2] == 'O')
        return 'O';

     if (numeros[0][0] == 'O' && numeros[1][0] == 'O' && numeros[2][0] == 'O')
        return 'O';
     if (numeros[0][1] == 'O' && numeros[1][1] == 'O' && numeros[2][1] == 'O')
        return 'O';
     if (numeros[0][2] == 'O' && numeros[1][2] == 'O' && numeros[2][2] == 'O')
        return 'O';

     if (numeros[0][0] == 'O' && numeros[1][1] == 'O' && numeros[2][2] == 'O')
        return 'O';
     if (numeros[2][0] == 'O' && numeros[1][1] == 'O' && numeros[0][2] == 'O')
        return 'O';

    //Draw
else if (numeros[0][0] != '1' && numeros[0][1] != '2' && numeros[0][2] != '3' && numeros[1][0] != '4' &&
         numeros[1][1] != '5' && numeros[1][2] != '6' && numeros[2][0] != '7' && numeros[2][1] != '8' && numeros[2][2] != '9')
        return 'D';
}

//Controla la Parte Fundamental del Juego 
void game (char numeros[3][3],char& Player,char Nombre [11],char Nombre_2 [11])
{
    char continuar = 'Y';

    system("cls");
    for(i=20;i<=110;i++){
			gotoxy(15+i,6);cout<<char(205);
			gotoxy(15+i,15);cout<<char(205);
		}
	for(i=6;i<=15;i++){
			gotoxy(35,0+i);cout<<char(186);
			gotoxy(125,0+i);cout<<char(186);
			
		}
		gotoxy(35,6);cout<<char(201); gotoxy(35,15);cout<<char(200);
	gotoxy(125,6);cout<<char(187); gotoxy(125,15);cout<<char(188);
    gotoxy(40,8);cout << "Sugerencia: solo se permite un maximo de 10 caracteres y no se permite espacios";
    gotoxy(68,10);cout << "Jugador 1 (Nombre): ";cin>>Nombre;                                          //Nombre del Primer Jugador Ingresado por el Usuario.
    gotoxy(68,12); cout << "Jugador 2 (Nombre): ";cin>>Nombre_2;    
    system("cls");
	for(i=1;i<=70;i++){
			gotoxy(40+i,18);cout<<char(176);
			Sleep(1);
			
		}
		system("cls");                                    //Nombre del Segundo Jugador Ingresado por el Usuario.
    tablero (numeros,Nombre,Nombre_2);

    while(true)                                                                                 //Mientras el Juego No Encuentre a Un Ganador o Un Empate Seguira Corriendo.
        {
            Datos(numeros,Player);
            tablero (numeros,Nombre,Nombre_2);

        if (Ganador(numeros) =='X')
            {
                gotoxy(20,13);cout << "X Gano!" << endl;break;
            }
        else if (Ganador(numeros) =='O')
            {
                gotoxy(20,13); cout << "O Gano!" << endl;break;
            }
        else if (Ganador(numeros) == 'D')
            {
                gotoxy(20,13); cout << "Es un empate!" << endl;break;
            }   
                Jugador(Player);       
        }
    gotoxy(20,15); cout<<"¿Quiere volver al menú de inicio?: Y/N";cin>>continuar;                    //Pregunta para Saber Si El Usuario Desea Continuar

    if((continuar=='y')||(continuar=='Y'))
            {
                system("cls");
                menu (numeros,Player,Nombre,Nombre_2);
            }
    return;
}

//Reinicia el Arreglo Llamado numeros, de Esta Manera se Puede Seguir Jugando sin Problemas Luego de Haber Finalizado la Primera Partida.
void Reinicio(char numeros[3][3])
{   
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            numeros[0][0]='1';
            numeros[0][1]='2';
            numeros[0][2]='3';
            numeros[1][0]='4';
            numeros[1][1]='5';
            numeros[1][2]='6';
            numeros[2][0]='7';
            numeros[2][1]='8';
            numeros[2][2]='9';
        }   
    }
    return;     
}

//Practicamente es la misma funcion game() sin embargo esta modificada para poder jugar contra el mismo ordenador
void IA (char numeros[3][3],char& Player,char Nombre[11],char Nombre_2[11])
{
    char continuar = 'Y';
    Nombre_2 = "Computadora (PC)";
    system("cls");
    for(i=20;i<=110;i++){
			gotoxy(15+i,4);cout<<char(205);
			gotoxy(15+i,15);cout<<char(205);
		}
	for(i=4;i<=15;i++){
			gotoxy(35,0+i);cout<<char(186);
			gotoxy(125,0+i);cout<<char(186);
			
		}
		gotoxy(35,4);cout<<char(201); gotoxy(35,15);cout<<char(200);
	gotoxy(125,4);cout<<char(187); gotoxy(125,15);cout<<char(188);
    gotoxy(68,6);cout << "Ingrese los nombres:";
    gotoxy(40,8);cout << "Sugerencia: solo se permite un maximo de 10 caracteres y no se permite espacios ";
    gotoxy(68,10);cout << "Jugador 1 (nombre): ";cin>>Nombre;                                          //Nombre del Primer Jugador Ingresado por el Usuario.
    gotoxy(68,12);cout << "Jugador  2 (nombre): " << Nombre_2;  
	 system("cls");
	for(i=1;i<=70;i++){
			gotoxy(40+i,18);cout<<char(176);
			Sleep(1);
			
		}
		system("cls");                                         //Nombre del Segundo Jugador.
    tablero (numeros,Nombre,Nombre_2);

    while(true)                                                                                 //Mientras el Juego No Encuentre a Un Ganador o Un Empate Seguira Corriendo.
        {
            Datos(numeros,Player);
            tablero (numeros,Nombre,Nombre_2);
            Jugador(Player); 

        if (Ganador(numeros) =='X')
            {
                gotoxy(20,13);cout << "X Gano!" << endl;break;
            }
        else if (Ganador(numeros) =='O')
            {
                gotoxy(20,13);cout << "O Gano!" << endl;break;
            }
        else if (Ganador(numeros) == 'D')
            {
                gotoxy(20,13);cout << "Es un empate!" << endl;break;
            }   

            PCDatos (numeros,Player);
            tablero (numeros,Nombre,Nombre_2);
            Jugador(Player);

        if (Ganador(numeros) =='X')
            {
                gotoxy(20,13);cout << "X Gano!" << endl;break;
            }
        else if (Ganador(numeros) =='O')
            {
                gotoxy(20,13);cout << "O Gano!" << endl;break;
            }
        else if (Ganador(numeros) == 'D')
            {
                gotoxy(20,13);cout << "Es un empate!" << endl;break;
            }  

        }
    gotoxy(20,15);cout<<"¿Quiere volver al menu de inicio?: Y/N";cin>>continuar;                    //Pregunta para Saber Si El Usuario Desea Continuar

    if((continuar=='y')||(continuar=='Y'))
            {
                Jugador(Player);
                system("cls");
                menu (numeros,Player,Nombre,Nombre_2);
            }
    return;
}

//Decisiones que tomara el ordenador
void PCDatos  (char numeros[3][3],char& Player)
{
    srand(time(0));
    int Campo = rand()%9+1;

    gotoxy(20,13);cout << "Turno de " << Player; 
    Sleep(2500);
    //Campo de Tiro
    if (Campo == 1)
    {
        if (numeros[0][0] == '1')
            numeros[0][0] = Player;
        else
        {
            PCDatos(numeros,Player);
        }
    }
    else if (Campo == 2)
    {
        if (numeros[0][1] == '2')
            numeros[0][1] = Player;
        else
        {
            PCDatos (numeros,Player);
        }
    }
    else if (Campo == 3)
    {
        if (numeros[0][2] == '3')
            numeros[0][2] = Player;
        else
        {
            PCDatos(numeros,Player);
        }
    }
    else if (Campo == 4)
    {
        if (numeros[1][0] == '4')
            numeros[1][0] = Player;
        else
        {
            PCDatos(numeros,Player);
        }
    }
    else if (Campo == 5)
    {
        if (numeros[1][1] == '5')
            numeros[1][1] = Player;
        else
        {
            PCDatos(numeros,Player);
        }
    }
    else if (Campo == 6)
    {
        if (numeros[1][2] == '6')
            numeros[1][2] = Player;
        else
        {
            PCDatos(numeros,Player);
        }
    }
    else if (Campo == 7)
    {
        if (numeros[2][0] == '7')
            numeros[2][0] = Player;
        else
        {
            PCDatos(numeros,Player);
        }
    }
    else if (Campo == 8)
    {
        if (numeros[2][1] == '8')
            numeros[2][1] = Player;
        else
        {
            PCDatos(numeros,Player);
        }
    }
    else if (Campo == 9)
    {
        if (numeros[2][2] == '9')
            numeros[2][2] = Player;
        else
        {
            PCDatos(numeros,Player);
        }
    }
    else 
    {
        gotoxy(20,13); cout << "El numero ingresado esta fuera de rango" << endl;
        PCDatos(numeros,Player);
    }
    return;
}
