// Room: /d/linzhi/lin23.c

inherit ROOM;

void create()
{
	set("short", "��ԭ����ɽ��");
	set("long", @LONG
�����Ǹ�ԭ����ɽ����ɽ�ҳʺ�ɫ��ɽ�屻��ɫ��ѩ���ǡ�
�����������£�ɽ��������ɫ���㿴�ſ��ţ���������Χ�澰
��������Ϣһ�°ɡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin22",
  "southup" : __DIR__"lin24",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}
