#include <stdio.h>

//=========================================================
// 2. Constante: valiarables que nunca cambian
//=========================================================

#define NUM_EQUIPOS 5
// Donde escribas NUM_EQUIPOS, el compilador lo reemplaza por 5

#define x 3
// Umbral de la regla:"más de X fallos" = "mś de 3".
// Un equipo con  o más fallos es sospechoso.


#define NUM_EVVENTOS 27
// Número total de eventos en nuestro arreglos

//===========================================================
// 3. ENUM: Nombres para los tipos de evento
//===========================================================
enum TipoEvento{
    ACCESO_CORRECTO,           // vale 0
    CONTRASENA_INCORRECTA,     // vale 1
    USUARIOS_INEXISTENTE,      // vale 2
    ACCESO_BLOQUEADO,          // vale 3
    NUM_TIPOS_EVENTOS          // vale 4(siempre al final)
};
// Un enum asigna números automáticamente: 0, 1, 2, 3,..
// Así no recordamos "1 = contraseña incorrecta", escribimos el nombre.
// NUM_TIPOS_EVENTO al final nos da el número total de tipos (4).

//=============================================================
//DATOS GLOBALES: Arreglos con los datos de entrada
//=============================================================

char *nombre_equipos[] = {"PC-01", "PC-02", "PC-03", "PC-04", "PC-05"};
// Arreglo de apuntadores a caracter (strings).
// nombre_equipos[0] = "PC-01", nombre_equipos[1] = "PC-02", etc.
// Solo lo usamos para imprimir.

char *nombre_tipos[] = {
    "Accesos_Correcto",
    "Contrasena_Incorrecta",
    "Usuario_Inexistente",
    "Acceso_Bloqueado"
};
// Arreglo de nombres de tipos de evento.
// nombre_tipos[0] = *Acceso_Correcto", etc.
// Solo lo usamos para imprimir.

int equipos[] = {
    0, 0, 1, 1, 4, 2, 4, 4, 2, 3, 4, 0, 1, 4, 3, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 4, 4
};
// Arreglo de 27 enteros. Cada número es el índice del equipo en un evento.
// Evento 1: PC-01 (0), Evento 2: PC-01 (0), PC-02 (1)...
// 0=PC-01, 1=PC-02, 2=PC-03, 2=PC-03, 3=PC-04, 4=PC-05

int tipos[] = {
    0, 1, 2, 1, 0, 1, 0, 2, 3, 3, 0, 1, 1, 3, 2, 2, 3, 0, 3, 1, 0, 2, 0, 3, 0, 1, 2
};
// Arreglo de 27 entero. Cada número es el índice del tipo de evento.
// 0=Acceso_Correcto, 1=Contrasena_Incorrecta, 2=Usuario_Inexistente, 3=Acceso_Bloqueado

// ================================================================================================
// PROTOTIPOS DE FUNCIONES: Aviso al compilador
// ================================================================================================
// Le dicen al copilador: "existenestas funciones".
// Van antes de main() para que main() pueda llamarlas sin error.

int obtenerIndiceTipo(int tipo);
// Pasa por valor: recibe un tipo y devuelve el indice de columna

void incrementarContador(int *contador);
// Pasa por referencia: recibe un apuntador a contador y lo incrementa

void procesarEventos(int matriz[][NUM_TIPOS_EVENTOS], int num_eventos);
// Procesa todos los eventos y llena la matriz.

void imprimirLog(int num_eventos);
// Imprime el log de eventos.

void imprimirResumen(int matriz[][NUM_TIPOS_EVENTO]);
// Imprime el resumen por equipo.

int esSospechoso(int matriz[][NUM_TIPOS_EVENTOS], int equipos);
// Determina si un equipo es sospechoso (1 = si, 0 = no).

//==================================================================================================


int main(){


}