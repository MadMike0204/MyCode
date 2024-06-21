import tkinter as tk
import tkinter.ttk as ttk
import tkinter.messagebox as mb
import tkinter.scrolledtext as sc
import openpyxl as px
import sys
import datetime
import time
from Exam import *
mWin=0
tno=0
tname=0
note=0
tqus=0
blogin=0
L_info=0
bnext=0
v=0
Lresult=0
tans=0
ba=0
bb=0
bc=0
bd=0

qusAndAns=QusAndAns()
qus=qusAndAns.getQusOfSelect()
ans=qusAndAns.getAnsOfSelect()
analyze=qusAndAns.getAnalyzeOfSelect()
eName,eTime=qusAndAns.getEnameAndEtime()
randselect=qusAndAns.getRandQusOfSelect()
totalSelect,iselectScore=qusAndAns.getTotalAndiScore()
totalScore=0
logstate=0
indexofselect=1

#计时器类
class myTimer:
    def __init__(self,window,label,seconds):
        self.hours=0
        self.minutes=0
        self.seconds=0
        self.is_running=False
        self.start_time=0
        self.window=window
        self.label=label
        self.duration=seconds
    def format_time(self,seconds):
        self.hours=seconds//3600
        self.minutes=(seconds%3600)//60
        self.seconds=seconds%60
        return '%02d:%02d:%02d'%(self.hours,self.minutes,self.seconds)
    #更新时间函数
    def update_time(self):
        if self.is_running:
            remaining_time=self.duration-(datetime.datetime.now()-self.start_time).total_seconds()
            if remaining_time<=0:
                self.is_running=False
                self.label.config(text='剩余时间：'+self.format_time(0))
                GameOver
            else:
                t=self.format_time(int(remaining_time))
                self.label.config(text='学号：%s    姓名：%s    剩余时间：%s'%(tno.get(),tname.get(),t))
                self.window.after(1000,self.update_time)
    #开始计时
    def start(self):
        self.start_time=datetime.datetime.now()
        self.is_running=True
        self.update_time()
    #停止计时
    def stop(self):
        self.is_running=False
        self.format.time(0)

def loginCall():
    global logstate
    sno=tno.get()
    sname=tname.get()
    #验证用户名和姓名是否存在
    stu=Stu()
    stu_info=stu.getStu()
    if (sno,sname) in stu_info: #学号 姓名存在
        logstate=1
        mb.showinfo('QuizGame','登录成功，开始游戏！')
        note.tab(1,state='normal')
        tqus.config(state='normal')
        tqus.focus_set()
        tno.config(state='disable')
        tname.config(state='disable')
        blogin['state']='disable'
        #切换到选择题选项卡
        tab1=note.tabs()[1]
        note.select(tab1)
        T1=myTimer(mWin,L_info,eTime*60)
        T1.start()
    else:
        mb.showinfo('QuizGame','学号或姓名错误，请重新输入！')
#未登录点击选项卡的事件处理
def click(event):
    global logstate
    if logstate==0:
        mb.showinfo('QuizGame','请先登录后开始测验游戏！')
#加载选择题选项卡事件处理（激活tqus）
def load(event):
    global indexofselect
    tqus.insert('0.0',str(indexofselect)+qus[randselect[0]])
    tqus.config(state='disable')
def radioCall():
    global indexofselect,totalScore
    if (v.get()!=ans[randselect[indexofselect-1]]):
        Lresult['fg']='red'
        Lresult.config(text='错误',font=('宋体',14,'bold'))
        tans.config(state='normal')
        s='答案：'+'/n'+'解析：'+analyze[indexofselect-1]
        tans.insert('0.0',s)
        tans.config(state='disable')
    else:
        Lresult['fg']='green'
        Lresult.config(text='正确',font=('宋体',14,'bold'))
    #完成答错后禁止重新选择
    ba.config(state='disable')
    bb.config(state='disable')
    bc.config(state='disable')
    bd.config(state='disable')
#下一题按钮事件
def nextCall():
    global indexofselect
    global v
    v.set('E')
    indexofselect+=1
    Lresult.config(text='')
    if(indexofselect>len(qus)):
        indexofselect=len(qus)
        bnext.config(state='disable')
        mb.showinfo('QuizGame','选择题结束，进入填空题！')
        note.tab(2,state='normal')
        tab2=note.tabs()[2]
        note.select(tab2)
        #游戏结束
        GameOver()
    ba.config(state='normal')
    bb.config(state='normal')
    bc.config(state='normal')
    bd.config(state='normal')
    tqus.config(state='normal')
    tans.config(state='normal')
    tqus.delete('0.0','40.200')
    tans.delete('0.0','40.200')
    tqus.insert('0.0',str(indexofselect)+qus[randselect[indexofselect-1]])
    tqus.config(state='disable')
    tans.config(state='disable')
#游戏结束，题目做完结束游戏，记录最高分
def GameOver():
    result=TxtFile.getMaxScore()
    if result==-1 or totalScore>result:
        mb.showinfo(title='QuozGame',message='您的分数为：%d\n恭喜你创造了新的得分记录！\n我们将记录你的成绩！谢谢！'%totalScore)
        sno=tno.get()
        sname=tname.get()
        TxtFile.setNewRecord(sno,sname,totalScore)
    else:
        mb.showinfo(title='QuizGame',message='您的分数为：%d\n对不起，你没有创造新的得分记录！\n下次再努力哦！谢谢！'%totalScore)
    mWin.destroy()
    sys.exit()
    

def main():
    global mWin,tno,tname,note,tqus,blogin,L_info,bnext,v,Lresult,tans,ba,bb,bc,bd
    mWin=tk.Tk()
    x=mWin.winfo_screenwidth()
    y=mWin.winfo_screenheight()
    x=(x-800)//2
    y=(y-600)//2
    mWin.geometry(f'800x600+{x}+{y}')
    mWin.title('QuizGame'+' '*50+'测验名称：'+eName+' '*10+'测验时长(分):'+str(eTime))
    L_info=ttk.Label(mWin,text='剩余时间：')
    L_info.pack(side=tk.BOTTOM)
    note=ttk.Notebook(mWin)
    note.pack(fill='both',expand=True)
    #登录选项卡
    frm1=ttk.Frame(note)
    frm1.pack(fill='both',expand=True)
    note.add(frm1,text='登录')
    text1=sc.ScrolledText(frm1,height=30,width=100,wrap=tk.WORD)
    text1.insert('0.0','\n\n'+'QuizGame游戏说明'.center(100))
    text1.insert('25.0 linestart','\n\n\n\n'+TxtFile.getGameInfo())

    lno=ttk.Label(frm1,text='学号：')
    lname=ttk.Label(frm1,text='姓名：')
    tno=ttk.Entry(frm1)
    tname=ttk.Entry(frm1)
    blogin=ttk.Button(frm1,text='登录',command=loginCall)#登录按钮
    #布局登录选项卡
    text1.grid(column=0,row=0,columnspan=8,rowspan=30,padx=50,pady=20,sticky=tk.E)
    lno.grid(column=3,row=30,padx=2,pady=5,sticky=tk.E)#右对齐
    tno.grid(column=4,row=30,padx=2,pady=5,sticky=tk.W)#左对齐
    lname.grid(column=3,row=31,padx=2,pady=5,sticky=tk.E)
    tname.grid(column=4,row=31,padx=2,pady=5,sticky=tk.W)
    blogin.grid(column=4,row=32,padx=5,pady=5,sticky=tk.W)
    #选择题选项卡
    frm2=ttk.Frame(note)
    frm2.pack(fill='both',expand=True)
    note.add(frm2,text='选择题',state='disabled')
    Lqus=ttk.Label(frm2,text='题目：')
    tqus=sc.ScrolledText(frm2)#题目
    tqus.config(state='disabled')
    v=tk.StringVar()
    ba=ttk.Radiobutton(frm2,text='A',variable=v,value='A',command=radioCall)#选项
    bb=ttk.Radiobutton(frm2,text='B',variable=v,value='B',command=radioCall)
    bc=ttk.Radiobutton(frm2,text='C',variable=v,value='C',command=radioCall)
    bd=ttk.Radiobutton(frm2,text='D',variable=v,value='D',command=radioCall)
    bnext=ttk.Button(frm2,text='下一题',command=nextCall)#下一题按钮
    Lans=ttk.Label(frm2,text='解析：')
    tans=sc.ScrolledText(frm2)#答案解析
    tans.config(state='disabled')
    tqus.bind('<FocusIn>',load)
    Lresult=tk.Label(frm2)
    #布局选择题选项卡
    Lqus.grid(column=0,row=1,padx=20,pady=15,sticky=tk.W)
    Lans.grid(column=9,row=1,padx=5,pady=15,sticky=tk.W)
    tqus.config(height=30,width=80)
    tqus.grid(column=0,row=2,columnspan=9,rowspan=30,padx=20,pady=5,sticky=tk.E)
    tans.config(height=30,width=20)
    tans.grid(column=9,row=2,columnspan=3,rowspan=30,padx=5,pady=5,sticky=tk.E)
    ba.grid(column=2,row=33,padx=2,pady=5,sticky=tk.E)
    bb.grid(column=3,row=33,padx=2,pady=5,sticky=tk.E)
    bc.grid(column=4,row=33,padx=2,pady=5,sticky=tk.E)
    bd.grid(column=5,row=33,padx=2,pady=5,sticky=tk.E)
    bnext.grid(column=3,row=36,columnspan=2,padx=2,pady=5,sticky=tk.E)
    Lresult.grid(column=9,row=36,padx=2,pady=5)
    #填空题选项卡
    frm3=ttk.Frame(note)
    frm3.pack(fill='both',expand=True)
    note.add(frm3,text='填空题',state='disabled')

    note.bind('<Button-1>',click)#左键点击选项卡事件
    mWin.mainloop()

if __name__=='__main__':
    main()
    
    
    
    
