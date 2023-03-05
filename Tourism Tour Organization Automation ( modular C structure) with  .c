#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
#include "turlar.h"
#include "musteri.h"
#include "rezervasyon.h"



// Moduler Yapı ile Turizm Tur Organizasyon Otomasyonu



int menu()

{   

    int secim;
    printf("\n\n\tTURIZIM TUR ORGANIZASYON OTOMASYONU\n\n");
    printf("\n\t1-TUR ISLEMLERI\n");
    printf("\n\t2-MUSTERI ISLEMLERI\n");
    printf("\n\t3-REZERVASYON ISLEMLERI\n");
    printf("\n\t0-PROGRAM KAPAT\n");
    printf("\n\tLutfen seciminizi yapiniz: ");
    scanf("%d",&secim);

    return secim;

}




int main ()
{
   
   int secim;
   secim=menu();

   while(secim!=0) // eger 0'a esit olursa program kapanir !
   {
    
      switch(secim)
      {
           case 1:
                turIslemleri();    
                break;

              case 2:
                    musterIslemleri();
                    break;

                case 3:
                    rezervasyonIslemleri();
                    break;

                default:
                printf("Yanlis secim yaptiniz");
                break;
      }
    
    secim=menu();

   }

   printf("program kapatiliyor...");


    return 0;
}


