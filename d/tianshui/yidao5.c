// Room: /u/xiaozhen/yidao5.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������Ĵ������·�����������������ӵġ���
�̵ġ����Ŵ󳵵�������ﲻ����·�߻���һЩС�̷��ڽ�����
�ǳ����֡���ʱ�������������߷ɳ۶���������һ·��������
������ˮ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"skou",
  "south" : __DIR__"yidao4",
]));
	set("no_clean_up", 0);
	set("outdoors","tianshui");
	setup();
	replace_program(ROOM);
}
