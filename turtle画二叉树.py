import turtle
def tree(branchlen, t):
    if branchlen > 5:
        t.forward(branchlen)  # 树干
        t.right(20)
        tree(branchlen - 15, t)
        t.left(40)
        tree(branchlen - 15, t)
        t.right(20)
        t.backward(branchlen)
t = turtle.Turtle()
t.shape('turtle')
myWin = turtle.Screen()
t.left(90)  # 左转90度
t.up()  # 抬笔
t.backward(200)  # 后退100
t.down()  # 落笔
t.color("green")
tree(120, t)
myWin.exitonclick()
turtle.done()
