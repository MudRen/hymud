// Room: /d/linzhi/lin46.c

inherit ROOM;

void create()
{
	set("short", "��ԭ������");
	set("long", @LONG
������һƬ�����֣����ܶ��Ǹߴ����Ҷ�ɡ���Χʮ�ֵİ�
�����ƺ���������������ص����������治ʱ���������������
���治Զ����һƬ���֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin45",
  "south" : __DIR__"bqlml_temple",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4000);
	setup();
	replace_program(ROOM);
}
