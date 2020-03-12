import easygui as g
import sys
while 1:
    g.msgbox(msg='嗨，欢迎进入第一个GUI制作的小游戏~~', image='cat.gif')
    msg = '你希望学习到怎样的知识呢？'
    title = '互动小游戏'
    choices = ['琴棋书画', '四书五经', '程序编写', '逆向分析']
    choice = g.choicebox(msg, title, choices)
    g.msgbox(msg='你的选择是：' + str(choice), title='结果')
    msg = '你希望重新开始小游戏吗？'
    title = '请离开'
    if g.ccbox(msg, title):
        pass
    else:
        sys.exit(0)
