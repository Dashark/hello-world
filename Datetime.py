import datetime
import time
import sxtwl


class DateTime(object):
    def __init__(self):
        tktime = datetime.datetime.now().timetuple()
        self.year = tktime.tm_year
        self.month = tktime.tm_mon
        self.day = tktime.tm_mday
        self.hour = tktime.tm_hour
        self.minute = tktime.tm_min
        self.second = tktime.tm_sec
        self.seconds = time.mktime(tktime)

    def showTime(self):
        print("%d/%d/%d  %d:%d:%d" % (self.year, self.month, self.day, self.hour, self.minute, self.second))
        print("The seconds from 1970.1.1（北京时间） is %d" % (self.seconds + 8 * 3600))
        # timestamps
        
    def ShowMoon(self):
        lunar = sxtwl.Lunar()  # 实例化日历库
        ymc = [u"十一", u"十二", u"正", u"二", u"三", u"四", u"五", u"六", u"七", u"八", u"九", u"十"]
        rmc = [u"初一", u"初二", u"初三", u"初四", u"初五", u"初六", u"初七", u"初八", u"初九", u"初十",
               u"十一", u"十二", u"十三", u"十四", u"十五", u"十六", u"十七", u"十八", u"十九",
               u"二十", u"廿一", u"廿二", u"廿三", u"廿四", u"廿五", u"廿六", u"廿七", u"廿八", u"廿九", u"三十", u"卅一"]
        day = lunar.getDayBySolar(self.year, self.month, self.day)
        #       print(u"公历:", day.y, "年", day.m, "月", day.d, "日")
        if day.Lleap:
            print("农历:润", ymc[day.Lmc], "月", rmc[day.Ldi], "日")
        else:
            print("农历:", ymc[day.Lmc], "月", rmc[day.Ldi])


dt = DateTime()
dt.showTime()
dt.ShowMoon()
