#ifndef _REZERVASYON_H
#define _REZERVASYON_H


typedef struct Rezervasyon 
{

  int id;
  int kisiSayisi;
  int toplamUcret;
  int turID;


  char musTC[20];
  char tarih[20];
 







}rez;











void rezervasyonOlustur();

void rezervasyonListele();

void rezervasyonGuncelle();

void rezervasyonSil();


int rezervasyonMenu();


void rezervasyonIslemleri();


#endif