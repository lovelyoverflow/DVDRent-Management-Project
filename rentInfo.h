/* Name: rentInfo.h  ver 1.0
 * Content: 영화 DVD 대여 정보 구조체
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#ifndef __RENTINFO_H__
#define __RENTINFO_H__

#include "dvdInfo.h"
#include "cusInfo.h"

typedef struct __dvdRentInfo 
{
    char cusID[ID_LEN];    // 대여 고객 ID
    char ISBN[ISBN_LEN];
    unsigned int rentDay;    // 대여일
} dvdRentInfo;

#endif
/* end of file */