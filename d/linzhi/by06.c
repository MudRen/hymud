// Room: /d/linzhi/by06.c

inherit ROOM;

void create()
{
	set("short", "���л���ʯ·");
	set("long", @LONG
�����ڻ���ʯ·�ϣ���ʱע�������ܵ������·������һ��
���ʷ��������Ӷ��ǲ����ס��������С��������·��Ϸˣ����
�������������������Ц��Ц��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"by05",
  "west" : __DIR__"house02",
  "north" : __DIR__"by07",
]));
        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
