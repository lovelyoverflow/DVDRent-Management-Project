#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER  100

static cusInfo * cusList[MAX_CUSTOMER];
static int numOfCustomer=0;

/* ��    ��: int AddCusInfo (char * ID, char * name, char * num)
 * ��    ��: cusInfo �Ҵ� �� ����. 
 * ��    ȯ: ���� �� '��ϵ� ������ ��', ���� �� 0�� ��ȯ.
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


/* ��    ��: cusInfo * GetCusPtrByID(char * ID)
 * ��    ��: �ش� ID�� ������ ��� �ִ� ������ ������ ��ȯ 
 * ��    ȯ: ��� �ȵ� ID�� ��� NULL ������ ��ȯ.
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


/* ��    ��: int IsRegistID(char * ID)
 * ��    ��: ���� �� ID���� Ȯ��. 
 * ��    ȯ: ���� �Ǿ����� 1, �ƴϸ� 0 ��ȯ.
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