#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>	// Ӧ��������û��Linux�û���...
#include <sqlite3.h>
//#include <io.h>		// ��...

#define FILENAME "DataBase.dat"
#define USERFILE "UserData.db"

typedef struct book {
	int id;		//ͼ����
	int isBorrowed;		//�Ƿ񱻽���
	struct book* next;
}Book;

typedef struct {
	int book_id;	//�ð�����
	char name[20];		//ͼ������
	int anthor_id;
	char anthor[20];	//����
	int press_id;
	char press[30];	//������
	int num;		//ʣ�����
	int all_num;	//�ܲ���

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

// ---*--FileSave�ļ�����--*---

//���ļ��ж�ȡ�����������
Chain* CreatChain();
//�������浽�ļ�������д�룩
int SaveToFile(char* filename, Chain* head);


// ---*--SQLManage�ļ�����--*---

//��ʼ�����ݿ�
sqlite3* initDataBase();
//��ѯ�û��Ľ��������SQL��ѯ��
char* getUserBooks(sqlite3* db, int user_id);
//�����û��Ľ����б�SQL������append
int updateUserBooks(sqlite3* db, int user_id, int book_id);
//������û��б���£�SQL������remove
int removeBookFromUserBooks(sqlite3* db, int user_id, int book_id);
//��ʾ�����˻�
void queryAllUsers();
//ɾ��ָ���˻�
int deleteUserById(int user_id);


// ---*--BookList�ļ�����--*---

//���������͵��鼮
int addBookType(Chain* head, int book_id, char* name, int anthor_id, char* anthor, char* press, int press_id, int all_num);
//���Ӷ�Ӧ�鼮�ŵ��鼮����	normal:0
int addBook(Chain* head, int book_id, int book_num);
//ɾ����Ӧ������鼮		normal:0
int DelBook(Chain* head, int book_id);
//��ʾBooks��Ϣ
void displayBooksInfo(Chain* head, int book_id);
// ����������ѯBooks��Ϣ
void queryBooksByName(Chain* head, const char* book_name);
//��ѯBook��Ϣ
void displayBookInfoById(Chain* head, int book_id);
//��ʾȫ��Books��Ϣ
void displayAllBooksInfo(Chain* head);
//����id����
int borrowBookById(Chain* head, int user_id, int book_id);
//����book_id����
int borrowBookByBookId(Chain* head, int user_id, int book_id);
// �����
int RecordWithId(Chain* head, int user_id, int id);
//�û������ַ���������ʾ
void viewUserBorrowedBooks(Chain* head, int user_id);

// ---*--login�ļ�����--*---

// ��ϣ���ƹ������������
char* input_password();
/// <summary>��¼��֤���� ���һ��int����Ϊ1ʱ����Ϊ����Ա��0ʱΪ������</summary>/// <param name="username"></param>/// <param name="password"></param>/// <returns>(int)�˻�ID</returns>
UserInfo loginSub(char* username, char* password);
/// <summary>ע�����û����� </summary>/// <param name="nickname"></param>///<param name="username"></param>/// <param name="password"></param>/// <param name="isAdmin"></param>/// <returns>1��ʾע��ɹ���-1��ʾʧ��</returns>
int Register(char* nickname, char* username, char* password, int isAdmin);


// ---------------���ϴ������ͨ��--------------------������Ҫ���˺ð� #��

// ---*--ҳ�溯��--**---

//UI����
int KeyboardChoice(int userChoice, int choice_max);
//����
VOID SetColor(UINT uFore, UINT uBack);

// ��¼��ע��
int login(Chain* head);
// ��̨�������
int Manage(UserInfo user, Chain* head);
// �û��˵�
int UserMenu(UserInfo user, Chain* head);

// �ѷŸ���ҳ��ĵط�
void AdminPageMain(UserInfo user, HANDLE hOut);
void AdminPageRegister(HANDLE hOut);

void UserPageMain(UserInfo user, HANDLE hOut);