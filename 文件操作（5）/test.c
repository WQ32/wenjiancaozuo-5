#include <stdio.h>
#include <string.h>
////fseek - �ļ��������ȡ - �ƶ��ļ�ָ�뵽�ض�λ��
////int fseek(FILE* stream, long offset,int origin); 
////      -   pfָ��         ƫ����    �ļ�ָ���λ��(SEEK_CUR��ǰλ�ã�SEEK_ENDĩβλ�ã�SEEK_SET��ʼλ��)
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
//	//1.�����ļ�ָ��
//	fseek(pf, -2, SEEK_CUR);
//	//2.��ȡ�ļ�
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

////ftell  - �����ļ�ָ���������ʼλ�õ�ƫ����
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

////rewind  -  ���ļ�ָ���λ�ûص��ļ�����ʼλ��
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
//	printf("%c\n", ch);     //����ӡa
//	fclose(pf);
//	pf == NULL;
//	return 0;
//}

////EOF - �ļ�������־
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
//	fclose(pf);   //��ӡ -1  ,�ļ�Ϊ�գ�������־Ϊ -1
//	pf = NULL;
//	return 0;
//}
////���ļ���ȡ�����У�������feof�ķ���ֱֵ�������ж��ļ����Ƿ����
////����Ӧ���ڵ��ļ���ȡ������ʱ���ж��Ƕ�ȡʧ�ܽ��������������ļ�����
////��ʽ���жϷ���ֵ�Ƿ���EOF��fgetc��,����NULL��fgets��
////�����ƣ������ж�fread����ֵ�Ƿ�С��ʵ��Ҫ��Ҫ���ĸ���

// perror����
int main()
{
	//strerror  - �Ѵ������Ӧ�Ĵ�����Ϣ���ַ�����ַ����
	// printf("%s\n", strerror(errno));   //��Ҫ����ͷ�ļ�<errno.h>
	//��perror
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("open file test2.txt");   //��������ͷ�ļ�
		return 0;
	}
	//���ļ�
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