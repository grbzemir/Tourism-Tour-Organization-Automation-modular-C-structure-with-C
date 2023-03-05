#include "musteri.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


musteri m1;

void musteriEkle()
{

    printf("Musteri Ekleme Ekranina Hosgeldiniz\n");

    printf("Musteri tc : ");
    scanf("%s",m1.tc);
    printf("Musteri ad soyad : ");
    scanf("%s",m1.adSoyad);
    printf("Musteri telefon : ");
    scanf("%s",m1.telefon);
    printf("Musteri adres : ");
    scanf("%s",m1.adres);
    printf("Musteri eposta : ");
    scanf("%s",m1.eposta);
    printf("Musteri dogum tarihi : ");
    scanf("%s",m1.dTarih);
    printf("Musteri dogum yeri : ");
    scanf("%s",m1.dyeri);
    printf("Musteri cinsiyet : ");
    scanf("%s",m1.cinsiyet);



    FILE *ptr = fopen("musteriler.txt","a");
    fwrite(&m1,sizeof(musteri),1,ptr);
    fclose(ptr);
    printf("%d TC/NO Numarali kaydi  basarili sekilde yapildi\n",m1.tc);

}

void musteriListele()
{

    system("cls");
    system("color B");
    printf("Musteri Listeleme Ekranina Hosgeldiniz\n");
    int durum;
    durum=0;
    FILE *ptr = fopen("musteriler.txt","r+b");
    printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n","TC NO","AD SOYAD","D-TARİHİ","D-YERİ","CINSIYET","ADRES","TELEFON","E-POSTA");
    while(fread(&m1,sizeof(musteri),1,ptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n",m1.tc,m1.adSoyad,m1.dTarih,m1.dyeri,m1.cinsiyet,m1.adres,m1.telefon,m1.eposta);
        durum=1;
    }
    if(durum==0)
    printf("\nHerhangi bir musteri kaydi bulunamadi\n");
    fclose(ptr);
    

}


void musteriGuncelle()
{

    system("cls");
    system("color B");
    printf("Musteri Guncelleme Ekranina Hosgeldiniz\n");
    int durum;
    durum=0;
    int sayac;
    sayac=0;
    char tc[20];
    FILE *ptr = fopen("musteri.txt","r+b");
    printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n","TC NO","AD SOYAD","D-TARİHİ","D-YERİ","CINSIYET","ADRES","TELEFON","E-POSTA");
    while(fread(&m1,sizeof(musteri),1,ptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n",m1.tc,m1.adSoyad,m1.dTarih,m1.dyeri,m1.cinsiyet,m1.adres,m1.telefon,m1.eposta);
        durum=1;
    }
    if(durum==0)
    printf("\nHerhangi bir musteri kaydi bulunamadi\n");
    else
    {

        rewind(ptr);
        durum=0; // dosyanin basina don
        printf("\nGuncellemek istediginiz musteri tc /id numarasini giriniz: ");
        scanf("%d",&tc);

    while(fread(&m1,sizeof(musteri),1,ptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        if(strcmp(tc,m1.tc) == )
        {
            durum=1;
            break;

        }
    }


    if(durum==0)
    printf("%d numarali kullanici yanlıs numara girmistir / tur kaydi bulunmamistir\n",numara);
    else
    {
       
       rewind(ptr);
       durum=0;

    printf("Guncellemek istediginiz verileri giriniz\n");

    printf("Musteri tc : ");
    scanf("%s",m1.tc);
    printf("Musteri ad soyad : ");
    scanf("%s",m1.adSoyad);
    printf("Musteri telefon : ");
    scanf("%s",m1.telefon);
    printf("Musteri adres : ");
    scanf("%s",m1.adres);
    printf("Musteri eposta : ");
    scanf("%s",m1.eposta);
    printf("Musteri dogum tarihi : ");
    scanf("%s",m1.dTarih);
    printf("Musteri dogum yeri : ");
    scanf("%s",m1.dyeri);
    printf("Musteri cinsiyet : ");
    scanf("%s",m1.cinsiyet);


    fseek(ptr,sayac*sizeof(musteri),0);
    fwrite(&m1,sizeof(musteri),1,ptr);
    printf("%d numarali musteri kaydi basarili sekilde guncellendi\n");

    }

}

fclose(ptr);
    

}


void musteriSil()
{


    
    system("cls");
    system("color B");
    printf("Musteri Silme Ekranina Hosgeldiniz\n");
    int durum;
    durum=0;
    char tc[20];
    FILE *ptr = fopen("turlar.txt","r+b");
    printf("%-20s%-20s%-20s%-20s%-20s%-20s\n","TC NO","AD SOYAD","D-TARİHİ","D-YERİ","CINSIYET","ADRES","TELEFON","E-POSTA");
    while(fread(&m1,sizeof(musteri),1,ptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        printf("%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s%-20s\n",m1.tc,m1.adSoyad,m1.dTarih,m1.dyeri,m1.cinsiyet,m1.adres,m1.telefon,m1.eposta);
        durum=1;
    }
    if(durum==0)
    printf("\nHerhangi bir musteri kaydi bulunamadi\n");
    else
    {

        rewind(ptr);
        durum=0; // dosyanin basina don
        printf("\nSilmek istediginiz musteri tc/id giriniz: ");
        scanf("%d",&tc);

    while(fread(&m1,sizeof(musteri),1,ptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        if(strcmp(tc,m1.tc) == 0 )
        {
            durum=1;
            break;

        }
    }


    if(durum==0)
    printf("%d numarali kullanici yanlıs tc/id girmistir / musteri kaydi bulunmamistir\n");
    else
    {
        char tercih;
        printf("%s numarali musteri kaydini silmek istediginize emin misiniz? (E/H)",numara);
        scanf("%s",&tercih);
        if(tercih=='E' || tercih=='H')
        {
          
       
       rewind(ptr);
       FILE *yedekPtr = fopen("yedek.txt","w+b");

      while(fread(&m1,sizeof(musteri),1,ptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        if(stcmp(tc,m1.tc) != 0)

        {
            fwrite(&m1,sizeof(musteri),1,yedekPtr);

            
        }
    }
      
        fclose(yedekPtr);
        fclose(ptr);

        remove("musteriler.txt");
        rename("yedek.txt","musteriler.txt");

      printf("%d numarali tur kaydi basarili sekilde silindi\n",numara);

    }

}
else
printf("%d numarali musteri kaydi silinemedi\n");

}

fclose(ptr);


}


int musteriMenu()
{


    int secim;
    system("color B");
    printf("\n\n\tMUSTERI ISLEMLERI\n\n");
    printf("\n\t1-MUSTERI EKLE\n");
    printf("\n\t2-MUSTERI LISTELEI\n");
    printf("\n\t3-MUSTERI GUNCELLE\n");
    printf("\n\t4-MUSTERI SIL\n");
    printf("\n\t0-ANA MENUYE DON\n");
    printf("\n\tLutfen seciminizi yapiniz: ");
    system("cls");
    scanf("%d",&secim);

    return secim;

    
}

void musteriIslemleri()
{

int secim;
   secim=musteriMenu();

   while(secim!=0) // eger 0'a esit olursa program kapanir !
   {
    
      switch(secim)

      {
           case 1:
                musteriEkle();    
                break;

              case 2:
                    musteriListele();
                    break;

                case 3:
                    musteriGuncelle();
                    break;

                case 4:
                    musteriSil();
                    break;

                default:
                printf("Yanlis secim yaptiniz");
                break;
      }

    

    secim=musteriMenu();

   }




   printf("Basarili sekilde cikis yapildi...");



}