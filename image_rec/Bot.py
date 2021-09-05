from pyautogui import *
import pyautogui
import time
import keyboard
import random
import win32api, win32con

# vermelho: x:1714 y:596 RGB:(185,74,72)
# verde: rgb(70,136,71)
# para entrar: X: 1892 Y:  919 RGB: ( 15, 116, 178)
def click(x,y):
    win32api.SetCursorPos((x,y))
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN,0,0)
    time.sleep(0.01)
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP,0,0)


while keyboard.is_pressed('q')==False:
    time.sleep(1)
    if(pyautogui.pixel(1380,545)==(70,136,71)):
        print("iniciada")
        click(1570,964)
        print("clicou")
    else:
        print("não iniciada")
else:
    print("Boa aula eu :D")
