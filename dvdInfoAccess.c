#include "common.h"
#include "dvdInfo.h"
#include "cusInfoAccess.h"

#define MAX_Dvd  100

static dvdInfo * dvdList[MAX_Dvd];
static int numOfDvd = 0;

int AddDvdInfo(char * ISBN, char * title, int genre)
{
	if (numOfDvd >= MAX_Dvd)
		return 0;

	dvdList[numOfDvd] = (dvdInfo*)malloc(sizeof(dvdInfo));

	strcpy(dvdList[numOfDvd]->ISBN, ISBN);
	strcpy(dvdList[numOfDvd]->title, title);
	dvdList[numOfDvd]->genre = genre;
	dvdList[numOfDvd]->rentState = RETURNED;
	dvdList[numOfDvd]->numOfRentCus = 0;

	numOfDvd++;
	return numOfDvd;
}

dvdInfo * GetDvdPtrByISBN(char * ISBN)
{
	int i;

	for (i = 0; i < numOfDvd; i++)
	{
		if (!strcmp(dvdList[i]->ISBN, ISBN))
		{
			return dvdList[i];
			break;
		}
	}

	return (dvdInfo*)NULL;
}

int IsEnrollISBN(char * ISBN)
{
	dvdInfo * pDvd = GetDvdPtrByISBN(ISBN);

	if (pDvd == NULL)
		return 0;
	else
		return 1;
}

void AddRentInfo(char * ISBN, char * ID, int day)
{
	dvdInfo * pDvd = GetDvdPtrByISBN(ISBN);
	int numOfRentCus = pDvd->numOfRentCus;

	strcpy(pDvd->rentList[numOfRentCus].cusID, ID);
	pDvd->rentList[numOfRentCus].rentDay = day;

	pDvd->numOfRentCus++;
	pDvd->rentState = RENTED;
}

int IsRentedDvd(char * ISBN)
{
	dvdInfo * pDvd = GetDvdPtrByISBN(ISBN);

	if (pDvd->rentState == RENTED)
		return 1;
	else
		return 0;
}

void RemoveRentInfo(char * ISBN)
{
	dvdInfo * pDvd = GetDvdPtrByISBN(ISBN);
	pDvd->rentState = RETURNED;
}

dvdRentInfo * GetRentListByISBN(char * ISBN)
{
	dvdInfo * pDvd = GetDvdPtrByISBN(ISBN);
	return pDvd->rentList;
}

int GetnumOfRentCusByISBN(char * ISBN)
{
	dvdInfo * pDvd = GetDvdPtrByISBN(ISBN);
	return pDvd->numOfRentCus;
}