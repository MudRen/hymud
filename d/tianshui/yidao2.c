// Room: /u/xiaozhen/yidao2.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������Ĵ������·�����������������ӵġ���
�̵ġ����Ŵ󳵵�������ﲻ����·�߻���һЩС�̷��ڽ�����
�ǳ����֡���ʱ�������������߷ɳ۶���������һ·��������
������ˮ������һֱ�߾��Ǳ߹ش�Ӫ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yidao3",
  "south" : __DIR__"yidao1",
]));
	set("no_clean_up", 0);
	set("outdoors","tianshui");
	set("objects",([
	__DIR__"npc/fruit_seller" : 1,
]));
	setup();
	replace_program(ROOM);
}
