// Room: /d/fengtian/wujia.c

inherit ROOM;

void create()
{
	set("short", "�Ի����");
	set("long", @LONG
�����Ի�����ң�������һ�����о�����Ի�����ζ�����
��ɽ�����Ҵ�����Ϊ�˾ȶ��ӻ����������������˹�˰��פ
�ء�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xiang2",
]));

	set("objects",([
	__DIR__"npc/wuqian" : 1,
]));

	setup();
	replace_program(ROOM);
}
