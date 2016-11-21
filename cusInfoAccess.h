#ifndef __CUSCONTROL_H__
#define __CUSCONTROL_H__

#include "cusInfo.h"

int AddCusInfo(char * ID, char * name, char * num);
cusInfo * GetCusPtrByID(char * ID);
int IsRegistID(char * ID);

#endif

/* end of file */