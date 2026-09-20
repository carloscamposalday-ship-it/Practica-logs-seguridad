#include <stdio.h>

// =========================================================
// 2. Constante: valiarables que nunca cambian
// =========================================================

#define NUM_EQUIPOS 5
// Donde escribas NUM_EQUIPOS, el compilador lo reemplaza por 5

#define x 3
// Umbral de la regla:"más de X fallos" = "más de 3".
// Un equipo con o más fallos es sospechoso.


#define NUM_EVENTOS 27
// Número total de eventos en nuestro arreglos

// ===========================================================
// 3. ENUM: Nombres para los tipos de evento
// ===========================================================
enum TipoEvento{
    ACCESO_CORRECTO,           // vale 0
    CONTRASENA_INCORRECTA,     // vale 1
    USUARIO_INEXISTENTE,      // vale 2
    ACCESO_BLOQUEADO,          // vale 3
    NUM_TIPOS_EVENTO          // vale 4(siempre al final)
};
// Un enum asigna números automáticamente: 0, 1, 2, 3,..
// Así no recordamos "1 = contraseña incorrecta", escribimos el nombre.
// NUM_TIPOS_EVENTO al final nos da el número total de tipos (4).

// =============================================================
//DATOS GLOBALES: Arreglos con los datos de entrada
// =============================================================

char *nombres_equipos[] = {"PC-01", "PC-02", "PC-03", "PC-04", "PC-05"};
// Arreglo de apuntadores a caracter (strings).
// nombre_equipos[0] = "PC-01", nombre_equipos[1] = "PC-02", etc.
// Solo lo usamos para imprimir.

char *nombres_tipos[] = {
    "Acceso_Correcto",
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

// ============================================================================
// PROTOTIPOS DE FUNCIONES: Aviso al compilador
//===========================================================================
// Le dicen al copilador: "existenestas funciones".
// Van antes de main() para que main() pueda llamarlas sin error.

int obtenerIndiceTipo(int tipo);
// Pasa por valor: recibe un tipo y devuelve el indice de columna

void incrementarContador(int *contador);
// Pasa por referencia: recibe un apuntador a contador y lo incrementa

void procesarEventos(int matriz[][NUM_TIPOS_EVENTO], int num_eventos);
// Procesa todos los eventos y llena la matriz.

void imprimirLog(int num_eventos);
// Imprime el log de eventos.

void imprimirResumen(int matriz[][NUM_TIPOS_EVENTO]);
// Imprime el resumen por equipo.

int esSospechoso(int matriz[][NUM_TIPOS_EVENTO], int equipo);
// Determina si un equipo es sospechoso (1 = si, 0 = no).

// ==================================================================================================
//FUNCIÓN MAIN: Punto de entrada del programa
// ===================================================================================================
int main(){
    //Matriz bidemensional: [equipos][tipos de evvento]
    // 5 filas (equipos) x 4 columnas (tipo)
    //{0} inicializa TODA las celdas en 0.
    int matriz[NUM_EQUIPOS][NUM_TIPOS_EVENTO] = {0};

    // 1. Procesar enevnentos para llenar la matriz.
    //  Pasa la matriz y el número de eventos.
    procesarEventos(matriz, NUM_EVENTOS);

    // 2. Imprimir el log de eventos.
    imprimirLog(NUM_EVENTOS);

    // 3. I,pri,ir el resumen por equipo.
    imprimirResumen(matriz);

    // 4. Le dice al sistema operativo que terminó bien
    return 0;
}

// ============================================================================
// FUNCIÓN: obtenreIdiceTipo (PASO POR VALOR)
// ============================================================================
// Recibe un número (tipo) por VALOR (una copia).
// Verificar que sea válido (0 a 3).
// Devuelve el indice si es valido, o -1 si no lo es.
// No modifica el valor original por que recibe una copia.
int obtenerIndiceTipo(int tipo) {
    // verificar que el tipo esté en el rango válidado.
    if (tipo >= 0 && tipo < NUM_TIPOS_EVENTO) {
        return tipo; // Válido: devuelve el indice
    }
    return -1; // Inválido: devuelve -1
}

// ============================================================================
// FUNCIÓN: incrementarContador (PASO POR REFERENCIA)
// ============================================================================
// Recibe un APUNTADORv a un entero (la dirección de memoria).
// Incrementa el valor en esa dierección en 1.
// si modifica el valor original porque recibe su dirección.
void incrementarContador(int *contador) {
     // *contador accede al valor apuntado.
     // (*contador)++ incrementa el valor en esa dirección en 1.
     // Los paréntesis son necerarios porque *contador++ se interpretaría.
     // como *(contador++), que es diferente.
     (*contador)++;

}
// =============================================================================
// FUNCIÓN: procesarEVentos(USA APUNTADORES)
// =============================================================================
// Recorre los arreglos de eventos usando ARIMÉTICA DE APUNTADORES.
// Para cada evento:
//  1. Obtiene el equipo y el tiempo.
//  2. Valida el tipo con obtenerIndiceTipo (paso por valor).
//  3. Incrementa la celda correspondiente con incrementarContador (paso por referencia).
void procesarEventos(int matriz[][NUM_TIPOS_EVENTO], int num_eventos) {
    // Apuntadores al inicio de los arreglos.
    // ptr_equipo apunta a equipos[0].
    // ptr_tipo apunta a tipos[0].
    int *ptr_equipo = equipos;
    int *ptr_tipo = tipos;

    // Recorre todos los eventos.
    for (int i = 0; i < num_eventos; i++){
        // *(ptr_equipo + i) es equivalente a equipos[i]
        // pero usando ARIMÉTICA DE APUNTADORES.
        int equipo = *(ptr_equipo + i);
        int tipo = *(ptr_tipo + i);

        // Valida el tipo (pasa por valor.
        int col = obtenerIndiceTipo(tipo);

        // Si el tipo es válido, incrementa la celda
        if (col != -1) {
            // &matriz[equipo][col] es la DIRECCIÓN de la celda.
            // incrementarContador la recibe por REFERENCIA.
            incrementarContador(&matriz[equipo][col]);
            
        }
    }
}

// =======================================================================
// FUNCIÓN: esSospechoso
// ========================================================================
// Suma los fallos (Contraseña_Incorrecta + Ususarios_Inexistente).
// Compara con x.
// Devueleve 1 si es sospechoso, 0 si no.
int esSospechoso(int matriz[][NUM_TIPOS_EVENTO], int equipo) {
    // Suma las columnas de fallos para esetipo.
    int fallos = matriz[equipo][CONTRASENA_INCORRECTA] +
                matriz[equipo][USUARIO_INEXISTENTE];

    // "más de X" significa extrictamente mayor que X.
    // Si X=3, entonces 4 o más es sospechoso.
    return fallos > x;  // Devuelve 1 (Verdadedo) 0 0 (falso)
}

// ==========================================================================
// FUNCIÓN: imprimirLog
// ===========================================================================
// Imprimir todos los eventos en orden.
// Usar nombre_equipos y nombres_tipos para mostrar texto legible.
void imprimirLog(int num_eventos) {
    printf("\n== LOG DE EVENTOS ===\n");

    for (int i = 0; i < num_eventos; i++) {
        // i+1 por que los eventos empiezan en 1, no en 0.
        // nombres_equipos[equipos[i]] obtiene el nombre del equipo.
        // nombres_tipos[tipos[i]] obtiene el nombre del equipo.
        // %2d = entero con al menos 2 digitos.
        // &-6s = string alineado a la izquierda en 6 caracteres.
        printf("Evento %2d: %-6s - %s\n",
                i + 1,
                nombres_equipos[equipos[i]],
                nombres_tipos[tipos[i]]);
    }
}
// =========================================================================
// FUNCIÓN: imprimirResumen
// =========================================================================
// Imprime la tabla de resumen por equipo.
// Muestra: Equipo, conteo de cada tipo, total fallos, y si es sospechoso.
void imprimirResumen(int matriz[][NUM_TIPOS_EVENTO]) {
    printf("\n=== RESUMEN POR EQUIPO ===\n");

    // Encabezados de la tabla.
    printf("%-8s %-8s %-12s %-10s %-10s %-8s %-12s\n",
        "Equipo", "Correcto", "Contraseña", "Usuario", "Bloqueado", "Fallos", "Sospechoso");

    // Rocorre cada equipo.
    for (int e = 0; e < NUM_EQUIPOS; e++) {
        // Calcula el total de fallos para este equipo
        int fallos = matriz[e][CONTRASENA_INCORRECTA] +
                     matriz[e][USUARIO_INEXISTENTE];

        // Imprimir la fila del equipo.
        // nombres_equipos[e] = nombre del equipo.
        // matriz[e][A(CCESO_CORRECTO] = conteo de acceso correto.
        //esSospechos(matriz, e) ? "Si" : "No" = if corto.
        printf("%-8s %-8d %-12d %-10d %-10d %-8d %-12s\n",
        nombres_equipos[e],
        matriz[e][ACCESO_CORRECTO],
        matriz[e][CONTRASENA_INCORRECTA],
        matriz[e][USUARIO_INEXISTENTE],
        matriz[e][ACCESO_BLOQUEADO],
        fallos,
        esSospechoso(matriz, e) ? "SI" : "NO");

    }
}

