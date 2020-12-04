// Room: /d/taiwan/zhuanyuan.c

inherit ROOM;

void create()
{
	set("short", "ׯ������");
	set("long", @LONG
�����ǰ��һ���ڳ����Ĵ�����,�ߴ��������ϡ������ǰ�ĻԻ�. 
���ȴ����Ѿ��Ե�ʮ������,�ڷ��з���֨֨������.ǽ�������³��� 
��é��,���Ʈ��. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/taiwan");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"chitang",
  "south" : __DIR__"tree8",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/shizi.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
