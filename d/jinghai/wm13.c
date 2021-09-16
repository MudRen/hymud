// Room: /d/jinghai/wm13.c

inherit ROOM;

void create()
{
	set("short", "水寨敌楼");
	set("long", @LONG
这里是无名堡水寨的最高点，处身其上，居高临下，远近景
物尽收眼底，堡外村房楼舍，海上船只往来历历在目。无名堡内
外每个制高点都有靖海派的岗哨，他们利用硝火，将得到的讯息
传回无名堡内。敌楼的下面是水寨大门。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"wm11",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
