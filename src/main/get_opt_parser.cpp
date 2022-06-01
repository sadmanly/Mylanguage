#include<stdlib.h>
#include<stdio.h>
#include<getopt.h>
#include"get_opt_parser.h"


static void usage()
{
    printf("-i          --infile  <file_name>        parse mysql_protocol\n");
    printf("-o          --outfile  <save_file_name>    save the info of pcap_file\n");
}

int GetoptParse(ParserInfo* result,int argc,char** argv)
{
    int opt;
    int ret = 0;
    struct option opt_choose[] =
            {
                    {"server_ip",1,NULL,'s'},
                    {"client_ip",1,NULL,'c'},
            };
    while ((opt = getopt_long(argc,argv,"s:c:",opt_choose,NULL))!=-1)
    {
        switch (opt)
        {
            case 's':
                sprintf(result->server_ip,"%s",optarg);
                ret++;
                break;
            case 'c':
                sprintf(result->client_ip,"%s",optarg);
                ret++;
                break;
            default:
                usage();
                break;
        }
    }
    return ret;
}