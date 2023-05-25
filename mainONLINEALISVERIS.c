#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void hosgeldinizfonksiyonu(){
    printf("*** ONLINE ALISVERIS MAGAZAMIZA HOSGELDINIZ ***\n");
    printf("===============================================\n");
    printf("..Iyi alisverisler dileriz..\n");
}

int secimfonksiyonu(){
    int secim;
    printf("Online sistemimize kayitliysaniz lutfen sistemimize giris yapiniz. Kayitli degilseniz lutfen sistemimize kayit olunuz. Dilerseniz 100 TL ve uzeri alisveris yapmak sarti ile misafir kullanici olarak magazamizdan faydalanabilirsiniz.\n\n Asagidaki islemlerden birini seciniz.\n[1]--Giris Yap\n[2]--Kayit Ol\n[3]--Misafir Kullanici Olarak Devam Et\n");
    scanf("%d", &secim);
    return secim;
}
int girisyapfonksiyonu(char kullaniciadi[20], char sifre[20]){
    char istenenkullaniciadi[20],istenensifre[20];
    while(1){
         printf("Lutfen kullanici adinizi giriniz: ");
         scanf("%s", &istenenkullaniciadi);
         if(strcmp(istenenkullaniciadi,kullaniciadi)==0){
               printf("Kullanici adi dogru girildi.\n\n ");
               break;
        }
        else{
               printf("Kullanici adi hatali girildi. Yeniden deneyiniz.\n\n");
               continue;
        }
    }
    while(1){
         printf("Lutfen sifrenizi giriniz: ");
         scanf("%s", &istenensifre);
         if(strcmp(istenensifre,sifre)==0){
         printf("Sifre girisiniz basarili.");
         break;
         }
         else{
         printf("Sifre girisiniz hatali. Yeniden deneyiniz.\n\n");
         continue;
        }
    }
}
struct kullanicilar{
    char isim[20],soyisim[20],kullaniciadi[20],sifre[20];
};
struct kullanicilar kullanicikayit(){
    struct kullanicilar kayit();
    char isim[20],soyisim[20],kullaniciadi[20],sifre[20];
    printf("Adiniz: ");
    scanf("%s", &isim);
    printf("Soyadiniz: ");
    scanf("%s", &soyisim);
    while(1){
        printf("Lutfen bir kullanici adi olusturunuz: ");
        scanf("%s", &kullaniciadi);
        if(strlen(kullaniciadi)<5){
        printf("Kullanici adi icin girilen karakter sayisi yetersiz. Lutfen yeniden deneyiniz. \n\n");
        continue;
        }
        else if(strlen(kullaniciadi)>=5){
            printf("Kullanici adiniz basariyla olusturuldu.\n\n");
            break;
            }
        }
        while(1){
            printf("Lutfen en az 5 haneli bir sifre olusturunuz: ");
             scanf("%s", &sifre);
             if(strlen(sifre)<5){
             printf("Olusturdugunuz sifre yetersiz. Lutfen yeniden deneyiniz. \n\n");
             continue;
             }
             else if(strlen(sifre)>=5){
             printf("Sifreniz basariyla olusturuldu.\n\n");
             break;
        }
        }
        printf("Magazamiza kaydiniz basariyla gerceklesmistir. Sizi giris yapma ekranina yonlendiriyoruz. Keyifli alisverisler dileriz :) \n\n");
        girisyapfonksiyonu(kullaniciadi,sifre);
}


int main() {
   char kullaniciadi[20],sifre[20];
   hosgeldinizfonksiyonu();
   int secim=secimfonksiyonu();
   if(secim==1){
       printf("Giris yapma ekranina yonlendiriliyorsunuz. Lutfen bekleyiniz.\n\n");
       sleep(2.5);
       girisyapfonksiyonu(kullaniciadi,sifre);
   }
   else if(secim==2){
       printf("Magazamizda kaydiniz bulunmamaktadir. Kayit yapma ekranina yonlendiriliyorsunuz. Lutfen bekleyiniz.\n\n");
       sleep(2.5);
       struct kullanicilar kullanicibir=kullanicikayit();
      
       
   }

	return 0;
}
