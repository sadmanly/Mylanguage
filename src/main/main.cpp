#include<iostream>
#include<string>

#include"private.h"
#include"json.h"
#include"get_opt_parser.h"

#define IN_FILE "./etc/my.ini"



bool init_info(ParserInfo* info)
{
    /*
        计算文件大小
    */
    FILE* configure_stmt = fopen(IN_FILE,"r+");
    fseek(configure_stmt, 0, SEEK_END);
	int total_size = ftell(configure_stmt);
	rewind(configure_stmt);
    char* buff = (char*)malloc(total_size);
  

    if(configure_stmt == NULL || buff == NULL)
        return false;

    fread(buff,total_size,1,configure_stmt);

    info->buff = buff;
    info->configure_stmt = configure_stmt;
    info->buff_size = total_size;
    return true;
}

void get_string_info_jsion(char* string_str,cJSON* key)
{
    if(key && key->valuestring && string_str[0] == 0)
    {
        sprintf(string_str,"%s",key->valuestring);
    }
}

bool parser_configure_file(ParserInfo* info)
{
    cJSON* cjson_server_ip = NULL;
    cJSON* cjson_client_ip = NULL;
    cJSON* cjson_info = NULL;
    char*  buff = NULL;

    if(init_info(info))
    {
        buff = info->buff;
        cjson_info = cJSON_Parse(buff);
        cjson_server_ip = cJSON_GetObjectItem(cjson_info,"server_ip");
        cjson_client_ip = cJSON_GetObjectItem(cjson_info,"client_ip");

        get_string_info_jsion(info->server_ip,cjson_server_ip);
        get_string_info_jsion(info->client_ip,cjson_client_ip);
    }
    return true;
}

void free_parserinfo(ParserInfo* info)
{
    if(info->buff && info->buff_size > 0)
    {
        free(info->buff);
        info->buff = NULL;
        info->buff_size = 0;
    }
}

void init_parser_info(ParserInfo* info)
{
    info->buff = NULL;
    info->buff_size = 0;
    info->configure_stmt = NULL;
    info->server_ip[0] = 0;
    info->client_ip[0] = 0;
}

int main(int argc,char** argv)
{
    ParserInfo info; 
    init_parser_info(&info);

    if(GetoptParse(&info,argc,argv) != 2)
    {
        parser_configure_file(&info);
    }
    
    printf("%s\n%s\n",(info.client_ip[0] != 0)?info.client_ip:"NULL",(info.server_ip[0] != 0)?info.server_ip:"NULL");

    free_parserinfo(&info);
    return 0;
}
