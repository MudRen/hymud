// Room: /d/jinghai/zhuque6.c

inherit ROOM;

void create()
{
	set("short", "ǰԺ��԰");
	set("long", @LONG
���������Ժ����˱ǵ��������㾫��һˬ������Ŀ�Ĺ�
�����۴����ǲ�֪���Ĵش��ʻ����컨��֦����֮�䣬����С·
���򻨴���������Ǿ�����ȸ�õĻ�԰������Ϊ���������߱�
����飬�������԰ɷ�Ƿ���һ�����ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"zhuque8",
  "north" : __DIR__"zhuque4",
  "southwest" : __DIR__"zhuque7",
]));
        set("objects",([
       __DIR__"npc/guan6" : 1,
       __DIR__"npc/yong4" : 1,
]));


	setup();

}
