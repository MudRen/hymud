// Room: /d/linzhi/lin51.c

inherit ROOM;

void create()
{
	set("short", "��ԭ���");
	set("long", @LONG
�����ڸ�ԭ����ϣ���ʱ����ע���š�ֻ����಻Զ��һȺ
Ұ��ţ����������ʳ��������û��ע�⵽�㡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin49",
  "westup" : __DIR__"lin52",
]));

  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3800);
	setup();
	replace_program(ROOM);
}
