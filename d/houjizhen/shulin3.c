// shulin3.c
// by dicky

inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
����һƬ���֣����о����ĵģ�����������䣬ң��ͺ�����Ϊ���
�������������˼������ء����ֵ�������һƬ�صأ����˼ɵ���ȥ������
һ����������������
LONG
);
	set("outdoors", "houjizhen");

	set("exits", ([
            "west" : __DIR__"shangang",
	    "east" : __DIR__"shulin2",
          ]));

	setup();
	replace_program(ROOM);
}   