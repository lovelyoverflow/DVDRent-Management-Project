#include "common.h"
#include "cusManager.h"
#include "dvdManager.h"
#include "screenOut.h"

enum{CUS_REGIST=1, CUS_SEARCH, DVD_ENROLL, DVD_SEARCH, DVD_RENT, DVD_RETURN, SHOW, QUIT};

void ClearLineFromReadBuffer(void)
{
	while (getchar() != '\n');
}

int main(void)
{
    int inputMenu = 0;
    
    while(1)
    {
        ShowMenu();
        scanf("%d", &inputMenu);
		ClearLineFromReadBuffer();

		switch (inputMenu)
		{
		case CUS_REGIST:
			RegistCustomer();
			break;

		case CUS_SEARCH:
			SearchCusInfo();
			break;

		case DVD_ENROLL:
			EnrollDvd();
			break;

		case DVD_SEARCH:
			SearchDvdInfo();
			break;

		case DVD_RENT:
			RentDvd();
			break;

		case DVD_RETURN:
			ReturnDvd();
			break;

		case SHOW:
			ShowAllRentCus();
			break;
		}
		
        if(inputMenu==QUIT)
        {
            puts("이용해 주셔서 고마워요~");
            break;
        }
    }    

    return 0;
}

/* end of file */