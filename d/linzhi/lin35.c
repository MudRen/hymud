// Room: /d/linzhi/lin35.c

inherit ROOM;

void create()
{
	set("short", "������������");
	set("long", @LONG
�������������������棬����ȥ�������ˡ���˵�����Ѿ�
��300 ������ʷ�ˡ������������ʹ�״���գ������³�ز�����
��Լ400 �����ҡ�����û�нϸߵĵ�����ƽ��ļ��ɺ���˳����
����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin34",
  "west" : __DIR__"lin36",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3500);
	setup();
	replace_program(ROOM);
}
