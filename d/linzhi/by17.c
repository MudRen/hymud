// Room: /d/linzhi/by17.c

inherit ROOM;

void create()
{
	set("short", "С��ʯ��");
	set("long", @LONG
������С��ʯ���ϣ�ֻ��һȺС�������ڽֱ�׷��׷ȥ����
ʱ����ϷЦ���������㿴����Щ���洿�ӵĲ���С��������ʮ��
��Ľ������һ�����ʷ����ǲ���ס�ĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"house04",
  "west" : __DIR__"byw",
  "east" : __DIR__"by16",
]));
        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
