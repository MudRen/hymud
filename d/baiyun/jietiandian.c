 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
#include <room.h> 
inherit ROOM; 
void create() 
{ 
        set("short", "����¥");
        set("long", @LONG 
Σ�����գ��������������֮�ߣ�Ҷ�³��Ļ����£���־�г�һ����¹��ԭ����
��¥�ش����Ƶ����֮�����·�һ���������Ƴ���ңָ��ԭ���ݡ�¥�ϱ������һ
����̨�Ϻ������ɵ������汱ӭ�硣
LONG 
           ); 
        set("exits",  
           ([  
       "north" : __DIR__"yuequedian",
       "south" : __DIR__"changlang",
            ])); 
        set("objects",  
           ([  
              __DIR__"npc/jiankuang" : 1,
            ])); 
       set("indoors", "baiyun");
        set("coor/x",10); 
        set("coor/y",-2000); 
        set("coor/z",20); 
        setup(); 
        create_door("south", "ʯ��", "north", DOOR_CLOSED); 
        replace_program(ROOM); 
}  
