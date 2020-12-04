// shulin4.c
// by dicky

inherit ROOM;

void create()
{
    set("short", "树林深处");
    set("long", @LONG
这是一片茂密的树林。很多棵几十丈高的大树聚在一块，象一把把琼天
大伞，连日月都被遮蔽得暗然无光。树林中还不时可以听到大自然发出的声响。
LONG
);
	set("outdoors", "houjizhen");

	set("exits", ([
	    "southeast": __DIR__"shulin2",

          ]));

	set("objects",([
		__DIR__"npc/tufei" : 2,
		__DIR__"npc/tufei1" : 1,
	]));

	setup();
	replace_program(ROOM);
}   