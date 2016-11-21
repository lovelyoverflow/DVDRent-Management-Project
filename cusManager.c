#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

/* 함    수: void RegistCustomer(void)
 * 기    능: 신규 회원 가입. 
 * 반    환: void
 *
 */


void RegistCustomer(void)
{
	char ID[ID_LEN];
	char name[NAME_LEN];
	char phoneNum[PHONE_LEN];

	while (1)
	{
		fputs("ID 입력: ", stdout);
		fgets(ID, ID_LEN, stdin);

		if (IsRegistID(ID) == 1)
		{
			puts("해당 ID는 이미 사용 중에 있습니다. 다른 ID를 사용해주십시오.");
			continue;
		}
		else
			break;
	}

	fputs("이름입력: ", stdout);
	fgets(name, NAME_LEN, stdin);

	fputs("전화번호 입력: ", stdout);
	fgets(phoneNum, PHONE_LEN, stdin);

	if (!AddCusInfo(ID, name, phoneNum))
	{
		puts("정상적인 데이터 저장에 실패하였습니다.");
		getchar();
		return;
	}

	puts("\n가입이 완료되었습니다.");
	getchar();
}

/* 함    수: void SearchCusInfo(void)
 * 기    능: ID를 통한 회원 정보 검색
 * 반    환: void
 * 
 */
void SearchCusInfo(void)
{
	cusInfo * Search;
	char ID[ID_LEN];

	fputs("찾는 ID 입력: ", stdout);
	fgets(ID, ID_LEN, stdin);
	
	Search = GetCusPtrByID(ID);

	if (Search != NULL)
		ShowCustomerInfo(Search);
	else
	{
		puts("해당 사용자를 찾을 수 없습니다.");
		getchar();

		return;
	}
}

/* end of file */