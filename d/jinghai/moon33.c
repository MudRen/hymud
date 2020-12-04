// Room: /d/jinghai/moon33.c

inherit ROOM;

void create()
{
	set("short", "地字号牢房");
	set("long", @LONG
这里是一间阴暗潮湿的小石室，只有一盏小油灯高悬在石壁
上方。里面空空如也，只有几张破草席铺在地上。屋里潮湿的四
壁生了青苔。屋子顶端悬挂这一条很粗大的铁链，看来这里是牢
房了。估计，这里关得不是重犯就是疯子。门口上挂一个小木牌
上面写着 [地]。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"moon31",
]));
        set("objects",([
//        __DIR__"npc/qiufan1" : 1,
]));



	setup();
	replace_program(ROOM);
}
