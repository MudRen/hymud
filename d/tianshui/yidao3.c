// Room: /u/xiaozhen/yidao3.c

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
  "northeast" : __DIR__"yidao4",
  "south" : __DIR__"yidao2",
]));
	set("no_clean_up", 0);
	set("outdoors","tianshui");
	setup();
	replace_program(ROOM);
}
