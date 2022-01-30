#include <stdio.h>
#include <stdlib.h>

void kullaniciSirala();  // turkce harfler oncelik olarak son sıradadir
void sirala();           
void kullaniciEkle();
void kullaniciBul();
void bul();
void format();
char* getObject();
char* getObject2();
int str_uzunluk();
int kontrol();
char secim_yap();
void sil();
void str_copy();
void replace();
int a_once_gelir();
int telefon_kontrol();  // hata kontrolu
int email_kontrol();    // hata kontrolu


struct Ogrenci
{
    char ogrencino[50];
    char ad[50]; 
    char soyad[50];
    char telno[50];
    char mail[50];  
};

struct String
{
    char* str;
};


int main () {
    char key[10];
    system("CLS");
    printf("\nMenü-1:\n");
    printf("1-> Kullanıcı ekle\n");
    printf("2-> Kullanıcı bul\n");
    printf("3-> Kullanıcı sırala\n");
    printf("4-> Çıkış\n");

    while (1) {
        char key = secim_yap(4);  
        switch (key) 
        {
        case '1':
            kullaniciEkle();break;
        case '2':
            kullaniciBul(); break;
        case '3':
            kullaniciSirala();break;
        case '4':
            exit(1);break;
        }
    }       
}

char secim_yap(int limit) {
    static char key[10];
    printf("\n Secim: ");
    fgets(key, 9, stdin);
    
    //girdiyi. kontrol et
    while(key[0] < 49 || key[0] > 48 +limit || str_uzunluk(key) > 1) {
        printf("\n\n  [!] Hatali Secim [!]\n");
        printf("  [!] Yalnizca rakam giriniz [!]\n");
        printf("\n  Secim: ");
        fgets(key, 9, stdin);
    }
    printf("\n");
    return key[0]; 
}

void kullaniciEkle() {
    struct Ogrenci ogrenci ;
        
    printf("Ogrenci no: ");
    //scanf("%s", &ogrenci.ogrencino);
    fgets(ogrenci.ogrencino, 20, stdin); // ? scanf duzgun calismiyor, fgets kullandim
    
    printf("Ogrenci adi: ");
    fgets (ogrenci.ad, 20, stdin); // 2 isimliler icin fgets kullan
    printf("Ogrenci soyadi: ");
    
   
    scanf("%s", &ogrenci.soyad);
    printf("Ogrenci telefon numarasi: ");
    scanf("%s", &ogrenci.telno);

    while (telefon_kontrol(ogrenci.telno) == 0)
    {
        printf("\n  [!] Lutfen gecerli bir telefon numarasi giriniz [!]\n\n");
        printf("Ogrenci telefon numarasi: ");
        scanf("%s", &ogrenci.telno);
    }
    
    printf("Ogrenci mail adresi: ");
    scanf("%s", &ogrenci.mail);

    while (email_kontrol(ogrenci.mail) == 0)
    {
        printf("\n  [!] Lutfen gecerli bir eposta adresi giriniz [!]\n\n");
        printf("Ogrenci mail adresi: ");
        scanf("%s", &ogrenci.mail);
    }
    

    // belirli uzunluga gore formatla
    format(ogrenci.ogrencino,17);
    format(ogrenci.ad,19); 
    format(ogrenci.soyad,19);
    format(ogrenci.telno,19);
    format(ogrenci.mail,30);

    FILE *dosya = fopen("dosya.txt", "a");
    fprintf(dosya, "%s%s%s%s%s\n", ogrenci.ad, ogrenci.soyad, ogrenci.ogrencino,  ogrenci.telno, ogrenci.mail);
    fclose(dosya);
    printf("\n Kullanici eklendi \n\n");
    exit(1);
}


void kullaniciBul() {
    system("CLS");
    FILE *dosya ;  
    if ((dosya = fopen("dosya.txt", "r")) == NULL){
		printf("\n [!] dosya.txt  bulunamadi [!]\n\n");
        exit(1);
    }
    printf("\n1-> Telefon numarasına göre bul\n");  
    printf("2-> Oğrenci numarasına göre bul\n");
    printf("3-> Mail adresine göre bul\n");
    printf("4-> Bir üst menüye dön\n");
    char key = secim_yap(4);

    switch (key)
    {
        case '1'  :
            printf("Telefon no: ");
            bul(3, dosya);
            break;
        case '2':      
            printf("Ogrenci no: ");
            bul(2, dosya);
            break;
        case '3':
            printf("Mail: ");
            bul(4, dosya);
            break;
        case '4': 
            fclose(dosya);
            main();
            break;
        }
    exit(1);
}

void bul(int a, FILE *dosya) {
    char veri[31];
    scanf("%s",veri);
    char line[150] ;    
    char *veri2;;
    printf("\n");
    
    while(! feof(dosya) ){
        fgets(line,150, dosya);
        veri2 = getObject(line,a);          
        if (kontrol(veri2, veri)) {
            printf("%s",line);   
        }

        sil(line); 
         
    }
    printf("\n");
    fclose(dosya);    
    
}

void kullaniciSirala() {
    system("CLS"); 
    FILE *dosya ;
    if ((dosya = fopen("dosya.txt", "r")) == NULL){
		printf("\n [!] dosya.txt  bulunamadi [!]\n\n");
        exit(1);
    }
    printf("\n1-> İsme göre\n");
    printf("2-> öğrenci numarasına göre\n");
    printf("3-> bir üst menüye dön\n");
    char key = secim_yap(3);

    switch (key) {
        case '1':  
            sirala(0, dosya);
            break;
        case '2':
            sirala(2, dosya);
            break;
        case '3':
            main();
            break;
        }
    exit(1);
}


void sirala(int deger, FILE *dosya) { //deger 0=isim, 2 = ogrenci numarasina gore siralar
    int i=0;
    char *veri = NULL;
    char *veri2 = NULL;
    struct String* satirlar = malloc(3* sizeof *satirlar); 
    satirlar[0].str = calloc(150 +2 , 1);
   
        
    while(! feof(dosya) ){

        satirlar[i].str = calloc(150 +2 , 1);
   
        fgets(satirlar[i].str, 150 , dosya); 
         i++;
 
  }

    i--;
 
    int key=i-1;
    int sira_listesi[i];
    for (int b=0; b < i;b++) {
        key=i;
        veri = getObject(satirlar[b].str, deger);
     
        for (int ii=0; ii<i; ii++) {veri2=NULL;

            veri2 = getObject2(satirlar[ii].str, deger);
                   
            if (a_once_gelir(veri, veri2)  )
                key--;

        }   

        sira_listesi[b] = key;     
    }

    key=0;
    int sira=0;

    int index;

    while (key<i)
    {
        if (sira==i)
            sira=0;

        index=sira_listesi[sira];
        if (index==key) {
            printf("%s",satirlar[sira].str);
            key++;
        }
        sira++;
    }

    printf("\n");
    for (int ii=0; ii<i; ++ii)
    {
        free(satirlar[ii].str);
       
    }
    free(satirlar);
    fclose(dosya);
       
}


//stringin icindekileri siler
void sil(char a[]) {
    for(int i=0;i<str_uzunluk(a);i++) {
        a[i] = ' ';
    }
}


// string uzunlugunu sabitle
void format(char text[], int size) {

    int sayi = 0;
    for (int i=0;i<str_uzunluk(text);i++) {
        if (text[i] < 0)
            sayi++;
    }
    sayi /= 2;
    size += sayi;
    int length = str_uzunluk(text);
   
    for (int i=0; i < size-2; i++) {
        if (i>= length || text[i] == 10 )
            text[i] = ' ';
    }
    
    text[size-2] = ' ';
    text[size-1] = '\0';

}


//iki stringin esitligini kontol eder
int kontrol(char a[], char  b[] ) {
    int aa = str_uzunluk(a) > str_uzunluk(b) ? str_uzunluk(b) : str_uzunluk(a);
    for(int i =0; i < aa; i++) {
        if (a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}

//saf string uzunluk
int str_uzunluk(char a[] ) {
  static int i = 0;
  i = 0;
  while (1) {
    if (a[i] == '\0' || a[i]=='\n') // '\n' i sakin silme
        return i ;
    i++; 
  }
}


// istenen degeri bulur ve dondur
char* getObject(char line[], int a) {
    //0 isim, 1 soyisim, 2 ogrno, 3 telno, 4 mail
    int firstSize = 0;
    int endSize = 0;
    static char text[30] =" ";
    int ii=0;
    int sayi = 0;
    
    switch (a)
    {
    case 0:
        firstSize = 0;
        endSize = 18;
        break;
    case 1:
        firstSize = 18;
        endSize = 36;
        break;
    case 2:
        firstSize = 36;
        endSize = 52;
        break;
    case 3:
        firstSize = 52;
        endSize = 70;
        break;
    case 4:
        firstSize = 70;
        endSize = 99; //
        break;
    }
    for (int i=0;i<endSize;i++) {
        if (line[i] < 0)            
            sayi++;
    }
    sayi /= 2;
    endSize+=sayi;
    
    sayi=0;
    for (int i=0;i<firstSize;i++) {
        if (line[i] < 0)         
            sayi++;
    }
    sayi /= 2;
    firstSize+=sayi;
    for(int i=firstSize; i<endSize; i++) {

        text[ii] = line[i];
        ii++;

    }
    text[endSize] = '\0';
    return text;

}

// istenen degeri bulur ve dondur
char* getObject2(char line[], int a) {
    //0 isim, 1 soyisim, 2 ogrno, 3 telno, 4 mail
    int firstSize = 0;
    int endSize = 0;
    static char text[30] =" ";
    int ii=0;
    int sayi = 0;
    
    switch (a)
    {
    case 0:
        firstSize = 0;
        endSize = 18;
        break;
    case 1:
        firstSize = 18;
        endSize = 36;
        break;
    case 2:
        firstSize = 36;
        endSize = 52;
        break;
    case 3:
        firstSize = 52;
        endSize = 70;
        break;
    case 4:
        firstSize = 70;
        endSize = 99; //
        break;
    }
    for (int i=0;i<endSize;i++) {
        if (line[i] < 0)            
            sayi++;
    }
    sayi /= 2;
    endSize+=sayi;
    
    sayi=0;
    for (int i=0;i<firstSize;i++) {
        if (line[i] < 0)         
            sayi++;
    }
    sayi /= 2;
    firstSize+=sayi;
    for(int i=firstSize; i<endSize; i++) {

        text[ii] = line[i];
        ii++;

    }
    text[endSize] = '\0';
    return text;

}


//string kopyalama
void str_copy(char a[], char b[]) {
    int i = str_uzunluk(b) ;// > str_uzunluk(b) ? str_uzunluk(b) : str_uzunluk(a);
    a[i] = '\0';
    i--;
    while(i >= 0) {
        a[i] = b[i];
        i--;
    }  
}

//string a alfabetik oncelikliyse 1 dondurur
int a_once_gelir(char a[], char b[]) { 
    int x,y;
    int size = str_uzunluk(a) > str_uzunluk(b) ? str_uzunluk(b) :str_uzunluk(a);
   // printf("size: %d\n",size);
    for (int i = 0; i< size;i++) {
        x = a[i];
        y = b[i];
        if (x>96)   x-=32;
        if (y>96)   y-=32;
       
        if(x<0 && y>0)
            return 0;
        else if(x>0 && y<0)
            return 1;
        else if (x>y && x>0)
            return 0;
        else if (x<y)
            return 1;
        else if (x>y)
            return 0;
        
    }
    return 1;
}

// string degerlerini yer degistirtir
void replace(char a[], char b[]) {
    int size1= str_uzunluk(a);
    int size2= str_uzunluk(b);
    char tmp[150];
    
    int i = 0;
    for (i =0; i<size1;i++) {
        tmp[i] = a[i];
    }
   
    sil(a);
    for (i =0; i<size2;i++) {
        a[i] = b[i];
    }
    sil(b);
    for (i =0; i<size1;i++) {
        b[i] = tmp[i];
    }
    a[size2+1] = '\0';
    b[size1+1] = '\0';
}


int telefon_kontrol(char no[]) {

    for (int i= 0 ; i< str_uzunluk(no);i++) {
        if (no[i] < 48 || no[i] > 57 )
            return 0;
    }
    return 1;
}

int email_kontrol(char mail[]) {
    int key=0;
    for (int i=0; i< str_uzunluk(mail);i++){
        if (mail[i] < 0)
            return 0;
        else if (mail[i] == '@')
            key++;
    }
    return key;
}
