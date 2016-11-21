#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"

/* ���α׷� ����� ���� �޴� */
void ShowMenu(void)
{
    system("cls");   //stdlib.h
    
    printf("���������� ��  �� �������������� \n");
    printf(" 1. �ű԰��� \n");
    printf(" 2. ���˻� \n");
	printf("____________________ \n");
	printf(" 3. DVD ��� \n");
	printf(" 4. DVD �˻� \n");
	printf("____________________ \n");
	printf(" 5. DVD �뿩 \n");
	printf(" 6. DVD �ݳ� \n");
	printf("____________________ \n");
	printf(" 7. DVD �뿩�� ��ü ��ȸ \n");
    printf(" 8. ���� \n");
    printf("���������������������������������������� \n");
    printf("���á� ");
}


/* �� ������ �⺻ ���� ��� */
void ShowCustomerInfo(cusInfo * pCus)
{
    system("cls");   //stdlib.h
    
    printf("���������������������������������� \n");
    printf("�� �� ID: %s \n", pCus->ID);
    printf("�� �� �̸�: %s \n", pCus->name);
    printf("�� �� ��ȭ��ȣ: %s \n", pCus->phoneNum);
    printf("���������������������������������� \n\n");
    
    getchar(); // Ű �Է½� �Ѿ�� ���ؼ�..
}

void ShowGenre(int genre)
{
	switch (genre)
	{
	case ACTION:
		fputs("�׼�", stdout);
		break;
	case COMIC:
		fputs("�ڹ�", stdout);
		break;
	case SF:
		fputs("SF", stdout);
		break;
	case ROMANTIC:
		fputs("�θ�ƽ", stdout);
		break;
	}
}

void ShowDvdInfo(dvdInfo * pDvd)
{
	system("cls");   //stdlib.h

	printf("���������������������������������� \n");
	printf("�� �� ISBN: %s \n", pDvd->ISBN);
	printf("�� �� ����: %s \n", pDvd->title);
	printf("�� �� �帣: "); ShowGenre(pDvd->genre); puts("");
	printf("���������������������������������� \n\n");

	getchar();
}

void ShowCustomerInfoContinue(cusInfo * pCus)
{
	printf("���������������������������������� \n");
	printf("�� �� ID: %s \n", pCus->ID);
	printf("�� �� �̸�: %s \n", pCus->name);
	printf("�� �� ��ȭ��ȣ: %s \n", pCus->phoneNum);
	printf("���������������������������������� \n\n");
}

/* end of file */