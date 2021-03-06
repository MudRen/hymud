// fangjian2.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "房间");
        set("long", @LONG
这是一间布置成卧室模样的小房间，有张石床，床上摆着个小小的木头
制成的摇篮，墙壁上悬着一个七弦琴，弦线都已经断了。
LONG );
       set("exits", ([
               "south" : __DIR__"shiji2",
       ]));
       set("no_clean_up", 0);
       setup();
}

void init()
{
        add_action("do_shout", "shout");
        add_action("do_shout", "han");
}

int do_shout(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;

if (me->query_temp("big5") && userp(me) && arg!="" ) arg=LANGUAGE_D->Big52GB(arg);

	if( arg=="芝麻开门" || arg=="opendoor") 
	{
		tell_object(me,"你气运丹田，对着墙壁大喝一声：“芝麻开门！”\n");

		message("vision", "过了一会儿，你只听到一阵轰隆隆的响声，出现了一道暗门。\n", me);
		set("exits/down", __DIR__"shishi4");
		remove_call_out("close");
		call_out("close", 8, this_object());

	}
}

void close(object room)
{
	message("vision","一阵轰隆隆的响声过后，石门又缓缓地关上了。\n", room);
	room->delete("exits/down");
}
