
inherit ROOM;

void create()
{
        set("short", "���· ");
        set("long", @LONG
·�������ɽ��������ɽ����չ��������Ũ��֮��������һ
������ɫ����壬ֱ�������������м�ͷ��ӥ�ڵ͵͵��������裬
�·����˵��������
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"palace_path2",
  "west" : __DIR__"work",
]));
        set("outdoors","xueting");

        setup();
        replace_program(ROOM);
}

