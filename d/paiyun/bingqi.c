// Room: /d/paiyun/bingqi.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�����ʯ�ң���ǽ�ڷŵ���һ���ŵı����ܣ�����
�Ͽտ���Ҳ���������ܵ�����������ɽկ��һֻ��С��������
����
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lu4",
]));

	setup();
	replace_program(ROOM);
}
