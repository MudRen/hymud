// Room: /d/linzhi/lin39.c

inherit ROOM;

void create()
{
	set("short", "��ԭ���");
	set("long", @LONG
�����Ǹ�ԭ��������»���һ�ˡ�������·�ϣ���ʱ��ע��
����Χ�ı仯��һ��紵�����㲻��������Щ�������治ʱ����
������ˮ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin36",
  "east" : __DIR__"lin40",
  "south" : __DIR__"lin41",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3800);
	setup();
	replace_program(ROOM);
}
