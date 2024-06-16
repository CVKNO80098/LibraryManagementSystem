#include "header.h"

void AdminPageMain(UserInfo user , HANDLE hOut) {
	system("cls");
	COORD pos;// 光标坐标变量

	pos.X = 0;
	pos.Y = 0;
	SetColor(0x0f, 0);
	printf("┌─────────────────────────────────────┐\n");
	printf("│              您好 %s             │\n", user.username);
	printf("├─────────────────────────────────────┤\n");
	printf("│        1、查看总图书情况            │\n");
	printf("│        2、查看册图书情况            │\n");
	printf("│        3、查找指定图书情况          |\n");
	printf("│        4、添加一种书籍              │\n");
	printf("│        5、入库书籍                  |\n");
	printf("|        6、注册新的账户              │\n");
	printf("|        7、查看所有账户              │\n");
	printf("|        8、删除指定账户              │\n");
	printf("│        9、退出                      │\n");
	printf("└─────────────────────────────────────┘\n");
}

void AdminPageRegister(HANDLE hOut) {
	system("cls");
	COORD pos;// 光标坐标变量
	//定义句柄变量

	pos.X = 0;
	pos.Y = 0;
	SetColor(0x0f, 0);
	printf("┌─────────────────────────────────────┐\n");
	printf("│             注册新账户              │\n");
	printf("├─────────────────────────────────────┤\n");
	printf("│        昵称：_______________        │\n");
	printf("│        账户：_______________        |\n");
	printf("│        密码：_______________        │\n");
	printf("│        是否是管理员（1or0):__       |\n");
	printf("|                                     │\n");
	printf("│        取消           确认          │\n");
	printf("└─────────────────────────────────────┘\n");
}

void UserPageMain(UserInfo user, HANDLE hOut) {
	system("cls");
	COORD pos;// 光标坐标变量

	pos.X = 0;
	pos.Y = 0;
	SetColor(0x0f, 0);
	printf("┌─────────────────────────────────────┐\n");
	printf("│              您好 %-5s             │\n", user.username);
	printf("├─────────────────────────────────────┤\n");
	printf("│        1、查看总图书情况            │\n");
	printf("│        2、查看册图书情况            │\n");
	printf("│        3、查找指定图书情况          |\n");
	printf("│        4、从库中借阅书籍            │\n");
	printf("│        5、借阅指定书籍              |\n");
	printf("|        6、归还书本                  │\n");
	printf("|        7、查看当前借阅              │\n");
	printf("│        9、退出                      │\n");
	printf("└─────────────────────────────────────┘\n");
}