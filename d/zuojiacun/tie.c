// Room: /d/zuojiacun/tie.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��һ�߽�����͸е�һ���������������������Ӣ�ܻ���
�����ڴ���ʲô������ÿ�������£��ͷ�����������������
�žͼ������Ĵ��ɽ����㲻�Ծ������Ա��������������̻�����
�����·���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lu18",
]));
  	set("objects",([
	"/d/city/npc/smith" : 1,
]));
	setup();
	replace_program(ROOM);
}
