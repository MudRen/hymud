// Room: /d/linzhi/lin36.c

inherit ROOM;

void create()
{
	set("short", "��ԭ���");
	set("long", @LONG
�����Ǹ�ԭ��������»���һ�ˡ�������·�ϣ���ʱ��ע��
����Χ�ı仯��һ��紵�����㲻��������Щ�����ɴ�����ȥ
��һ���š�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin35",
  "northwest" : __DIR__"lin37",
  "south" : __DIR__"lin39",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3600);
	setup();
	replace_program(ROOM);
}
