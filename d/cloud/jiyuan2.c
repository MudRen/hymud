
// jiyuan2.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2150,4220,5}));
	set("short", "����Ժ��¥");
	set("long",
"��������Ժ�Ĺ����������������Ʒ������ʫ�����ĵط����������š�\n"
);
        set("exits", ([
                "down"  : __DIR__"jiyuan" ]) );

	set("objects", ([
                __DIR__"npc/girl" : 1,
	]) );

        setup();

}


