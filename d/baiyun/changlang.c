//Created by justdoit at May 2001
//All Rights Reserved ^_^ 

#include <room.h> 
inherit ROOM; 
void create() 
{ 
        set("short", "��");
        set("long", @LONG 
����¥�������ڣ�˭Ҳ�޷��������֮�о�Ȼ�����һ����ֱ���ĳ���������
�Ե��Ų���ĳ����ƣ������䲻��������Ҳ�ɱ��·���ƺ���������ɽ������Ȼ��Ѩ
������ɣ��˹����䴦������խ����ʱȴ��Ȼ������ֻ�����н��ͣ����г�������ˮ
֮��������������ö��������������ǰ���ƺ���Щ��ƹ����������
LONG 
           ); 
        set("exits",  
           ([  
       "north" : __DIR__"jietiandian",
       "south" : __DIR__"changlang2",
            ])); 
        set("objects",  
           ([  
            ])); 
       set("indoors", "baiyun");
        set("coor/x",10); 
        set("coor/y",-2020); 
        set("coor/z",20); 
        setup(); 
        create_door("north", "ʯ��", "south", DOOR_CLOSED); 
        replace_program(ROOM); 
}      
