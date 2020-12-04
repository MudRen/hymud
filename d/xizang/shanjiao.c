 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", HIC"圣母峰山脚"NOR); 
        set("long", @LONG
方到圣母峰下，纵目四望，但见冰川交错，俨若银龙，又是另外一番奇景。冰
川的冰层，虽因受到初夏的阳光，已有部分融化，但山顶的雪花，一片一片轻飘飘
落下，就好像水晶末一般，由于太阳光的折射和散射，整个冰层都变成浅蓝色的透
明体，端的是奇丽万状，难以形容。
LONG); 
        set("type","street");
        set("exits",([
                "up":__DIR__"maze1",
                "northeast":__DIR__"birdroad3",
        ]) );
        
                set("objects", ([
                __DIR__"npc/master1" : 1,
                __DIR__"npc/master2" : 1,
        ]));
        
        set("outdoors", "xizang");
        set("coor/x",-1260);
        set("coor/y",-90);
        set("coor/z",0); 
        setup();
        //replace_program(ROOM);
}     
int valid_leave(object me, string dir)
{
	if ( objectp(present("master hongpao", environment(me))) && 
		dir == "up")
		return notify_fail("一个武林高手拦住了你的去路。\n");
	if ( objectp(present("master yan", environment(me))) && 
		dir == "up")
		return notify_fail("一个武林高手拦住了你的去路。\n");



	return ::valid_leave(me, dir);
}