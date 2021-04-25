#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//ESTAS QUESTÕES FORAM FEITAS PELOS ALUNOS:
//
//ARTHUR RAMOS
//LEONARDO VINÍCIOS
//LÍVIA SOARES
//LUCAS BARROS
//PEDRO MESQUITA ISIDORO
//RUTHE INGRYD

//01)

int primos(int i, int numero)  {
    if( i <= sqrt(numero))
     {
        if( numero % i == 0 )  {
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

int primo2(int num, int n) {
    if (n >= sqrt(num)) {
		return 1;
	}
	
	if (num % n == 0) {
		return 0;
	}
	return primo2(num,n+1);
}

void printPrimo(int n) {
    if(primo2(n,2)) {
        printf("%d\n",n);
    }
    printPrimo(n + 1);
}

int main() {
    printf("1\n2\n");
    printPrimo(3);
    return 0;
}

//03)


int eh_primo(int x) {
	for (int i = 2; i < x; i++) {
		if(x%i == 0) return 0;
	}
	return 1;
}

int main() {
	int n, fatores_primos[1000000];

	scanf("%d", &n);
	for (int i = 0; i < 1000000; i++) fatores_primos[i] = -1;
	
	for (int i=2 ; ; ){
		if(eh_primo(i) && n%i == 0) {
			if(fatores_primos[i] == -1) {
				fatores_primos[i] = 1;
			}
			else{
				fatores_primos[i]++;
			}

			n=n/i;
		} else {
			i++;
		}

		if(n==1) {
			break;
		}
	}

	for (int i = 0; i < 1000000; i++) {
		if(fatores_primos[i] != -1) printf("%d^%d ", i, fatores_primos[i]);
	}
	printf("\n");
	return 0;
}

//04)

int eh_primo(int x) {
	for (int i = 2; i < x; i++) {
		if(x%i == 0) return 0;
	}
	return 1;
}

void calcula_fatores(int fatores[], int n) {
	for (int i=2 ; ; ) {
		if(eh_primo(i) && n%i == 0) {
			if(fatores[i] == -1) fatores[i] = 1;
			else fatores[i]++;
			n=n/i;
		}
		else i++;

		if(n==1) break;
	}
	return;
}

void printa_fatores(int fatores[]) {
	int ponto=0;
	for (int i = 0; i < 1000000; i++) {
		if(fatores[i] != -1){
			if(ponto != 0) printf(".");
			ponto = 1;
			printf("%d^%d", i, fatores[i]);
		}
	}
	printf("\n\n");
	return;
}

void completa_fatores(int fatores_n1[], int fatores_n2[]) {
	for(int i = 2 ; i<1000000 ; i++){
		if(fatores_n1[i] > 0 && fatores_n2[i] == -1) {
			fatores_n2[i] = 0;
		}

		if(fatores_n2[i] > 0 && fatores_n1[i] == -1) {
			fatores_n1[i] = 0;
		}
	}
}

void mdc_fatores(int fatores_n1[], int fatores_n2[]) {
	int mdc=1, min=-1;

	for (int i = 0; i < 1000000; i++) {
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

	for (int i = 0; i < 1000000; i++) {
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

	for (int i = 0; i < 1000000; i++) {
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

// INICIALIZA TODOS OS VALORES DOS VETORES EM ZERO
void zera_vetor(int *v1, int *v2, int i) {
	if(i<50) {
		v1[i] = v2[i] = 0;
		zera_vetor(v1 , v2, i+1);
	}
	return;
}

// ARMAZENA OS QUOCIENTES ENCONTRADOS NO ALGORITMO DE EUCLIDES
int euclides(int x, int y, int *v, int i) {
	if(x%y != 0) {
		i = euclides(y, x%y, v, i);
		v[i] = x/y;
		i++;
	}
	return i;
}

// CALCULA OS VALORES DA TABELA QUE CONTEM OS VALORES "s" E "t"
// SENDO ELES OS FATORES MULTIPLICATIVOS DOS DOIS NUMEROS
void calc_fatores(int *q, int *f, int i) {
	if(q[i] != 0) {
		f[i+2] = (q[i]*f[i+1]) + f[i];
		calc_fatores(q, f, i+1);
	}
	return;
}

int main(){
	int x, y, quocientes[50], fatores[50];

	scanf("%d %d", &x, &y);

	// CASO UM OU OS DOIS NUMEROS SEJAM ZERO, NÃO PODEMOS APLICAR EUCLIDES
	// DESSA FORMA NÃO EXECUTAMOS AS FUNÇÕES, E PULAMOS DO "if" PARA O "else"
	if(x!=0 && y!=0) {
		zera_vetor(&quocientes[0], &fatores[0], 0);
		fatores[1] = 1;
		euclides(x, y, &quocientes[0], 0);
		calc_fatores(&quocientes[0], &fatores[0], 0);

		// PERCORRE O VETOR ONDE ESTÃO OS FATORES E PRINTA OS DOIS ULTIMOS
		// ESSES SÃO OS FATORES "s" E "t", E OS PRINTA NA ORDEM CORRETA
		for (int i = 1;  ; ++i) {
			if(fatores[i] == 0 && x<y && fatores[i-2]*y > fatores[i-1]*x){
				printf("%d*%d - %d*%d\n", fatores[i-2], y, fatores[i-1], x);
				break;
			} else if(fatores[i] == 0 && x<y && (fatores[i-2]*y < fatores[i-1]*x)) {
				printf("%d*%d - %d*%d\n", fatores[i-1], x, fatores[i-2], y);
				break;
			} else if(fatores[i] == 0 && x>y && (fatores[i-2]*x > fatores[i-1]*y)) {
				printf("%d*%d - %d*%d\n", fatores[i-2], x, fatores[i-1], y);
				break;
			} else if(fatores[i] == 0 && x>y && (fatores[i-2]*x < fatores[i-1]*y)) {
				printf("%d*%d - %d*%d\n", fatores[i-1], y, fatores[i-2], x);
				break;
			}
		}
	}
	// A SEGUIR ESTÃO OS CASOS DE TESTE ESPECIAIS ONDE A ENTRADA PODE TER ZERO(S)
	else if(x>y) printf("1*%d - 1*%d\n", x, y);
	else if(y>x) printf("1*%d - 1*%d\n", y, x);
	else printf("1*%d - 1*%d\n", x, y);

	return 0;
}


//07)

// PROGRAMA PRA CALCULAR O INVERSO MODULAR :D
int main() {
    int a, m, aa;
    printf("digite os valores de 'a' e 'mod':\n");
    scanf("%d%d", &a, &m);
    aa = inversa_modular(a,m);
    if (aa == -1) {
    	printf("Nao possui inverso modular.\n");
    	return 0;
	}
    printf("O inverso modular de 'a': %d", aa);
	return 0;
}

int inversa_modular(int a, int m) {
    int i;
	for (i = 0; i < m; ++i) {
		//printf("i: %d\n", i);
        if ((a * i) % m == 1) {
			return i;
		}
    }
    return -1;
}

//08)

// PROGRAMA PRA CALCULAR A SOLU??O DA CONGRUENCIA DE AX ? B MOD M :D
int main() {
    printf("Dada uma congruencia tipo ax = b (mod m), defina os valores de a, b e m:\n");
    
	int i, a, b, m, aa=99, x, mdc;
	scanf("%d%d%d", &a, &b, &m);
	mdc = calcular_mdc(a,m);
	if (!(b % mdc == 0)) {
		printf("A congruencia nao tem solucao.\n");
		return 0;
	} 
	
	a /= mdc;
	b /= mdc;
	m /= mdc;
	
	aa = inversa_modular(a, m);
	x = (b * aa) % m;
    for (i=0; i<mdc; i++) {
    	printf("x = %d (mod %d)\n", x+(i*m), m);
	}   
	return 0;
} 

int inversa_modular(int a, int m) {
    int i;
	for (i = 0; i < m; ++i) {
		//printf("i: %d\n", i);
        if ((a * i) % m == 1) {
			return i;
		}
    }
    return -1;
}

int calcular_mdc(int a, int d) {
	int r = a %d;
	while (r>0){
		a = d;
		d = r;
		r = a % d;
	}
	return d;
}


//09)

//ESTA FUNÇÃO FUNCION DE FORMA SIMILAR A QUESTÃO 10).
// PARA INICIALIZAR ESSA, TAMBÉM É NECESSÁRIO COLOCAR O NÚMERO DE CONGRUÊNCIAS.
//SABEMOS QUE NESSE EXEMPLO, É PEDIDO SOMENTE 3 ENTRADAS, PORÉM POR QUESTÕES DE EFICIÊNCIA, DECIDIMOS FAZER UMA GERAL PARA MAIS DE 3.
int euclides2(int x, int y) {
	if(x%y == 1){
		return 1;
	}else if(x%y == 0) {
		return 0;
	} else {
		return euclides2(y, x%y );
	}
}

int verifica_coprimos(int mods[], int qtdd_congruencias) {
	for (int i = 0; i < qtdd_congruencias-1; i++){
		for (int j = i+1; j < qtdd_congruencias; j++) {
			if(!euclides2(mods[i] , mods[j])){
				printf("Os modulos nao sao coprimos!\n");
				return 0;
			}
		}
	}
	return 1;
}

int calcula_M(int mods[], int qtdd_congruencias) {
	int M=1;
	for (int i = 0; i < qtdd_congruencias; i++) {
		M *= mods[i];
	}
	return M;
}

void calcula_Ms(int mods[], int Ms[], int M, int qtdd_congruencias) {
	for (int i = 0; i < qtdd_congruencias; i++) {
		Ms[i] = M/mods[i];
	}
}

void encontra_solucoes(int Ms[], int mods[], int s[], int qtdd_congruencias) {
	for (int i = 0; i < qtdd_congruencias; i++) {
		for (int j = 1; ; j++) {
			if((Ms[i]*j)%mods[i] == 1) {
				s[i] = j;
				break;
			}
		}
	}
}

int calcula_x(int Ms[], int s[], int restos[], int qtdd_congruencias) {
	int x=0;
	for (int i = 0; i < qtdd_congruencias ; i++) {
		x += Ms[i]*s[i]*restos[i];
	}
	return x;
}

int main(){
	int restos[50], mods[50], M, Ms[50], s[50], x, solucao, qtdd_congruencias;

	printf("Digite a quantidade de congruencias: ");
	scanf("%d", &qtdd_congruencias);

	for(int i = 0; i<qtdd_congruencias ; i++) {
		scanf("%d %d", &restos[i], &mods[i]);
	}

	if(!verifica_coprimos(mods, qtdd_congruencias)) {
		return 0;
	}

	M = calcula_M(mods, qtdd_congruencias);
	calcula_Ms(mods, Ms, M, qtdd_congruencias);
	encontra_solucoes(Ms, mods, s, qtdd_congruencias);
	x = calcula_x(Ms, s, restos, qtdd_congruencias);
	solucao = x%M;

	printf("A solucao eh: %d!\n", solucao);

	return 0;
}


//10)


int euclides2(int x, int y) {
	if(x%y == 1) {
		return 1;
	}else if(x%y == 0) {
		return 0;
	} else {
		return euclides2(y , x%y);
	}
}

int verifica_coprimos(int mods[], int qtdd_congruencias) {
	for (int i = 0; i < qtdd_congruencias-1; i++) {
		for (int j = i+1; j < qtdd_congruencias; j++) {
			if(!euclides2(mods[i] , mods[j])) {
				printf("Os modulos nao sao coprimos!\n");
				return 0;
			}
		}
	}
	return 1;
}

int calcula_M(int mods[], int qtdd_congruencias) {
	int M=1;
	for (int i = 0; i < qtdd_congruencias; i++) {
		M *= mods[i];
	}
	return M;
}

void calcula_Ms(int mods[], int Ms[], int M, int qtdd_congruencias) {
	for (int i = 0; i < qtdd_congruencias; i++) {
		Ms[i] = M/mods[i];
	}
}

void encontra_solucoes(int Ms[], int mods[], int s[], int qtdd_congruencias) {
	for (int i = 0; i < qtdd_congruencias; i++) {
		for (int j = 1; ; j++) {
			if((Ms[i]*j)%mods[i] == 1) {
				s[i] = j;
				break;
			}
		}
	}
}

int calcula_x(int Ms[], int s[], int restos[], int qtdd_congruencias) {
	int x=0;
	for (int i = 0; i < qtdd_congruencias ; i++) {
		x += Ms[i]*s[i]*restos[i];
	}
	return x;
}

int main() {
	int restos[50], mods[50], M, Ms[50], s[50], x, solucao, qtdd_congruencias;

	printf("Digite a quantidade de congruencias: ");
	scanf("%d", &qtdd_congruencias);

	for(int i = 0; i<qtdd_congruencias ; i++) {
		scanf("%d %d", &restos[i], &mods[i]);
	}

	if(!verifica_coprimos(mods, qtdd_congruencias)) {
		return 0;
	}

	M = calcula_M(mods, qtdd_congruencias);
	calcula_Ms(mods, Ms, M, qtdd_congruencias);
	encontra_solucoes(Ms, mods, s, qtdd_congruencias);
	x = calcula_x(Ms, s, restos, qtdd_congruencias);
	solucao = x%M;

	printf("A solucao eh: %d!\n", solucao);

	return 0;
}
