import time
from tkinter import messagebox
import tkinter

form=tkinter.Tk()
form.withdraw()
form.attributes('-topmost', True)
m=0.1
s=0
messagebox.showinfo(message_=f'{m}분 후 알림')
time.sleep(m*60)
while (messagebox.askyesno(message_=f'총 {s}분 경과. 한번 더?')):
    s+=m
    time.sleep(m*60)