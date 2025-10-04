
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROMPT "//> "
#define TAM_MAX_ENTRADA 1000

int main() {
    //Se definen las variables a usar.
    int i, pid, num_parametros = 1;
    char entrada[TAM_MAX_ENTRADA];
    char *str;
    char **listaArgv;
    char *errorComando;
    int longitud_errorComando;
    char salir = 0;

    while (salir == 0) {
        //Se inicializan las variables necesarias.
        i = 0;
        num_parametros = 1;
        listaArgv = malloc(sizeof(char)*num_parametros);

        //Se imprime por la salida estandar el prompt.
        write(1, PROMPT, strlen(PROMPT));

        //Se lee el comando y sus posibles parametros mientras se introducen en el shell.
        read(0, &entrada[i], 1);
        while (entrada[i] != '\n' && i < (TAM_MAX_ENTRADA - 1)) {
            read(0, &entrada[++i], 1);
        }
        entrada[i] = '\0';
        //Se separa la entrada en los distintos componentes de argv.
        str = strtok(entrada, " ");
        if (str != NULL) {
            for (i = 0; str != NULL; i++) {
                listaArgv = realloc(listaArgv, (i+2) * sizeof(char *));
                listaArgv[i]=malloc((strlen(str)+1)*sizeof(char));
                strcpy(listaArgv[i],str);
                str = strtok(NULL, " ");
                num_parametros += 1;
            }
            listaArgv[i] =  NULL;
            //Comando "salir".
            if (strcmp(listaArgv[0], "salir") == 0) {
                salir = 1;

            //Comando "muestra", con su comprobacion de errores y ejecucion por parte de un proceso hijo.
            } else if (strcmp(listaArgv[0], "muestra") == 0) {
                if (num_parametros > 3) {
                    write(2,"AVISO. Comando muestra, unicamente funciona para 0 o 1 parametros.\n",strlen("AVISO. Comando muestra, unicamente funciona para 0 o 1 parametros.\n"));

                }
                else {
                    //Se crea el proceso hijo y se ejecuta el comando.
                    pid = fork();
                    if (pid == -1) {
                        write(2,"Error al crear el proceso hijo.\n",strlen("Error al crear el proceso hijo.\n"));
                    } else if (pid == 0) {
                        if(execvp("/bin/cat", listaArgv)==-1){
                            write(2,"Error al ejecutar el comando muestra.\n",strlen("Error al ejecutar el comando muestra.\n"));
                        }
                        if(execvp("/bin/cat", listaArgv)==-1){
                            write(2,"Error al ejecutar el comando muestra.\n",strlen("Error al ejecutar el comando muestra.\n"));
                        }
                    } else {
                        wait(0);
                    }
                }

            //Comando "lista", con su comprobacion de errores y ejecucion por parte de un proceso hijo.
            } else if (strcmp(listaArgv[0], "lista") == 0) {
                if (num_parametros > 3) {
                    write(2,"AVISO. Comando lista, unicamente funciona para 0 o 1 parametros.\n",strlen("AVISO. Comando lista, unicamente funciona para 0 o 1 parametros.\n"));

                } else {
                    //Se crea el proceso hijo y se ejecuta el comando.
                    pid = fork();
                    if (pid == -1) {
                        write(2,"Error al crear el proceso hijo.\n",strlen("Error al crear el proceso hijo.\n"));
                    } else if (pid == 0) {
                        if(execvp("/bin/ls", listaArgv)==-1){
                            write(2,"Error al ejecutar el comando lista.\n",strlen("Error al ejecutar el comando lista.\n"));
                        }
                    } else {
                        wait(0);
                    }
                }

            //Comando "copia", con su comprobacion de errores y ejecucion por parte de un proceso hijo.
            } else if (strcmp(listaArgv[0], "copia") == 0) {
                if(num_parametros > 4){
                    write(2,"AVISO. Comando copia,unicamente funciona para 2 parametros\n",strlen("AVISO. Comando copia, unicamente funciona para 2 parametros\n"));

                } else {
                    //Se crea el proceso hijo y se ejecuta el comando.
                    pid = fork();
                    if (pid == -1) {
                        write(2,"Error al crear el proceso hijo.\n",strlen("Error al crear el proceso hijo.\n"));
                    } else if (pid == 0) {
                        if(execvp("./copia", listaArgv)==-1){
                            write(2,"Error al ejecutar el comando copia.\n",strlen("Error al ejecutar el comando copia.\n"));
                        }
                    } else {
                        wait(0);
                    }
                }

            //En caso de que el comando introducido no coincida con los anteriores se lanza un error en pantalla.
            } else {
                errorComando = malloc(TAM_MAX_ENTRADA*sizeof(char));
                sprintf(errorComando,"ERROR. La orden %s no es un comando valido. Use muestra, copia o lista.\n",listaArgv[0]);
                write(2,errorComando,strlen(errorComando));
            }
            //Se libera la memoria de cada uno de los parametros.
            for(i = 0; i < num_parametros; i++) {
                free(listaArgv[i]);
            }
        }
        //Se libera la memoria del array.
        free(listaArgv);
    }

    return 0;
}