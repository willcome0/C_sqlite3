#include <stdio.h>
#include <stdlib.h>
#include "sqlite/sqlite3.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
   int i;
   for(i=0; i<argc; i++)
   {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main(int argc, char* argv[])
{
	sqlite3 *db=NULL;
	char *zErrMsg = 0;
	int rc;
	char *sql;			//表一

	FILE *fp = fopen("debug.txt", "r");

	/*连接数据库，不存在则创建*/
	rc = sqlite3_open("shujuku.db", &db);
	if( rc )
	{
		fprintf(stderr, "打开 %s 失败！\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return 0;
	}
	else
		printf("打开成功！\n");
	getchar();
	system("CLS"); 
	/**************************/

	sql = "CREATE TABLE COMPANY("  \
	     "ID INT PRIMARY KEY     NOT NULL," \
	     "NAME           TEXT    NOT NULL," \
	     "AGE            INT     NOT NULL," \
	     "ADDRESS        CHAR(50)," \
	     "SALARY         REAL );";

	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if( rc != SQLITE_OK )
	{
		printf("表创建失败 : %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		printf("表创建成功\n");
	}
	getchar();
	system("CLS"); 
	
	fclose(fp);
	sqlite3_close(db); //关闭数据库

	return 0;

} 
