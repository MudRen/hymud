// Room: /d/snow/inneryard.c

inherit ROOM;

void create()
{
	set("short", "�쾮");
	set("long", @LONG
�����Ǵ�������е��쾮�������߿��Իص�����������������
�����ϱ����д����˵��᷿������һ������ͨ�������Ժ���쾮��
�������滨��ݣ���������һ��ʯ��(pillar)�������ƺ������֡�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"guestroom",
  "north" : __DIR__"nyard",
  "west" : __DIR__"schoolhall",
  "east" : __DIR__"innerhall",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "pillar" : "ʯ���Ͽ���������ָ�졢������������â���ԡ�������硣
",
]));
	set("no_clean_up", 0);
	set("outdoors", "xueting");

	setup();
	replace_program(ROOM);
}
