# Payroll-system-C
文件信息：
作者：Chay
版本：alpha1.0
最后修改时间：2022/9/4 10:04:00
工资管理系统C语言版
本程序遵守Apache License 2.0开源协议，
本程序转载至《C语言从入门到精通》。
本库提供2个版本，VS版针对Visual Studio 17.3.2做出一些更改，以适应Visual Studio运行环境;
Dev-C++版适用于大部分运行环境。
有一个Bug还未解决，
本程序未开发完成！！！
代码见main.c（Dev-C++版）或VS版.cpp（VS版）。
两者代码一致！
结构体定义如下：
```C
typedef struct employee {
	char num[10];//编号 
	char name[15];//姓名 
	float jbgz;//基本工资 
	float jj;//奖金 
	float kk;//扣款 
	float yfgz;//应发工资 
	float sk;//税款 
	float sfgz;//实发工资 
}ZGGZ;//定义职工的数据结构 √
```
函数声明如下：
```C
void gotoxy(int x, int y);//使光标移动到固定坐标
void printheader();//打印表头信息
void printdata(ZGGZ pp);//打印记录信息
void Disp(ZGGZ tp[], int n);//显示tp数组中存储的n条记录
float numberinput(const char* notice);//输入数字并验证长度
void stringinput(char* t, int lens, const char* notice);//输入字符串并验证长度
int Locate(ZGGZ tp[], int n, char findmess[], const char nameornum[]);//定位数组中符合要求的元素，并返回下标值
int Add(ZGGZ tp[], int n);//增加工资记录，并返回当前数组中的当前记录数
void Qur(ZGGZ tp[], int n);//查找满足条件的记录，并显示
int Del(ZGGZ tp[], int n);//查找满足条件的记录，并删除
void Modify(ZGGZ tp[], int n);//修改工资记录
int Insert(ZGGZ tp[], int n);//插入工资记录，并返回数组中的当前记录数
void Tongji(ZGGZ tp[], int n);//统计职工工资的整体分布情况
void Sort(ZGGZ tp[], int n);//按实发工资字段降序排序
void Save(ZGGZ tp[], int n);//写入磁盘数据文件
void menu();//显示主菜单
void Wrong();//显示错误信息
void Nofind();//显示未查找到职工信息
```
