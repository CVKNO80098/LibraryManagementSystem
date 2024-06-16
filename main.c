#include "header.h"

/* 文件是否存在？ */
int file_exist(char* filename) {
	FILE* fp;
	if (!(fp = fopen(filename, "r"))) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	// 各种初始化
	if (file_exist(FILENAME))
	{
		FILE* fp = fopen(FILENAME, "wb");
		fclose(fp);
	}
	Chain *head = CreatChain();
	//// 创建一些测试数据
	//Book book1 = { 1, 0, NULL };
	//Book book2 = { 2, 0, NULL };
	//book1.next = &book2;

	//Books books = { 100, "Test Book", 1, "Test Author", 1, "Test Press", 2, 2, &book1 };

	//Chain chain = { books, NULL };
	//Chain head = { {0, "", 0, "", 0, "", 0, 0, NULL}, &chain };  // 初始化链表头部

	sqlite3* db = initDataBase();
	sqlite3_close(db);

	//BorrowingWithId(db, head, user.id, 10000);
	//printf("%s", getUserBooks(db, user.id));
	//RecordWithId(db, head, user.id, 10000);

	login(head);
	SaveToFile(FILENAME, head);
}
