
// Room: /u/cloud/wroad2.c

inherit ROOM;

void create()
{
        set("coor",({2050,3800,0}));
	set("short", "�����ֵ�");
        set("long",
"������������������߾���ʮ��·�ڡ������Ժ�����������֣������кܶ��˵����ӡ�����\n"
"���ӻ��̣������Ų���������򿪡�\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wroad1",
  "south" : __DIR__"monky",
  "east" : __DIR__"cross",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

