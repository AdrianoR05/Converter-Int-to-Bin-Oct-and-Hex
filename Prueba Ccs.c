#include <18f4550.h>
#use delay(clock=8Mhz)
#include <hdm64gs12.c> // Libreria MANEJO LCD GRAFICO (lcdg)
#include <graphics.c> // Libreria FUNCIONES LCD GRAFICO
#define use_portb_kbd TRUE
#include <kbd4x4.c> // LIBRERIA MANEJO TECLADO MATRICIAL 4X4 (tm)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char prueba[20];
int16 numEnt;
char num[20] = "";
char num1, num2, num3, num4;
int numU, numD, numT, numC;
char choice;
int8 val;
char textTitle[40] = "Menu de Conversiones";
char textDec[40] = "1 Dec a Bin-Oct-Hex";
char textBin[40] = "2 Bin a Gray";
char textGray[40] = "3 Gray a Bin";

void readInput(char *input, int maxLength) {
    char key;
    int index = 0;
    while (index < maxLength - 1) {
        key = kbd_getc();
        if (key != 0) {
            if (key == '#') { // Assuming '#' is used to end input
                break;
            }
            if (key >= '0' && key <= '9') { // Only accept numeric characters
                input[index++] = key;
                glcd_text57(4 + (index * 6), 32, &key, 1, on); // Display the input character
            }
        }
    }
    input[index] = '\0'; // Null-terminate the string
}
void decimal_binary(int num, char bin[]) {
    int i = 0;
    int j;
    char temp[20];
    
    if (num == 0) {
        bin[0] = '0';
        bin[1] = '\0';
        return;
    }
    
    while (num > 0) {
        temp[i] = (num % 2) + '0';
        num = num / 2;
        i++;
    }
    
    // Invertir el array para obtener el binario correcto
    for (j = 0; j < i; j++) {
        bin[j] = temp[i - j - 1];
    }
    bin[i] = '\0';
}

void decimal_octal(int num, char oct[]) {
    int i = 0;
    int j;
    char temp[20];
    
    if (num == 0) {
        oct[0] = '0';
        oct[1] = '\0';
        return;
    }
    
    while (num > 0) {
        temp[i] = (num % 8) + '0';
        num = num / 8;
        i++;
    }
    
    // Invertir el array para obtener el octal correcto
    for (j = 0; j < i; j++) {
        oct[j] = temp[i - j - 1];
    }
    oct[i] = '\0';
}

void decimal_hexadecimal(int num, char hex[]) {
    int i = 0;
    int j;
    char temp[20];
    char hex_chars[] = "0123456789ABCDEF";
    
    if (num == 0) {
        hex[0] = '0';
        hex[1] = '\0';
        return;
    }
    
    while (num > 0) {
        temp[i] = hex_chars[num % 16];
        num = num / 16;
        i++;
    }
    
    // Invertir el array para obtener el hexadecimal correcto
    for (j = 0; j < i; j++) {
        hex[j] = temp[i - j - 1];
    }
    hex[i] = '\0';
}

void decToBinOctHex(){
    char input[20];
    char bin[20], oct[20], hex[20];
    const char *text1 = "Ingrese Decimal:";
    const char *text2 = "Binario:";
    const char *text3 = "Octal:";
    const char *text4 = "Hexadecimal:";
    
    glcd_text57(4, 16, text1, 1, on);
    readInput(input, 20);
    
    int numEnt = atoi(input); // Convertir la cadena a entero
    
     // Convertir a binario
    decimal_binary(numEnt, bin);
    // Convertir a octal
    decimal_octal(numEnt, oct);
    // Convertir a hexadecimal
    decimal_hexadecimal(numEnt, hex);
    
    glcd_fillscreen(0);
    
    // Mostrar las conversiones con un espaciado adecuado
    glcd_text57(4, 8, text2, 1, on);
    glcd_text57(4, 16, bin, 1, on);
    delay_ms(1000);
    
    glcd_text57(4, 24, text3, 1, on);
    glcd_text57(4, 32, oct, 1, on);
    delay_ms(1000);
    
    glcd_text57(4, 40, text4, 1, on);
    glcd_text57(4, 48, hex, 1, on);
    delay_ms(1000);
}



void binaryToGray(char bin[], char gray[], int n) {
    gray[0] = bin[0]; // MSB of Gray code is same as that of given Binary code
    for (int i = 1; i < n; i++) {
        gray[i] = (bin[i] == bin[i-1]) ? '0' : '1';
    }
    gray[n] = '\0'; // Null-terminate the string
}

void grayToBinary(char gray[], char bin[], int n) {
    bin[0] = gray[0]; // MSB of Binary code is same as that of given Gray code
    for (int i = 1; i < n; i++) {
        bin[i] = (gray[i] == '0') ? bin[i-1] : (bin[i-1] == '0' ? '1' : '0');
    }
    bin[n] = '\0'; // Null-terminate the string
}



void convertBinToGray() {
    char bin[20], gray[20];
    const char *text1 = "Ingrese Binario:";
    const char *text2 = "Gray Code:";
    
    glcd_text57(4, 16, text1, 1, on);
    readInput(bin, 20);
    
    int n = strlen(bin);
    binaryToGray(bin, gray, n);
    
    glcd_fillscreen(0);
    glcd_text57(4, 8, text2, 1, on);
    glcd_text57(4, 16, gray, 1, on);
}

void convertGrayToBin() {
    char gray[20], bin[20];
    const char *text3 = "Ingrese Gray:";
    const char *text4 = "Binary Code:";
    
    glcd_text57(4, 16, text3, 1, on);
    readInput(gray, 20);
    
    int n = strlen(gray);
    grayToBinary(gray, bin, n);
    
    glcd_fillscreen(0);
    glcd_text57(4, 8, text4, 1, on);
    glcd_text57(4, 16, bin, 1, on);
}

void main(){
   kbd_init(); // Inicia el tm
   glcd_init(on); // inicia el lcdg
   glcd_fillscreen(0); //limpia el lcdg
   choice = 0;
   val = 0;
   
   while(true){
      
      
      
      num1 = 0;
      num2 = 0;
      num3 = 0;
      num4 = 0;
      choice = 0;
      glcd_fillscreen(0); //limpia el lcdg
      glcd_text57(0,0,textTitle,1,on);
      glcd_text57(4,16,textDec,1,on);
      glcd_text57(4,32,textBin,1,on);
      glcd_text57(4,50,textGray,1,on);
      do{
      choice = kbd_getc();
      } while(choice==0);
      //glcd_fillscreen(0);
      val=choice-48;
      //glcd_text57(4,4,val,1,on);
      //delay_ms(1000);
      
      switch (val) {
            case 1:
            glcd_fillscreen(0);
               glcd_text57(4,4,textDec,1,on);
               decToBinOctHex();
               delay_ms(1000);
                break;
            case 2:
            glcd_fillscreen(0);
                glcd_text57(4, 4, textBin, 1, on);
                convertBinToGray();
                delay_ms(1000);
                break;
            case 3:
            glcd_fillscreen(0);
                glcd_text57(4,4,textGray,1,on);
                convertGrayToBin();
                delay_ms(1000);
                break;
        }
      
   }
}
