/*
  定义一个描述日期的类(Date)，数据成员包括年(year)，月(month)和日(day)。
  成员函数包括：
  (1) void setYMD(int, int, int); 设置年月日。
  (2) void getYMD(int *, int *, int *); 获取年月日的值，指针做参数。
  (3) void getYMD(int &, int &, int &); 获取年月日的值，引用做参数。
  (4) boo1 1eapYear(); 若 year是闰年，则返回 true; 否则返回 false。
      判断闰年的条件：
      若年份能被 4 整除而不能被 100 整除，或者年份能被 400
  整除，则该年份是闰年。 (5) void increaseDay(); 实现日子 day 加 1
  的操作，注意要考虑每个月不同日子数，可
      能需要做日月年的“进位”操作。即如果当月的最后一个日子加
  1，则“进位”到下一个月，当 年的最后一个日子加
  1，则“进位”到下一年。二月份还要考虑是否为闰年。 提示：2月份平年 28 天、闰年 29
  天，4/6/9/11月的每月 30 天,其余月份每月 31 天。
  运行时,可用如下日期测试程序的正确性：
  2015.2.28 (2015 年不是闰年)
  2015.3.5
  2015.4.30
  2015.5.30
  2015.12.31
  2000.2.28 (2000年是闰年)
  2000.2.29
  (6) void show(); 按 year/month/day 的格式输出日期，如 2015/1/28。
  请编写完整的程序，在主函数中定义日期类对象，输入年月日，完成上述所有成员函数的测试工作
*/

#include <iostream>

using namespace std;

class Date {
 public:
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
  Date d1;
  int y, m, d;

  //测试setYMD();
  cout << "请输入年月日(以空格隔开)：";
  cin >> y >> m >> d;
  d1.setYMD(y, m, d);

  //测试getYMD(int *, int *，int *);
  int gy, gm, gd;
  d1.getYMD(&gy, &gm, &gd);
  cout << gy << "/" << gm << "/" << gd << endl;

  //测试getYMD(int &, int &, int &);
  d1.getYMD(gy, gm, gd);
  cout << gy << "/" << gm << "/" << gd << endl;

  //测试leapYear();
  if (d1.leapYear()) {
    cout << y << "是闰年。" << endl;
  } else {
    cout << y << "不是闰年。" << endl;
  }

  //测试increaseDay();
  d1.increaseDay();

  cout << "增加一天后日期为：" << endl;

  //测试show();
  d1.show();

  return EXIT_SUCCESS;
}