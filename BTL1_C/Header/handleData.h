/*
* File: handleData.h
* Author: Tùng Hoàng
* Date: 22/10/2024
* Description: This is header file consist of declare functions and variables for handling data 
*/
#include "../Header/buildTree.h"


#ifndef _HANDLEDATA_H
#define _HANDLEDATA_H


/*
* Function: handleData
* Description: This function will process the data in the .csv file, then arrange it into nodes alphabetically based on the first name's letter.
* Input:
*... head: A double pointer pointing to the first node of the linked list. The function will directly modify this list.

* Output:
*  return none
*/

void handleData(Node **head);
#endif