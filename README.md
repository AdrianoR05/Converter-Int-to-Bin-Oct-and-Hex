<div align="center">
  <a href="#english-version">🇺🇸 English</a> | <a href="#versión-en-español">🇪🇸 Español</a>
</div>

---

# 🇺🇸 English Version

# 🔢 Converter: Int to Bin, Oct, Hex & Gray Code

This repository contains the source code for an interactive system based on the **PIC18F4550** microcontroller. The project allows for conversions between different numeral systems (Decimal, Binary, Octal, Hexadecimal) and Gray code, utilizing a GLCD screen for display and a 4x4 matrix keypad for data entry.

## ✨ Main Features

The system features an interactive menu that allows the user to select between three main operating modes:

1. **Decimal to multiple bases conversion:** Converts an input decimal number to its equivalent in **Binary**, **Octal**, and **Hexadecimal** simultaneously.
2. **Binary to Gray conversion:** Takes a binary string and converts it to Gray Code.
3. **Gray to Binary conversion:** Performs the reverse operation, transforming Gray Code back to Binary format.

## 🛠️ Hardware Required

To implement or simulate this project (e.g., in Proteus), you will need:

* **Microcontroller:** PIC18F4550 (operating with an 8MHz clock).
* **Display:** Graphic LCD compatible with the HDM64GS12 controller.
* **Input:** 4x4 Matrix Keypad (connected to Port B of the microcontroller).

## 💻 Dependencies and Libraries

The code is written in C and is designed to be compiled with the **CCS C Compiler**. It uses the following libraries:

* `18f4550.h`: Main microcontroller header.
* `hdm64gs12.c`: Graphic LCD hardware management.
* `graphics.c`: Drawing and text functions for the Graphic LCD.
* `kbd4x4.c`: Custom driver (included in the repository) for scanning and debouncing the 4x4 matrix keypad.

## 🚀 System Usage

1. Upon powering up the system, the screen will display the **"Menu de Conversiones"** (Conversion Menu).
2. Use the matrix keypad to press the number of the desired option (`1`, `2`, or `3`).
3. Enter the number you wish to convert using the numeric keypad.
4. Press the `#` key to confirm the input.
5. The results will be displayed on the GLCD screen. The system will automatically return to the main menu to perform a new operation.

## 📂 Code Structure

* `Prueba Ccs.c`: Contains the main program logic, user menu, and mathematical functions for the conversions.
* `KBD4x4.c`: Header file that manages the matrix keypad reading, including pin configuration and debouncing mitigation.

## 📄 License

This project is licensed under the **GNU General Public License v3.0 (GPLv3)** - see the [LICENSE](LICENSE) file for details.

---

<br>

# 🇪🇸 Versión en Español

# 🔢 Converter: Int to Bin, Oct, Hex & Gray Code

Este repositorio contiene el código fuente para un sistema interactivo basado en el microcontrolador **PIC18F4550**. El proyecto permite realizar conversiones entre diferentes sistemas numéricos (Decimal, Binario, Octal, Hexadecimal) y código Gray, utilizando una pantalla GLCD para la visualización y un teclado matricial 4x4 para el ingreso de datos.

## ✨ Características Principales

El sistema cuenta con un menú interactivo que permite al usuario seleccionar entre tres modos de operación principales:

1. **Conversión de Decimal a múltiples bases:** Convierte un número decimal ingresado a su equivalente en **Binario**, **Octal** y **Hexadecimal** simultáneamente.
2. **Conversión de Binario a Gray:** Toma una cadena binaria y la convierte a Código Gray.
3. **Conversión de Gray a Binario:** Realiza la operación inversa, transformando Código Gray de vuelta a formato Binario.

## 🛠️ Hardware Requerido

Para implementar o simular este proyecto (por ejemplo, en Proteus), necesitarás:

* **Microcontrolador:** PIC18F4550 (operando con un reloj de 8MHz).
* **Pantalla:** LCD Gráfico compatible con el controlador HDM64GS12.
* **Entrada:** Teclado Matricial 4x4 (conectado al Puerto B del microcontrolador).

## 💻 Dependencias y Librerías

El código está escrito en C y está diseñado para ser compilado con **CCS C Compiler**. Hace uso de las siguientes librerías:

* `18f4550.h`: Cabecera principal del microcontrolador.
* `hdm64gs12.c`: Manejo del hardware del LCD Gráfico.
* `graphics.c`: Funciones de dibujo y texto para el LCD Gráfico.
* `kbd4x4.c`: Driver personalizado (incluido en el repositorio) para el escaneo y manejo del teclado matricial 4x4 con *debouncing*.

## 🚀 Uso del Sistema

1. Al encender el sistema, la pantalla mostrará el **"Menú de Conversiones"**.
2. Utiliza el teclado matricial para presionar el número de la opción deseada (`1`, `2` o `3`).
3. Ingresa el número que deseas convertir utilizando los números del teclado.
4. Presiona la tecla `#` para confirmar el ingreso del número.
5. Los resultados se mostrarán en la pantalla GLCD. El sistema regresará al menú principal automáticamente para realizar una nueva operación.

## 📂 Estructura del Código

* `Prueba Ccs.c`: Contiene la lógica principal del programa, el menú de usuario y las funciones matemáticas para las conversiones.
* `KBD4x4.c`: Archivo de cabecera que gestiona la lectura del teclado matricial, incluyendo la configuración de pines y la mitigación de rebotes (*debounce*).

## 📄 Licencia

Este proyecto está bajo la licencia **GNU General Public License v3.0 (GPLv3)** - mira el archivo [LICENSE](LICENSE) para más detalles.
