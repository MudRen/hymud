// Room: /d/china/junying/xiaozhen/minju2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ﲼ�õúܼ�ª��ǽ�Ϲ��ż�����Ƥ��һ�˳�ì��һ��
�������������������Դ���Ϊ���ġ�һ�������ڵ����Ѿ�����һ
Ϣ�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"minju",
]));
	set("no_clean_up", 0);
	set("objects",([
  __DIR__"npc/liehu" : 1,
]));
	setup();
	replace_program(ROOM);
}
