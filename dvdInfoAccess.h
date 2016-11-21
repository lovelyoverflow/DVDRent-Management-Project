#ifndef __DVD_INFO_ACCESS_H__
#define __DVD_INFO_ACCESS_H__

#include "dvdinfo.h"

int AddDvdInfo(char * ISBN, char * title, int genre);
dvdInfo * GetDvdPtrByISBN(char * ISBN);
int IsEnrollISBN(char * ISBN);

void AddRentInfo(char * ISBN, char * ID, int day);
int IsRentedDvd(char * ISBN);
void RemoveRentInfo(char * ISBN);
dvdRentInfo * GetRentListByISBN(char * ISBN);
int GetnumOfRentCusByISBN(char * ISBN);

#endif