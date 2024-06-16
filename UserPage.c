#include "header.h"

int UserMenu(UserInfo user, Chain* head) {

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
				UserPageMain(user, hOut);
				pos.X = 9;
				pos.Y = 3;
				SetConsoleCursorPosition(hOut, pos);
				SetColor(0x0a, 0);
				printf("1���鿴��ͼ�����");
				if ((user_choice = KeyboardChoice(user_choice, 7)) == 200)
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
				UserPageMain(user, hOut);
				pos.X = 9;
				pos.Y = 4;
				SetConsoleCursorPosition(hOut, pos);
				SetColor(0x0a, 0);
				printf("2���鿴��ͼ�����");
				if ((user_choice = KeyboardChoice(user_choice, 7)) == 200) {
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
				pos.X = 0;
				pos.Y = 0;
				UserPageMain(user, hOut);
				pos.X = 9;
				pos.Y = 5;
				SetConsoleCursorPosition(hOut, pos);
				SetColor(0x0a, 0);
				printf("3������ָ��ͼ�����");
				if ((user_choice = KeyboardChoice(user_choice, 7)) == 200) {
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
			case 3: {
				UserPageMain(user, hOut);
				pos.X = 9;
				pos.Y = 6;
				SetConsoleCursorPosition(hOut, pos);
				SetColor(0x0a, 0);
				printf("4���ӿ��н����鼮");
				if ((user_choice = KeyboardChoice(user_choice, 7)) == 200) {
					system("cls");
					printf("������ID:");
					int key = 0;
					scanf("%d", &key); getchar();

					if (borrowBookByBookId(head, user.id, key)) {
						Sleep(1000);
						SetColor(0x04, 0);
						printf("�鼮���ĳ���");
					}
					else {
						SetColor(0x0a, 0);
						printf("�鼮�ѳɹ����");
					}
					printf("\n\n���س�������\n");
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
				printf("5������ָ���鼮");
				if ((user_choice = KeyboardChoice(user_choice, 7)) == 200) {
					system("cls");
					printf("������ID:");
					int key = 0;
					scanf("%d", &key); getchar();

					if (borrowBookById(head, user.id, key)) {
						SetColor(0x04, 0);
						printf("�鼮���ĳ���");
						Sleep(1000);
						
					}
					else {
						SetColor(0x0a, 0);
						printf("�鼮�ѳɹ����");
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
				printf("6���黹�鱾");
				if ((user_choice = KeyboardChoice(user_choice, 7)) == 200) {
					system("cls");
					printf("������ID:");
					int key = 0;
					scanf("%d", &key); getchar();

					if (RecordWithId(head, user.id, key))
					{
						SetColor(0x04, 0);
						printf("�鼮�黹����");
						Sleep(1000);
						break;
					} 
					else
					{
						SetColor(0x0a, 0);
						printf("�鼮�ѳɹ��黹");
					}
					printf("\n���س�������");
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
				printf("7���鿴��ǰ����");
				if ((user_choice = KeyboardChoice(user_choice, 7)) == 200) {
					system("cls");
					viewUserBorrowedBooks(head, user.id);
					printf("\n\n���س�������");
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
				printf("9���˳�");
				if ((user_choice = KeyboardChoice(user_choice, 7)) == 200) {
					system("cls");
					SetColor(0x0a, 0);
					printf("��ӭ�´ι���~");
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