// Room: /d/linzhi/lin54.c

inherit ROOM;

void create()
{
	set("short", "��ԭ���");
	set("long", @LONG
�����ڸ�ԭ����ϣ���ʱ����ע���š�ֻ����಻Զ��һȺ
Ұ��ţ����������ʳ��������û��ע�⵽�㡣�㲻�ɵüӿ���
�Ų���������ȥ���������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin53",
  "west" : __DIR__"lin55",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4300);
	setup();
	replace_program(ROOM);
}
