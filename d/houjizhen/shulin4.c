// shulin4.c
// by dicky

inherit ROOM;

void create()
{
    set("short", "�����");
    set("long", @LONG
����һƬï�ܵ����֡��ܶ�ü�ʮ�ɸߵĴ�������һ�飬��һ�Ѱ�����
��ɡ�������¶����ڱεð�Ȼ�޹⡣�����л���ʱ������������Ȼ���������졣
LONG
);
	set("outdoors", "houjizhen");

	set("exits", ([
	    "southeast": __DIR__"shulin2",

          ]));

	set("objects",([
		__DIR__"npc/tufei" : 2,
		__DIR__"npc/tufei1" : 1,
	]));

	setup();
	replace_program(ROOM);
}   