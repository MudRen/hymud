 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
#include <room.h> 
inherit ROOM; 
void create() 
{ 
        set("short", "���ƹ�"); 
        set("long", @LONG 
��������Ҷ�³�����ס�ĵط���Ҷ�³���ͼ��λ�Ѿá����԰��ƳǴ����Իʹ�Ϊ 
ͼ��������Ψ�д˴���Ϊ���š�СС�ĵ����ڣ�һ����һ�Σ�һ�Զ��ѡ�ǽ��һ���� 
�������飺һ��������������ɣ�
LONG 
           ); 
        set("exits",  
           ([  
       "north" : __DIR__"changlang3",
//           "west"  : __DIR__"beach1", 
//           "east"  : __DIR__"beach2", 
            ])); 
        set("objects",  
           ([  
//       __DIR__"obj/vase" : 1,
       "/d/huanghe/yyd/npc/changcf":1,
       __DIR__"npc/master" : 1,
            ])); 
        set("indoors", "baiyun");
        set("coor/x",10); 
        set("coor/y",-2200); 
        set("coor/z",20); 
        setup(); 
        create_door("north", "ʯ��", "south", DOOR_CLOSED); 
        replace_program(ROOM); 
}     
