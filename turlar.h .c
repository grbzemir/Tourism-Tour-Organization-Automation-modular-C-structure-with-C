#ifndef _TURLAR_H
#define _TURLAR_H


typedef struct turlar
{
 
   int id;
   int fiyat;
   int kontenjan;

   char turYeri[20];
   char basTarih[20];
   char bitTarih[20];


} tur ;




void turEkle();


void turListele();


void turGuncelle();



void turSil();


int turMenu();


void turIslemleri();


#endif  
