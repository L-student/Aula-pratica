#include <stdio.h>
#include <math.h>

//01)

int primos(int i, int numero) {
    if( i <= sqrt(numero))
    {
        if( numero % i == 0 ) {
            printf("NAO EH PRIMO!\n");
        }
        else {
            return primos( i + 1, numero);
        }
    }
    else {
        printf("EH PRIMO!\n");
        return 0;
    }
}

int main() {
    int numero;
    scanf("%d", &numero);
    primos( 2, numero);
     return 0;
}

//02)


//03)


int eh_primo(int x){
	for (int i = 2; i < x; i++){
		if(x%i == 0) return 0;
	}
	return 1;
}

int main(){
	int n, fatores_primos[1000000];

	scanf("%d", &n);
	for (int i = 0; i < 1000000; i++) fatores_primos[i] = -1;
	
	for (int i=2 ; ; ){
		if(eh_primo(i) && n%i == 0){
			if(fatores_primos[i] == -1){
				fatores_primos[i] = 1;
			}
			else{
				fatores_primos[i]++;
			}

			n=n/i;
		}else{
			i++;
		}

		if(n==1){
			break;
		}
	}

	for (int i = 0; i < 1000000; i++){
		if(fatores_primos[i] != -1) printf("%d^%d ", i, fatores_primos[i]);
	}
	printf("\n");
	return 0;
}
//04)
int eh_primo(int x){
	for (int i = 2; i < x; i++){
		if(x%i == 0) return 0;
	}
	return 1;
}

void calcula_fatores(int fatores[], int n){
	for (int i=2 ; ; ){
		if(eh_primo(i) && n%i == 0){
			if(fatores[i] == -1) fatores[i] = 1;
			else fatores[i]++;
			n=n/i;
		}
		else i++;

		if(n==1) break;
	}
	return;
}

void printa_fatores(int fatores[]){
	int ponto=0;
	for (int i = 0; i < 1000000; i++){
		if(fatores[i] != -1){
			if(ponto != 0) printf(".");
			ponto = 1;
			printf("%d^%d", i, fatores[i]);
		}
	}
	printf("\n\n");
	return;
}

void completa_fatores(int fatores_n1[], int fatores_n2[]){
	for(int i = 2 ; i<1000000 ; i++){
		if(fatores_n1[i] > 0 && fatores_n2[i] == -1){
			fatores_n2[i] = 0;
		}

		if(fatores_n2[i] > 0 && fatores_n1[i] == -1){
			fatores_n1[i] = 0;
		}
	}
}

void mdc_fatores(int fatores_n1[], int fatores_n2[]){
	int mdc=1, min=-1;

	for (int i = 0; i < 1000000; i++)
	{
		if(fatores_n1[i] != -1){
			if(min != -1) printf(".");
			min = (fatores_n1[i] > fatores_n2[i]) ? fatores_n2[i] : fatores_n1[i];
			mdc *= (int)pow(i,min);
			printf("%d^%d", i, min);
		}
	}
	printf(" = %d\n\n", mdc);
}

void mmc_fatores(int fatores_n1[], int fatores_n2[]){
	int mmc=1, max=-1;

	for (int i = 0; i < 1000000; i++)
	{
		if(fatores_n1[i] != -1){
			if(max != -1) printf(".");
			max = (fatores_n1[i] > fatores_n2[i]) ? fatores_n1[i] : fatores_n2[i];
			mmc *= (int)pow(i,max);
			printf("%d^%d", i, max);
		}
	}
	printf(" = %d\n\n", mmc);
}

int main(){
	int n1, n2, fatores_n1[1000000], fatores_n2[1000000];

	scanf("%d %d", &n1, &n2);

	for (int i = 0; i < 1000000; i++){
		fatores_n1[i] = -1;
		fatores_n2[i] = -1;
	}

	calcula_fatores(fatores_n1, n1);
	calcula_fatores(fatores_n2, n2);

	completa_fatores(fatores_n1, fatores_n2);

	printf("%d = ", n1);
	printa_fatores(fatores_n1);
	printf("%d = ", n2);
	printa_fatores(fatores_n2);

	printf("MDC(%d,%d) = ", n1, n2);
	mdc_fatores(fatores_n1, fatores_n2);
	printf("MMC(%d,%d) = ", n1, n2);
	mmc_fatores(fatores_n1, fatores_n2);

	return 0;
}

//05)

int mdc(int a, int b) { 
       if (a % b != 0) {
            return mdc(b, a % b);
       }
        else {
            return b;
        }
   }
 
int main() {
    int a, b, resultado;
    scanf("%d%d", &a, &b);
    resultado = mdc(a, b);
    printf("O MDC de %d e %d = %d\n", a, b, resultado);
 
    return 0;
}

//06)


//07)


//08)


//09)


//10)

