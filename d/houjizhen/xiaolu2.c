// xiaolu2.c
// by dicky

inherit ROOM;

void create()
{
set("short", "С·");
	set("long", @LONG
��������һƬ������̦��С·�ϣ����ڳ�ʱ��û�������ߣ�·���Ե�
�ǳ��Ļ������鲻�Խ��ķ����˽Ų���С·һֱ��ǰ�����ȥ��һ������
·����������ǰ��
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([ /* sizeof() == 1 */
        "north" : __DIR__"tulu1",
        "southeast" : __DIR__"xiaolu1",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
