 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", HIC"ʥĸ��ɽ��"NOR); 
        set("long", @LONG
����ʥĸ���£���Ŀ������������������ٲ����������������һ���澰����
���ı��㣬�����ܵ����ĵ����⣬���в����ڻ�����ɽ����ѩ����һƬһƬ��ƮƮ
���£��ͺ���ˮ��ĩһ�㣬����̫����������ɢ�䣬�������㶼���ǳ��ɫ��͸
���壬�˵���������״���������ݡ�
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
		return notify_fail("һ�����ָ�����ס�����ȥ·��\n");
	if ( objectp(present("master yan", environment(me))) && 
		dir == "up")
		return notify_fail("һ�����ָ�����ס�����ȥ·��\n");



	return ::valid_leave(me, dir);
}