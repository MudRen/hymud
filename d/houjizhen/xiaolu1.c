// xiaolu1.c
// by dicky

inherit ROOM;

void create()
{
set("short", "С·");
	set("long", @LONG
��������һƬ������̦��С·�ϣ����ڳ�ʱ��û�������ߣ�·���Ե�
�ǳ��Ļ������鲻�Խ��ķ����˽Ų���С·һֱ��ǰ�����ȥ����������
ͷ������һƬ�ž���
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([ /* sizeof() == 1 */
        "northwest" : __DIR__"xiaolu2",
        "south" : __DIR__"zhulin3",
]));

	set("objects",([
		__DIR__"npc/dadao" : 1,
	]));

	setup();
	replace_program(ROOM);
}
