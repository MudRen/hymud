// Room: /u/cloud/entrance.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("coor",({2000,4000,0}));
	set("short", "�����");
        set("long",
"���������������.���������������ˮ������һ������,������ҵ�����ʢ����Ҷ��Ϊ��\n"
"�������������������Ϻ�������,��������������ϱ߼����ϴ����Ľ���������ڴ���\n"
"���ٸ��Ĺ���(sign),��֪��д��Щʲô��\n"
);

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        set("exits", ([ /* sizeof() == 2 */
		  "northwest" : __DIR__"shillfoot",
		  "south" : __DIR__"nwroad1",

	]));

       set("outdoors", "cloud");

        setup();
//        replace_program(ROOM);
}

string look_sign(object me)
{
        return "������д��:[����] �ɴ�������ȡ�ƽ�һ��\n";
}

