// tulu2.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
前面就是侯集镇了，一条笔直的石板大道通向前方，路上不时的有南来北
往的车马经过，到了这里你发现人们的衣服都比较厚，原来这里靠近天山已经
不远了。
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([
		"west" : __DIR__"paifang",
		"southeast" : __DIR__"tulu1",
	]));
	setup();
	replace_program(ROOM);
}
