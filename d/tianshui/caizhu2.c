// Room: /u/xiaozhen/caizhu2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������Ǻ�ҵ������ˣ����ֹ���������Ŀ��������ͭ����
ש����Ӧ�о��У�û�뵽һ��С�����ϵĲ����һ���ô���С���
�������������е������ϣ������ĵغ��Ų�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"caizhu1",
  "south" : __DIR__"caizhu3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
