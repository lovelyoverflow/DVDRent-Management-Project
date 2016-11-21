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
		fputs("ISBN 입력: ", stdout);
		fgets(ISBN, ISBN_LEN, stdin);

		if (IsEnrollISBN(ISBN) == 1)
		{
			puts("해당 ISBN은 이미 등록되었습니다.");
			getchar();
			system("cls");
			return;
		}
		else
			break;
	}

	fputs("제목 입력: ", stdout);
	fgets(title, TITLE_LEN, stdin);

	fputs("장르 입력 (액션 1, 코믹 2, SF 3, 로맨틱 4): ", stdout);
	scanf("%d", &genre);
	
	if (!AddDvdInfo(ISBN, title, genre))
	{
		puts("DVD정보를 저장하지 못하였습니다.");
		getchar();
		return;
	}
	

	puts("\n등록이 완료되었습니다.");
	getchar();
}

void SearchDvdInfo(void)
{
	char ISBN[ISBN_LEN];

	fputs("찾는 ISBN 입력: ", stdout);
	fgets(ISBN, ISBN_LEN, stdin);

	dvdInfo * pDvd = GetDvdPtrByISBN(ISBN);

	if (pDvd == 0)
	{
		puts("등록되지 않은 DVD입니다");
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

	fputs("대여 DVD ISBN 입력: ", stdout);
	fgets(ISBN, ISBN_LEN, stdin);

	if (!IsEnrollISBN(ISBN) || IsRentedDvd(ISBN))
	{
		puts("등록되지 않은 ISBN이거나 이미 대여중인 DVD입니다.");
		getchar();
		system("cls");
		return;
	}

	puts("대여가 가능합니다. 대여 과정을 진행합니다.");

	fputs("대여 고객 ID입력: ", stdout);
	fgets(ID, ID_LEN, stdin);

	if (!IsRegistID(ID))
	{
		puts("가입 고객이 아닙니다.");
		getchar();
		system("cls");
		return;
	}

	fputs("대여 날짜 입력: ", stdout);
	scanf("%d", &day);

	AddRentInfo(ISBN, ID, day);
	puts("대여가 완료되었습니다.");
	getchar();
	system("cls");
	return;
}

void ReturnDvd(void)
{
	char ISBN[ISBN_LEN];

	fputs("대여 DVD ISBN 입력: ", stdout);
	fgets(ISBN, ISBN_LEN, stdin);

	if (!IsEnrollISBN(ISBN) || !IsRentedDvd(ISBN))
	{
		puts("등록되지 않은 ISBN이거나 대여되지 않은 DVD입니다.");
		getchar();
		system("cls");
		return;
	}

	RemoveRentInfo(ISBN);

	puts("반납이 완료되었습니다.");
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

	fputs("찾는 ISBN입력: ", stdout);
	fgets(ISBN, ISBN_LEN, stdin);

	if (!IsEnrollISBN(ISBN))
	{
		puts("등록되지 않은 ISBN입니다.");
		getchar();
		system("cls");
		return;
	}

	dRI = GetRentListByISBN(ISBN);
	numOfRentCus = GetnumOfRentCusByISBN(ISBN);

	for (int i = 0; i < numOfRentCus; i++)
	{
		printf("대여일 %d \n", dRI[i].rentDay);
		cI = GetCusPtrByID(dRI[i].cusID);

		ShowCustomerInfoContinue(cI);		
	}

	puts("조회를 완료하였습니다.");
	getchar();
}