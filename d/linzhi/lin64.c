// Room: /d/linzhi/lin64.c

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
  "northwest" : __DIR__"lin65",
  "southeast" : __DIR__"lin55",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3600);
	setup();
	replace_program(ROOM);
}
