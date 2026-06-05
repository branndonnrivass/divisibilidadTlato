#include <stdio.h>
#include <stdlib.h>
//no esta protejido contra todo no sean pasados de rosca
//ദ്ദി ˉ͈̀꒳ˉ͈́ )✧
typedef struct 
{
   int q;
   int r;
} Div;//braulio agrego las estructuas,se le hace mas facil dice

// Estructura para almacenar los resultados durante el euclides.
typedef struct
{
    int mcd;
    int x;
    int y;
} BezoutOut;

Div divicion(int a, int b);
void Euclides(int a, int b);
BezoutOut EuclidesExtendido(int a, int b);

int main()
{
    int a, b;
    int op;
    //menu bonito porque solo programo cosas en consola :)
    printf("\nIngresar opcion:\n");
    printf("===============\n");
    printf("1.- Forma de la divisibilidad\n");
    printf("2.- Algoritmo de Euclides \n");
    printf("3.- Euclides Extendido\n");
    printf("Opcion ->");

    if (scanf("%d", &op) != 1) return 1;

    switch (op)
    {
    case 1: // Forma de la divisibilidad
        printf("ingresar dividendo: ");
        scanf("%d", &a);
        printf("ingresar divisor: ");
        scanf("%d", &b);

        if (b == 0) {
            printf("Error: Division por cero.\n");
            break;//no calen el break santillan dice que es mala practica pero ya no me acuerdo porque
        }

        Div d2;
        d2 = divicion(a, b);
        printf("Forma de la divisibilidad: %d = %d * %d + %d\n", a, b, d2.q, d2.r);
        break;

    case 2: //Euclides 
        printf("ingresar primer termino: ");
        scanf("%d", &a);
        printf("ingresar segundo termino: ");
        scanf("%d", &b);
//tomen awa
        Euclides(a, b);
        break;
    
    case 3: // euclides pero con bezout ,porque hacer otra funcion distinta esta dificultoso
        printf("ingresar primer termino (a): ");
        scanf("%d", &a);
        printf("ingresar segundo termino (b): ");
        scanf("%d", &b);

        BezoutOut res = EuclidesExtendido(a, b);
        printf("\nResultados:\n");
        printf("MCD(%d, %d) = %d\n", a, b, res.mcd);
        printf("Coeficientes de Bezout: x = %d, y = %d\n", res.x, res.y);
        printf("Combinacion lineal: %d*(%d) + %d*(%d) = %d\n", a, res.x, b, res.y, res.mcd);
        break;
        
    default:
        printf("Opcion no valida.\n");
        break;
    }

    return 0;
}

// Tu funcion de division por restas sucesivas (mantenida intacta)
Div divicion(int a, int b) {
    Div d1;
    d1.q = 0;
    d1.r = abs(a);

    if ((a >= 0) && (b > 0)) {
        while (d1.r >= abs(b)) {
            d1.r = d1.r - abs(b);
            d1.q++;
        }
    }
    if ((a >= 0) && (b < 0)) {
        while (d1.r >= abs(b)) {
            d1.r = d1.r - abs(b);
            d1.q++;
        }
        d1.q = -d1.q;
    }
    if ((a < 0) && (b > 0)) {
        while (d1.r >= abs(b)) {
            d1.r = d1.r - abs(b);
            d1.q++;
        }
        //toquen pasto
        if (d1.r != 0) {
            d1.q = -(d1.q + 1);
            d1.r = b - d1.r;
        } else {
            d1.q = -d1.q;
        }
    }
    if ((a < 0) && (b < 0)) {
        while (d1.r >= abs(b)) {
            d1.r = d1.r - abs(b);
            d1.q++;
        }
        if (d1.r != 0) {
            d1.q++;
            d1.r = ((-b) - d1.r);
        } else {
            d1.q = -d1.q;
        }
    }
    return d1;
}
//La neta media hora en 5 lineas. que rabia
void Euclides(int a, int b) {
    while (b != 0) {
        Div d = divicion(a, b);
        a = b;
        b = d.r;
    }
    printf("\nMaximo comun divisor: %d\n", a);
}

// Algoritmo de Euclides Extendido 
BezoutOut EuclidesExtendido(int a, int b) {
    int x0 = 1, x1 = 0;
    int y0 = 0, y1 = 1;
    
    while (b != 0) {
        Div d = divicion(a, b);
        
        int temp_a = b;
        b = d.r;
        a = temp_a;
        
        // Actualizacion de los coeficientes de Bezout
        //para ser jsutos, esto no lo hubiera resulto asi , 
        //yo hubiera usado un arreglo , pero encontre esta solucion en stakoverfloww 
        int temp_x = x1;
        x1 = x0 - d.q * x1;
        x0 = temp_x;
        
        int temp_y = y1;
        y1 = y0 - d.q * y1;
        y0 = temp_y;
    }
    
    BezoutOut resultado;
    resultado.mcd = a;
    resultado.x = x0;
    resultado.y = y0;
    
    return resultado;
}

int leerEnteroSeguro(const char* mensaje) {
    int valor;
    int valido = 0;
    char c;

    while (!valido) {
        printf("%s", mensaje);
        
        // scanf devuelve la cantidad de elementos exitosamente leidos
        if (scanf("%d", &valor) == 1) {
            valido = 1; // Exito
        } else {
            printf("Error: Entrada no valida. Introduce un numero entero.\n");
        }

        // Limpiar el bufer de entrada (stdin) hasta encontrar un salto de linea o fin de archivo
        while ((c = getchar()) != '\n' && c != EOF);
    }
    return valor;
}
