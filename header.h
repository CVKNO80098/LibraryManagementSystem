#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>	// 应该这个软件没有Linux用户吧...
#include <sqlite3.h>
//#include <io.h>		// 嗯...

#define FILENAME "DataBase.dat"
#define USERFILE "UserData.db"

typedef struct book {
	int id;		//图书编号
	int isBorrowed;		//是否被借阅
	struct book* next;
}Book;

typedef struct {
	int book_id;	//该版书编号
	char name[20];		//图书名称
	int anthor_id;
	char anthor[20];	//作者
	int press_id;
	char press[30];	//出版社
	int num;		//剩余册数
	int all_num;	//总册数

	Book *book;
}Books;

typedef struct {
	int id;
	char username[20];
	int isAdmin;
} UserInfo;

typedef struct node{
	Books data;
	struct node* next;
}Chain;

// ---*--FileSave文件函数--*---

//从文件中读取链并组成链表
Chain* CreatChain();
//将链表保存到文件（覆盖写入）
int SaveToFile(char* filename, Chain* head);


// ---*--SQLManage文件函数--*---

//初始化数据库
sqlite3* initDataBase();
//查询用户的借阅情况（SQL查询）
char* getUserBooks(sqlite3* db, int user_id);
//更新用户的借阅列表（SQL操作）append
int updateUserBooks(sqlite3* db, int user_id, int book_id);
//还书的用户列表更新（SQL操作）remove
int removeBookFromUserBooks(sqlite3* db, int user_id, int book_id);
//显示所有账户
void queryAllUsers();
//删除指定账户
int deleteUserById(int user_id);


// ---*--BookList文件函数--*---

//增加新类型的书籍
int addBookType(Chain* head, int book_id, char* name, int anthor_id, char* anthor, char* press, int press_id, int all_num);
//增加对应书籍号的书籍本书	normal:0
int addBook(Chain* head, int book_id, int book_num);
//删除对应种类的书籍		normal:0
int DelBook(Chain* head, int book_id);
//显示Books信息
void displayBooksInfo(Chain* head, int book_id);
// 根据书名查询Books信息
void queryBooksByName(Chain* head, const char* book_name);
//查询Book信息
void displayBookInfoById(Chain* head, int book_id);
//显示全部Books信息
void displayAllBooksInfo(Chain* head);
//根据id借书
int borrowBookById(Chain* head, int user_id, int book_id);
//根据book_id借书
int borrowBookByBookId(Chain* head, int user_id, int book_id);
// 还书的
int RecordWithId(Chain* head, int user_id, int id);
//用户借阅字符串处理显示
void viewUserBorrowedBooks(Chain* head, int user_id);

// ---*--login文件函数--*---

// 古希腊掌管密码输入的神
char* input_password();
/// <summary>登录验证函数 最后一个int参数为1时代表为管理员，0时为借阅者</summary>/// <param name="username"></param>/// <param name="password"></param>/// <returns>(int)账户ID</returns>
UserInfo loginSub(char* username, char* password);
/// <summary>注册新用户函数 </summary>/// <param name="nickname"></param>///<param name="username"></param>/// <param name="password"></param>/// <param name="isAdmin"></param>/// <returns>1表示注册成功，-1表示失败</returns>
int Register(char* nickname, char* username, char* password, int isAdmin);


// ---------------以上代码测试通过--------------------尽量不要动了好吧 #悲

// ---*--页面函数--**---

//UI交互
int KeyboardChoice(int userChoice, int choice_max);
//美化
VOID SetColor(UINT uFore, UINT uBack);

// 登录及注册
int login(Chain* head);
// 后台管理界面
int Manage(UserInfo user, Chain* head);
// 用户菜单
int UserMenu(UserInfo user, Chain* head);

// 堆放各种页面的地方
void AdminPageMain(UserInfo user, HANDLE hOut);
void AdminPageRegister(HANDLE hOut);

void UserPageMain(UserInfo user, HANDLE hOut);