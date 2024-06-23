#include "header.h"

//���������͵��鼮
int addBookType(Chain* head, int book_id, char* name, int anthor_id, char* anthor, char* press, int press_id, int all_num) {
	Books* new_book = (Book*)malloc(sizeof(Book));
	new_book->book_id = book_id;
	strcpy(new_book->name, name);
	new_book->anthor_id = anthor_id;
	strcpy(new_book->anthor, anthor);
	new_book->press_id = press_id;
	strcpy(new_book->press, press);
	new_book->all_num = all_num;
	new_book->num = all_num;
	strcpy(new_book->press, press);
	new_book->book = NULL;

	Book* Bnode = new_book->book;

	int id = 0;

	if (Bnode == NULL) {
		Book* book = (Book*)malloc(sizeof(Book));
		book->id = book_id * 10000 + id++;
		book->next = NULL;
		book->isBorrowed = 0;
		new_book->book = book;
		Bnode = new_book->book;
		all_num--;
	}

	for (int i = 0; i < all_num; i++) {
		Book* book = (Book*)malloc(sizeof(Book));
		book->id = book_id * 10000 + id++;
		book->isBorrowed = 0;
		book->next = NULL;
		Bnode->next = book;
		Bnode = Bnode->next;
	}
	// �ӹ���ɣ�bushi��

	int books_id = 0;
	Chain* node = head;
	for (books_id = 0; node->next != NULL; books_id++)
		node = node->next;
	node->next = new_book;
	node->next->next = NULL;
	return 0;
}

// ���Ӷ�Ӧ�鼮�ŵ��鼮���� normal:0
int addBook(Chain* head, int book_id, int book_num) {

	int findIt = 0;
	Chain* node = head;
	int id;

	for (int i = 0; node != NULL; i++) {
		if (node->data.book_id == book_id) {
			findIt = 1;
			break;
		}
		node = node->next;
	}
		
	// ��Ӽ���
	if (findIt) {
		node->data.all_num += book_num;
		node->data.num += book_num;
	} else {
		return 1;
	}

	Book* Bnode = node->data.book;
	for (id = 0; Bnode != NULL && Bnode->next != NULL; id++)
		Bnode = Bnode->next;

	id++;

	if (Bnode == NULL) {
		Book* book = (Book*)malloc(sizeof(Book));
		book->id = book_id * 10000 + id++;
		book->next = NULL;
		book->isBorrowed = 0;
		node->data.book = book;
		Bnode = node->data.book;
		book_num--;
	}
	
	for (int i = 0; i < book_num; i++) {
		Book* book = (Book*)malloc(sizeof(Book));
		book->id = book_id*10000 + id++;
		book->isBorrowed = 0;
		book->next = NULL; 
		Bnode->next = book;
		Bnode = Bnode->next;
	}
	return 0;
}

//ɾ����Ӧ������鼮 normal:0
int DelBook(Chain* head, int book_id) {
	Chain* node = head;
	int isDone = 0;
	for (int i = 0; node != NULL && node->next != NULL; i++)
	{
		if (node->next->data.book_id == book_id)
		{
			isDone = 1;
			Book* book = node->next->data.book;
			while (book != NULL)
			{
				Book* tpb = book;
				book = book->next;
				free(tpb);
			}
			Chain* node_tp = node->next;
			node->next = node_tp->next;
			free(node_tp);
		}
		node = node->next;
	}
	if (isDone)
		return 0;
	return 1;
}

//��ʾBooks��Ϣ
void displayBooksInfo(Chain* head, int book_id) {
	Chain* current = head->next; // ����ͷ�ڵ�

	printf("�������������������Щ����������������������������������������Щ������������������������Щ��������������������������Щ������������������������Щ����������������Щ������������������Щ�������������������\n");
	printf("��  ID    �� ͼ������           �� ����       �� ������      �� �ܲ���     �� ʣ���� �� �鱾��ũ� ����״̬��\n");
	printf("�������������������੤���������������������������������������੤�����������������������੤�������������������������੤�����������������������੤���������������੤�����������������੤������������������\n");


	while (current != NULL) {
		if (current->data.book_id == book_id) {
			// ��ӡ Books ��Ϣ
			Book* book = current->data.book;
			while (book != NULL) {
				printf("�� %6d �� %-18s �� %-10s �� %-11s �� %10d �� %6d �� %7d �� %7s ��\n",
					current->data.book_id,
					current->data.name,
					current->data.anthor,
					current->data.press,
					current->data.all_num,
					current->data.num,
					book->id,
					book->isBorrowed ? "�ѽ��" : "δ���");
				book = book->next;
			}
			printf("�������������������ة����������������������������������������ة������������������������ة��������������������������ة������������������������ة����������������ة������������������ة�������������������\n");
			return;
		}
		current = current->next;
	}
	system("cls");
	printf("δ�ҵ�book_idΪ%d��Books.\n", book_id);
}

// ����������ѯBooks��Ϣ
void queryBooksByName(Chain* head, const char* book_name) {
	Chain* current = head->next;
	int found = 0;

	printf("�������������������Щ����������������������������������������Щ������������������������Щ��������������������������Щ������������������������Щ����������������Щ������������������Щ�������������������\n");
	printf("��  ID    �� ͼ������           �� ����       �� ������      �� �ܲ���     �� ʣ���� �� �鱾��ũ� ����״̬��\n");
	printf("�������������������੤���������������������������������������੤�����������������������੤�������������������������੤�����������������������੤���������������੤�����������������੤������������������\n");

	while (current != NULL) {
		if (strcmp(current->data.name, book_name) == 0) {
			found = 1;
			Book* book = current->data.book;
			while (book != NULL) {
				printf("�� %6d �� %-18s �� %-10s �� %-11s �� %10d �� %6d �� %7d �� %7s ��\n",
					current->data.book_id,
					current->data.name,
					current->data.anthor,
					current->data.press,
					current->data.all_num,
					current->data.num,
					book->id,
					book->isBorrowed ? "�ѽ��" : "δ���");
				book = book->next;
			}
		}
		current = current->next;
	}

	printf("�������������������ة����������������������������������������ة������������������������ة��������������������������ة������������������������ة����������������ة������������������ة�������������������\n");
	if (!found) {
		system("cls");
		SetColor(0x04, 0);
		printf("δ�ҵ�����Ϊ��%s ��ͼ��\n", book_name);
	}
}

//��ѯBook��Ϣ
void displayBookInfoById(Chain* head, int book_id) {
	Chain* current = head->next; // ����ͷ�ڵ�

	while (current != NULL) {
		Book* book = current->data.book;
		while (book != NULL) {
			if (book->id == book_id) {
				// ��ӡ Books ��Ϣ
				printf("�鼮ID:\t%d\n", current->data.book_id);
				printf("����:\t%s\n", current->data.name);
				printf("����:\t%s (ID:\t%d)\n", current->data.anthor, current->data.anthor_id);
				printf("������:\t%s (ID:\t%d)\n", current->data.press, current->data.press_id);
				printf("�ܲ���:\t%d\n", current->data.all_num);
				printf("ʣ�����:\t%d\n", current->data.num);

				//����
				printf("����ID:\t%d\t\n", book->id);
				printf("�Ƿ񱻽����\t%s\t\n", (book->isBorrowed ? "��" : "��"));
				return;
			}
			book = book->next;
		}
		current = current->next;
	}
	printf("δ�ҵ�IDΪ%d����.\n", book_id);
}

//��ѯȫ��Books��Ϣ
void displayAllBooksInfo(Chain* head) {
	printf("�������������������������Щ����������������������������Щ������������������������������Щ��������������Щ���������������\n");
	printf("��    ID     �� %-12s �� %-13s �� %-5s �� %-5s ��\n", "�鼮����", "������", "����", "ʣ��");
	printf("�������������������������੤���������������������������੤�����������������������������੤�������������੤��������������\n");

	Chain* node = head->next;

	while (node != NULL) {
		printf("�� %-9d �� %-12s �� %-13s �� %-5s �� %-5d ��\n", node->data.book_id, node->data.name, node->data.press, node->data.anthor, node->data.num);
		node = node->next;
	}
	printf("�������������������������ة����������������������������ة������������������������������ة��������������ة���������������\n");

}

//����book_id����
int borrowBookByBookId(Chain* head, int user_id, int book_id) {

	sqlite3* db = NULL;

	if (sqlite3_open(USERFILE, &db)) {
		fprintf(stderr, "�޷������ݿ�: %s\n", sqlite3_errmsg(db));
	}
	Chain* current = head->next;

	while (current != NULL) {
		if (current->data.book_id == book_id) {
			Book* book = current->data.book;
			while (book != NULL) {
				if (!book->isBorrowed) {
					book->isBorrowed = 1;
					current->data.num -= 1;
					updateUserBooks(db, user_id, book->id);
					printf("�û�%d��ͼ��ID%d����ͼ��ID%d\n", user_id, book->id, book_id);
					sqlite3_close(db);
					return 0;
				}
				book = book->next;
			}
			printf("ͼ��ID%d��û�пɽ��ͼ��\n", book_id);
			sqlite3_close(db);
			return -1;
		}
		current = current->next;
	}
	printf("δ�ҵ�IDΪ%d��ͼ��\n", book_id);
	sqlite3_close(db);
	return -1;
}

//����id����
int borrowBookById(Chain* head, int user_id, int book_id) {

	sqlite3 *db = NULL;

	if (sqlite3_open(USERFILE, &db)) {
		fprintf(stderr, "�޷������ݿ�: %s\n", sqlite3_errmsg(db));
	}


	int target_book_id = book_id / 10000;  // ���� Books �� book_id �� Book �� id �ĸ�λ����
	Chain* current = head->next;

	while (current != NULL) {
		if (current->data.book_id == target_book_id) {
			Book* book = current->data.book;
			while (book != NULL) {
				if (book->id == book_id) {
					if (!book->isBorrowed) {
						book->isBorrowed = 1;
						current->data.num -= 1;
						updateUserBooks(db, user_id, book->id);
						printf("�û�%d�����ID%d\n", user_id, book->id);
						sqlite3_close(db);
						return 0;
					}
					else {
						printf("ͼ��ID%d�ѱ����\n", book_id);
						sqlite3_close(db);
						return -1;
					}
				}
				book = book->next;
			}
		}
		current = current->next;
	}
	printf("�Ҳ���IDΪ%d��ͼ��\n", book_id);
	sqlite3_close(db);
	return -1;
}

//����id����
int RecordWithId(Chain* head, int user_id, int id) {

	sqlite3* db = NULL;

	if (sqlite3_open(USERFILE, &db)) {
		fprintf(stderr, "�޷������ݿ�: %s\n", sqlite3_errmsg(db));
	}
	Chain* current = head->next;  // ��ͷ������һ���ڵ㿪ʼ����

	while (current != NULL) {
		Book* book = current->data.book;
		while (book != NULL) {
			if (book->id == id) {
				if (!book->isBorrowed) {
					printf("IDΪ%d���鼮δ�����á�\n", id);
					sqlite3_close(db);
					return -1; // �鼮δ������
				}
				else {
					book->isBorrowed = 0;
					current->data.num++; // ���Ӹ������ʣ�౾��

					// �����û������б�
					if (removeBookFromUserBooks(db, user_id, id) != 0) {
						printf("�޷������û���ͼ���б�\n");
						sqlite3_close(db);
						return -1;
					}

					printf("IDΪ%d���û��ѹ黹IDΪ%d��ͼ�顣\n", id, user_id);
					sqlite3_close(db);
					return 0; // �黹�ɹ�
				}
			}
			book = book->next;
		}
		current = current->next;
	}

	printf("�Ҳ���IDΪ%d��ͼ�顣\n", id);
	sqlite3_close(db);

	return -1; // δ�ҵ�ָ��ID���鼮
}

//�û������ַ���������ʾ
void viewUserBorrowedBooks(Chain* head, int user_id) {

	sqlite3* db = NULL;

	if (sqlite3_open(USERFILE, &db)) {
		fprintf(stderr, "�޷������ݿ�: %s\n", sqlite3_errmsg(db));
	}

	char* books_str = getUserBooks(db, user_id);
	if (!books_str) {
		printf("No books found for user ID %d\n", user_id);
		sqlite3_close(db);
		return;
	}

	// �ָ�books_str�е��鼮ID
	char* token = strtok(books_str, ",");
	int book_ids[100];
	int count = 0;

	while (token != NULL) {
		book_ids[count++] = atoi(token);
		token = strtok(NULL, ",");
	}

	printf("�û�ID %d �����:\n", user_id);
	printf("�������������Щ��������������������������Щ������������������������������Щ��������������������������Щ���������������������������\n");
	printf("�� %3s �� %11s �� %-13s �� %-11s �� %11s ��\n", "ID", "�鼮ID", "�鼮����", "�鼮����", "�Ƿ񱻽��");
	printf("�������������੤�������������������������੤�����������������������������੤�������������������������੤��������������������������\n");

	// ���������ҵ���Ӧ���鼮��Ϣ
	for (int i = 0; i < count; i++) {
		int found = 0;
		Chain* current = head->next;

		while (current != NULL) {
			Book* book = current->data.book;
			while (book != NULL) {
				if (book->id == book_ids[i]) {
					printf("�� %3d �� %11d �� %-13s �� %-11s �� %11s ��\n",
						i + 1, book->id, current->data.name, current->data.anthor,
						book->isBorrowed ? "Yes" : "No");
					found = 1;
					break;
				}
				book = book->next;
			}
			if (found) break;
			current = current->next;
		}
		if (!found) {
			printf("�� %3d �� %11d �� %-13s �� %-11s �� %11s ��\n",
				i + 1, book_ids[i], "Unknown", "Unknown", "Unknown");
		}
	}

	printf("�������������ة��������������������������ة������������������������������ة��������������������������ة���������������������������\n");
	free(books_str);
	sqlite3_close(db);
}
