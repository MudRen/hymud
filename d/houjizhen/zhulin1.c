// zhulin1.c
//by dicky

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
���ܶ������ܵ����֣�һ̤�������������·�������˼�������
Ω����̤��ƺ֮����ż����΢�������Ҷ�������������������˳�
��Ϊ֮һ�ӣ����Ǿ��ѵ��������ڡ�
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([
		"southdown" :  __DIR__"xiaoxi",
		"north" : __DIR__"zhulin2",
	]));

	setup();
	replace_program(ROOM);
}
