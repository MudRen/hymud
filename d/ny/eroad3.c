
// Room: /d/snow/eroad3.c

inherit ROOM;

void create()
{
        set("coor",({1400,4900,10}));
	set("short", "ɽ·");
        set("long",
"����һ��˵����˵խ��Ҳ��խ��ɽ·��·���ü���������̦�Ĵ�ʯ�̳ɣ�������һ����\n"
"�أ�������������������м��䷿�ݴ�������ľ�䣬��������ɽ�ڣ�ɽ·�������ν�һ����\n"
"��С��,������һƬ���֡�\n"
);
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"eroad2",
]));
        set("outdoors", "ny");

        setup();
        replace_program(ROOM);
}
