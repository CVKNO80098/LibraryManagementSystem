#include "header.h"

sqlite3* initDataBase() {
    sqlite3* db = NULL;
    char* zErrMsg = 0;
    char* sql;

    if (sqlite3_open(USERFILE, &db)) {
        fprintf(stderr, "无法打开数据库: %s\n", sqlite3_errmsg(db));
    }

    /* 创建 SQL 表 */
    sql = "CREATE TABLE IF NOT EXISTS USER("  \
        "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
        "NICKNAME TEXT NOT NULL,"\
        "NAME TEXT NOT NULL," \
        "PASSWORD TEXT NOT NULL," \
        "BOOKS TEXT," \
        "POWER INT NOT NULL);";

    if (sqlite3_exec(db, sql, 0, 0, &zErrMsg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    return db;
}

char* getUserBooks(sqlite3* db, int user_id) {
    sqlite3_stmt* stmt;
    const char* getUserBooksSql = "SELECT BOOKS FROM USER WHERE ID = ?";
    char* userBooks = NULL;

    if (sqlite3_prepare_v2(db, getUserBooksSql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "无法prepare statement: %s\n", sqlite3_errmsg(db));
        return NULL;
    }

    sqlite3_bind_int(stmt, 1, user_id);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        const unsigned char* currentBooks = sqlite3_column_text(stmt, 0);
        if (currentBooks) {
            userBooks = strdup((const char*)currentBooks);
        }
        else {
            userBooks = strdup("");
        }
    }

    sqlite3_finalize(stmt);
    return userBooks;
}

int updateUserBooks(sqlite3* db, int user_id, int book_id) {
    sqlite3_stmt* stmt;
    const char* updateUserBooksSql = "UPDATE USER SET BOOKS = ? WHERE ID = ?";
    char newBookList[256] = { 0 };

    char* currentBooks = getUserBooks(db, user_id);
    if (!currentBooks) {
        return -1; // 获取用户借阅列表失败
    }

    if (strlen(currentBooks) > 0) {
        snprintf(newBookList, sizeof(newBookList), "%s,%d", currentBooks, book_id);
    }
    else {
        snprintf(newBookList, sizeof(newBookList), "%d", book_id);
    }

    free(currentBooks);

    if (sqlite3_prepare_v2(db, updateUserBooksSql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return -1;
    }

    sqlite3_bind_text(stmt, 1, newBookList, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, user_id);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        fprintf(stderr, "无法更新用户的书籍: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return -1;
    }

    sqlite3_finalize(stmt);
    return 0;
}

int removeBookFromUserBooks(sqlite3* db, int user_id, int book_id) {
    sqlite3_stmt* stmt;
    const char* updateUserBooksSql = "UPDATE USER SET BOOKS = ? WHERE ID = ?";
    char newBookList[256] = { 0 };

    char* currentBooks = getUserBooks(db, user_id);
    if (!currentBooks) {
        return -1; // 获取用户借阅列表失败
    }

    if (strlen(currentBooks) > 0) {
        char* token = strtok(currentBooks, ",");
        int first = 1;
        while (token != NULL) {
            if (atoi(token) != book_id) {
                if (!first) {
                    strncat(newBookList, ",", sizeof(newBookList) - strlen(newBookList) - 1);
                }
                strncat(newBookList, token, sizeof(newBookList) - strlen(newBookList) - 1);
                first = 0;
            }
            token = strtok(NULL, ",");
        }
    }

    free(currentBooks);

    if (sqlite3_prepare_v2(db, updateUserBooksSql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return -1;
    }

    sqlite3_bind_text(stmt, 1, newBookList, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, user_id);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        fprintf(stderr, "无法更新用户书籍: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return -1;
    }

    sqlite3_finalize(stmt);
    return 0;
}

void queryAllUsers() {

    sqlite3* db;
    if (sqlite3_open(USERFILE, &db)) {
        fprintf(stderr, "无法打开数据库: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_stmt* stmt;
    const char* sql = "SELECT * FROM USER;";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    system("cls");
    SetColor(0x0f, 0);

    printf("┌─────┬──────────────┬───────────────┬───────┐\n");
    printf("│ ID  │  NICKNAME    │   NAME        │ POWER │\n");
    printf("├─────┼──────────────┼───────────────┼───────┤\n");

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char* nickname = sqlite3_column_text(stmt, 1);
        const unsigned char* name = sqlite3_column_text(stmt, 2);
        int power = sqlite3_column_int(stmt, 5);
        printf("│ %3d │ %-12s │ %-13s │ %5d │\n", id, nickname, name, power);
    }

    printf("└─────┴──────────────┴───────────────┴───────┘\n");

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    printf("按回车键继续");
}

int deleteUserById( int user_id) {
    sqlite3* db;
    if (sqlite3_open(USERFILE, &db)) {
        fprintf(stderr, "无法打开数据库: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_stmt* stmt;
    const char* sql = "DELETE FROM USER WHERE ID = ?";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return -1;
    }

    sqlite3_bind_int(stmt, 1, user_id);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        fprintf(stderr, "删除用户失败: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return -1;
    }

    sqlite3_finalize(stmt);
    return 0;
}


