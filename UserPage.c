#include "header.h"

int UserMenu(UserInfo user, Chain* head) {

	COORD pos;// 光标坐标变量
	//定义句柄变量
	HANDLE hOut = NULL;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	int user_choice = 0;

	while (1)
	{
		switch (user_choice)
		{
			case 0: {
				UserPageMain(user, hOut);
				pos.X = 9;
				pos.Y = 3;
				SetConsoleCursorPosition(hOut, pos);
				SetColor(0x0a, 0);
				printf("1、查看总图书情况");
				if ((user_choice = KeyboardChoice(user_choice, 7)) == 200)
				{
					system("cls");
					SetColor(0x0f, 0);
					displayAllBooksInfo(head);
					printf("\n按回车键继续");
					getchar();
				}
				break;
			}
			case 1: {
				UserPageMain(user, hOut);
				pos.X = 9;
				pos.Y = 4;
				SetConsoleCursorPosition(hOut, pos);
				SetColor(0x0a, 0);
				printf("2、查看册图书情况");
				if ((user_choice = KeyboardChoice(user_choice, 7)) == 200) {
					system("cls");
					SetColor(0x0f, 0);
					printf("┌─────────────────────────────────────┐\n");
					printf("│              查询                   │\n");
					printf("├─────────────────────────────────────┤\n");
					printf("│       书籍id：______________        │\n");
					printf("└─────────────────────────────────────┘\n");
					pos.X = 16;
					pos.Y = 3;
					SetConsoleCursorPosition(hOut, pos);
					int book_id;
					scanf("%d", &book_id);
					system("cls");
					displayBooksInfo(head, book_id);
					getchar(); getchar();
				}
				break;
			}
			case 2: {
				pos.X = 0;
				pos.Y = 0;
				UserPageMain(user, hOut);
				pos.X = 9;
				pos.Y = 5;
				SetConsoleCursorPosition(hOut, pos);
				SetColor(0x0a, 0);
				printf("3、查找指定图书情况");
				if ((user_choice = KeyboardChoice(user_choice, 7)) == 200) {
					system("cls");
					SetColor(0x0f, 0);
					printf("┌─────────────────────────────────────┐\n");
					printf("│              查询                   │\n");
					printf("├─────────────────────────────────────┤\n");
					printf("│     书本唯一ID：______________      │\n");
					printf("└─────────────────────────────────────┘\n");
					pos.X = 18;
					pos.Y = 3;
					SetConsoleCursorPosition(hOut, pos);
					int id;
					scanf("%d", &id);
					system("cls");
					displayBookInfoById(head, id);
					printf("按回车键继续");
					getchar(); getchar();
				}
				break;
			}
			case 3: {
				UserPageMain(user, hOut);
				pos.X = 9;
				pos.Y = 6;
				SetConsoleCursorPosition(hOut, pos);
				SetColor(0x0a, 0);
				printf("4、从库中借阅书籍");
				if ((user_choice = KeyboardChoice(user_choice, 7)) == 200) {
					system("cls");
					printf("请输入ID:");
					int key = 0;
					scanf("%d", &key); getchar();

					if (borrowBookByBookId(head, user.id, key)) {
						Sleep(1000);
						SetColor(0x04, 0);
						printf("书籍借阅出错！");
					}
					else {
						SetColor(0x0a, 0);
						printf("书籍已成功借出");
					}
					printf("\n\n按回车键继续\n");
					getchar();
				}
				break;
			}
			case 4: {
				UserPageMain(user, hOut);
				pos.X = 9;
				pos.Y = 7;
				SetConsoleCursorPosition(hOut, pos);
				SetColor(0x0a, 0);
				printf("5、借阅指定书籍");
				if ((user_choice = KeyboardChoice(user_choice, 7)) == 200) {
					system("cls");
					printf("请输入ID:");
					int key = 0;
					scanf("%d", &key); getchar();

					if (borrowBookById(head, user.id, key)) {
						SetColor(0x04, 0);
						printf("书籍借阅出错！");
						Sleep(1000);
						
					}
					else {
						SetColor(0x0a, 0);
						printf("书籍已成功借出");
					}
				}
				break;
			}
			case 5: {
				UserPageMain(user, hOut);
				pos.X = 9;
				pos.Y = 8;
				SetConsoleCursorPosition(hOut, pos);
				SetColor(0x0a, 0);
				printf("6、归还书本");
				if ((user_choice = KeyboardChoice(user_choice, 7)) == 200) {
					system("cls");
					printf("请输入ID:");
					int key = 0;
					scanf("%d", &key); getchar();

					if (RecordWithId(head, user.id, key))
					{
						SetColor(0x04, 0);
						printf("书籍归还出错！");
						Sleep(1000);
						break;
					} 
					else
					{
						SetColor(0x0a, 0);
						printf("书籍已成功归还");
					}
					printf("\n按回车键继续");
					getchar();
				}
				break;
			}
			case 6: {
				UserPageMain(user, hOut);
				pos.X = 9;
				pos.Y = 9;
				SetConsoleCursorPosition(hOut, pos);
				SetColor(0x0a, 0);
				printf("7、查看当前借阅");
				if ((user_choice = KeyboardChoice(user_choice, 7)) == 200) {
					system("cls");
					viewUserBorrowedBooks(head, user.id);
					printf("\n\n按回车键继续");
					getchar();
				}
				break;
			}
			case 7: {
				UserPageMain(user, hOut);
				pos.X = 9;
				pos.Y = 10;
				SetConsoleCursorPosition(hOut, pos);
				SetColor(0x0a, 0);
				printf("9、退出");
				if ((user_choice = KeyboardChoice(user_choice, 7)) == 200) {
					system("cls");
					SetColor(0x0a, 0);
					printf("欢迎下次光临~");
					SaveToFile(FILENAME, head);
					exit(0);
				}
				break;
			}
			case 200: {
				user_choice = 0;
				break;
			}
		}
	}
	return 0;
}