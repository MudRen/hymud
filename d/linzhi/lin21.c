// Room: /d/linzhi/lin21.c

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
  "east" : __DIR__"lin16",
  "westup" : __DIR__"lin22",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 1600);
	setup();
	replace_program(ROOM);
}
