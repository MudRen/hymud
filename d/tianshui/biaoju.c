// Room: /u/xiaozhen/biaoju.c

inherit ROOM;

void create()
{
	set("short", "�����ھ�");
	set("long", @LONG
�����������������������ھ��ˣ�����ʯ̳�ϸ�����һ��
���ɶ�ߵ���ˣ������������ý�������̫��������������������
��������һֻ�ͻ��������������š������ھ֡��ĸ��վ�������
���֡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"biaoju2",
  "south" : __DIR__"eroad2",
]));
	set("objects",([
	__DIR__"npc/bfighter.c" : 1,
	__DIR__"npc/bfighter1.c" : 2,
]));
	setup();
	replace_program(ROOM);
}
