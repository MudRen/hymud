// Room: /u/xiaozhen/yidao4.c

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
  "north" : __DIR__"yidao5",
  "southwest" : __DIR__"yidao3",
]));
	set("no_clean_up", 0);
	set("outdoors","tianshui");
	setup();
	replace_program(ROOM);
}
