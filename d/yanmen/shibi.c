// Create by lonely@NT
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ʯ��"NOR);
        set("long",
"����쵽�����Ρ���Ӫפ�����ˣ�ԶԶ�ؿ��Կ�����Ӫ�ڷ���ĳ���\n"
"����ʱ�м�ƥ����ɱ��������������ٿ�����Ȼವ�һö�������ͷ�Ϸ�\n"
"�������ǸϿ��뿪�ĺá�\n"
);

        set("no_fly", "1");
        set("exits", ([ /* sizeof() == 5 */   
               "south" :   __DIR__"canyon2",
               "north" :   __DIR__"luanshi8",
        ]));    

        set("objects", ([

        ]));
    
        setup();
        replace_program(ROOM);
}

