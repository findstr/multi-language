/**
=========================================================================
 Author: findstr
 Email: findstr@sina.com
 File Name: main.c
 Description: (C)  2015-04  findstr
   
 Edit History: 
   2015-04-06    File created.
=========================================================================
**/
#include <stdio.h>
#include "multi-lan.h"

int main(int argc, char **argv)
{
        if (argc != 2) {
                printf("<USAGE>: <test> <en>/<cn>");
                return 0;
        }

        multi_lan_init(argv[1]);

        printf("translate string is:%s\n", multi_lan_get("lan_hello"));

        multi_lan_exit();
}
