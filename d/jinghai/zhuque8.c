// Room: /d/jinghai/zhuque8.c

inherit ROOM;

void create()
{
	set("short", "���᷿");
	set("long", @LONG
���ǿ����Ե��᷿�����ڸɾ����࣬�����˾�������ɨ��ǽ
�Ϲ��ż����ֻ���һ����̵ĵ������ݽǳг��Ϲ��ŵĻ�����ֱ
׺�����ϣ���������Щ�����ˣ����˲����������档
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"zhuque6",
  "west" : __DIR__"zhuque9",
]));

	setup();
	replace_program(ROOM);
}
