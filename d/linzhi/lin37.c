// Room: /d/linzhi/lin37.c

inherit ROOM;

void create()
{
	set("short", "���˹�");
	set("long", @LONG
���������ֻ�ŵ����ǻ�����ˮ����ԭ�����������ˮ��
���ٲ��������ļ��˹��ˡ������������ˮ�����ٲ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"lin43",
  "west" : __DIR__"lin38",
  "southeast" : __DIR__"lin36",
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
