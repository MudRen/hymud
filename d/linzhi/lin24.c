// Room: /d/linzhi/lin24.c

inherit ROOM;

void create()
{
	set("short", "����ɽ·");
	set("long", @LONG
�����Ǹ�ԭ����ɽ����ɽ�ҳʺ�ɫ��ɽ�屻��ɫ��ѩ���ǡ�
�����������£�ɽ��������ɫ���㿴�ſ��ţ���������Χ�澰
���������ϲ�Զ����÷��ѩɽ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"lin20",
  "northdown" : __DIR__"lin23",
  "southwest" : __DIR__"lin25",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 5400);
	setup();
	replace_program(ROOM);
}
