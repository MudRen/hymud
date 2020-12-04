// Room: /d/jinghai/moon4.c

inherit ROOM;

void create()
{
	set("short", "山寨门前的空地");
	set("long", @LONG
这里是一大块人为开出空地。空空旷旷什么都没有。向南是
一个山寨大门, 圆木围墙一直连绵至山冈处。大门敞开，两旁分
列这一队头带红头巾手持钢刀的兵勇，他们面无表情的笔直的站
立在那里。向北又一条土路延伸至山冈尽头。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"moon3",
  "south" : __DIR__"moon5",
]));
/*
        set( "GATE_ROOM",1 );
        set( "gate_dir",(["south" : __DIR__"moon5"]) );

        set( "close_look",@LONG
这里是明月水寨门外。正北面是一条林中小路静悄悄的向远
处延伸，望向南边不远处就是明月水寨寨门。这时，天色已晚，
庄门已经关上了。
LONG
);

        set( "gate_name","明月水寨寨门" );
*/
        set("outdoors","jinghai");


	setup();
	replace_program(ROOM);
}
