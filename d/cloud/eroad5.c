
// Room: /u/cloud/eroad4.c

inherit ROOM;

void create()
{
        set("short", "�賡");
        set("long",
"�����������Ĳ賡�����ʢ����Ҷ����������в��ٲ蹤��æ�Ųɲ衣\n"
);
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"eroad6",
]));

        set("objects", ([
                __DIR__"npc/worker" : 2,
        ]) );
        set("no_clean_up", 0);
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

