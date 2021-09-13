#include<stdio.h>
#include<math.h>
#include<conio.h>

// #define G 6,672e-11 //m3kg-1s-2 constante gravitacional
// #define M 5.974e24 //kg massa da Terra
#define MU 3.986004e5  //km3/s2 constante de Kepler
// [N] = [kg*m/s2]
#define pi M_PI

void print(double r, double T, double v){ 
    double h=r-6378;
    printf("\nr: %.4lf km\n",r);
    printf("T: %.4lf s (Periodo da orbita circular)\n",T);
    printf("T: %.4lf h (Periodo da orbita circular)\n",T/60/60);
    printf("v: %.4lf km/s\n",v);
    if (h<0) h=0;
    printf("h: %.4lf km\n",h);
}

int main(){
    double r,v,T;
    int ch;
    printf("Escolha a entrada:\n\t1-RAIO\n\t2-ALTURA\n\t3-VELOCIDADE\n\t4-PERIODO\nEscolha: ");
    scanf("%d",&ch);
    // ch = _getch()-48; 
    // printf("%d\n",ch);//getch();
    switch(ch){
        case 1:
            printf("Entre com o raio (km): ");
            scanf("%lf",&r);
            v=sqrt(MU/r); //km/s
            T=2*pi*r/v; //s
            break;
        case 2:
            printf("Entre com a altura (km): ");
            scanf("%lf",&r);
            r+=6378;
            v=sqrt(MU/r); //km/s
            T=2*pi*r/v; //s
            break;
        case 3:
            printf("Entre com a velocidade (km/s): ");
            scanf("%lf",&v);
            r=MU/(v*v); //km
            T=2*pi*r/v; //s
            break;
        case 4:
            printf("Entre com o periodo (s): ");
            scanf("%lf",&T);
            r=pow(pow(T/(2*pi),2)*MU,1/3.0);
            v=sqrt(MU/r); //km/s
            break;
        default:
            printf("Nao existe essa opçao");
            ch=0;
    }
    if (ch) print(r,T,v);
    getch();
    return 0;
}
