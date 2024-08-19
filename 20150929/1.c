/*algoritam
kojim se učitava prirodan broj n, a zatim određuje i
ispisuje par najmanjih blizanaca većih od n. Dva prirodna
broja su blizanci ako su prosti i razlikuju se za dva.
Prirodan broj veći od jedan je prost ako je djeljiv samo sa
jedan i samim sobom. Npr. blizanci su 3 i 5, 5 i 7, 11 i
13, itd.
rok 29.09.2015*/


#include <stdio.h>


int main()
{
    int n;
    printf("Unesite n:");
    scanf("%d",&n);

    int prvi=n;                 //2   3

    while(1)    //pitati za petlju
    {

        int ProstPrvi=1;
        int ProstDrugi=1;

        for(int i=2; i*i<=prvi; i++)
        {
            if(prvi%i==0)
            {

                ProstPrvi=0;
                break;
            }
        }


        int drugi=prvi+2;
        for(int i =2; i*i<=drugi; i++)
        {
            if(drugi%i==0)
            {

                ProstDrugi=0;
                break;
            }
        }

        if(ProstDrugi&&ProstPrvi)
        {
            printf("To su brojevi %d i %d", prvi, drugi);
            break;
        }


        prvi++;
    }

    return 0;
}
