// Room: /d/taiwan/huayuan.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "С��԰");
	set("long", @LONG
�����ǰ��һ��С��԰,��Ϊ�Ѿ��ܾ�û�˴�ɨ,�������ǲ�֦��Ҷ. 
��ղų�����������ɽ�Ͱ��ڻ�԰�м�,������һ��С¥. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/taiwan");
	set("exits", ([ /* sizeof() == 3 */
  "in" : __DIR__"midao2.c",
  "north" : __DIR__"xiaolou",
  "west" : __DIR__"caiyuan",
]));

	setup();
	replace_program(ROOM);
}
