// Room: /d/linzhi/lin52.c

inherit ROOM;

void create()
{
	set("short", "��ԭ���");
	set("long", @LONG
�����ڸ�ԭ����ϣ���ʱ����ע���š�ֻ����಻Զ��һȺ
Ұ��ţ����������ʳ��������û��ע�⵽�㡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"lin51",
  "west" : __DIR__"lin53",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}
