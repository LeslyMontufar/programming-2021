# -*- coding: utf-8 -*-
"""
Created on Sun Mar 14 18:09:38 2021

@author: lesly

Title: Comandos importantes no python
"""

def hello():
    """Print "Hello World" and return None."""
    print("Hello World")
    
hello()

# sep e end na fco print
print("Fundamentos","Programación","en",sep="***",end="...")
print("Python")

# seta
n = 1
print("    *    "*n,"   * *   "*n,"  *   *  "*n," *     * "*n,"***   ***"*n,"  *   *  "*n,"  *   *  "*n,"  *****  "*n,sep="\n"*n,end="\n"+str(n)+" setas\nAvatar, a lenda de Aang")

# print converte para o decimal
print(0o123)
print(0x123)

print('"Estoy"','""aprendiendo""','""""Python""""',sep="\n")

print(2 ** 3)
print(2 ** 3.)

# Da divisao, semrpe resultara um valor flutuante
print(6 / 3)
print(6 / 3.)

# Divisao inteira = floor division
print(6 // 4)