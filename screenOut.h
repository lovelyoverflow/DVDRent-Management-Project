#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"

void ShowMenu(void);
void ShowCustomerInfo(cusInfo * pCus);
void ShowDvdInfo(dvdInfo * pDvd);
void ShowCustomerInfoContinue(cusInfo * pCus);

#endif

/* end of file */