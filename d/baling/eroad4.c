

inherit ROOM;


void create()
{
	set("short", "城口县");
	set("long", @LONG
这是一条官路。人来人往。挑担子的行商，赶着大车的马夫，熙熙
攘攘，非常热闹。不时还有两三骑快马从身边飞驰而过，扬起一路尘埃
。向东则是通往涪陵县的官道。
LONG
	);
	
	set("exits", ([
                "northwest" : __DIR__"eroad3",
                "east" : __DIR__"eroad5",
	]));
    
	set("outdoors", "qiuci");
	setup();
	replace_program(ROOM);
}
