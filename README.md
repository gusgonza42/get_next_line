<div align="center">
<h1>get_next_line</h1>
<img src="https://raw.githubusercontent.com/gusgonza42/my-utils-gusgonza/main/ft_badges_42/badge_01_get_next_line_500px.png" style="width: 150px; height: 150px;">


[![Build Status](https://img.shields.io/static/v1?label=Build%20Status&message=success&color=green)](https://github.com/gusgonza42/get_next_line)

</div>
- - -

Claro, aquí tienes una versión en español para incluir en el README de tu proyecto:

---

## 💡 Acerca del Proyecto

> _El objetivo de este proyecto es implementar una función que devuelva una línea leída desde un descriptor de archivo._

Este proyecto te permitirá entender cómo se abren, leen y cierran archivos en un sistema operativo, y cómo son interpretados por C. Esta tarea es fundamental para cualquier programador, ya que gran parte del tiempo se basa en la manipulación de archivos para la gestión y persistencia de datos. Consiste en codificar una función que devuelve una línea a la vez desde un archivo de texto.

Para obtener información más detallada, consulta el [**Subject**](https://github.com/gusgonza42/get_next_line/blob/main/get_next_line-es.subject.pdf).

## 🛠️ Uso

### Requisitos

La función está escrita en lenguaje C y por lo tanto requiere el compilador **gcc** y algunas **bibliotecas estándar de C** para funcionar.

### Instrucciones

**1. Uso en tu código**

Para utilizar la función en tu código, simplemente incluye su encabezado:

```C
#include "get_next_line.h"
```

y al compilar tu código, agrega los archivos fuente y los FLAGS necesarios:

```shell
gcc get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<tamaño>
```

## 📋 Pruebas

Solo necesitas editar el archivo get_next_line.c y descomentar la función main y los encabezados dentro de él. Puedes editar los archivos test.txt para colocar otro texto si deseas probar otros casos. Luego, simplemente ejecuta este comando (cambia "xx" con el tamaño del buffer deseado):

```shell
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c && ./a.out
```


