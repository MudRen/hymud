#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���Ź�"NOR);
        set("long",
"������ǡ����Ρ���Ӫ�ˣ�һ�����߸�������������һ�������\n"
"���顸�Ρ��֣�ǰ�治Զ�����ξ�Ԫ˧����Ӫ�ˡ�����פ�ص��ξ���Ϊ��\n"
"��ֹ�ɹ��������ֵĹؼ����ϣ�һ�����ﱻ�������ƣ���ô���ξ��᧿�\n"
"Σ�ˣ�\n"
);

        set("no_fly", "1");
        set("exits", ([ /* sizeof() == 5 */
              "south" :   "/d/guanwai/laolongtou",
               "north" :   __DIR__"shance",
        ]));
        set("objects", ([
            "d/city/npc/wujiang" : 1,
            "d/city/npc/bing" : 5,
	]));


        setup();
        replace_program(ROOM);
}


