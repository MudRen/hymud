// Room: /d/lumaji/lu7.c

inherit ROOM;

void create()
{
	set("short", "��ʯС��");
	set("long", @LONG
���������볤������Զ������һ��Ψһ�����У�����·�ϵ���
�˺ܶ࣬����඼���Ǳ����ˡ�·��������һ�ҿ�ջ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"kezhan",
  "south" : __DIR__"lu8",
  "north" : __DIR__"lu6",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
