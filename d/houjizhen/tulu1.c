// tulu1.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
������һ����·�ϣ�ż��������������ҴҶ�������ó������������
�����볤����Զ�ˣ���������������һ�ᣬ�Ϳ��Խ��������������Ե�
����ļž���
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([
		"northwest" : __DIR__"tulu2",
		"south" : __DIR__"xiaolu2",
	]));
	setup();
	replace_program(ROOM);
}
