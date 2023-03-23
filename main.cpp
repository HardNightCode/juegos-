#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
using namespace std;


//-----------------------4enlínea------------------------------------//

const int FILAS = 6;
const int COLUMNAS = 7;

char tablero[FILAS][COLUMNAS];

// Declarar  tablero en blanco
void inicializarTablero() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            tablero[i][j] = ' ';
        }
    }
}

// Muestrar tablero en consola
void mostrarTablero() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << "| " << tablero[i][j] << " ";
        }
        cout << "|" << endl;
    }
    for (int j = 0; j < COLUMNAS; j++) {
        cout << "+---";
    }
    cout << "+" << endl;
    for (int j = 0; j < COLUMNAS; j++) {
        cout << "  " << j+1 << " ";
    }
    cout << endl;
}

// Movimientos en tablero
bool columnaLlena(int columna) {
    return tablero[0][columna] != ' ';
}

// Anadir ficha en columna
bool anadirFicha(int columna, char jugador) {
    for (int i = FILAS-1; i >= 0; i--) {
        if (tablero[i][columna] == ' ') {
            tablero[i][columna] = jugador;
            return true;
        }
    }
    return false;
}

// Comprobación 4 en línea
bool hayGanador(char jugador) {
    // Comprobación horizontal
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS-3; j++) {
            if (tablero[i][j] == jugador &&
                tablero[i][j+1] == jugador &&
                tablero[i][j+2] == jugador &&
                tablero[i][j+3] == jugador) {
                return true;
            }
        }
    }
    
    // Comprobación vertical
    for (int i = 0; i < FILAS-3; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (tablero[i][j] == jugador &&
                tablero[i+1][j] == jugador &&
                tablero[i+2][j] == jugador &&
                tablero[i+3][j] == jugador) {
                return true;
            }
        }
    }
    
    // Comprobación diagonal hacia abajo
    for (int i = 0; i < FILAS-3; i++) {
        for (int j = 0; j < COLUMNAS-3; j++) {
            if (tablero[i][j] == jugador &&
                tablero[i+1][j+1] == jugador &&
                tablero[i+2][j+2] == jugador &&
                tablero[i+3][j+3] == jugador) {
                return true;
            }
        }
    }
    
    // Comprobación diagonal hacia arriba 
for (int i = 3; i < FILAS; i++) {
for (int j = 0; j < COLUMNAS-3; j++) {
if (tablero[i][j] == jugador &&
tablero[i-1][j+1] == jugador &&
tablero[i-2][j+2] == jugador &&
tablero[i-3][j+3] == jugador) {
return true;
            }
        }
    }

// Empate
cout<<endl<<"Empate"<<endl;
return false;
}



//-----------------------Login------------------------------------



// Declarar espacio de cuenta
struct Cuenta {
    string nombreUsuario;
    string contrasena;
};

// Función para verificar si existe una cuenta (mismo directorio)
bool existeCuenta(string nombreUsuario, string contrasena) {
    ifstream archivoCuentas("cuentas.txt");

    string usuario, password;

    while (archivoCuentas >> usuario >> password) {
        if (usuario == nombreUsuario && password == contrasena) {
            archivoCuentas.close();
            return true;
        }
    }

    archivoCuentas.close();
    return false;
}

// Crear nueva cuenta
void crearCuenta() {
    string nombreUsuario, contrasena;

    cout << "Introduce un nombre de usuario: ";
    cin >> nombreUsuario;

    cout << "Introduce una contrasena: ";
    cin >> contrasena;

    ofstream archivoCuentas("cuentas.txt", ios::app);

    archivoCuentas << nombreUsuario << " " << contrasena << endl;

    archivoCuentas.close();
}



//-----------------------HundirLaFlota------------------------------------
const int tamanotablero = 10;

void iniciartablero(char tablero[][tamanotablero]) {
    for (int i = 0; i < tamanotablero; i++) {
        for (int j = 0; j < tamanotablero; j++) {
            tablero[i][j] = '.';
        }
    }
}

void mostrartablero(char tablero[][tamanotablero]) {
    cout << "  ";
    for (int i = 0; i < tamanotablero; i++) {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < tamanotablero; i++) {
        cout << i << " ";
        for (int j = 0; j < tamanotablero; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}

bool estocado(char tablero[][tamanotablero], int fila, int columna) {
    if (tablero[fila][columna] == 'S') {
        tablero[fila][columna] = 'X';
        return true;
    } else if (tablero[fila][columna] == '.') {
        tablero[fila][columna] = 'O';
    }
    return false;
}

void posbarco(char tablero[][tamanotablero], int numbarcos) {
    srand(time(NULL));
    int count = 0;
    while (count < numbarcos) {
        int fila = random() % tamanotablero;
        int columna = random() % tamanotablero;
        if (tablero[fila][columna] == '.') {
            tablero[fila][columna] = 'S';
            count++;
        }
    }
}

bool siderrota(char tablero[][tamanotablero]) {
    for (int i = 0; i < tamanotablero; i++) {
        for (int j = 0; j < tamanotablero; j++) {
            if (tablero[i][j] == 'S') {
                return false;
            }
        }
    }
    return true;
}

void turnojug(char tablero[][tamanotablero]) {
    int fila, columna;
    cout << "Introduce fila y columna: ";
    cin >> fila >> columna;
    if (estocado(tablero, fila, columna)) {
        cout << "Tocado!\n";
    } else {
        cout << "Fallaste!\n";
    }
}

void turnomaquina(char tablero[][tamanotablero]) {
    srand(time(NULL));
    int fila = random() % tamanotablero;
    int columna = random() % tamanotablero;
    if (estocado(tablero, fila, columna)) {
        cout << "La máquina ha impactado en (" << fila << ", " << columna << ")\n";
    } else {
        cout << "La máquina ha fallado en (" << fila << ", " << columna << ")\n";
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main() {
    string nombreUsuario, contrasena;
    bool cuentaExistente = false;

    cout << "¿Tienes una cuenta? (S/N): ";
    char respuesta;
    cin >> respuesta;

    if (respuesta == 'S' || respuesta == 's') {            //------------------------------Juegos en la sesión--------------------------
        // Inicio de sesión
        do {
            cout << "Introduce tu nombre de usuario: ";
            cin >> nombreUsuario;

            cout << "Introduce tu contrasena: ";
            cin >> contrasena;

            cuentaExistente = existeCuenta(nombreUsuario, contrasena);

            if (!cuentaExistente) {
                cout << "Nombre de usuario o contrasena incorrectos. Vuelve a intentarlo." << endl;
            }

        } while (!cuentaExistente);

        cout<< "Bienvenido, "<< nombreUsuario<< "!"<< endl;
        
        cout<<endl<<endl;
 

int quejuego;
cout<<" Opciones "<<endl;
cout<<"     1): 4 en línea. "<<endl;
cout<<"     2): Hundir la flota. "<<endl;
cout<<"¿Qué quieres hacer?: ";cin>>quejuego;
system("clear");

while (quejuego==1){
//------------------------------------Jugar 4enlínea--------------------------------------

char jugadorActual = 'X';
inicializarTablero();
mostrarTablero();


while (true) {
    
    int columna;
    cout << "Jugador " << jugadorActual << ", en qué columna quieres colocar tu ficha? ";
    cin >> columna;
    columna--; // Ajustar con -1
    if (columna < 0 || columna >= COLUMNAS || columnaLlena(columna)) {
        cout << "Columna inválida. Inténtalo de nuevo." << endl;
        continue;
    }
    if (anadirFicha(columna, jugadorActual)) {
        if (hayGanador(jugadorActual)) {
            cout << "¡Jugador " << jugadorActual << " ha ganado!" << endl;
            break;
        }
        jugadorActual = jugadorActual == 'X' ? 'O' : 'X';
        mostrarTablero();
    } else {
        cout << "Columna llena. Inténtalo de nuevo." << endl;
    }
}


}
while (quejuego==2){
//------------------------------------Jugar HundirLaFlota--------------------------------------
char playertablero[tamanotablero][tamanotablero];
char maquinatablero[tamanotablero][tamanotablero];
iniciartablero(playertablero);
iniciartablero(maquinatablero);
posbarco(playertablero, 5);
posbarco(maquinatablero, 5);

while (!siderrota(playertablero) && !siderrota(maquinatablero)) {
    cout << "Tu turno:\n";
    mostrartablero(playertablero);
    turnojug(maquinatablero);

    if (!siderrota(maquinatablero)) {
        cout << "Turno de la máquina:\n";
        turnomaquina(playertablero);
        mostrartablero(playertablero);
    }
}

if (siderrota(playertablero)) {
    cout << "Enhorabuena! Has ganado el juego!\n";
} else {
    cout << "Lo siento, te ha ganado la máquina.\n";
}
}
    }
//--------------------------------------------------------------------------
    
    
    
     else if (respuesta == 'N' || respuesta == 'n') {
        // Crear nueva cuenta
        crearCuenta();
        cout << "Cuenta creada exitosamente. Inicie sesión para continuar." << endl;

    } else {
        // Respuesta inválida
        cout << "Respuesta inválida." << endl;
    }

    return 0;
}


