#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandomNumber() {
    // Yeterince rastgele bir sayı elde etmek için daha karmaşık bir yöntem kullanılıyor
    return rand() ^ (rand() << 15) ^ (rand() << 30) ^ (rand() << 45);
}

/*
%50 ihtimalle 0'dan büyük, %50 ihtimalle sifirdan kucuk degerler ureten bir sayi ve onun degerini degistirmek icin
1 milyon uzerinden olma puani karsikoyma puani alan fonksiyon
*/
int simulateEvent(int olmapuani, int karsikoymapuani) {
    int shotResult = olmapuani - karsikoymapuani;
    int random = getRandomNumber() % 1000000;
    random+=shotResult;

    if (random > 0) {
        //printf("\nrandom : %d\n", random);
        return 1; // Başarılı
    } else {
        //printf("\nrandom : %d\n", random);
        return 0; // Başarısız
    }
}

int main() {
    srand(time(NULL));
    int olma=0,karsi=0;

    int olmapuani = 1000000;
    int karsikoymapuani = 500000;

    int result = simulateEvent(olmapuani, karsikoymapuani);

    if (result == 1) {
        printf("Basarili\n");
    } else {
        printf("Basarisiz\n");
    }
    
    /*simulateevent debugger
    int rad=0,radbuyuksifir=0,radkucuksifir=0
    printf("olma puani :");
    scanf("%d",&olma);
    printf("\nkarsi puani :");
    scanf("%d",&karsi);
    for(int i=0;i<1000000;i++){
    	rad=simulateEvent(olma,karsi);
    	if(rad==1)
    	radkucuksifir++;
    	else
    	radbuyuksifir++;
	}
	printf("basarisiz: %d\n",radbuyuksifir);
	printf("basarili: %d",radkucuksifir);*/

    return 0;
}
