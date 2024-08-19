/*Dijagramom toka predstaviti
algoritam koji učitava prirodne brojeve a i b (a<b),
a zatim ispisuje sve brojeve iz intervala [a, b] koji
ispunjavaju uslov da je zbir svih cifara broja
jednak kvadratu najlakše cifre. Na primer, broj 63
ispunjava dati uslov, jer je 6 + 3 = 3 * 3.
Rok 07.09.2020*/

#include <stdio.h>

int main()
{
    int a,b;
    printf("Unesite a i b");
    scanf("%d %d",&a,&b);

    for (int i=a; i<=b; i++)
    {
        int temp=i;

        int najmanja=9;
        int suma=0;

        while(temp>0)
        {

            int cifra=temp%10;
            suma+=cifra;

            if(cifra<najmanja)
            {
                najmanja=cifra;
            }


            temp /= 10;
        }

        if(najmanja*najmanja==suma)
        {
            printf("Suma i kvadrat su jednaki i to je bro %d\n",i);
        }
    }

    return 0;
}
