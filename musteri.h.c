#ifndef _MUSTERI_H
#define _MUSTERI_H

typedef struct Musteriler 
{

  char tc[20];
  char adSoayd[20];
  char dTarih[20];
  char dyeri[20];
  char cinsiyet[20];
  char adres[20];
  char tel[20];
  char eposta[20];



} musteri ;

void musteriEkle();


void musteriListele();


void musteriGuncelle();



void musteriSil();


int musteriMenu();

void musteriIslemleri();

#endif