// Room: /d/linzhi/by10.c

inherit ROOM;

void create()
{
	set("short", "���ȴ�����");
	set("long", @LONG
�������׹��ӹ��ڵĴ����������ﶬ���Ϻ����޿������
ʮ�����ˡ�������Ƭ���־͵��׹����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"by09",
  "north" : __DIR__"by11",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 2100);
	setup();
	replace_program(ROOM);
}
