
// Room: /u/cloud/nroad1.c

inherit ROOM;

void create()
{
        set("short", "���г��㳡");
        set("long",
"�����������Ķ��г��㳡���㳡�����в����ˡ�\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"nroad1",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

