// Room: /d/linzhi/lin28.c

inherit ROOM;

void create()
{
	set("short", "������ɽ��ƽ��");
	set("long", @LONG
������������ɽ���ϲ�ƽ�£����ﺣ����4200�����ң�����
���ƽ̹��һ������ӭ��������ͷҲ��̧����������������̧
ͷ��ȥ��ֻ�������м�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin27",
  "south" : __DIR__"rqb_temple",
]));

  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/man" : 2,
  __DIR__"npc/lama" : 1,
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}
