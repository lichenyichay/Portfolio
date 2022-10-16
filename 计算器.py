# -*- coding:UTF-8 -*-
# @Author:Chay
# @TIME:2022/10/15 7:57
# @FILE:计算器.py
# @Software: IntelliJ IDEA Community Edition 2022.2.1

from tkinter import *
from tkinter import Tk

# 新建一个窗口
window: Tk = Tk()

# 设置大小及标题
window.minsize(600, 505)
window.maxsize(600, 505)
window.title("带界面的计算器")

show_top = StringVar()
show_top.set("")
show_bottom = StringVar()
show_bottom.set("0")

# 设置控件
label1 = Label(window,
               font=("微软雅黑", 20),
               bg="#C0FAF9",
               fg="#828282",
               anchor="se",
               textvariable=show_top,
               bd=9)

label2 = Label(window,
               font=("微软雅黑", 20),
               bg="#EEE9E9",
               fg="black",
               anchor="se",
               textvariable=show_bottom,
               bd=9)

label1.place(width=600, height=140)
label2.place(y=140, width=600, height=90)

# 设计按键响应函数
lists = []
# 作用分别是标记是否有运算符号和等号按键被按下，默认都是False
isPressSign = False
isPressEqual = False
# 设计按键
btn0 = Button(window,
              text="0",
              font=("微软雅黑", 20),
              fg="black",
              bd=5)
btn1 = Button(window,
              text="1",
              font=("微软雅黑", 20),
              fg="black",
              bd=5)
btn2 = Button(window,
              text="2",
              font=("微软雅黑", 20),
              fg="black",
              bd=5)
btn3 = Button(window,
              text="3",
              font=("微软雅黑", 20),
              fg="black",
              bd=5)
btn4 = Button(window,
              text="4",
              font=("微软雅黑", 20),
              fg="black",
              bd=5)
btn5 = Button(window,
              text="5",
              font=("微软雅黑", 20),
              fg="black",
              bd=5)
btn6 = Button(window,
              text="6",
              font=("微软雅黑", 20),
              fg="black",
              bd=5)
btn7 = Button(window,
              text="7",
              font=("微软雅黑", 20),
              fg="black",
              bd=5)
btn8 = Button(window,
              text="8",
              font=("微软雅黑", 20),
              fg="black",
              bd=5)
btn9 = Button(window,
              text="9",
              font=("微软雅黑", 20),
              fg="black",
              bd=5)
btn_point = Button(window,
                   text=".",
                   font=("微软雅黑", 20),
                   fg="black",
                   bd=5)
btn_ac = Button(window,
                text="AC",
                font=("微软雅黑", 20),
                fg="black",
                bd=5)
btn_back = Button(window,
                  text="←",
                  font=("微软雅黑", 20),
                  fg="black",
                  bd=5)
btn_division = Button(window,
                      text="÷",
                      font=("微软雅黑", 20),
                      fg="black",
                      bd=5)
btn_mul = Button(window,
                 text="×",
                 font=("微软雅黑", 20),
                 fg="black",
                 bd=5)
btn_sub = Button(window,
                 text="－",
                 font=("微软雅黑", 20),
                 fg="black",
                 bd=5)
btn_add = Button(window,
                 text="＋",
                 font=("微软雅黑", 20),
                 fg="black",
                 bd=5)
btn_equal = Button(window,
                   text="=",
                   font=("微软雅黑", 20),
                   fg="black",
                   bd=5)
btn_percent = Button(window,
                     text="%",
                     font=("微软雅黑", 20),
                     fg="black",
                     bd=5)
# 放置按键
btn0.place(x=150, y=450, width=150, height=55)
btn1.place(x=0, y=395, width=150, height=55)
btn2.place(x=150, y=395, width=150, height=55)
btn3.place(x=300, y=395, width=150, height=55)
btn4.place(x=0, y=340, width=150, height=55)
btn5.place(x=150, y=340, width=150, height=55)
btn6.place(x=300, y=340, width=150, height=55)
btn7.place(x=0, y=285, width=150, height=55)
btn8.place(x=150, y=285, width=150, height=55)
btn9.place(x=300, y=285, width=150, height=55)
btn_point.place(x=300, y=450, width=150, height=55)
btn_ac.place(x=0, y=230, width=150, height=55)
btn_back.place(x=150, y=230, width=150, height=55)
btn_division.place(x=300, y=230, width=150, height=55)
btn_mul.place(x=450, y=230, width=150, height=55)
btn_sub.place(x=450, y=285, width=150, height=55)
btn_add.place(x=450, y=340, width=150, height=55)
btn_equal.place(x=450, y=395, width=150, height=55)
btn_percent.place(x=0, y=450, width=150, height=55)

window.mainloop()
