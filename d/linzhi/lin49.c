// Room: /d/linzhi/lin49.c

inherit ROOM;

void create()
{
	set("short", "��ԭ���");
	set("long", @LONG
�����Ǹ�ԭƽ�����·��ʮ��ƽ����������·�ϣ���������
���죬�װ׵��ƣ�����ʮ��Ͼ�ݡ�Զ��һȺ��֪ʲô����������
�س��Ųݣ���ʱ��������Ľ��������������Ȫ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lin51",
  "north" : __DIR__"lin50",
  "southeast" : __DIR__"lin48",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3800);
	setup();
	replace_program(ROOM);
}
