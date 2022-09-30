#include <stdio.h>
#include <string.h>
////fseek - 文件的随机读取 - 移动文件指针到特定位置
////int fseek(FILE* stream, long offset,int origin); 
////      -   pf指针         偏移量    文件指针的位置(SEEK_CUR当前位置，SEEK_END末尾位置，SEEK_SET起始位置)
//#include <string.h>
//#include <errno.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//1.定义文件指针
//	fseek(pf, -2, SEEK_CUR);
//	//2.读取文件
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

////ftell  - 返回文件指针相对于起始位置的偏移量
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//fseek(pf, -2, SEEK_END);
//	// fgetc(pf);
//	int pos = ftell(pf);
//	printf("%d\n", pos);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

////rewind  -  让文件指针的位置回到文件的起始位置
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//	fseek(pf, 2, SEEK_SET);
//	rewind(pf);
//	ch = getc(pf);
//	printf("%c\n", ch);     //都打印a
//	fclose(pf);
//	pf == NULL;
//	return 0;
//}

////EOF - 文件结束标志
//
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	int ch = fgetc(pf);
//	printf("%d\n", ch);
//	fclose(pf);   //打印 -1  ,文件为空，结束标志为 -1
//	pf = NULL;
//	return 0;
//}
////在文件读取过程中，不能用feof的返回值直接用来判断文件的是否结束
////而是应用于当文件读取结束的时候，判断是读取失败结束，还是遇到文件结束
////方式：判断返回值是否是EOF（fgetc）,还是NULL（fgets）
////二进制：就是判断fread返回值是否小于实际要求要读的个数

// perror函数
int main()
{
	//strerror  - 把错误码对应的错误信息的字符串地址返回
	// printf("%s\n", strerror(errno));   //需要引入头文件<errno.h>
	//用perror
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("open file test2.txt");   //不用引入头文件
		return 0;
	}
	//读文件
	int ch = 0;
	while ((ch = fgetc(pf)) != EOF)
	{
		putchar(ch);
	}
	if (ferror(pf))
	{
		printf("error\n");
	}
	else if (feof(pf))
	{
		printf("end of file\n");
	}

	fclose(pf);
	pf = NULL;
	return 0;
}