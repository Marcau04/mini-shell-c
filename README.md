# 🖥️ Mini Shell en C

Este proyecto implementa un **shell básico en C** con algunos comandos propios y gestión de procesos mediante llamadas al sistema POSIX.  
El objetivo es comprender el funcionamiento interno de un intérprete de comandos y practicar la creación/ejecución de procesos, paso de parámetros y control de errores.

---

## ⚙️ Funcionalidad

El shell muestra un prompt personalizado:
```bash
//>
```
Y permite ejecutar los siguientes comandos:

- **`salir`**  
  Termina la ejecución del shell.

- **`muestra [fichero]`**  
  Muestra el contenido de un fichero (usa internamente `/bin/cat`).  
  - Si no se proporciona fichero, se espera entrada estándar.  
  - Acepta 0 o 1 parámetro.  

- **`lista [directorio]`**  
  Lista los ficheros de un directorio (usa internamente `/bin/ls`).  
  - Acepta 0 o 1 parámetro.  

- **`copia <origen> <destino>`**  
  Copia el contenido de un fichero a otro usando un binario auxiliar (`./copia`).  
  - Requiere exactamente 2 parámetros.  

- **Cualquier otro comando**  
  Devuelve un error indicando que la orden no es válida.

---

## 🚀 Compilación y ejecución

### Compilación
```bash
gcc shell.c -o shell
```
### Ejecución
```bash
./shell
```
El prompt quedará a la espera de comandos hasta que se introduzca salir.

--- 

## 📖 Ejemplo de uso

```bash
//> lista
# muestra los ficheros del directorio actual

//> muestra fichero.txt
# muestra el contenido de fichero.txt

//> copia origen.txt destino.txt
# copia el contenido de origen.txt en destino.txt

//> salir
# termina la ejecución
```

---

## 🛠️ Tecnologías utilizadas

- Lenguaje: C

- Llamadas al sistema: fork, execvp, wait, read, write

- Manejo dinámico de memoria con malloc y free

---

## ✨ Aprendizaje

Este proyecto me permitió:

- Comprender el funcionamiento básico de un shell.

- Manejar procesos en C y la comunicación entre padre/hijo.

- Usar execvp para delegar comandos a binarios del sistema.

- Implementar parsing simple de entrada con strtok.

- Practicar control de errores y validación de parámetros.

---

## 👤 Autores

- Marcos Alonso Ulloa (@Marcau04)
- Gonzalo Sánchez Maroto
