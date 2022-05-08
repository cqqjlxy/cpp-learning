/*
实验指导书实验11-1：
*/
#include <iostream>

using namespace std;

class Time {
private:
	int hour, minute, second;	//表示时间的时分秒
	
	//静态成员表示基准时间
	static int baseHour;
	static int baseMinute;
	static int baseSecond;

	static int timeToSecond(Time t);

public:
	//构造函数，完成对时间的初始化 
	Time(int hour = 0, int minute = 0, int second = 0) {
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}

	//静态成员函数，计算时间t与基准时间相差的总秒数
	static int timeBaseDifference(Time t);

	//以时：分：秒的格式输出时间
	void show() {
		cout << hour << ":" << minute << ":" << second << endl;
	}

	//友元函数：返回t1和t2的单位时间差
	friend int difference(Time t1, Time t2) {
		return (Time::timeToSecond(t1) - Time::timeToSecond(t2));
	}
};

//初始化基准时间
int Time::baseHour = 1;
int Time::baseMinute = 10;
int Time::baseSecond = 10;

//实现转秒数静态成员函数
int Time::timeToSecond(Time t) {
	int totalSec;
	totalSec = (t.hour * 60 * 60) + (t.minute * 60) + t.second;
	return totalSec;
}

//实现计算差值的函数
int Time::timeBaseDifference(Time t) {
	return  (timeToSecond(t) - ((baseHour * 60 * 60) + (baseMinute * 60) + baseSecond));
}

int main() {
	Time t1(1, 11, 2);
	Time t2(1, 12, 50);
	t1.show();
	t2.show();
	cout << "t1与基准时间的差值为: " << Time::timeBaseDifference(t1) << "秒" << endl;
	cout << "t2与基准时间的差值为: " << Time::timeBaseDifference(t2) << "秒" << endl;
	cout << "t1与t2的差值为: " << difference(t1, t2) << "秒" << endl;
	return 0;
	
}


