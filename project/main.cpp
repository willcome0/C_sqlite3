#include <stdio.h> 
#include "sqlite/sqlite3.h"


int main(void)
{
	sqlite3 *db=NULL;
	char *zErrMsg = 0;
	int rc;
	
	rc = sqlite3_open("zieckey.db", &db); 
	if( rc )
	{
		fprintf(stderr, "打开 %s 失败！\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return 0;
	}
	else
		printf("打开成功！\n");
	
	sqlite3_close(db); //关闭数据库
	
	return 0;

}
