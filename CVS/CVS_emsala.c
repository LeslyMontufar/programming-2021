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
    printf("Questao 1\n");
    float t,tp,eta,M,E,r0,phi0,x0,y0,a,e;

    a=27000; //km
    e=0.001;
    t=6*60*60; //s
    tp=0; //tempo ao perigeu

    eta=1/a*sqrt(MU/a); //vel media angular rad /s
    M=eta*(t-tp); //anomalia media
    E=M;
    r0=a*(1-e*cos(E));
    phi0=acos( (a*(1-e*e)/r0 -1) /e);

    x0=r0*cos(phi0);
    y0=r0*sin(phi0);
    printf("eta: %g rad/s (Velocidade media angular)\n",eta);
    printf("T: %g s (Periodo)\n",(2*M_PI/eta));
    printf("T: %g h (Periodo)\n",(2*M_PI/eta)/60/60);
    printf("M: %.4f rad ~ E\n",M);
    printf("(r0,phi0): %.4f km, %.4f rad\n",r0,phi0);
    printf("(x0,y0): %.4f km, %.4f km\n",x0,y0);
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