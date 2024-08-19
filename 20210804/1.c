/*algoritam koji uD
itava prirodan broj n (nb	%100), a
zatim ispisuje zbir cifara broja n te informaciju o
tome da li je taj zbir prost broj. Prirodan broj veci
od jedan je prost ako je deljiv samo sa jedan i
samim sobom.
24.08.2021 */
//13  706
//sam + iz prve :)

#include <stdio.h>

int main()
{
    int n;

    printf("Unesite n:");
    scanf("%d",&n);

    int zbir=0;
    int temp=n;

    while(temp>0)
    {
        int cifra=temp%10;

        zbir+=cifra;

        temp/=10;
    }


    int prost=1;
    for(int i=2; i*i<=zbir; i++)
    {
        if(zbir%i==0)
        {
            prost=0;
            break;
        }
    }
    if(prost==1)
    {
        printf("Zbir svih cifara %d je %d i to je prost broj",n, zbir);
    }
    else printf("Zbir svih cifara %d je %d i to nije prost broj", n,zbir);
    return 0;
}
