# Estructura de Datos Lab 1

**Larga vida a Olognia.**

En el pueblo de Olognia, un error en el **Programa Experimental de Poder Extremo** ha causado que esbirros ataquen el 
pueblo. Para defenderlo, un héroe deberá enfrentarlos uno a uno en el orden en que son generados.

El objetivo del programa es implementar una simulación de batalla utilizando una **deque** para manejar a los esbirros y determinar
si el héroe logra salvar a Olognia antes de que su vida llegue a 0.

## Requisitos

Para compilar y ejecutar este proyecto, se necesita:
- Un compilador de C++ compatible con C++14
- [CMake](https://cmake.org/) versión 3.10 o superior.

## Instrucciones de Construcción
### Linux/macOS

1. Abre una terminal y navega al directorio del proyecto:
   ```sh
   cd path/to/Estructura-de-Datos-Lab-1
   ```

2. Crea un directorio `build` y accede a él:
   ```sh
   mkdir build
   cd build
   ```

3. Genera los archivos de construcción con CMake:
   ```sh
   cmake ..
   ```

4. Construye el proyecto:
   ```sh
   make
   ```

5. Ejecuta el programa:
   ```sh
   ./Estructura-de-Datos-Lab-1
   ```

### Windows

1. Abre una terminal o PowerShell y navega al directorio del proyecto:
   ```cmd
   cd path\to\Estructura-de-Datos-Lab-1
   ```

2. Crea un directorio `build` y accede a él:
   ```cmd
   mkdir build
   cd build
   ```

3. Genera los archivos de construcción con CMake:
   ```cmd
   cmake ..
   ```

4. Construye el proyecto:
   ```cmd
   cmake --build .
   ```

5. Ejecuta el programa:
   ```cmd
   .\Estructura-de-Datos-Lab-1.exe
   ```

## **Ejemplo de Uso**

### Entrada
```
25
7
2 3 2 9 2 3 2
1 2 1 3 1 2 1
0 0 0 1 0 0 0
```

### Salida
```
26
EZ pizi
```

En este ejemplo:
- El héroe comienza con **25 puntos de vida**.
- Hay **7 esbirros**, con sus respectivas características:
    - Vida: `2 3 2 9 2 3 2`
    - Ataque: `1 2 1 3 1 2 1`
    - Tipo: `0 0 0 1 0 0 0` (solo el cuarto esbirro es un **CANO**).
- La simulación determina que el mechón logra salvar el pueblo, causando un total de **26 puntos de daño**.

## Autores
- Daniel Aburto Rivera ([@daaburto](https://github.com/daaburto))
- Joaquín Sandoval Reyes ([@joaqsandoval04](https://github.com/joaqsandoval04))