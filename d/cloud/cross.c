
// Room: /u/cloud/square.c

inherit ROOM;

void create()
{
        set("coor",({2100,3800,0}));
	set("short", "ʮ��·��");
        set("long",
"������������ʯ·�����ｻ�棬·�����ſùŻ������������Ӻϱ���ô�֡��������и���\n"
"ʾ�����ǹٸ����ġ�\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wroad2",
  "north" : __DIR__"nroad2",
  "south" : __DIR__"sroad1",
  "east" : __DIR__"eroad1",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

