# 🖥️ Mini Shell en C

Este proyecto implementa un **shell básico en C** con algunos comandos propios y gestión de procesos mediante llamadas al sistema POSIX.  
El objetivo es comprender el funcionamiento interno de un intérprete de comandos y practicar la creación/ejecución de procesos, paso de parámetros y control de errores.

---

## ⚙️ Funcionalidad

El shell muestra un prompt personalizado:
´´´bash
//>
´´´
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
´´´
