#include "turlar.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>

tur t1;

void turEkle()
{

    printf("Tur Ekleme Ekranina Hosgeldiniz\n");
    FILE *numPtr = fopen("turNumarasi.dat","a+b");
    int numara;
    numara=0;
    while (fread(&numara,sizeof(int),1,numPtr)!=NULL) // Null hiçbir deger atanamamıs veya hicbir degere sahip olmayan demektir.
    {

    }

    numara++;
    fwrite(&numara,sizeof(int),1,numPtr);
    fclose(numPtr);

    t1.id=numara;

    printf("Tur yeri (adi)");
    scanf("%s",t1.turYeri);
    printf("Kontenjan");
    scanf("%d",&t1.kontenjan);
    printf("Fiyat");
    scanf("%d",&t1.fiyat);
    printf("Tur Baslangic Tarihi");
    scanf("%s",t1.basTarih);
    printf("Tur Bitis Tarihi");
    scanf("%s",t1.bitTarih);


    FILE *ptr = fopen("turlar.txt","a");
    fwrite(&t1,sizeof(tur),1,ptr);
    fclose(ptr);
    printf("%d Numarali tur kaydi  basarili sekilde yapildi\n",numara);

}

void turListele()
{

    system("cls");
    system("color B");
    printf("Tur Listeleme Ekranina Hosgeldiniz\n");
    int durum;
    durum=0;
    FILE *ptr = fopen("turlar.txt","r+b");
    printf("%-20s%-20s%-20s-%20s%-20s%-20s\n" \n,"Tur Numarasi","Tur Yeri","Kontenjan","Fiyat","Baslangic Tarihi","Bitis Tarihi");
    while(fread(&t1,sizeof(tur),1,ptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        printf("%-20d%-20s%-20d-%20d%-20s%-20s\n",t1.id,t1.turYeri,t1.kontenjan,t1.fiyat,t1.basTarih,t1.bitTarih);
        durum=1;
    }
    if(durum==0)
    printf("\nHerhangi bir tur kaydi bulunamadi\n");
    fclose(ptr);
    


}


void turGuncelle()
{


  

    system("cls");
    system("color B");
    printf("Tur Guncelleme Ekranina Hosgeldiniz\n");
    int durum;
    durum=0;
    int numara;
    int sayac;
    sayac=0;
    FILE *ptr = fopen("turlar.txt","r+b");
    printf("%-20s%-20s%-20s-%20s%-20s%-20s\n" \n,"Tur Numarasi","Tur Yeri","Kontenjan","Fiyat","Baslangic Tarihi","Bitis Tarihi");
    while(fread(&t1,sizeof(tur),1,ptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        printf("%-20d%-20s%-20d-%20d%-20s%-20s\n",t1.id,t1.turYeri,t1.kontenjan,t1.fiyat,t1.basTarih,t1.bitTarih);
        durum=1;
    }
    if(durum==0)
    printf("\nHerhangi bir tur kaydi bulunamadi\n");
    else
    {

        rewind(ptr);
        durum=0; // dosyanin basina don
        printf("\nGuncellemek istediginiz turun numarasini giriniz: ");
        scanf("%d",&numara);

    while(fread(&t1,sizeof(tur),1,ptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        if(numara==t1.id)
        {
            durum=1;
            break;

        }
        sayac++;
    }


    if(durum==0)
    printf("%d numarali kullanici yanlıs numara girmistir / tur kaydi bulunmamistir\n",numara);
    else
    {
       
       rewind(ptr);
       durum=0;
       printf("Guncellemek istediginiz verileri giriniz\n");

     printf("Tur yeri (adi)");
     scanf("%s",t1.turYeri);
     printf("Kontenjan");
     scanf("%d",&t1.kontenjan);
     printf("Fiyat");
     scanf("%d",&t1.fiyat);
     printf("Tur Baslangic Tarihi");
     scanf("%s",t1.basTarih);
     printf("Tur Bitis Tarihi");
     scanf("%s",t1.bitTarih);



     fseek(ptr,sayac*sizeof(tur),0);
     fwrite(&t1,sizeof(tur),1,ptr);
     printf("%d numarali tur kaydi basarili sekilde guncellendi\n",numara);

    }

}

fclose(ptr);
    

}


void turSil()
{

    
   
    system("cls");
    system("color B");
    printf("Tur Silme Ekranina Hosgeldiniz\n");
    int durum;
    durum=0;
    int numara;
    FILE *ptr = fopen("turlar.txt","r+b");
    printf("%-20s%-20s%-20s-%20s%-20s%-20s\n" \n,"Tur Numarasi","Tur Yeri","Kontenjan","Fiyat","Baslangic Tarihi","Bitis Tarihi");
    while(fread(&t1,sizeof(tur),1,ptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        printf("%-20d%-20s%-20d-%20d%-20s%-20s\n",t1.id,t1.turYeri,t1.kontenjan,t1.fiyat,t1.basTarih,t1.bitTarih);
        durum=1;
    }
    if(durum==0)
    printf("\nHerhangi bir tur kaydi bulunamadi\n");
    else
    {

        rewind(ptr);
        durum=0; // dosyanin basina don
        printf("\nSilmek istediginiz turun numarasini giriniz: ");
        scanf("%d",&numara);

    while(fread(&t1,sizeof(tur),1,ptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        if(numara==t1.id)
        {
            durum=1;
            break;

        }
    }


    if(durum==0)
    printf("%d numarali kullanici yanlıs numara girmistir / tur kaydi bulunmamistir\n");
    else
    {
        char tercih;
        printf("%d numarali tur kaydini silmek istediginize emin misiniz? (E/H)",numara);
        scanf("%s",&tercih);
        if(tercih=='E' || tercih=='H')
        {
          
       
       rewind(ptr);
       FILE *yedekPtr = fopen("yedek.txt","w+b");

      while(fread(&t1,sizeof(tur),1,ptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        if(numara!=t1.id)

        {
            fwrite(&t1,sizeof(tur),1,yedekPtr);

            
        }
    }
      
        fclose(yedekPtr);
        fclose(ptr);

        remove("turlar.txt");
        rename("yedek.txt","turlar.txt");

      printf("%d numarali tur kaydi basarili sekilde silindi\n",numara);

    }

}
else
printf("%d numarali tur kaydi silinemedi\n",numara);

}

fclose(ptr);



}


int turMenu()
{


    int secim;
    system("color B");
    printf("\n\n\tTUR ISLEMLERI\n\n");
    printf("\n\t1-TUR EKLE\n");
    printf("\n\t2-TUR LISTELEI\n");
    printf("\n\t3-TUR GUNCELLE\n");
    printf("\n\t4-TUR SIL\n");
    printf("\n\t0-ANA MENUYE DON\n");
    printf("\n\tLutfen seciminizi yapiniz: ");
    system("cls");
    scanf("%d",&secim);

    return secim;
    
}

void turIslemleri()
{


   int secim;
   secim=turMenu();

   while(secim!=0) // eger 0'a esit olursa program kapanir !
   {
    
      switch(secim)

      {
           case 1:
                turEkle();    
                break;

              case 2:
                    turListele();
                    break;

                case 3:
                    turGuncelle();
                    break;

                case 4:
                    turSil();
                    break;

                default:
                printf("Yanlis secim yaptiniz");
                break;
      }

    
    secim=menu();

   }



   printf("Basarili sekilde cikis yapildi...");


}