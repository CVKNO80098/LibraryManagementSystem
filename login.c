#include "header.h"

char* input_password() {
    char *password = (char*)malloc(sizeof(char)*20);
    int i = 0;
    while ((password[i] = getch()) != '\r') {
        if (password[i] == '\b') {//古希腊主管退格的神（）
            i--;
            printf("\b \b");
        } else {
            printf("*");
            i++;
        }
    }
    password[i] = '\0';
    return password;
}

UserInfo loginSub(char* username, char* password) {
    sqlite3* db = initDataBase();
    sqlite3_stmt* stmt;
    const char* sql = "SELECT ID, NICKNAME, POWER FROM USER WHERE NAME = ? AND PASSWORD = ?";

    UserInfo userInfo = { -1, -1 ,-1 }; // 初始化为无效值

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
         
        return userInfo;
    }

    sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password, -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        userInfo.id = sqlite3_column_int(stmt, 0);
        strcpy(userInfo.username, sqlite3_column_text(stmt, 1));
        userInfo.isAdmin = sqlite3_column_int(stmt, 2);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return userInfo;
}

int Register(char* nickname, char* username, char* password, int isAdmin) {
    sqlite3* db = initDataBase();
    sqlite3_stmt* stmt;
    const char* checkUserSql = "SELECT COUNT(*) FROM USER WHERE NAME = ?";
    const char* insertUserSql = "INSERT INTO USER (NICKNAME, NAME, PASSWORD, POWER) VALUES (?, ?, ?, ?)";
    int result = 0;

    // 检查用户名是否已存在
    if (sqlite3_prepare_v2(db, checkUserSql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return -1;
    }

    sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_ROW && sqlite3_column_int(stmt, 0) > 0) {
        fprintf(stderr, "用户名已存在。\n");
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return -1;
    }

    sqlite3_finalize(stmt);

    // 插入新用户
    if (sqlite3_prepare_v2(db, insertUserSql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return -1;
    }

    sqlite3_bind_text(stmt, 1, nickname, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, username, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, password, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, isAdmin);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        fprintf(stderr, "无法注册用户: %s\n", sqlite3_errmsg(db));
    }
    else {
        result = 1;  // 注册成功
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return result;  // 1表示注册成功，-1表示失败
}