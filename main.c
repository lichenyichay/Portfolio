/*
* �ļ�����main.cpp
* ���ߣ�Chay
* ����޸�ʱ�䣺2022/9/4 9:50:30
* �汾��alpha1.0
* ���ã����ʹ���ϵͳ�ļ�
* ���ܣ����ļ���VS��.cpp��ͬһ���ļ�������һ�£������ڳ�Visual Studio��������C/C++����������һ��bug�����ڿ����У�
*/
#include <stdio.h>          //��׼��������� 
#include "stdlib.h"         //��׼������ 
#include "string.h"         //�ַ��������� 
#include "conio.h"          //��Ļ����������
#include <Windows.h>
#define HEADER1 " ----------------------------ְ������---------------------------- "
#define HEADER2 "| ��� | ���� |��������| ���� | �ۿ� |Ӧ������| ˰�� |ʵ������| \n" 
#define HEADER3 "|--------|-----------|--------|--------|--------|--------|--------|--------| \n"
#define FORMAT "|%-8s|%-10s |%8.2f|%8.2f|%8.2f|%8.2f|%8.2f|%8.2f| \n" 
#define DATA p->num,p->name,p->jbgz,p->jj,p->kk,p->yfgz,p->sk,p->sfgz
#define END "--------------------------------------------------------------------------------- \n"
#define N 60
int saveflag = 0;//�Ƿ���Ҫ���̵ı�־������ȫ�֣� 
typedef struct employee {
	char num[10];//��� 
	char name[15];//���� 
	float jbgz;//�������� 
	float jj;//���� 
	float kk;//�ۿ� 
	float yfgz;//Ӧ������ 
	float sk;//˰�� 
	float sfgz;//ʵ������ 
}ZGGZ;//����ְ�������ݽṹ ��
void gotoxy(int x, int y)
{
	COORD c{};
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}//ʹ����ƶ����̶�����
void printheader() {
	printf(HEADER1);
	printf(HEADER2);
	printf(HEADER3);
}//��ӡ��ͷ��Ϣ �� 
void printdata(ZGGZ pp) {
	ZGGZ* p;
	p = &pp;
	printf(FORMAT, DATA);
}//��ӡ��¼��Ϣ �� 
void Disp(ZGGZ tp[], int n) {
	int i;
	if (n == 0) {
		printf("\n=====>û��ְ�����ʼ�¼��\n");
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
}//��ʾtp�����д洢��n����¼ �� 
float numberinput(const char* notice) {
	float t = 0.00;
	do {
		printf(notice);
		scanf_s("%f",&t);
		if (t < 0) {
			printf("\n��������ڵ���0����ֵ��\n");
		}
	} while (1);
	return t;
}//�����û�����ĸ���������ֵ ��
void stringinput(char* t, int lens, const char* notice) {
	char n[255]{};
	do {
		printf(notice);
		scanf_s("%s", n);
		if (strlen(n) > lens) {
			printf("\n���Ȳ�����Ҫ��\n");
		}
	} while (strlen(n)>lens);
	strcpy(t, n);
}//�����ַ����������г�����֤ ��
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
}//��λ�����з���Ҫ���Ԫ�أ��������±�ֵ �� 
int Add(ZGGZ tp[], int n) {
	char ch = 0, num[10]{};
	int i = 0, flag = 0;
	system("cls");
	Disp(tp, n);

	while (1) {
		while (1) {
			stringinput(num,10, "�������ţ�д0�˳���:");
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
				printf("==>���%s�ѱ�ռ�ã��Ƿ��������룿��y/n����",num);
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
		stringinput(tp[n].name, 15, "������");
		tp[n].jbgz = numberinput("�������ʣ�");
		tp[n].jj = numberinput("����");
		tp[n].kk = numberinput("�ۿ");
		tp[n].yfgz = tp[n].jbgz + tp[n].jj - tp[n].kk;
		tp[n].sk = tp[n].yfgz * 0.12;
		tp[n].sfgz = tp[n].yfgz - tp[n].sk;
		saveflag = 1;
		n++;
	}
	return n;
}//���ӹ��ʼ�¼�������������еĵ�ǰ��¼�� ��
void Qur(ZGGZ tp[], int n) {
	int select = 0;
	char searchinput[20]{};
	int p = 0;
	if (n <= 0) {
		system("cls");
		printf("\n=====>��ְ�����ʼ�¼��\n");
		getchar();
		return;
	}
	system("cls");
	printf("\n      =====>1����ְ����Ų�ѯ  =====>2����ְ��������ѯ\n");
	printf("        ��ѡ��1��2����");
	scanf("%d",&select);
	if (select == 1) {
		stringinput(searchinput,10,"������ְ����ţ�");
		p = Locate(tp, n, searchinput, "num");
		if (p != -1) {
			printheader();
			printdata(tp[p]);
			printf(END);
			printf("��������˳�");
			getchar();
		}
		else {
			Nofind();
			getchar();
		}
	}
	else if (select==2) { 
		stringinput(searchinput,15, "������Ա����������");
		p = Locate(tp, n, searchinput, "name");
		if (p != -1) { 
			printheader();
			printdata(tp[p]);
			printf(END);
			printf("��������˳�");
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
}//�������������ļ�¼������ʾ ��
int Del(ZGGZ tp[], int n) {
	int sel = 0;
	char findmess[20]{};
	int p = 0, i = 0;
	if (n <= 0) { 
		system("cls");
		printf("\n��ְ�����ʼ�¼��\n");
		getchar();
		return n;
	}
	system("cls");
	Disp(tp, n);
	printf("\n     =====>1�������ɾ��     =====>2��������ɾ��");
	printf("       ��ѡ��1��2����");
	scanf("%d",&sel);
	if (sel == 1) { 
		stringinput(findmess,10,"������ְ����ţ�");
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
			printf("\n==>ɾ����ϣ�\n");
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
		stringinput(findmess, 15, "������ְ��������");
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
			printf("\n==>ɾ����ϣ�\n");
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
}//�ҵ����������ļ�¼����ɾ�� ��
void Modify(ZGGZ tp[], int n) {
	char findmess[20]{};
	int p = 0;
	if (n <= 0) { 
		system("cls");
		printf("\n=====>û��ְ�����ʼ�¼��\n");
		getchar();
		return ;
	}
	system("cls");
	printf("�޸�ְ�����ʼ�¼");
	Disp(tp, n);
	stringinput(findmess, 10, "������Ա�����:");
	p = Locate(tp, n, findmess, "num");
	if (p != -1) { 
		printf("��ţ�%s,\n",tp[p].num);
		printf("������%s,",tp[p].name);
		stringinput(tp[p].name,15,"�������µ�������");
		printf("�������ʣ�%8.2f",tp[p].jbgz);
		tp[p].jbgz=numberinput("�������ʣ�");
		printf("����%8.2f", tp[p].jj);
		tp[p].jj = numberinput("����");
		printf("�ۿ%8.2f", tp[p].kk);
		tp[p].kk = numberinput("�ۿ");
		tp[n].yfgz=tp[n].jbgz+tp[n].jj-tp[n].kk;
		tp[n].sk=tp[n].yfgz*0.12;
		tp[n].sfgz=tp[n].yfgz-tp[n].sk;
		printf("\n=====>�޸���ɣ�");
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
}//�޸Ĺ��ʼ�¼ �� 
int Insert(ZGGZ tp[], int n) {
	char ch = 0, num[10]{}, s[10]{};
	ZGGZ newinfo{};
	int flag = 0,i = 0,kkk = 0;
	system("cls");
	Disp(tp, n);
	while (1) { 
		stringinput(s,10,"���������λ��ǰһλ�ı�ţ�");
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
			printf("���%s�����ڡ�����һ��? (y/n)",s);
			scanf("%c",ch);
			if (ch == 'y' || ch == 'Y') {
				continue;
			}
			else {
				return n;
			}
		}
		//�������������Add()������ͬ
	while (1) {
		stringinput(num, 10, "�������ţ�д0�˳���:");
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
				printf("==>���%s�ѱ�ռ�ã��Ƿ��������룿��y/n����", num);
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
	stringinput(newinfo.name, 15, "������");
	newinfo.jbgz = numberinput("�������ʣ�");
	newinfo.jj = numberinput("����");
	newinfo.kk = numberinput("�ۿ");
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
	stringinput(newinfo.name, 15, "������");
	newinfo.jbgz = numberinput("�������ʣ�");
	newinfo.jj = numberinput("����");
	newinfo.kk = numberinput("�ۿ");
	newinfo.yfgz = newinfo.jbgz + newinfo.jj - newinfo.kk;
	newinfo.sk = newinfo.yfgz * 0.12;
	newinfo.sfgz = newinfo.yfgz - newinfo.sk;
	n++;
	Disp(tp, n);
	printf("\n\n");
	getchar();
	return n;
}//���빤�ʼ�¼�������������еĵ�ǰ��¼�� ��
void Tongji(ZGGZ tp[], int n) {
	int count10000 = 0,count5000 = 0,count2000 = 0,count0 = 0;
	int i = 0;
	if (n <= 0) { 
		system("cls");
		printf("\n=====>��ְ�����ʼ�¼��\n");
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
	printf("\n-----------------------------ͳ�ƽ��-----------------------------\n");
	printf("     ʵ������>=10000:%d��\n",count10000);
	printf("5000<=ʵ������<10000:%d��\n", count5000);
	printf(" 2000<=ʵ������<5000:%d��\n", count2000);
	printf("          ʵ������<2000:%d��\n", count0);
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("\n\n��������˳�");
	getchar();
}//ͳ��ְ�����ʵ�����ֲ���� ��
void Sort(ZGGZ tp[], int n) {
	int i = 0,j = 0,flag = 0;
	ZGGZ newinfo{};
	if (n <= 0) { 
		system("cls");
		printf("\n=====>��ְ�����ʼ�¼��\n");
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
	printf("\n=====>������ɣ�\n");
}//��ʵ�������ֶν������� ��
void Save(ZGGZ tp[], int n) {
	FILE* fp = nullptr;
	int i = 0;
	fp = fopen("C:\\zggz", "wb");
	if (fp == NULL) { 
		printf("\n=====>�޷����ļ���");
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
		printf("\n\n=====>������ɣ�����ļ�¼������%d\n",i);
		getchar();
		saveflag = 0;
	}
	else { 
		system("cls");
		printf("û��δ�����Ա����¼��\n");
		getchar();
	}
	fclose(fp);
}//д����������ļ� ��
void menu() {
	HDC hdc = nullptr;
	hdc.GetDC();
	system("cls");
	SetTextColor(hdc,RGB(0,128,0));
	gotoxy(10, 5);
	cprintf("                      ���ʹ���ϵͳ                      \n");
	gotoxy(10, 8);
	cprintf("**************************�˵�**************************\n");
	gotoxy(10, 9);
	cprintf("        1�����ӹ��ʼ�¼            2��ɾ�����ʼ�¼      \n");
	gotoxy(10, 10);
	cprintf("        3����ѯ���ʼ�¼            4���޸Ĺ��ʼ�¼      \n");
	gotoxy(10, 11);
	cprintf("        5�����빤�ʼ�¼            6��ͳ�ƹ��ʼ�¼      \n");
	gotoxy(10, 12);
	cprintf("        7�����ʼ�¼����            8�����湤�ʼ�¼      \n");
	gotoxy(10, 13);
	cprintf("        9����ʾ���ʼ�¼            0���˳�����ϵͳ      \n");
	gotoxy(10, 14);
	cprintf("********************************************************\n");
}//��ʾ���˵� ��
void Wrong() {
	printf("\n\n\n\n\n\a\a\a\a\a***********����������󣬰�������˳�***********\n\a");
	getchar();
}//��ʾ������Ϣ ��
void Nofind() {
	printf("\n\a=====>δ���ҵ���ְ������Ϣ");
}//��ʾδ���ҵ�ְ����Ϣ �� 
int main() {
	ZGGZ gz[N]{};//����ṹ�� 
	FILE* fp;//�ļ�ָ�� 
	int select;//����ѡ�������� 
	char ch;//���棨y,Y,n,N�� 
	int count = 0;//�����ļ��еļ�¼����
	fp = fopen("C:\\zggz", "ab+");//��׷�ӷ�ʽ�򿪶������ļ����ɶ���д�����ļ������ڣ���ᴴ�����ļ� 
	if (fp == NULL) {
		printf("\n=====> �޷����ļ�!\n");
		return 0;
	}
	while (!feof(fp)) {
		if (fread(&gz[count], sizeof(ZGGZ), 1, fp));//һ�ζ�ȡһ�����ʼ�¼ 
		count++;
	}
	fclose(fp);
	printf("\n==> �ɹ����ļ����ܼ�¼���� : %d.\n", count);
	getchar();
	menu();
	while (1) {
		system("cls");
		menu();
		printf("\n                  ������˵����(0-9):");//��ʾ��ʾ��Ϣ 
		scanf("&d", &select);
		if (select == 0) {
			if (saveflag == 1) {//����������������޸���δ���д��̲�������˱�־Ϊ1 
				getchar();
				printf("\n==>�Ƿ���д���?(y/n):");
				scanf("%c", &ch);
				if (ch == 'y' || ch == 'Y')
					Save(gz, count);
			}
			printf("\n===>��л����ʹ��!");
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
}//������ ��
