
// jiyuan2.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2050,3950,5}));
	set("short", "��������¥");
	set("long",
"���ǲ�¥�Ķ��㣬����������ī�ͳ�ϲ���ڴ�Ʒ�����������װ��Ÿ����̡�\n"
);
        set("exits", ([
                "down"  : __DIR__"tearoom" ]) );

	set("objects", ([
                __DIR__"npc/chess_player" : 1,
	]) );

        setup();

}


