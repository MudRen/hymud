 // Room: dong0
inherit ROOM;
#include <room.h>
void create()
{
        set("short", "����");
        set("long", @LONG
���������������ԡ�����һ������������ǰһ�Ű�����ɢ����
��ʱ�ʻ�����ɫ�ѹ����Ĵ������羵�������Ӱ��ӳ�뻭�С�
LONG
        ); 
        set("exits", ([ /* sizeof() == 4 */ 
        "eastup" : __DIR__"gu4", 
                "south" :__DIR__"goldroom",     
        ])); 
        set("objects",([
                __DIR__"npc/yinbin2" : 1,
//                      __DIR__"npc/cat1" : 1,
        ]) );
      set("coor/x",80);
        set("coor/y",10);
        set("coor/z",-20);
        setup();
      create_door("eastup","����","westdown",DOOR_CLOSED);
}  
