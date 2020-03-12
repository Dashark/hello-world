class Force:  # 力
    def __init__(self, x, y):  # x，y轴分量
        self.fx, self.fy = x, y

    def show(self):  # 打印出力的值
        print("Force<%s,%s>" % (self.fx, self.fy))

    def add(self, force2):  # 与另一个力合成
        x = self.fx + force2.fx
        y = self.fy + force2.fy
        return Force(x, y)


# 生成一个力对象
f1 = Force(0, 1)
f1.show()
# 生成另一个力
f2 = Force(3, 4)
f2.show()
# 合成新的力
f3 = f1.add(f2)
f3.show()
