// Room: /d/linzhi/lin18.c

inherit ROOM;

void create()
{
	set("short", "����ش�");
	set("long", @LONG
������λ�ںӹ���������ش�������ƽ����1600�����ҡ���
ƽ̹�ش���ס���Ų��ٵ��ʷ��������ǲ�����ʱ��ס����Ҫ�ǲ�
���ػ������뿴��Ҳ�á�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin17",
  "southwest" : __DIR__"lin19",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 1600);
	setup();
	replace_program(ROOM);
}
