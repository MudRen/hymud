// Room: /d/linzhi/by02.c

inherit ROOM;

void create()
{
	set("short", "��б��");
	set("long", @LONG
�����ǰ�һ����б�֣��ֵ�������һ���ʷ�������ȥ����
���ز����ס�������������ţ���Ȼ���ý���һ������ͷһ����
ԭ���ǲ�������൰�ϣ��㰵������һ�䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"by01",
  "northwest" : __DIR__"by03",
  "south" : __DIR__"house01",
]));
        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
