// Room: /u/xiaozhen/yidao1.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������Ĵ������·�����������������ӵġ���
�̵ġ����Ŵ󳵵�������ﲻ����·�߻���һЩС�̷��ڽ�����
�ǳ����֡���ʱ�������������߷ɳ۶���������һ·��������
������ˮ������һֱ�߾��Ǳ߹ش�Ӫ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yidao2",
  "south" : "/d/huanghe/tumenzi",
]));

        set("objects",([
        __DIR__"npc/scholar" :1,
]));
	set("outdoors","tianshui");
	setup();
	replace_program(ROOM);
}
