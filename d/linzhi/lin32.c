// Room: /d/linzhi/lin32.c

inherit ROOM;

void create()
{
	set("short", "���������Ŷ�");
	set("long", @LONG
���������������Ŷ��棬������ȥ�������ˡ���˵�����Ѿ�
��300 ������ʷ�ˡ������������ʹ�״���գ������³�ز�����
��Լ400 �����ҡ�����û�нϸߵĵ�����ƽ��ļ��ɺ���˳����
����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin31",
  "west" : __DIR__"lin33",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));

        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3400);
	setup();
	replace_program(ROOM);
}
