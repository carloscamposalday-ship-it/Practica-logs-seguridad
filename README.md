Análisis de Registros de Ataques

Programa en C que analiza registros de acceso a un servidor para detectar equipos con comportamiento sospechoso.

El programa:
- Lee un arreglo de eventos (equipo + tipo de evento)
- Construye una matriz de conteos por equipo y tipo
- Aplica la regla: si un equipo acumula más de 3 fallos (Contraseña_Incorrecta + Usuario_Inexistente), se marca como sospechoso
- Imprime el log de eventos y el resumen por equipo

Compilación

gcc Proyecto_logs.c -o Proyecto_logs

Ejecución

./Proyecto_logs

Documentación

- Diseño: https://github.com/carloscamposalday-ship-it/Proyecto_logs/wiki/Diseño
- PSPO: https://github.com/carloscamposalday-ship-it/Proyecto_logs/wiki/PSPO
- Pruebas: https://github.com/carloscamposalday-ship-it/Proyecto_logs/wiki/Pruebas
