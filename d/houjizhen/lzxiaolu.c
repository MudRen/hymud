// lzxiaolu.c
// by dicky

inherit ROOM;

void create()
{
    set("short", "林中小路");
	set("long", @LONG
小路两边的灌木越来越多，路面上的荆棘不时的把你的手脚划破，一些长
草中常常倏的蹿出一条毒蛇，让你心惊胆颤。
LONG	);

	set("outdoors", "houjizhen");

	set("exits", ([ 
                 "east" : __DIR__"shigang",
                 "northwest" : __DIR__"songlin1",
])); 

	  setup();
           replace_program(ROOM);
}

