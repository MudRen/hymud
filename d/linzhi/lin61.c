// Room: /d/linzhi/lin61.c

inherit ROOM;

void create()
{
	set("short", "��³�ز������±�");
	set("long", @LONG
��������³�ز��������±ڣ����ۿ�ȥ����ˮ�������£���
���������졣�±����������³�ز������ߣ����ﳤ�����ȴ�
�����ȴ�ֲ���˵�����Ƕ��档
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin60",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}
