// Room: /d/linzhi/lin66.c

inherit ROOM;

void create()
{
	set("short", "��ԭ����");
	set("long", @LONG
�����Ǹ�ԭ���£�������Ȼ�ܸߣ��������Ѳ��Ǻܶ�������
���ܾ�û�߹����������·�ˣ������Ż��˽Ų���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"lin67",
  "southeast" : __DIR__"lin65",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3400);
	setup();
	replace_program(ROOM);
}
