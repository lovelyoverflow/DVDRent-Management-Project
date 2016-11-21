#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

/* ��    ��: void RegistCustomer(void)
 * ��    ��: �ű� ȸ�� ����. 
 * ��    ȯ: void
 *
 */


void RegistCustomer(void)
{
	char ID[ID_LEN];
	char name[NAME_LEN];
	char phoneNum[PHONE_LEN];

	while (1)
	{
		fputs("ID �Է�: ", stdout);
		fgets(ID, ID_LEN, stdin);

		if (IsRegistID(ID) == 1)
		{
			puts("�ش� ID�� �̹� ��� �߿� �ֽ��ϴ�. �ٸ� ID�� ������ֽʽÿ�.");
			continue;
		}
		else
			break;
	}

	fputs("�̸��Է�: ", stdout);
	fgets(name, NAME_LEN, stdin);

	fputs("��ȭ��ȣ �Է�: ", stdout);
	fgets(phoneNum, PHONE_LEN, stdin);

	if (!AddCusInfo(ID, name, phoneNum))
	{
		puts("�������� ������ ���忡 �����Ͽ����ϴ�.");
		getchar();
		return;
	}

	puts("\n������ �Ϸ�Ǿ����ϴ�.");
	getchar();
}

/* ��    ��: void SearchCusInfo(void)
 * ��    ��: ID�� ���� ȸ�� ���� �˻�
 * ��    ȯ: void
 * 
 */
void SearchCusInfo(void)
{
	cusInfo * Search;
	char ID[ID_LEN];

	fputs("ã�� ID �Է�: ", stdout);
	fgets(ID, ID_LEN, stdin);
	
	Search = GetCusPtrByID(ID);

	if (Search != NULL)
		ShowCustomerInfo(Search);
	else
	{
		puts("�ش� ����ڸ� ã�� �� �����ϴ�.");
		getchar();

		return;
	}
}

/* end of file */