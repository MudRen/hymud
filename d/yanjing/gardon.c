// Room: /d/yanjing/gardon
inherit ROOM;

void create()
{
  set ("short", "СԺ��");
  set ("long", @LONG
�ƹ�һ�����飬��ǰ�����������߰�ǽ��С�ݡ�����Ѱ�����°���
�ľ��ݣ�����������ݸ���������֮�м���.������Χ���������,����
Щ�߲�,�Աߵ�һ��ˮ�������Ǽ�ˮ�����õ�.
LONG);

  set("outdoors", "yanjing");
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"gardon1",
  "west" : __DIR__"inroom",
]));

	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kanshou.c" : 2,
]));
  setup();
  //replace_program(ROOM);
}
int valid_leave(object me,string dir)
{
	object npc;

	npc=present("kan shou",this_object());
	if(dir=="west" && objectp(npc) && living(npc))
	return notify_fail("���س���һ����ŭ���������ѵģ���ʲô��ɣ�\n");
	return ::valid_leave(me,dir);
}
