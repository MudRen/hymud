//Cracked by Roath
// pine_forest8.c 松林
// by Marz@XKX 11/11/96

inherit ROOM;


void create()
{
	set("short", "松林");
	set("long", @LONG
	这是松林深处，暗无天日，朦胧中只感觉到左右前后到处
都是树影。地上有一两个死人骷髅，发着绿荧荧的磷光。你惊骇之
间，一脚踩在钢针般的松针上！
LONG
	);
	
	switch(random(6)){
        case 0:
		set("objects", ([ __DIR__"obj/pine" : 3]));
		break;
	case 1:
		set("objects", ([
			__DIR__"obj/pine" : 3,
			__DIR__"obj/songguo" : 2]));
		break;
	case 2:
		set("objects", ([ __DIR__"obj/snake" : 1]));
		break;
	case 3:
		set("objects", ([
			__DIR__"obj/pine" : 2,
			__DIR__"obj/snake" : 1]));
		break;
	case 4:
		set("objects", ([ __DIR__"obj/snake" : 2]));
		break;
	case 5:
		set("objects", ([ __DIR__"obj/pine" : 2]));
		break;
	}	          	
	
	set("exits", ([
		"south" : __DIR__"pine_forest"+(7+random(3)),
		"north" : __DIR__"pine_forest"+(8+random(2)),
		"east" : __DIR__"pine_forest"+(random(8)),
		"west" : __DIR__"pine_forest"+(random(8)),
	]));
	
	set("cost", 3);
	setup();
}


void init()
{
	object me = this_player();
	
	if ( !objectp(me->query_temp("armor/boots")) )
		me->receive_damage("qi", 10);  

}

