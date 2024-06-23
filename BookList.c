#include "header.h"

//增加新类型的书籍
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
	// 加工完成（bushi）

	int books_id = 0;
	Chain* node = head;
	for (books_id = 0; node->next != NULL; books_id++)
		node = node->next;
	node->next = new_book;
	node->next->next = NULL;
	return 0;
}

// 增加对应书籍号的书籍本书 normal:0
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
		
	// 添加计数
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

//删除对应种类的书籍 normal:0
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

//显示Books信息
void displayBooksInfo(Chain* head, int book_id) {
	Chain* current = head->next; // 跳过头节点

	printf("├────────┬────────────────────┬────────────┬─────────────┬────────────┬────────┬─────────┬─────────┤\n");
	printf("│  ID    │ 图书名称           │ 作者       │ 出版社      │ 总册数     │ 剩余数 │ 书本序号│ 借阅状态│\n");
	printf("├────────┼────────────────────┼────────────┼─────────────┼────────────┼────────┼─────────┼─────────┤\n");


	while (current != NULL) {
		if (current->data.book_id == book_id) {
			// 打印 Books 信息
			Book* book = current->data.book;
			while (book != NULL) {
				printf("│ %6d │ %-18s │ %-10s │ %-11s │ %10d │ %6d │ %7d │ %7s │\n",
					current->data.book_id,
					current->data.name,
					current->data.anthor,
					current->data.press,
					current->data.all_num,
					current->data.num,
					book->id,
					book->isBorrowed ? "已借出" : "未借出");
				book = book->next;
			}
			printf("└────────┴────────────────────┴────────────┴─────────────┴────────────┴────────┴─────────┴─────────┘\n");
			return;
		}
		current = current->next;
	}
	system("cls");
	printf("未找到book_id为%d的Books.\n", book_id);
}

// 根据书名查询Books信息
void queryBooksByName(Chain* head, const char* book_name) {
	Chain* current = head->next;
	int found = 0;

	printf("├────────┬────────────────────┬────────────┬─────────────┬────────────┬────────┬─────────┬─────────┤\n");
	printf("│  ID    │ 图书名称           │ 作者       │ 出版社      │ 总册数     │ 剩余数 │ 书本序号│ 借阅状态│\n");
	printf("├────────┼────────────────────┼────────────┼─────────────┼────────────┼────────┼─────────┼─────────┤\n");

	while (current != NULL) {
		if (strcmp(current->data.name, book_name) == 0) {
			found = 1;
			Book* book = current->data.book;
			while (book != NULL) {
				printf("│ %6d │ %-18s │ %-10s │ %-11s │ %10d │ %6d │ %7d │ %7s │\n",
					current->data.book_id,
					current->data.name,
					current->data.anthor,
					current->data.press,
					current->data.all_num,
					current->data.num,
					book->id,
					book->isBorrowed ? "已借出" : "未借出");
				book = book->next;
			}
		}
		current = current->next;
	}

	printf("└────────┴────────────────────┴────────────┴─────────────┴────────────┴────────┴─────────┴─────────┘\n");
	if (!found) {
		system("cls");
		SetColor(0x04, 0);
		printf("未找到书名为：%s 的图书\n", book_name);
	}
}

//查询Book信息
void displayBookInfoById(Chain* head, int book_id) {
	Chain* current = head->next; // 跳过头节点

	while (current != NULL) {
		Book* book = current->data.book;
		while (book != NULL) {
			if (book->id == book_id) {
				// 打印 Books 信息
				printf("书籍ID:\t%d\n", current->data.book_id);
				printf("名称:\t%s\n", current->data.name);
				printf("作者:\t%s (ID:\t%d)\n", current->data.anthor, current->data.anthor_id);
				printf("出版社:\t%s (ID:\t%d)\n", current->data.press, current->data.press_id);
				printf("总册数:\t%d\n", current->data.all_num);
				printf("剩余册数:\t%d\n", current->data.num);

				//本书
				printf("本书ID:\t%d\t\n", book->id);
				printf("是否被借出：\t%s\t\n", (book->isBorrowed ? "是" : "否"));
				return;
			}
			book = book->next;
		}
		current = current->next;
	}
	printf("未找到ID为%d的书.\n", book_id);
}

//查询全部Books信息
void displayAllBooksInfo(Chain* head) {
	printf("┌───────────┬──────────────┬───────────────┬───────┬───────┐\n");
	printf("│    ID     │ %-12s │ %-13s │ %-5s │ %-5s │\n", "书籍名称", "出版社", "作者", "剩余");
	printf("├───────────┼──────────────┼───────────────┼───────┼───────┤\n");

	Chain* node = head->next;

	while (node != NULL) {
		printf("│ %-9d │ %-12s │ %-13s │ %-5s │ %-5d │\n", node->data.book_id, node->data.name, node->data.press, node->data.anthor, node->data.num);
		node = node->next;
	}
	printf("└───────────┴──────────────┴───────────────┴───────┴───────┘\n");

}

//根据book_id借书
int borrowBookByBookId(Chain* head, int user_id, int book_id) {

	sqlite3* db = NULL;

	if (sqlite3_open(USERFILE, &db)) {
		fprintf(stderr, "无法打开数据库: %s\n", sqlite3_errmsg(db));
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
					printf("用户%d从图书ID%d借了图书ID%d\n", user_id, book->id, book_id);
					sqlite3_close(db);
					return 0;
				}
				book = book->next;
			}
			printf("图书ID%d中没有可借的图书\n", book_id);
			sqlite3_close(db);
			return -1;
		}
		current = current->next;
	}
	printf("未找到ID为%d的图书\n", book_id);
	sqlite3_close(db);
	return -1;
}

//根据id借书
int borrowBookById(Chain* head, int user_id, int book_id) {

	sqlite3 *db = NULL;

	if (sqlite3_open(USERFILE, &db)) {
		fprintf(stderr, "无法打开数据库: %s\n", sqlite3_errmsg(db));
	}


	int target_book_id = book_id / 10000;  // 假设 Books 的 book_id 是 Book 的 id 的高位部分
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
						printf("用户%d借的书ID%d\n", user_id, book->id);
						sqlite3_close(db);
						return 0;
					}
					else {
						printf("图书ID%d已被借出\n", book_id);
						sqlite3_close(db);
						return -1;
					}
				}
				book = book->next;
			}
		}
		current = current->next;
	}
	printf("找不到ID为%d的图书\n", book_id);
	sqlite3_close(db);
	return -1;
}

//根据id还书
int RecordWithId(Chain* head, int user_id, int id) {

	sqlite3* db = NULL;

	if (sqlite3_open(USERFILE, &db)) {
		fprintf(stderr, "无法打开数据库: %s\n", sqlite3_errmsg(db));
	}
	Chain* current = head->next;  // 从头结点的下一个节点开始遍历

	while (current != NULL) {
		Book* book = current->data.book;
		while (book != NULL) {
			if (book->id == id) {
				if (!book->isBorrowed) {
					printf("ID为%d的书籍未被借用。\n", id);
					sqlite3_close(db);
					return -1; // 书籍未被借阅
				}
				else {
					book->isBorrowed = 0;
					current->data.num++; // 增加该类书的剩余本数

					// 更新用户借阅列表
					if (removeBookFromUserBooks(db, user_id, id) != 0) {
						printf("无法更新用户的图书列表。\n");
						sqlite3_close(db);
						return -1;
					}

					printf("ID为%d的用户已归还ID为%d的图书。\n", id, user_id);
					sqlite3_close(db);
					return 0; // 归还成功
				}
			}
			book = book->next;
		}
		current = current->next;
	}

	printf("找不到ID为%d的图书。\n", id);
	sqlite3_close(db);

	return -1; // 未找到指定ID的书籍
}

//用户借阅字符串处理显示
void viewUserBorrowedBooks(Chain* head, int user_id) {

	sqlite3* db = NULL;

	if (sqlite3_open(USERFILE, &db)) {
		fprintf(stderr, "无法打开数据库: %s\n", sqlite3_errmsg(db));
	}

	char* books_str = getUserBooks(db, user_id);
	if (!books_str) {
		printf("No books found for user ID %d\n", user_id);
		sqlite3_close(db);
		return;
	}

	// 分割books_str中的书籍ID
	char* token = strtok(books_str, ",");
	int book_ids[100];
	int count = 0;

	while (token != NULL) {
		book_ids[count++] = atoi(token);
		token = strtok(NULL, ",");
	}

	printf("用户ID %d 借的书:\n", user_id);
	printf("├─────┬─────────────┬───────────────┬─────────────┬─────────────┤\n");
	printf("│ %3s │ %11s │ %-13s │ %-11s │ %11s │\n", "ID", "书籍ID", "书籍名称", "书籍作者", "是否被借出");
	printf("├─────┼─────────────┼───────────────┼─────────────┼─────────────┤\n");

	// 遍历链表找到对应的书籍信息
	for (int i = 0; i < count; i++) {
		int found = 0;
		Chain* current = head->next;

		while (current != NULL) {
			Book* book = current->data.book;
			while (book != NULL) {
				if (book->id == book_ids[i]) {
					printf("│ %3d │ %11d │ %-13s │ %-11s │ %11s │\n",
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
			printf("│ %3d │ %11d │ %-13s │ %-11s │ %11s │\n",
				i + 1, book_ids[i], "Unknown", "Unknown", "Unknown");
		}
	}

	printf("└─────┴─────────────┴───────────────┴─────────────┴─────────────┘\n");
	free(books_str);
	sqlite3_close(db);
}
