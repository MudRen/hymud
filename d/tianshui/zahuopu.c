// Room: /u/xiaozhen/zahuopu.c

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����һ��СС���ӻ��̣����ڵش�������Ľ��紦�����⵽
����¡������С�����һ�أ����ֻ���Ӧ�о��С������ϰ���Ե
�ܺã�����׿����СС�ĵ��̾������������ļ�ɢ�ء��ƹ��
�����������һֻ�����ϣ�С����к��������Ŀ��ˡ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"eroad3",
]));
	set("no_clean_up", 0);
	set("objects",([
	__DIR__"npc/seller" : 1
]));
	setup();
	replace_program(ROOM);
}
