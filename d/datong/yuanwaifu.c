// Room: /open/dt/yuanwaifu.c

inherit ROOM;

void create()
{
	set("short", "Ա�⸮");
	set("long", @LONG
��Ա���޵ĺ�԰�����ݳ�����һ�����ĺ�԰�֣����Ǵ�������Ҳ��
��Щ������԰�ڼ�ɽˮ�ش������£�һ��һľ����߽��ģ�����ϸ΢֮
��ȴ��������ͨ��֮�С���Ŀ�������˱Ƿ��㣬��������

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hongchanglu6",
]));
        set("objects",([
       __DIR__"npc/cui" :1,

]));
	setup();
	replace_program(ROOM);
}
