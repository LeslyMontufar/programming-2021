package br.com.programas;
import java.util.Arrays;
import java.util.Random;
import java.awt.*; // para aplicações com interfaces graficas

public class Main {
    public static void main(String[] args){
        java.util.Scanner ler = new java.util.Scanner(System.in); //bom qnd é pouco referenciado
        int [] a = new int[5];
        Random numeros = new Random();
        for (int i=0; i < a.length; i++) {
            a[i]=numeros.nextInt();
            System.out.println("a[" + i + "]=" + a[i]);
        }
        System.out.println();
        int [] b = a.clone();
        Arrays.sort(b);
        for (int i=0; i < a.length; i++) {
            System.out.println("b[" + i + "]=" + b[i]);
        }
    }
}
