// Room: /d/linzhi/lin47.c

inherit ROOM;

void create()
{
	set("short", "��ԭƽ�µ�");
	set("long", @LONG
�����Ǹ�ԭƽ�µ���·��ʮ��ƽ����������·�ϣ���������
���죬�װ׵��ƣ�����ʮ��Ͼ�ݡ�Զ��һȺ��֪ʲô����������
�س��Ųݣ���ʱ��������Ľ�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"lin48",
  "southeast" : __DIR__"lin44",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}
