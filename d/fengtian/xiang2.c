// Room: /d/fengtian/xiang2.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
һ������С�����ס��ʢ���ǽ���һЩ������Ի���С��
�ܸɾ���࣬С��������������������Ի��ң���˵��������
���������˹�˰��פ�ء�
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wujia",
  "south" : __DIR__"xiang1",
]));

	set("objects",([
	"/clone/npc/man" : 3,
]));

	set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
