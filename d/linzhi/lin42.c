// Room: /d/linzhi/lin42.c
// Room: /d/linzhi/lin41.c

inherit ROOM;

void create()
{
	set("short", "��ԭ��·����");
	set("long", @LONG
�����ǲ���Ψһ��һƬƻ���������������ƻ��ʮ��������
���д��࣬��ڸ���ÿ����·�ʱ�����ٲ��񶼴��żһ�����
���ժƻ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin41",
  "south" : __DIR__"lin45",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4000);
	setup();
	replace_program(ROOM);
}


