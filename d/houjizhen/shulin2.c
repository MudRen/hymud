// shulin2.c
// by dicky

inherit ROOM;

void create()
{
    set("short", "�����");
    set("long", @LONG
�������ֵ�������о����ĵģ�ż������Ұ�޵ĺ���������������
������ï�ܵ������š���Ҷ�ķ�϶��ż������һֻС�񱻾������ܿ�
�����߼ʡ�����ʱ���ж��߳�û����ò�Ҫ�ڴ˾�����
LONG
);
	set("outdoors", "houjizhen");

	set("exits", ([
            "west" : __DIR__"shulin3",
	    "northwest": __DIR__"shulin4",
	    "east" : __DIR__"shulin1",
          ]));

	set("objects",([
		__DIR__"npc/snake" : 1,
	]));

	setup();
	replace_program(ROOM);
}   