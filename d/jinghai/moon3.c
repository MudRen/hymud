// Room: /d/jinghai/moon3.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
������һƬï�ܵ������һ�ÿô�����ֱ��������ָ����
��������ïʢ�������������, ��ס�����⣬�Ե����й��߻谵
����ʱ����С�񾪷ɶ�ȥ������һ��ͨ��ɽ�ԵĶ���С·����
�������ת�������𽥿�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"moon2",
  "south" : __DIR__"moon4",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
