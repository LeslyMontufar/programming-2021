#include<stdio.h>
#include<math.h>
#include<locale.h>

// #define G 6,672e-11 //m3kg-1s-2 constante gravitacional
// #define M 5.974e24 //kg massa da Terra
#define MU 3.986004e5  //km3/s2 constante de Kepler
// [N] = [kg*m/s2]

void vel(float phi0, float a, float e);

int main(){
    setlocale(LC_ALL, "Portuguese");
    // float e,a,alt_perigeu;
    // alt_perigeu=4.86e3; //km
    // e=0.001;    
    // a=alt_perigeu/(1-e); //km
    // printf("a: %.4f km\n",a);
    
    // printf("Apogeu:\n");
    // vel(180,a,e);
    // printf("Perigeu:\n");
    // vel(0,a,e);

    float r,m,Fin,v,T;
    r=16369; //km
    m=970; //kg

    Fin=m*MU/(r*r); //kg*km/s2
    printf("Fin: %.4f kN\n",Fin);

    v=sqrt(MU/r); //km/s
    printf("v: %.4f km/s\n",v);

    T=2*M_PI*r/v; //s
    printf("T: %.4f s (Periodo da orbita circular)\n",T);
    printf("T: %.4f h (Periodo da orbita circular)\n",T/60/60);

    return 0;
}

void vel(float phi0, float a, float e){ //a em km
    float r0,v;
    phi0*=180/M_PI;
    r0=a*(1-e*e)/(1+e*cos(phi0));
    v=sqrt( MU/a *(2*a/r0 -1) );
    printf("r0: %.4f km\n",r0);
    printf("Velocidade linear v: %.4f km/s\n",v);
} 