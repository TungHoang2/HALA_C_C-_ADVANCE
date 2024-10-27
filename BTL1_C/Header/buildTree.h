/*
* File: handleData.h
* Author: Tùng Hoàng
* Date: 22/10/2024
* Description: This is header file consist of declare functions and variables for handling data 
*/

#ifndef _BUILDTREE_H
#define _BUILDTREE_H

typedef struct Node
{
    struct
    {
        char *name;
        char *age;
        char *address;
        char *phNB;
    } inFo;
    struct Node *next;
} Node;

typedef struct CenterPoint
{
    struct
    {
        char *name;
        char *age;
        char *address;
        char *phNB;
    } inFo;
    struct CenterPoint *left;
    struct CenterPoint *right;
} CenterPoint;

/*
* Function: handleData
* Description: This function will process the data in the .csv file, then arrange it into nodes alphabetically based on the first letter.
* Input:
*... *head: 
*... start: index which is begin of the linked list (often equal 0)
*... end: index which is the end of the linked list (often equal length-1)

* Ouput:
*  return type struct Centerpoint that user define 
*/

CenterPoint *buildTree(Node *head, int start, int end);
CenterPoint *centerPoint(Node *head);

#endif