#include "header.h"

int Manage(UserInfo user, Chain* head) {

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
			AdminPageMain(user, hOut);
			pos.X = 9;
			pos.Y = 3;
			SetConsoleCursorPosition(hOut, pos);
			SetColor(0x0a, 0);
			printf("1、查看总图书情况");
			if ((user_choice = KeyboardChoice(user_choice, 8)) == 200)
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
			AdminPageMain(user, hOut);
			pos.X = 9;
			pos.Y = 4;
			SetConsoleCursorPosition(hOut, pos);
			SetColor(0x0a, 0);
			printf("2、查看册图书情况");
			if ((user_choice = KeyboardChoice(user_choice, 8)) == 200) {
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
			AdminPageMain(user, hOut);
			pos.X = 9;
			pos.Y = 5;
			SetConsoleCursorPosition(hOut, pos);
			SetColor(0x0a, 0);
			printf("3、查找指定图书情况");
			if ((user_choice = KeyboardChoice(user_choice, 8)) == 200) {
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
			pos.X = 0;
			pos.Y = 0;
			AdminPageMain(user, hOut);
			pos.X = 9;
			pos.Y = 6;
			SetConsoleCursorPosition(hOut, pos);
			SetColor(0x0a, 0);
			printf("4、添加一种书籍");
			if ((user_choice = KeyboardChoice(user_choice, 8)) == 200) {
				system("cls");
				SetColor(0x0f, 0);
				int user_choice = 0;

				printf("┌─────────────────────────────────────┐\n");
				printf("│               添加书籍              │\n");
				printf("├─────────────────────────────────────┤\n");
				printf("│      书籍ID：  ____________         │\n");
				printf("│      书籍名称：____________         |\n");
				printf("│      作者ID:   ____________         │\n");
				printf("│      作者名：  ____________         |\n");
				printf("|      出版社ID: ____________         │\n");
				printf("|      出版社名: ____________         │\n");
				printf("|      册数：    ____________         │\n");
				printf("│        取消           确认          │\n");
				printf("└─────────────────────────────────────┘\n");

				pos.X = 17;
				pos.Y = 3;
				SetConsoleCursorPosition(hOut, pos);
				int id;
				scanf("%d", &id); getchar();

				pos.X = 17;
				pos.Y = 4;
				SetConsoleCursorPosition(hOut, pos);
				int book_name[10];
				gets(book_name);

				pos.X = 17;
				pos.Y = 5;
				SetConsoleCursorPosition(hOut, pos);
				int anthor_id;
				scanf("%d", &anthor_id); getchar();

				pos.X = 17;
				pos.Y = 6;
				SetConsoleCursorPosition(hOut, pos);
				char anthor[10];
				gets(anthor);

				pos.X = 17;
				pos.Y = 7;
				SetConsoleCursorPosition(hOut, pos);
				int press_id;
				scanf("%d", &press_id); getchar();

				pos.X = 17;
				pos.Y = 8;
				SetConsoleCursorPosition(hOut, pos);
				char press[20];
				gets(press);

				pos.X = 17;
				pos.Y = 9;
				SetConsoleCursorPosition(hOut, pos);
				int num = 0;
				scanf("%d", &num); getchar();

				while (1)
				{
					switch (user_choice)
					{
					case 0: {
						pos.X = 0;
						pos.Y = 10;
						SetConsoleCursorPosition(hOut, pos);
						SetColor(0x0f, 0);
						printf("│        取消           确认          │");
						pos.X = 9;
						SetConsoleCursorPosition(hOut, pos);
						SetColor(0x04, 0);
						printf("取消");
						if ((user_choice = KeyboardChoice2(user_choice)) == 200) {
							break;
						}
						break;
					}
					case 1: {
						pos.X = 0;
						pos.Y = 10;
						SetConsoleCursorPosition(hOut, pos);
						SetColor(0x0f, 0);
						printf("│        取消           确认          │");
						pos.X = 24;
						SetConsoleCursorPosition(hOut, pos);
						SetColor(0x0a, 0);
						printf("确认");
						if ((user_choice = KeyboardChoice2(user_choice)) == 200) {
							addBookType(head, id, book_name, anthor_id, anthor, press, press_id, num);
						}
						break;
					}
					}
					if (user_choice == 200) {
						break;
					}
				}

			}
			break;
		}
		case 4: {
			AdminPageMain(user, hOut);
			pos.X = 9;
			pos.Y = 7;
			SetConsoleCursorPosition(hOut, pos);
			SetColor(0x0a, 0);
			printf("5、入库书籍");
			if ((user_choice = KeyboardChoice(user_choice, 8)) == 200) {

				int user_choice = 0;
				system("cls");
				SetColor(0x0f, 0);
				printf("┌─────────────────────────────────────┐\n");
				printf("│               书籍入库              │\n");
				printf("├─────────────────────────────────────┤\n");
				printf("│      书籍ID：  ____________         │\n");
				printf("|      册数：    ____________         │\n");
				printf("│        取消           确认          │\n");
				printf("└─────────────────────────────────────┘\n");
				pos.X = 17;
				pos.Y = 3;
				SetConsoleCursorPosition(hOut, pos);
				int id = 0;
				scanf("%d", &id); getchar();

				pos.X = 17;
				pos.Y = 4;
				SetConsoleCursorPosition(hOut, pos);
				int num = 0;
				scanf("%d", &num); getchar();

				while (1)
				{
					switch (user_choice)
					{
					case 0: {
						pos.X = 0;
						pos.Y = 5;
						SetConsoleCursorPosition(hOut, pos);
						SetColor(0x0f, 0);
						printf("│        取消           确认          │");
						pos.X = 9;
						SetConsoleCursorPosition(hOut, pos);
						SetColor(0x04, 0);
						printf("取消");
						if ((user_choice = KeyboardChoice2(user_choice)) == 200) {
							break;
						}
						break;
					}
					case 1: {
						pos.X = 0;
						pos.Y = 5;
						SetConsoleCursorPosition(hOut, pos);
						SetColor(0x0f, 0);
						printf("│        取消           确认          │");
						pos.X = 24;
						SetConsoleCursorPosition(hOut, pos);
						SetColor(0x0a, 0);
						printf("确认");
						if ((user_choice = KeyboardChoice2(user_choice)) == 200) {
							addBook(head, id, num);
						}
						break;
					}
					}
					if (user_choice == 200) {
						break;
					}
				}
			}
			break;
		}
		case 5: {
			AdminPageMain(user, hOut);
			pos.X = 9;
			pos.Y = 8;
			SetConsoleCursorPosition(hOut, pos);
			SetColor(0x0a, 0);
			printf("6、注册新的账户");
			if ((user_choice = KeyboardChoice(user_choice, 8)) == 200) {
				system("cls");
				int user_choice = 0;

				AdminPageRegister(hOut);
				pos.X = 15;
				pos.Y = 3;
				SetConsoleCursorPosition(hOut, pos);
				char nickname[10];
				gets(nickname);
				
				pos.X = 15;
				pos.Y = 4;
				SetConsoleCursorPosition(hOut, pos);
				char username[10];
				gets(username);
				
				pos.X = 15;
				pos.Y = 5;
				SetConsoleCursorPosition(hOut, pos);
				char* password = input_password();
				pos.X = 30;
				pos.Y = 6;
				SetConsoleCursorPosition(hOut, pos);
				int isAdmin;
				scanf("%d", &isAdmin);

				while (1)
				{
					switch (user_choice)
					{
						case 0: {
							pos.X = 0;
							pos.Y = 8;
							SetConsoleCursorPosition(hOut, pos);
							SetColor(0x0f, 0);
							printf("│        取消           确认          │");
							pos.X = 9;
							SetConsoleCursorPosition(hOut, pos);
							SetColor(0x04, 0);
							printf("取消");
							if ((user_choice = KeyboardChoice2(user_choice)) == 200) {
								break;
							}
							break;
						}
						case 1: {
							pos.X = 0;
							pos.Y = 8;
							SetConsoleCursorPosition(hOut, pos);
							SetColor(0x0f, 0);
							printf("│        取消           确认          │");
							pos.X = 24;
							SetConsoleCursorPosition(hOut, pos);
							SetColor(0x0a, 0);
							printf("确认");
							if ((user_choice = KeyboardChoice2(user_choice)) == 200) {
								Register(nickname, username, password, isAdmin);
							}
							break;
						}
					}
					if (user_choice == 200) {
						break;
					}
				}
			}
			break;
		}
		case 6: {
			AdminPageMain(user, hOut);
			pos.X = 9;
			pos.Y = 9;
			SetConsoleCursorPosition(hOut, pos);
			SetColor(0x0a, 0);
			printf("7、查看所有账户");
			if ((user_choice = KeyboardChoice(user_choice, 8)) == 200) {
				queryAllUsers();
				getchar();
				system("cls");
			}
			break;
		}
		case 7: {
			AdminPageMain(user, hOut);
			pos.X = 9;
			pos.Y = 10;
			SetConsoleCursorPosition(hOut, pos);
			SetColor(0x0a, 0);
			printf("8、删除指定账户");
			if ((user_choice = KeyboardChoice(user_choice, 8)) == 200) {
				system("cls");
				SetColor(0x0f, 0);
				printf("┌─────────────────────────────────────┐\n");
				printf("│              删除账户               │\n");
				printf("├─────────────────────────────────────┤\n");
				printf("│        账户ID：______________       │\n");
				printf("└─────────────────────────────────────┘\n");
				pos.X = 18;
				pos.Y = 3;
				SetConsoleCursorPosition(hOut, pos);
				int id;
				scanf("%d", &id);
				system("cls");
				SetColor(0x0f, 0);
				if (deleteUserById(id)) {
					printf("发生错误");
				}
				
				printf("按回车键继续");
				getchar(); getchar();
			}
			break;
		}
		case 8: {
			AdminPageMain(user, hOut);
			pos.X = 9;
			pos.Y = 11;
			SetConsoleCursorPosition(hOut, pos);
			SetColor(0x0a, 0);
			printf("9、退出");
			if ((user_choice = KeyboardChoice(user_choice, 8)) == 200) {
				system("cls");
				SetColor(0x0a, 0);
				printf("欢迎下次光临~");
				SaveToFile(FILENAME, head);
				exit(0);
			}
			break;
		}
		case 200:
			user_choice = 0;
		default:
			break;
		}
	}

	

	return 0;
}