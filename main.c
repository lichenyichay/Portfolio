/*
* 文件名：main.cpp
* 作者：Chay
* 最后修改时间：2022/9/4 9:50:30
* 版本：alpha1.0
* 作用：工资管理系统文件
* 介绍：本文件与VS版.cpp是同一个文件，代码一致，适用于除Visual Studio外其他的C/C++编译器，有一个bug，正在开发中！
*/
#include <stdio.h>          //标准输入输出库 
#include "stdlib.h"         //标准函数库 
#include "string.h"         //字符串操作库 
#include "conio.h"          //屏幕操作函数库
#include <Windows.h>
#define HEADER1 " ----------------------------职工工资---------------------------- "
#define HEADER2 "| 编号 | 姓名 |基本工资| 奖金 | 扣款 |应发工资| 税款 |实发工资| \n" 
#define HEADER3 "|--------|-----------|--------|--------|--------|--------|--------|--------| \n"
#define FORMAT "|%-8s|%-10s |%8.2f|%8.2f|%8.2f|%8.2f|%8.2f|%8.2f| \n" 
#define DATA p->num,p->name,p->jbgz,p->jj,p->kk,p->yfgz,p->sk,p->sfgz
#define END "--------------------------------------------------------------------------------- \n"
#define N 60
int saveflag = 0;//是否需要存盘的标志变量（全局） 
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
void gotoxy(int x, int y)
{
	COORD c{};
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}//使光标移动到固定坐标
void printheader() {
	printf(HEADER1);
	printf(HEADER2);
	printf(HEADER3);
}//打印表头信息 √ 
void printdata(ZGGZ pp) {
	ZGGZ* p;
	p = &pp;
	printf(FORMAT, DATA);
}//打印记录信息 √ 
void Disp(ZGGZ tp[], int n) {
	int i;
	if (n == 0) {
		printf("\n=====>没有职工工资记录！\n");
		getchar();
		return;
	}
	printf("\n\n");
	printheader();
	i = 0;
	while (i < n) {
		printdata(tp[i]);
		i++;
		printf(HEADER3);
	}
	getchar();
}//显示tp数组中存储的n条记录 √ 
float numberinput(const char* notice) {
	float t = 0.00;
	do {
		printf(notice);
		scanf_s("%f",&t);
		if (t < 0) {
			printf("\n请输入大于等于0的数值！\n");
		}
	} while (1);
	return t;
}//返回用户输入的浮点型数据值 √
void stringinput(char* t, int lens, const char* notice) {
	char n[255]{};
	do {
		printf(notice);
		scanf_s("%s", n);
		if (strlen(n) > lens) {
			printf("\n长度不符合要求！\n");
		}
	} while (strlen(n)>lens);
	strcpy(t, n);
}//输入字符串，并进行长度验证 √
int Locate(ZGGZ tp[], int n, char findmess[], const char nameornum[]) {
	int i = 0;
	if (strcmp(nameornum, "num") == 0) {
		while (i < n) {
			if (strcmp(tp[i].num, findmess)) {
				return i;
				i++;
			}
		}
	}
	else if (strcmp(nameornum, "name")) {
		while (i < n) {
			if (strcmp(tp[i].num, findmess)) {
				return i;
				i++;
			}
		}
	}
	else {
		return -1;
	}
}//定位数组中符合要求的元素，并返回下标值 √ 
int Add(ZGGZ tp[], int n) {
	char ch = 0, num[10]{};
	int i = 0, flag = 0;
	system("cls");
	Disp(tp, n);

	while (1) {
		while (1) {
			stringinput(num,10, "请输入编号（写0退出）:");
			flag = 0;
			if (strcmp(num, "0") == 0) {
				return n;
			}
			i = 0;
			while (i < n) {
				if (strcmp(tp[i].num, num) == 0) {
					flag = 1;
					break;
				}
				i++;
			}
			if (flag == 1) {
				getchar();
				printf("==>编号%s已被占用，是否重新输入？（y/n）：",num);
				scanf_s("%c", ch);
				if (ch == 'y' || ch == 'Y') {
					continue;
				}
				else {
					return n;
				}
			}
			else {
				break;
			}
		}
		strcpy(tp[n].num, num);
		stringinput(tp[n].name, 15, "姓名：");
		tp[n].jbgz = numberinput("基本工资：");
		tp[n].jj = numberinput("奖金：");
		tp[n].kk = numberinput("扣款：");
		tp[n].yfgz = tp[n].jbgz + tp[n].jj - tp[n].kk;
		tp[n].sk = tp[n].yfgz * 0.12;
		tp[n].sfgz = tp[n].yfgz - tp[n].sk;
		saveflag = 1;
		n++;
	}
	return n;
}//增加工资记录，并返回数组中的当前记录数 √
void Qur(ZGGZ tp[], int n) {
	int select = 0;
	char searchinput[20]{};
	int p = 0;
	if (n <= 0) {
		system("cls");
		printf("\n=====>无职工工资记录！\n");
		getchar();
		return;
	}
	system("cls");
	printf("\n      =====>1、按职工编号查询  =====>2、按职工姓名查询\n");
	printf("        请选择（1或2）：");
	scanf("%d",&select);
	if (select == 1) {
		stringinput(searchinput,10,"请输入职工编号：");
		p = Locate(tp, n, searchinput, "num");
		if (p != -1) {
			printheader();
			printdata(tp[p]);
			printf(END);
			printf("按任意键退出");
			getchar();
		}
		else {
			Nofind();
			getchar();
		}
	}
	else if (select==2) { 
		stringinput(searchinput,15, "请输入员工的姓名：");
		p = Locate(tp, n, searchinput, "name");
		if (p != -1) { 
			printheader();
			printdata(tp[p]);
			printf(END);
			printf("按任意键退出");
			getchar();
		}
		else {
			Nofind();
			getchar();
		}
	}
	else {
		Wrong();
		getchar();
	}
}//查找满足条件的记录，并显示 √
int Del(ZGGZ tp[], int n) {
	int sel = 0;
	char findmess[20]{};
	int p = 0, i = 0;
	if (n <= 0) { 
		system("cls");
		printf("\n无职工工资记录！\n");
		getchar();
		return n;
	}
	system("cls");
	Disp(tp, n);
	printf("\n     =====>1、按编号删除     =====>2、按姓名删除");
	printf("       请选择（1或2）：");
	scanf("%d",&sel);
	if (sel == 1) { 
		stringinput(findmess,10,"请输入职工编号：");
		p = Locate(tp, n, findmess, "num");
		getchar();
		if (p != -1) {
			for (i = p + 1; i < n; i++) { 
				strcpy(tp[i - 1].num, tp[i].num);
				strcpy(tp[i - 1].name, tp[i].name);
				tp[i - 1].jbgz = tp[i].jbgz;
				tp[i - 1].jj = tp[i].jj;
				tp[i - 1].kk = tp[i].kk;
				tp[i - 1].yfgz = tp[i].yfgz;
				tp[i - 1].sk = tp[i].sk;
				tp[i - 1].sfgz = tp[i].sfgz;
			}
			printf("\n==>删除完毕！\n");
			n--;
			getchar();
			saveflag = 1;
		}
		else { 
			Nofind();
			getchar();
		}
	}
	else if (sel == 2) {
		stringinput(findmess, 15, "请输入职工姓名：");
		p = Locate(tp, n, findmess, "name");
		getchar();
		if (p != -1) {
			for (i = p + 1; i < n; i++) {
				strcpy(tp[i - 1].num, tp[i].num);
				strcpy(tp[i - 1].name, tp[i].name);
				tp[i - 1].jbgz = tp[i].jbgz;
				tp[i - 1].jj = tp[i].jj;
				tp[i - 1].kk = tp[i].kk;
				tp[i - 1].yfgz = tp[i].yfgz;
				tp[i - 1].sk = tp[i].sk;
				tp[i - 1].sfgz = tp[i].sfgz;
			}
			printf("\n==>删除完毕！\n");
			n--;
			getchar();
			saveflag = 1;
		}
		else {
			Nofind();
			getchar();
		}
	}
	return n;
}//找到满足条件的记录，并删除 √
void Modify(ZGGZ tp[], int n) {
	char findmess[20]{};
	int p = 0;
	if (n <= 0) { 
		system("cls");
		printf("\n=====>没有职工工资记录！\n");
		getchar();
		return ;
	}
	system("cls");
	printf("修改职工工资记录");
	Disp(tp, n);
	stringinput(findmess, 10, "请输入员工编号:");
	p = Locate(tp, n, findmess, "num");
	if (p != -1) { 
		printf("编号：%s,\n",tp[p].num);
		printf("姓名：%s,",tp[p].name);
		stringinput(tp[p].name,15,"请输入新的姓名：");
		printf("基本工资：%8.2f",tp[p].jbgz);
		tp[p].jbgz=numberinput("基本工资：");
		printf("奖金：%8.2f", tp[p].jj);
		tp[p].jj = numberinput("奖金：");
		printf("扣款：%8.2f", tp[p].kk);
		tp[p].kk = numberinput("扣款：");
		tp[n].yfgz=tp[n].jbgz+tp[n].jj-tp[n].kk;
		tp[n].sk=tp[n].yfgz*0.12;
		tp[n].sfgz=tp[n].yfgz-tp[n].sk;
		printf("\n=====>修改完成！");
		getchar();
		Disp(tp, n);
		getchar();
		saveflag = 1;
	}
	else { 
		Nofind();
		getchar();
	}
	return ;
}//修改工资记录 √ 
int Insert(ZGGZ tp[], int n) {
	char ch = 0, num[10]{}, s[10]{};
	ZGGZ newinfo{};
	int flag = 0,i = 0,kkk = 0;
	system("cls");
	Disp(tp, n);
	while (1) { 
		stringinput(s,10,"请输入插入位置前一位的编号：");
		flag = 0; 
		i = 0;
		while (i < n) { 
			if (strcmp(tp[i].num, s) == 0) { 
				kkk = i;
				flag = 1;
				break;
			}
			i++;
		}
		if (flag == 1) { 
			break;
		}
		else {
			getchar();
			printf("编号%s不存在。再试一次? (y/n)",s);
			scanf("%c",ch);
			if (ch == 'y' || ch == 'Y') {
				continue;
			}
			else {
				return n;
			}
		}
		//以下输入操作与Add()函数相同
	while (1) {
		stringinput(num, 10, "请输入编号（写0退出）:");
			flag = 0;
			i = 0;
			while (i < n) {
				if (strcmp(tp[i].num, num) == 0) {
					flag = 1;
					break;
				}
				i++;
			}
			if (flag == 1) {
				getchar();
				printf("==>编号%s已被占用，是否重新输入？（y/n）：", num);
				scanf_s("%c", ch);
				if (ch == 'y' || ch == 'Y') {
					continue;
				}
				else {
					return n;
				}
			}
			else {
				break;
			}
		}
	}
	strcpy(newinfo.num, num);
	stringinput(newinfo.name, 15, "姓名：");
	newinfo.jbgz = numberinput("基本工资：");
	newinfo.jj = numberinput("奖金：");
	newinfo.kk = numberinput("扣款：");
	newinfo.yfgz = newinfo.jbgz + newinfo.jj - newinfo.kk;
	newinfo.sk = newinfo.yfgz * 0.12;
	newinfo.sfgz = newinfo.yfgz - newinfo.sk;
	saveflag = 1;
	for (i = n - 1; i > kkk; i--) { 
		strcpy(tp[i+1].num, tp[i].num);
		strcpy(tp[i+1].name,tp[i].name);
		tp[i+1].jbgz = tp[i].jbgz;
		tp[i+1].jj = tp[i].jj;
		tp[i+1].kk = tp[i].kk;
		tp[i+1].yfgz = tp[i].yfgz;
		tp[i+1].sk = tp[i].sk;
		tp[i+1].sfgz = tp[i].sfgz;
	}
	strcpy(newinfo.num, num);
	stringinput(newinfo.name, 15, "姓名：");
	newinfo.jbgz = numberinput("基本工资：");
	newinfo.jj = numberinput("奖金：");
	newinfo.kk = numberinput("扣款：");
	newinfo.yfgz = newinfo.jbgz + newinfo.jj - newinfo.kk;
	newinfo.sk = newinfo.yfgz * 0.12;
	newinfo.sfgz = newinfo.yfgz - newinfo.sk;
	n++;
	Disp(tp, n);
	printf("\n\n");
	getchar();
	return n;
}//插入工资记录，并返回数组中的当前记录数 √
void Tongji(ZGGZ tp[], int n) {
	int count10000 = 0,count5000 = 0,count2000 = 0,count0 = 0;
	int i = 0;
	if (n <= 0) { 
		system("cls");
		printf("\n=====>无职工工资记录！\n");
		getchar();
		return ;
	}
	system("cls");
	Disp(tp, n);
	i = 0;
	while (i < n) { 
		if (tp[i].sfgz >= 10000) { 
			count10000++;
			i += 1;
			continue;
		}
		if (tp[i].sfgz >= 5000) {
			count5000++;
			i += 1;
			continue;
		}
		if (tp[i].sfgz >= 2000) {
			count2000++;
			i += 1;
			continue;
		}
		if (tp[i].sfgz < 2000) {
			count0++;
			i += 1;
			continue;
		}
	}
	printf("\n-----------------------------统计结果-----------------------------\n");
	printf("     实发工资>=10000:%d人\n",count10000);
	printf("5000<=实发工资<10000:%d人\n", count5000);
	printf(" 2000<=实发工资<5000:%d人\n", count2000);
	printf("          实发工资<2000:%d人\n", count0);
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("\n\n按任意键退出");
	getchar();
}//统计职工工资的整体分布情况 √
void Sort(ZGGZ tp[], int n) {
	int i = 0,j = 0,flag = 0;
	ZGGZ newinfo{};
	if (n <= 0) { 
		system("cls");
		printf("\n=====>无职工工资记录！\n");
		getchar();
		return ;
	}
	system("cls");
	Disp(tp,n);
	for (i = 0;i<n;i++) { 
		flag = 0;
		for (j=0;j<n-1;j++) { 
			if ((tp[j].sfgz<tp[j + 1].sfgz)) {
				flag = 1;
				strcpy(newinfo.num,tp[j].num);
				strcpy(newinfo.name, tp[j].name);
				newinfo.jbgz = tp[j].jbgz;
				newinfo.sfgz = tp[j].sfgz;
				newinfo.yfgz = tp[j].yfgz;
				newinfo.jj = tp[j].jj;
				newinfo.kk = tp[j].kk;
				newinfo.sk = tp[j].sk;

				strcpy(tp[j].num, tp[j + 1].num);
				strcpy(tp[j].name, tp[j + 1].name);
				tp[j].jbgz = tp[j + 1].jbgz;
				tp[j].sfgz = tp[j + 1].sfgz;
				tp[j].yfgz = tp[j + 1].yfgz;
				tp[j].jj = tp[j + 1].jj;
				tp[j].kk = tp[j + 1].kk;
				tp[j].sk = tp[j + 1].sk;

				strcpy(tp[j + 1].num, newinfo.num);
				strcpy(tp[j + 1].name, newinfo.name);
				tp[j + 1].jbgz = newinfo.jbgz;
				tp[j + 1].sfgz = newinfo.sfgz;
				tp[j + 1].yfgz = newinfo.yfgz;
				tp[j + 1].jj = newinfo.jj;
				tp[j + 1].kk = newinfo.kk;
				tp[j + 1].sk = newinfo.sk;
			}
			if (flag == 0) {
				break; 
			}
		}
	}
	Disp(tp, n);
	saveflag = 1;
	printf("\n=====>排序完成！\n");
}//按实发工资字段降序排序 √
void Save(ZGGZ tp[], int n) {
	FILE* fp = nullptr;
	int i = 0;
	fp = fopen("C:\\zggz", "wb");
	if (fp == NULL) { 
		printf("\n=====>无法打开文件！");
		getchar();
		return ;
	}
	for (i = 0; i < n; i++) { 
		if (fwrite(&tp[i],sizeof(ZGGZ),1,fp)){ 
			continue; 
		}
		else { 
			break; 
		}
	}
	if (i > 0) { 
		getchar();
		printf("\n\n=====>保存完成，保存的记录条数：%d\n",i);
		getchar();
		saveflag = 0;
	}
	else { 
		system("cls");
		printf("没有未保存的员工记录！\n");
		getchar();
	}
	fclose(fp);
}//写入磁盘数据文件 √
void menu() {
	HDC hdc = nullptr;
	hdc.GetDC();
	system("cls");
	SetTextColor(hdc,RGB(0,128,0));
	gotoxy(10, 5);
	cprintf("                      工资管理系统                      \n");
	gotoxy(10, 8);
	cprintf("**************************菜单**************************\n");
	gotoxy(10, 9);
	cprintf("        1、增加工资记录            2、删除工资记录      \n");
	gotoxy(10, 10);
	cprintf("        3、查询工资记录            4、修改工资记录      \n");
	gotoxy(10, 11);
	cprintf("        5、插入工资记录            6、统计工资记录      \n");
	gotoxy(10, 12);
	cprintf("        7、工资记录排序            8、保存工资记录      \n");
	gotoxy(10, 13);
	cprintf("        9、显示工资记录            0、退出管理系统      \n");
	gotoxy(10, 14);
	cprintf("********************************************************\n");
}//显示主菜单 √
void Wrong() {
	printf("\n\n\n\n\n\a\a\a\a\a***********错误：输入错误，按任意键退出***********\n\a");
	getchar();
}//显示错误信息 √
void Nofind() {
	printf("\n\a=====>未查找到此职工的信息");
}//显示未查找到职工信息 √ 
int main() {
	ZGGZ gz[N]{};//定义结构体 
	FILE* fp;//文件指针 
	int select;//保存选择结果变量 
	char ch;//保存（y,Y,n,N） 
	int count = 0;//保存文件中的记录条数
	fp = fopen("C:\\zggz", "ab+");//以追加方式打开二进制文件，可读可写，若文件不存在，则会创建此文件 
	if (fp == NULL) {
		printf("\n=====> 无法打开文件!\n");
		return 0;
	}
	while (!feof(fp)) {
		if (fread(&gz[count], sizeof(ZGGZ), 1, fp));//一次读取一条工资记录 
		count++;
	}
	fclose(fp);
	printf("\n==> 成功打开文件，总记录条数 : %d.\n", count);
	getchar();
	menu();
	while (1) {
		system("cls");
		menu();
		printf("\n                  请输入菜单序号(0-9):");//显示提示信息 
		scanf("&d", &select);
		if (select == 0) {
			if (saveflag == 1) {//若对数组的数据有修改且未进行存盘操作，则此标志为1 
				getchar();
				printf("\n==>是否进行存盘?(y/n):");
				scanf("%c", &ch);
				if (ch == 'y' || ch == 'Y')
					Save(gz, count);
			}
			printf("\n===>感谢您的使用!");
			getchar();
			break;
		}
		switch (select) {
		case 1: {
			count = Add(gz, count);
			break;
			}
		case 2: {
			count = Del(gz, count);
			break;
			}
		case 3: {
			Qur(gz, count);
			break;
			}
		case 4: {
			Modify(gz, count);
			break;
			}
		case 5: {
			Insert(gz, count);
			break;
			}
		case 6: {
			Tongji(gz, count);
			break;
			}
		case 7: {
			Sort(gz, count);
			break;
			}
		case 8: {
			Save(gz, count);
			break;
			}
		case 9: {
			system("cls");
			Disp(gz, count);
			break;
			}
		default: {
			Wrong();
			getchar();
			break;
			}
		}
	}
	return 0;
}//主函数 √
