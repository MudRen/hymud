// Room: /d/linzhi/by11.c
// Room: /d/linzhi/by10.c

inherit ROOM;

void create()
{
	set("short", "�ӹȴ���");
	set("long", @LONG
�������׹��ӹȵĴ������ڣ�ֻ���Ĵ��Ǹ�ɽֲ���һ��
�������������졣������޷��ҵ���·������ֻ���������ˡ���
��һ���������죬���͵ػ�ͷһ����ֻ��һ����Ӱವش������
�����ˣ�������һ�������ɵüӿ��˽Ų���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"by10",
  "north" : __DIR__"by12",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 2100);
	setup();
	replace_program(ROOM);
}

