#pragma once


typedef struct ParserInfo{
    char*  buff;
    int    buff_size;
    FILE* configure_stmt;
    char  server_ip[50];
    char  client_ip[50];
}ParserInfo;