// Room: /d/linzhi/lin19.c

inherit ROOM;

void create()
{
	set("short", "��ԭ�µ�");
	set("long", @LONG
�����Ǹ�ԭ�µ�������������Ѹ�ٰθߣ������Ǻӹ�������
��ش������ߵ����������Զ��ѩɽ���ʣ�������ҫ�£�����
���׹�������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"lin18",
  "westup" : __DIR__"lin20",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3200);
	setup();
	replace_program(ROOM);
}
