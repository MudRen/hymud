// Room: /d/taiwan/caiyuan.c

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
һ�����˾�ס�ķ���,����ֻ��һ��С��,����ĵط������˸����� 
��,�������ֶ������ڷŵ���������,���������Ǹ���������. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"huayuan",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"obj/huajian.c" : 1,
  __DIR__"obj/penghu.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
