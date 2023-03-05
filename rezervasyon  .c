#include "rezervasyon.h"
#include "musteri.h"
#include "turlar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>


rez r1;
tur t1;



void rezervasyonOlustur()

{


    printf("Rezervasyon Olusturma Ekranina Hosgeldiniz\n");
    FILE *numPtr = fopen("rezNumarasi.dat","a+b");
    int numara;
    numara=0;
    while (fread(&numara,sizeof(int),1,numPtr)!=NULL) // Null hiçbir deger atanamamıs veya hicbir degere sahip olmayan demektir.
    {

    }

    numara++;
    fwrite(&numara,sizeof(int),1,numPtr);
    fclose(numPtr);

    r1.id=numara;
     
    musterListele();
    printf("Musteri TC Numarasi");
    scanf("%s",r1.musteriTC);

    // turListele();

   
    printf("Tur Listeleme Ekranina Hosgeldiniz\n");
    int durum;
    durum=0;
    FILE *tptr = fopen("turlar.txt","r+b");
    printf("%-20s%-20s%-20s-%20s%-20s%-20s\n" \n,"Tur Numarasi","Tur Yeri","Kontenjan","Fiyat","Baslangic Tarihi","Bitis Tarihi");
    while(fread(&t1,sizeof(tur),1,tptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        printf("%-20d%-20s%-20d-%20d%-20s%-20s\n",t1.id,t1.turYeri,t1.kontenjan,t1.fiyat,t1.basTarih,t1.bitTarih);
        durum=1;
    }
    if(durum==0)
    printf("\nHerhangi bir tur kaydi bulunamadi\n");
  
    
   //

   else
   {

     printf("Tur Numarasi");
     scanf("%d",&r1.turNo);
     printf("Kisi Sayisi : ");
     scanf("%d",&r1.kisiSayisi);
     printf("Rezervasyon Tarihi : ");
     scanf("%s",r1.Tarih);

     //
    
    rewind(tptr);
    while(fread(&t1,sizeof(tur),1,tptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        if(t1.id==r1.turID)
        break;
    }


  
     //

     r1.toplamUcret=r1.kisiSayisi*t1.fiyat;
    
     
    FILE *ptr = fopen("rezervasyonlar.txt","a");
    fwrite(&r1,sizeof(rez)1,ptr);
    fclose(ptr);
    printf("%d Numarali rezervasyon kaydi  basarili sekilde yapildi\n",numara);

   }
      fclose(tptr);

}

void rezervasyonListele()

{

    system("cls");
    system("color B");
    printf("Rezervasyon Listeleme Ekranina Hosgeldiniz\n");
    int durum;
    durum=0;
    FILE *ptr = fopen("rezervasyonlar.txt","r+b");
    printf("%-20s%-20s%-20s%-20s%-20s%-20s\n" \n," NUMARA","TC NO","TC ID","K-SAYISI","REZ -TARIHI","TOPLAM -UCRET");
    while(fread(&r1,sizeof(rez),1,ptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        printf("%-20d%-20s%-20d%-20d%-20s%-20s\n",r1.id,r1.musTC,r1.turID,r1.kisiSayisi,r1.Tarih,r1.toplamUcret);
        durum=1;
    }
    if(durum==0)
    printf("\nHerhangi bir tur kaydi bulunamadi\n");
    fclose(ptr);
    
}

void rezervasyonGuncelle()

{


    system("cls");
    system("color B");
    printf("Rezervasyon Guncelleme Ekranina Hosgeldiniz\n");
    int durum;
    durum=0;
    int numara;
    FILE *ptr = fopen("turlar.txt","r+b");
     printf("%-20s%-20s%-20s%-20s%-20s%-20s\n" \n," NUMARA","TC NO","TC ID","K-SAYISI","REZ -TARIHI","TOPLAM -UCRET");
    while(fread(&r1,sizeof(rez),1,ptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        printf("%-20d%-20s%-20d%-20d%-20s%-20s\n",r1.id,r1.musTC,r1.turID,r1.kisiSayisi,r1.Tarih,r1.toplamUcret);
        durum=1;
    }
    if(durum==0)
    printf("\nHerhangi bir rezervasyon kaydi bulunamadi\n");
    else
    {

        rewind(ptr);
        durum=0; // dosyanin basina don
        printf("\nGuncellemek istediginiz rezervasyon numarasini giriniz: ");
        scanf("%d",&numara);

    while(fread(&r1,sizeof(rez),1,ptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        if(numara==r1.id)
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
        
        // 

        
    printf("Tur Listeleme Ekranina Hosgeldiniz\n");
    int durum;
    durum=0;
    FILE *tptr = fopen("turlar.txt","r+b");
    printf("%-20s%-20s%-20s-%20s%-20s%-20s\n" \n,"Tur Numarasi","Tur Yeri","Kontenjan","Fiyat","Baslangic Tarihi","Bitis Tarihi");
    while(fread(&t1,sizeof(tur),1,tptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        printf("%-20d%-20s%-20d-%20d%-20s%-20s\n",t1.id,t1.turYeri,t1.kontenjan,t1.fiyat,t1.basTarih,t1.bitTarih);
        durum=1;
    }
    if(durum==0)
    printf("\nHerhangi bir tur kaydi bulunamadi\n");
    else
    {
        printf("Tur numarasini giriniz: ");
        scanf("%d",&r1.turID);
        printf("Kisi Sayisi : ");
        scanf("%d",&r1.kisiSayisi);
        printf("Rezervasyon Tarihi : ");
        scanf("%s",r1.rezTarih);
       

         //
         
        FILE *tptr = fopen("turlar.txt","r+b"); 
        while(fread(&t1,sizeof(tur),1,tptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
        {

            if(r1.turID ==t1.id)
            break;

        }
      
        //

         r1.toplamUcret=r1.kisiSayisi*t1.fiyat;
 
          fseek(ptr,(sayac)*sizeof(rez),0);
          fwrite(&r1,sizeof(rez),1,ptr);
          printf("%d numarali rezervasyon kaydi basarili sekilde guncellendi\n",numara);
          fclose(ptr);

    }

        //


    
    }

}

fclose(ptr);
    

}

void rezervasyonSil()


{

    system("cls");
    system("color B");
    printf("Rezervasyon Silme Ekranina Hosgeldiniz\n");
    int durum;
    durum=0;
    int numara;
    FILE *ptr = fopen("rezervasyonlar.txt","r+b");
    printf("%-20s%-20s%-20s%-20s%-20s%-20s\n" \n," NUMARA","TC NO","TC ID","K-SAYISI","REZ -TARIHI","TOPLAM -UCRET");
    while(fread(&t1,sizeof(tur),1,ptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        printf("%-20d%-20s%-20d%-20d%-20s%-20s\n",r1.id,r1.musTC,r1.turID,r1.kisiSayisi,r1.Tarih,r1.toplamUcret);
        durum=1;
    }
    if(durum==0)
    printf("\nHerhangi bir rezervasyon kaydi bulunamadi\n");
    else
    {

        rewind(ptr);
        durum=0; // dosyanin basina don
        printf("\nSilmek istediginiz rezervasyon numarasini giriniz: ");
        scanf("%d",&numara);

    while(fread(&r1,sizeof(rez),1,ptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        if(numara==r1.id)
        {
            durum=1;
            break;

        }
    }


    if(durum==0)
    printf("%d numarali kullanici yanlıs numara girmistir / rezervasyon kaydi bulunmamistir\n");
    else
    {
        char tercih;
        printf("%d numarali rezervasyon kaydini silmek istediginize emin misiniz? (E/H)",numara);
        scanf("%s",&tercih);
        if(tercih=='E' || tercih=='H')
        {
          
       
       rewind(ptr);
       FILE *yedekPtr = fopen("yedek.txt","w+b");

      while(fread(&r1,sizeof(tez),1,ptr)!=NULL) // yani dosyanin basindan sonuna kadar oku !
    {

        if(numara!=t1.id)

        {
            fwrite(&r1,sizeof(rez),1,yedekPtr);

            
        }
    }
      
        fclose(yedekPtr);
        fclose(ptr);

        remove("rezervasyonlar.txt");
        rename("yedek.txt","rezervasyonlar.txt");

      printf("%d numarali rezervasyon kaydi basarili sekilde silindi\n",numara);

    }

}
else
printf("%d numarali rezervasyon kaydi silinemedi\n",numara);

}

fclose(ptr);













}


int  rezervasyonMenu()
{



    int secim;
    system("color B");
    printf("\n\n\tREZERVASYON ISLEMLERI\n\n");
    printf("\n\t1-REZERVASYON OLUSTUR\n");
    printf("\n\t2-REZERVASYON LISTELE\n");
    printf("\n\t3-REZERVASYON GUNCELLE\n");
    printf("\n\t4-REZERVASYON SIL\n");
    printf("\n\t0-ANA MENUYE DON\n");
    printf("\n\tLutfen seciminizi yapiniz: ");
    system("cls");
    scanf("%d",&secim);

    return secim;
    

}



void  rezervasyonIslemleri()

{

   int secim;
   secim=rezervasyonMenu();

   while(secim!=0) // eger 0'a esit olursa program kapanir !
   {
    
      switch(secim)

      {
           case 1:
                rezervasyonOlustur();    
                break;

              case 2:
                    rezervasyonListele();
                    break;

                case 3:
                    rezervasyonGuncelle();
                    break;

                case 4:
                    rezervasyonSil();
                    break;

                default:
                printf("Yanlis secim yaptiniz");
                break;
      }

    
    secim=menu();

   }



   printf("Basarili sekilde cikis yapildi...");






}