#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>
#include <stdarg.h>

#define pi M_PI
void sat_estacao_info(double Le, double le, double ls);
void print(const char* fmt, ...);
int main(){
    setlocale(LC_ALL,"Portuguese");
    double Le,le,ls;//,gama,d,El,a,c,s,alfa,az;
    
    // Ex 2.5
    printf("EX 2.5\n\n");
    Le=18; //graus sul
    le=48;//graus oeste
    ls=80;//graus oeste

    //Satelite Geo
    // float Ls=0,rs=42242;
    // float re=6371;

    // gama=acos(cos(Le)*cos(ls-le)+sin(Ls));
    // d=rs*sqrt(1+pow(re/rs,2)-2*(re/rs)*cos(gama));//distancia
    // El=acos(sin(gama)/(d/rs));//angulo de elevacao El
    
    // printf("Dist: %f km\n",d);
    // printf("Angulo de elevacao: %f graus\n",El*180/pi);

    sat_estacao_info(Le,le,ls);

    // Ex 2.6
    printf("\nEX 2.6\n\n");
    ls=70;//graus oeste
    sat_estacao_info(Le,le,ls);
    
    return 0;
}

void sat_estacao_info(double Le, double le, double ls){
    Le=Le*pi/180;
    le=le*pi/180;
    ls=ls*pi/180;
    double gama,d,El,a,c,s,alfa,az,Ls=0;
    gama=acos(cos(Le)*cos(ls-le));
    d=42242*sqrt(1.02274-0.301596*cos(gama));
    El=acos(sin(gama)/(d/42242));

    a=fabs(ls-le);
    c=fabs(Le-Ls);
    s=0.5*(a+c+gama);
    printf("%lf %lf %lf %lf\n",gama,a,c,s);

    alfa=2*atan(sqrt(sin(s-gama)*sin(s-c) / (sin(s)*sin(s-a)) ) );
    printf("%lf\n",alfa);
    az=360-alfa*180/pi;//azimute da est.terrena a um satelite geo
    //noroeste

    printf("Dist: %.4lf km\n",d);
    printf("Angulo de elevacao: %.4lf graus\n",El*180/pi);
    printf("Azimute: %g graus\n",az);
}