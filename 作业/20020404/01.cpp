/*
  10-3
  对10-2增加构造函数
  (1) 假定默认日期为你编写程序当天的日期。请为Date类增加4个构造函数：
    1、无参数，在函数体中，直接将日期设置为默认日期。
    2、只有1个参数用来指定年，月和日在函数体中直接设置为默认日期的月和日。
    3、有2个参数用于指定年和月，在函数体中直接设置日为默认日期的日。
    4、有3个参数用于指定年、月、日
  (2) 增加拷贝初始化构造函数
  提示，定义5个日期类对象，分别用于测试上述5个构造函数
*/

#include <iostream>
//设置默认日期
#define dYear 2022
#define dMonth 04
#define dDay 05
using namespace std;

class Date {
 public:
  //无参数构造函数
  Date() {
    m_Day = dDay;
    m_Month = dMonth;
    m_Year = dYear;
  }

  //一个参数用来指定年
  Date(int y) {
    m_Day = dDay;
    m_Month = dMonth;
    m_Year = y;
  }

  //两个参数用来指定年月
  Date(int y, int m) {
    m_Day = dDay;
    m_Month = m;
    m_Year = y;
  }

  //三个参数用来指定年月日
  Date(int y, int m, int d) {
    m_Day = d;
    m_Month = m;
    m_Year = y;
  }

  //拷贝构造函数
  Date(Date &temp) {
    m_Day = temp.m_Day;
    m_Month = temp.m_Month;
    m_Year = temp.m_Year;
  }

  //设置年月日的函数
  void setYMD(int y, int m, int d) {
    m_Year = y;
    m_Month = m;
    m_Day = d;
  }

  //获取年月日的值，指针做参数
  void getYMD(int *y, int *m, int *d) {
    cout << "以指针做参数获取年月日的值：" << endl;
    *y = m_Year;
    *m = m_Month;
    *d = m_Day;
  }

  //获取年月日的值，引用做参数
  void getYMD(int &y, int &m, int &d) {
    cout << "以引用做参数获取年月日的值：" << endl;
    y = m_Year;
    m = m_Month;
    d = m_Day;
  }

  //判断是否为闰年
  bool leapYear() {
    if ((m_Year % 4 == 0 && m_Year % 100 != 0) || m_Year % 400 == 0) {
      return true;
    } else {
      return false;
    }
  }

  //实现day加1的操作
  void increaseDay() {
    //判断是否为每年最后一天
    bool if_LastYearDay = (ifLastDay() && (m_Month == 12));
    if (ifLastDay() && !if_LastYearDay) {
      //普通的每月最后一天
      lastDay();
    } else if (if_LastYearDay) {
      //每年的最后一天
      lastYearDay();
    } else {
      //普通日期
      normalDay();
    }
  }

  //按year/month/day的格式输出日期
  void show() { cout << m_Year << "/" << m_Month << "/" << m_Day << endl; }

 private:
  int m_Year, m_Month, m_Day;

  //判断是否为最后一天
  bool ifLastDay() {
    //分三类： 2月、4/6/9/11、剩下的其他月份

    // 2月份
    if (m_Month == 2) {
      //先判断是否为闰年
      if (leapYear()) {
        //是闰年判断是否为29日
        if (m_Day == 29) {
          return true;
        } else {
          return false;
        }
      } else {
        //不是闰年判断是否为28日
        if (m_Day == 28) {
          return true;
        } else {
          return false;
        }
      }
    } else if (m_Month == 4 || m_Month == 6 || m_Month == 9 || m_Month == 11) {
      // 4/6/9/11月份 判断是否为30
      if (m_Day == 30) {
        return true;
      } else {
        return false;
      }
    } else {
      //其他月份判断是否为31
      if (m_Day == 31) {
        return true;
      } else {
        return false;
      }
    }
  }

  //正常日期操作
  void normalDay() { m_Day++; }

  //每月最后一日操作
  void lastDay() {
    m_Day = 1;
    m_Month++;
  }

  //每年最后一日操作
  void lastYearDay() {
    m_Day = 1;
    m_Month = 1;
    m_Year++;
  }
};

int main() {
  //测试缺省构造函数
  Date d0;
  cout << "缺省构造为：" << endl;
  d0.show();

  //测试一个参数构造函数
  Date d1(2000);
  cout << "只有年做参数构造为：" << endl;
  d1.show();

  //测试两个参数构造函数
  Date d2(2000, 01);
  cout << "只有年月做参数构造为：" << endl;
  d2.show();

  //测试三个参数构造函数
  Date d3(2000, 01, 01);
  cout << "有三个参数构造为：" << endl;
  d3.show();

  //测试拷贝构造
  Date d4(d3);
  cout << "拷贝构造为：" << endl;
  d4.show();

  return 0;
}