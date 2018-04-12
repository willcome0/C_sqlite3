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
		fprintf(stderr, "�� %s ʧ�ܣ�\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return 0;
	}
	else
		printf("�򿪳ɹ���\n");
	
	sqlite3_close(db); //�ر����ݿ�
	
	return 0;

}
