//sgzl
inherit ROOM;

void create ()
{
	set ("short", "ѩ·");
	set ("long", @LONG

ǰ���·����ȫ�����������ѩ֮�У�ѩ�µ�һ�����ˣ�
����ﻬ����·������춱��ϣ�����̤һ���գ��Ʊص�
����������е��÷�����ǡ�
LONG);


	set("exits", 
	([ //sizeof() == 4
		"southdown" : __DIR__"binggu",
		"northup" : __DIR__"xuelu2",
	]));
	


	set("outdoors", "xueshan");

	setup();
}



