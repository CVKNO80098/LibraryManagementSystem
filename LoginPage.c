#include "header.h"

int login(Chain *head) {
	COORD pos;// 光标坐标变量
	//定义句柄变量
	HANDLE hOut = NULL;

	//获取标准输出句柄
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	while (1) {
		SetColor(0x0f, 0);
		pos.X = 0;
		pos.Y = 0;

		SetConsoleCursorPosition(hOut, pos);
		printf("┌───────────────────┐\n"); // len:21
		printf("│       请登录：    │\n");
		printf("│账户：_____________│\n");
		printf("│密码：_____________│\n");
		printf("└───────────────────┘\n");

		pos.X = 7;
		pos.Y = 2;
		SetConsoleCursorPosition(hOut, pos);
		static char username[20];
		gets(&username);

		pos.X = 7;
		pos.Y = 3;
		SetConsoleCursorPosition(hOut, pos);
		char* password = input_password();

		pos.X = 7;
		pos.Y = 8;
		SetConsoleCursorPosition(hOut, pos);

		UserInfo user = loginSub(username, password);
		if (user.id == -1) {
			SetColor(0x0c, 0);
			printf("账户或密码错误！");
		}
		else {
			if (user.isAdmin == 1)
			{
				system("cls");
				Manage(user, head);
			}
			else {
				system("cls");
				UserMenu(user, head);
			}
		}
	}
}