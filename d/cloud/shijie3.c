
// Room: /u/cloud/shijie3.c

inherit ROOM;

void create()
{
        set("coor",({4100,-1000,0}));
	set("short", "��ʯ��·");
        set("long",
"��������һ����ʯ���̳ɵ���С����,�߽�һƬ��ͩ��,��ʱ����������ࡣ������������\n"
"�������߾�Ȼ��һ����ͤ��\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"shijie4",
  "west" : __DIR__"zhuting",
  "south" : __DIR__"shijie2",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

