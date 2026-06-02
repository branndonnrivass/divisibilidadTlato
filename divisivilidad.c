#include <stdio.h>


int main()
{
    /*holla perritos mi codigo para la division*/
    int a,b,q=0,r;
    printf("ingresar dividendo:");
    scanf("%d",&a);
    printf("ingresar divisor:");
    scanf("%d",&b);
    r=abs(a);
    if((a>=0) &&(b>0))  {
        while ( r >= abs(b))
        {
        
            r=r-abs(b);

            q++;
        }
    }
    if((a>=0) &&(b<0))  {
        while ( r >= abs(b))
        {
        
            r=r-abs(b);

            q++;
        }
        q=-q;
    }

    if((a<0) &&(b>0))  {
        while ( r >= abs(b))
        {
        
            r=r-abs(b);

            q++;
        }
        if (r!=0)
        {
           q = -(q + 1);
            r = b - r;
        }
        else
            q=-q;
        
    }

      if((a<0) &&(b<0))  {
        while ( r >= abs(b))
        {
        
            r=r-abs(b);

            q++;
        }
        if (r!=0)
        {
           q ++;
            r = ((-b) - r);
        }
        else
            q=-q;
        
    }


    printf(" %d=%d * %d + %d",a,b,q,r);
        return 0;
}
