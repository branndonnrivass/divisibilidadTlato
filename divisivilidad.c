#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
   int q;
   int r;
}Div;

Div divicion(int a, int b);
void Euclides(int a, int b);

int main()
{
    /*holla perritos mi codigo para la division*/
    int a,b,q=0,r;
    printf("ingresar dividendo:");
    scanf("%d",&a);
    printf("ingresar divisor:");
    scanf("%d",&b);
    Div d2 ;
    
    
    d2= divicion(a,b);


    printf(" %d=%d * %d + %d",a,b,d2.q,d2.r);
    Euclides(a,b);
        return 0;
}


Div divicion(int a , int b ){
    Div d1;
    d1.q=0;

    d1.r=abs(a);
    if((a>=0) &&(b>0))  {
        while ( d1.r >= abs(b))
        {
        
            d1.r=d1.r-abs(b);

            d1.q++;
        }
    }
    if((a>=0) &&(b<0))  {
        while ( d1.r >= abs(b))
        {
        
            d1.r=d1.r-abs(b);

            d1.q++;
        }
        d1.q=-d1.q;
    }

    if((a<0) &&(b>0))  {
        while ( d1.r >= abs(b))
        {
        
            d1.r=d1.r-abs(b);

            d1.q++;
        }
        if (d1.r!=0)
        {
           d1.q = -(d1.q + 1);
            d1.r = b - d1.r;
        }
        else
            d1.q=-d1.q;
        
    }

      if((a<0) &&(b<0))  {
        while ( d1.r >= abs(b))
        {
        
            d1.r=d1.r-abs(b);

            d1.q++;
        }
        if (d1.r!=0)
        {
           d1.q ++;
            d1.r = ((-b) - d1.r);
        }
        else
            d1.q=-d1.q;
        
    }
 return d1;
}



void Euclides(int a, int b){
while (b!=0)
{
 Div d ;

d=divicion(a,b);
a=b;
b=d.r;
}
printf("\n Maximo comun divisor : %d",a);




}