// Room: /d/linzhi/lin48.c

inherit ROOM;

void create()
{
	set("short", "��ԭƽ�²��");
	set("long", @LONG
�����Ǹ�ԭ�²����·��ʮ��ƽ����������·�ϣ���������
���죬�װ׵��ƣ�����ʮ��Ͼ�ݡ�Զ��һȺ��֪ʲô����������
�س��Ųݣ���ʱ��������Ľ�������ȥ��Զ���ǰ�һ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"byw",
  "northwest" : __DIR__"lin49",
  "southeast" : __DIR__"lin47",
  "south" : __DIR__"lin69",	
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3500);
	setup();
	replace_program(ROOM);
}
