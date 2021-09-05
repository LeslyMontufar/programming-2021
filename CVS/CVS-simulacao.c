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
    float r,m,Fin,v,T;
    r=10369; //km
    m=1000; //kg
    Fin=m*MU/(r*r); //kg*km/s2
    printf("Fin: %.4f kN\n",Fin);

    v=sqrt(MU/r); //km/s
    printf("v: %.4f km/s\n",Fin);

    T=2*M_PI*r/v; //s
    printf("T: %.4f s (Periodo da orbita circular)\n",T);
    printf("T: %.4f h (Periodo da orbita circular)\n",T/60/60);

    printf("\nQuestao 2\n");
    float e,a;
    e=0.25;    
    a=2e3/(1-e); //km
    printf("a: %.4f km\n",a);
    
    printf("Apogeu:\n");
    vel(180,a,e);
    printf("Perigeu:\n");
    vel(0,a,e);

    printf("\nQuestao 3\n");    
    // float a,e;
    a=12e3; //km
    e=0.1;
    printf("Dist do apogeu: %.4f km\n",a*(1+e));
    vel(180,a,e);
    printf("Dist do perigeu: %.4f km\n",a*(1-e));
    vel(0,a,e);

    printf("\nQuestao 4\n");   
    float t,tp,eta,M,E,r0,phi0,x0,y0;
    a=22000; //km
    e=0.1;
    t=20*60; //s
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

    printf("\nQuestao 5 - Orbita circular geoestacionaria\n");   
    r=35783;//km
    v=sqrt(MU/r);//km/s - velocidade do satélite em órbita circular
    T=2*M_PI*r/v;//período
    eta=2*M_PI/T;//vel angular


    printf("v: %.4f m/s\n",1e3*v);
    printf("T: %.4f min\n",T/60);
    printf("T: %.4f h\n",T/60/60);
    printf("eta: %g rad/s\n",eta);
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