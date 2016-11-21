#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER  100

static cusInfo * cusList[MAX_CUSTOMER];
static int numOfCustomer=0;

/* 함    수: int AddCusInfo (char * ID, char * name, char * num)
 * 기    능: cusInfo 할당 및 저장. 
 * 반    환: 성공 시 '등록된 정보의 수', 실패 시 0을 반환.
 *
 */
int AddCusInfo(char * ID, char * name, char * num)
{
	if (numOfCustomer >= MAX_CUSTOMER)
		return 0;

	cusList[numOfCustomer] = (cusInfo*)malloc(sizeof(cusInfo));

	strcpy(cusList[numOfCustomer]->ID, ID);
	strcpy(cusList[numOfCustomer]->name, name);
	strcpy(cusList[numOfCustomer]->phoneNum, num);

	numOfCustomer++;
	return numOfCustomer;
}


/* 함    수: cusInfo * GetCusPtrByID(char * ID)
 * 기    능: 해당 ID의 정보를 담고 있는 변수의 포인터 반환 
 * 반    환: 등록 안된 ID의 경우 NULL 포인터 반환.
 *
 */
cusInfo * GetCusPtrByID(char * ID)
{
	int i; 

	for (i = 0; i < numOfCustomer; i++)
	{
		if (!strcmp(cusList[i]->ID, ID))
		{
			return cusList[i];
			break;
		}
	}

	return (cusInfo*)NULL;
}


/* 함    수: int IsRegistID(char * ID)
 * 기    능: 가입 된 ID인지 확인. 
 * 반    환: 가입 되었으면 1, 아니면 0 반환.
 *
 */
int IsRegistID(char * ID)
{
	cusInfo * pCus = GetCusPtrByID(ID);

	if (pCus == 0)
		return 0;
	else
		return 1;
}

/* end of file */