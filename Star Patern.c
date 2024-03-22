#include <stdio.h>

int main(){

    int rows, i, j;
    printf("Enter a number of rows: ");
    scanf("%d", &rows);

    for(i = 1; i <= rows; i++){ // die äussere schleife wird gestartet, sie läuft von 1 bis zur eingegebenen anzahl der rows
        for(j = 1; j <= rows - i; j++){ // hier werden leerzeichen ausgegeben. die anzahl der leerzeichen ist abhängig von der aktuellenn zeilennummer i und der gewünschten anzahl der zeilen rows. es werden immer weniger leerzeichen ausgegeben je weiter die äusserste schleife fortfährt
            printf(" ");
        }
        for(j = 1; j <= rows; j++){ // macht das gleiche wie die äusserste schleife, jedoch sorgt die schleife dazu, dass die Sterne in jeder zeile gleich sind. 
            printf("*");
        }
        printf("\n");
    }
    return 0;
}