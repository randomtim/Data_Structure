#include "function.h"

//功能：保留小数点后n位（需要完善）
double roundn(double a, int n)
{
	double b;
	b = round(a*pow(10, n));
	b = b / pow(10, n);
	return b;
}



//功能:字符串转整型（自用版）
//str:待转化的字符串
//返回值:int型数据
int atoi_s(const char* str)
{
	char maxunit = INTMAX % 10;
	int maxtest = INTMAX / 10;
	short signflag = 1;//符号位
	int digit = 0, value = 0;

	if (!str)//字符串为空返回0
		return 0;
	while (*str == ' ')//忽略字符串前端空格
		str++;
	if (*str == '+' || *str == '-') {//从正负号后开始转化
		if (*str == '-') {
			signflag = -1;
		}
		str++;
	}
	if (*str == '0')//不支持'03'此类型转化，直接返回 0
		return 0;
	while (*str >= '0'&&*str <= '9') {
		digit = *str - '0';//字符转数字
		if (signflag > 0) {
			if (value > maxtest || (value == maxtest && digit > maxunit))
				return INTMAX;
		}
		else {
			if (value > maxtest || (value == maxtest && digit > maxunit + 1))
				return INTMIN*signflag;
		}
		value = value * 10 + digit;
		str++;
	}


	return value*signflag;
}