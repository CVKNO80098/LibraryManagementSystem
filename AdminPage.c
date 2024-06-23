#include "header.h"

int Manage(UserInfo user, Chain* head) {

	COORD pos;// ����������
	//����������
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
			printf("1���鿴��ͼ�����");
			if ((user_choice = KeyboardChoice(user_choice, 9)) == 200)
			{
				system("cls");
				SetColor(0x0f, 0);
				displayAllBooksInfo(head);
				printf("\n���س�������");
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
			printf("2��id�鿴��ͼ�����");
			if ((user_choice = KeyboardChoice(user_choice, 9)) == 200) {
				system("cls");
				SetColor(0x0f, 0);
				printf("������������������������������������������������������������������������������\n");
				printf("��              ��ѯ                   ��\n");
				printf("������������������������������������������������������������������������������\n");
				printf("��       �鼮id��______________        ��\n");
				printf("������������������������������������������������������������������������������\n");
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
			AdminPageMain(user, hOut);
			pos.X = 9;
			pos.Y = 5;
			SetConsoleCursorPosition(hOut, pos);
			SetColor(0x0a, 0);
			printf("3���������Ҳ�ͼ�����");
			if ((user_choice = KeyboardChoice(user_choice, 9)) == 200) {
				system("cls");
				SetColor(0x0f, 0);
				printf("������������������������������������������������������������������������������\n");
				printf("��              ��ѯ                   ��\n");
				printf("������������������������������������������������������������������������������\n");
				printf("��     �鱾���ƣ�______________        ��\n");
				printf("������������������������������������������������������������������������������\n");
				pos.X = 18;
				pos.Y = 3;
				SetConsoleCursorPosition(hOut, pos);
				char name[20];
				gets(name);
				system("cls");
				queryBooksByName(head, name);
				printf("���س�������");
				getchar(); 
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
			printf("4��id����ָ��ͼ�����");
			if ((user_choice = KeyboardChoice(user_choice, 9)) == 200) {
				system("cls");
				SetColor(0x0f, 0);
				printf("������������������������������������������������������������������������������\n");
				printf("��              ��ѯ                   ��\n");
				printf("������������������������������������������������������������������������������\n");
				printf("��     �鱾ΨһID��______________      ��\n");
				printf("������������������������������������������������������������������������������\n");
				pos.X = 18;
				pos.Y = 3;
				SetConsoleCursorPosition(hOut, pos);
				int id;
				scanf("%d", &id);
				system("cls");
				displayBookInfoById(head, id);
				printf("���س�������");
				getchar(); getchar();
			}
			break;
		}
		case 4: {
			pos.X = 0;
			pos.Y = 0;
			AdminPageMain(user, hOut);
			pos.X = 9;
			pos.Y = 7;
			SetConsoleCursorPosition(hOut, pos);
			SetColor(0x0a, 0);
			printf("5�����һ���鼮");
			if ((user_choice = KeyboardChoice(user_choice, 9)) == 200) {
				system("cls");
				SetColor(0x0f, 0);
				int user_choice = 0;

				printf("������������������������������������������������������������������������������\n");
				printf("��               ����鼮              ��\n");
				printf("������������������������������������������������������������������������������\n");
				printf("��      �鼮ID��  ____________         ��\n");
				printf("��      �鼮���ƣ�____________         |\n");
				printf("��      ����ID:   ____________         ��\n");
				printf("��      ��������  ____________         |\n");
				printf("|      ������ID: ____________         ��\n");
				printf("|      ��������: ____________         ��\n");
				printf("|      ������    ____________         ��\n");
				printf("��        ȡ��           ȷ��          ��\n");
				printf("������������������������������������������������������������������������������\n");

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
						printf("��        ȡ��           ȷ��          ��");
						pos.X = 9;
						SetConsoleCursorPosition(hOut, pos);
						SetColor(0x04, 0);
						printf("ȡ��");
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
						printf("��        ȡ��           ȷ��          ��");
						pos.X = 24;
						SetConsoleCursorPosition(hOut, pos);
						SetColor(0x0a, 0);
						printf("ȷ��");
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
		case 5: {
			AdminPageMain(user, hOut);
			pos.X = 9;
			pos.Y = 8;
			SetConsoleCursorPosition(hOut, pos);
			SetColor(0x0a, 0);
			printf("6��ɾ��һ���鼮");
			if ((user_choice = KeyboardChoice(user_choice, 9)) == 200) {
				system("cls");
				SetColor(0x0f, 0);
				printf("������������������������������������������������������������������������������\n");
				printf("��              ɾ��ָ���鼮           ��\n");
				printf("������������������������������������������������������������������������������\n");
				printf("��       �鼮id��______________        ��\n");
				printf("������������������������������������������������������������������������������\n");
				pos.X = 16;
				pos.Y = 3;
				SetConsoleCursorPosition(hOut, pos);
				int book_id;
				scanf("%d", &book_id);
				system("cls");
				if (!DelBook(head, book_id))
				{
					system("cls");
					SetColor(0x0a, 0);
					printf("�鼮�ѳɹ�ɾ��");
					Sleep(500);
				} else {
					system("cls");
					SetColor(0x04, 0);
					printf("�鼮ɾ��ʧ�ܣ�");
					Sleep(500);
				}
				getchar(); getchar();
			}
			break;
		}
		case 6: {
			AdminPageMain(user, hOut);
			pos.X = 9;
			pos.Y = 9;
			SetConsoleCursorPosition(hOut, pos);
			SetColor(0x0a, 0);
			printf("7������鼮");
			if ((user_choice = KeyboardChoice(user_choice, 9)) == 200) {

				int user_choice = 0;
				system("cls");
				SetColor(0x0f, 0);
				printf("������������������������������������������������������������������������������\n");
				printf("��               �鼮���              ��\n");
				printf("������������������������������������������������������������������������������\n");
				printf("��      �鼮ID��  ____________         ��\n");
				printf("|      ������    ____________         ��\n");
				printf("��        ȡ��           ȷ��          ��\n");
				printf("������������������������������������������������������������������������������\n");
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
						printf("��        ȡ��           ȷ��          ��");
						pos.X = 9;
						SetConsoleCursorPosition(hOut, pos);
						SetColor(0x04, 0);
						printf("ȡ��");
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
						printf("��        ȡ��           ȷ��          ��");
						pos.X = 24;
						SetConsoleCursorPosition(hOut, pos);
						SetColor(0x0a, 0);
						printf("ȷ��");
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
		case 7: {
			AdminPageMain(user, hOut);
			pos.X = 9;
			pos.Y = 10;
			SetConsoleCursorPosition(hOut, pos);
			SetColor(0x0a, 0);
			printf("8��ע���µ��˻�");
			if ((user_choice = KeyboardChoice(user_choice, 9)) == 200) {
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
							printf("��        ȡ��           ȷ��          ��");
							pos.X = 9;
							SetConsoleCursorPosition(hOut, pos);
							SetColor(0x04, 0);
							printf("ȡ��");
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
							printf("��        ȡ��           ȷ��          ��");
							pos.X = 24;
							SetConsoleCursorPosition(hOut, pos);
							SetColor(0x0a, 0);
							printf("ȷ��");
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
		case 8: {
			AdminPageMain(user, hOut);
			pos.X = 9;
			pos.Y = 11;
			SetConsoleCursorPosition(hOut, pos);
			SetColor(0x0a, 0);
			printf("9���鿴�����˻�");
			if ((user_choice = KeyboardChoice(user_choice, 9)) == 200) {
				queryAllUsers();
				getchar();
				system("cls");
			}
			break;
		}
		case 9: {
			AdminPageMain(user, hOut);
			pos.X = 9;
			pos.Y = 12;
			SetConsoleCursorPosition(hOut, pos);
			SetColor(0x0a, 0);
			printf("10��ɾ��ָ���˻�");
			if ((user_choice = KeyboardChoice(user_choice, 9)) == 200) {
				system("cls");
				SetColor(0x0f, 0);
				printf("������������������������������������������������������������������������������\n");
				printf("��              ɾ���˻�               ��\n");
				printf("������������������������������������������������������������������������������\n");
				printf("��        �˻�ID��______________       ��\n");
				printf("������������������������������������������������������������������������������\n");
				pos.X = 18;
				pos.Y = 3;
				SetConsoleCursorPosition(hOut, pos);
				int id;
				scanf("%d", &id);
				system("cls");
				SetColor(0x0f, 0);
				if (deleteUserById(id)) {
					printf("��������");
				}
				
				printf("���س�������");
				getchar(); getchar();
			}
			break;
		}
		case 10: {
			AdminPageMain(user, hOut);
			pos.X = 9;
			pos.Y = 13;
			SetConsoleCursorPosition(hOut, pos);
			SetColor(0x0a, 0);
			printf("11���˳�");
			if ((user_choice = KeyboardChoice(user_choice, 9)) == 200) {
				system("cls");
				SetColor(0x0a, 0);
				printf("��ӭ�´ι���~");
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