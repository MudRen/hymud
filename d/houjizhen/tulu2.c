// tulu2.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
ǰ����Ǻ���ˣ�һ����ֱ��ʯ����ͨ��ǰ����·�ϲ�ʱ����������
���ĳ����������������㷢�����ǵ��·����ȽϺ�ԭ�����￿����ɽ�Ѿ�
��Զ�ˡ�
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([
		"west" : __DIR__"paifang",
		"southeast" : __DIR__"tulu1",
	]));
	setup();
	replace_program(ROOM);
}
