// Room: /d/fengtian/xiang1.c

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

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"wy1",
  "east" : __DIR__"minju",
  "north" : __DIR__"xiang2",
]));

	set("outdoors", "fengtian");

	setup();
	replace_program(ROOM);
}
