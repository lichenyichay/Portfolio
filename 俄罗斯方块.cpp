/*
作者：Chay
最后编辑时间：2022/10/16 
内容：俄罗斯方块游戏
*/

// 预处理

// 导库
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <graphics.h>

// 定义宏常量
#define VK_LEFT  0x4b00// 定义按键码
#define VK_RIGHT 0x4d00// 定义按键码
#define VK_DOWN  0x5000// 定义按键码
#define VK_UP    0x4800// 定义按键码
#define VK_ESC   0x011b// 定义按键码
#define TIMER    0x1c          // 设置中断码
#define MAX_BOX 19          // 共有19种不同形态的方块
#define BSIZE 20          // 方块边长20像素
#define Sys_x 160          // 方块界面左上角x坐标
#define Sys_y 25          // 方块界面左上角y坐标
#define Hori_boxs 10          // 方块界面宽10*20像素
#define Vertical_boxs 15          // 方块界面长15*20像素
#define Begin_boxs_x Hori_boxs/2          // 产生第一个方块时出现的起始位置
#define FgColor 3          // 前景颜色
#define BgColor 0          // 背景颜色
#define Left_Winx Sys_x+Hori_boxs*BSIZE+46         // 右边状态栏的x坐标
#define false 0
#define true 1
#define MoveLeft 1          // 移动方向
#define MoveRight 2          // 移动方向
#define MoveDown 3          // 移动方向
#define MoveRoll 4          // 移动方向

// 定义全局变量
int current_box_numb;          //保存当前方块编号
int Curbox_x = Sys_x + Begin_boxs_x * BSIZE;          //保存方块当前x坐标
int Curbox_y = Sys_y;          //保存方块当前y坐标
int flag_newbox;          //是否产生新方块的标记
int speed = 0;          //下落速度
int score = 0;          //总分
int speed_step = 30;          //每等级所需分数
void interrupt(*oldtimer)(void);

// 定义结构体

// 游戏底板结构体
typedef struct BOARD {
	int var;
	int color;
}BOARD;
BOARD Table_borad[Vertical_boxs][Hori_boxs];

//方块结构
typedef struct SHAPE {
	char box[2];
	int color;
	int next;
}SHAPE;
SHAPE shapes[MAX_BOX]={0x88,0xc0,CYAN,1},{0xe8,0x0,CYAN,2}


void main() {
	;
}