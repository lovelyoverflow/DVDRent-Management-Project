#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"
#include "cusInfoAccess.h"

void EnrollDvd(void)
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	while (1)
	{
		fputs("ISBN �Է�: ", stdout);
		fgets(ISBN, ISBN_LEN, stdin);

		if (IsEnrollISBN(ISBN) == 1)
		{
			puts("�ش� ISBN�� �̹� ��ϵǾ����ϴ�.");
			getchar();
			system("cls");
			return;
		}
		else
			break;
	}

	fputs("���� �Է�: ", stdout);
	fgets(title, TITLE_LEN, stdin);

	fputs("�帣 �Է� (�׼� 1, �ڹ� 2, SF 3, �θ�ƽ 4): ", stdout);
	scanf("%d", &genre);
	
	if (!AddDvdInfo(ISBN, title, genre))
	{
		puts("DVD������ �������� ���Ͽ����ϴ�.");
		getchar();
		return;
	}
	

	puts("\n����� �Ϸ�Ǿ����ϴ�.");
	getchar();
}

void SearchDvdInfo(void)
{
	char ISBN[ISBN_LEN];

	fputs("ã�� ISBN �Է�: ", stdout);
	fgets(ISBN, ISBN_LEN, stdin);

	dvdInfo * pDvd = GetDvdPtrByISBN(ISBN);

	if (pDvd == 0)
	{
		puts("��ϵ��� ���� DVD�Դϴ�");
		getchar();
		system("cls");
		return;
	}

	ShowDvdInfo(pDvd);
}

void RentDvd(void)
{
	char ID[ID_LEN];
	char ISBN[ISBN_LEN];
	int day;

	fputs("�뿩 DVD ISBN �Է�: ", stdout);
	fgets(ISBN, ISBN_LEN, stdin);

	if (!IsEnrollISBN(ISBN) || IsRentedDvd(ISBN))
	{
		puts("��ϵ��� ���� ISBN�̰ų� �̹� �뿩���� DVD�Դϴ�.");
		getchar();
		system("cls");
		return;
	}

	puts("�뿩�� �����մϴ�. �뿩 ������ �����մϴ�.");

	fputs("�뿩 �� ID�Է�: ", stdout);
	fgets(ID, ID_LEN, stdin);

	if (!IsRegistID(ID))
	{
		puts("���� ���� �ƴմϴ�.");
		getchar();
		system("cls");
		return;
	}

	fputs("�뿩 ��¥ �Է�: ", stdout);
	scanf("%d", &day);

	AddRentInfo(ISBN, ID, day);
	puts("�뿩�� �Ϸ�Ǿ����ϴ�.");
	getchar();
	system("cls");
	return;
}

void ReturnDvd(void)
{
	char ISBN[ISBN_LEN];

	fputs("�뿩 DVD ISBN �Է�: ", stdout);
	fgets(ISBN, ISBN_LEN, stdin);

	if (!IsEnrollISBN(ISBN) || !IsRentedDvd(ISBN))
	{
		puts("��ϵ��� ���� ISBN�̰ų� �뿩���� ���� DVD�Դϴ�.");
		getchar();
		system("cls");
		return;
	}

	RemoveRentInfo(ISBN);

	puts("�ݳ��� �Ϸ�Ǿ����ϴ�.");
	getchar();
	system("cls");
	return;
}

void ShowAllRentCus(void)
{
	dvdRentInfo * dRI;
	cusInfo * cI;
	char ISBN[ISBN_LEN];
	int numOfRentCus;

	fputs("ã�� ISBN�Է�: ", stdout);
	fgets(ISBN, ISBN_LEN, stdin);

	if (!IsEnrollISBN(ISBN))
	{
		puts("��ϵ��� ���� ISBN�Դϴ�.");
		getchar();
		system("cls");
		return;
	}

	dRI = GetRentListByISBN(ISBN);
	numOfRentCus = GetnumOfRentCusByISBN(ISBN);

	for (int i = 0; i < numOfRentCus; i++)
	{
		printf("�뿩�� %d \n", dRI[i].rentDay);
		cI = GetCusPtrByID(dRI[i].cusID);

		ShowCustomerInfoContinue(cI);		
	}

	puts("��ȸ�� �Ϸ��Ͽ����ϴ�.");
	getchar();
}