// Room: /d/linzhi/lin53.c

inherit ROOM;

void create()
{
	set("short", "��ԭ���");
	set("long", @LONG
�����ڸ�ԭ����ϣ���ʱ����ע���š�ֻ����಻Զ��һȺ
Ұ��ţ����������ʳ��������û��ע�⵽�㡣�㲻�ɵüӿ���
�Ų���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin52",
  "west" : __DIR__"lin54",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}
