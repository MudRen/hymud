inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
������һ����������Ĵ�ٵ��������������ݵ����ɵ�����
�����ǿ�㣬����ݵ���ʮ���ۡ�
LONG);
	set("exits", ([
		"west"  : "/d/cangzhou/sroad4",
		"east"  : __DIR__"shang_road2",
	]));
	set("outdoors", "ruzhou");
	setup();
	replace_program(ROOM);
}
