// Room: /d/xizang/linzhie.c

inherit ROOM;

void create()
{
	set("short", "��֥����");
	set("long", @LONG
����������ѽ�����֥�����ˣ�����ش��ض�����³�ز�
�����Ρ��õ������Ű��塢��������������۾ӵأ����׷���
���졣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : "/d/qingzh/xroad1",
  "west" : __DIR__"lin01",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3500);
	setup();
	replace_program(ROOM);
}
