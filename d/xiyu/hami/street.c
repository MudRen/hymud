// street   小巷子
// Ffox 98-4-30 10:09

inherit ROOM;

void create()
{
    set( "short", "小巷子");
    set( "long", @LONG
一条僻静的小巷子，这里的宁静气氛显得更加浓重一些，小巷子里面的路依
然是青石板路面，人走在上面发出嗒嗒的响声，声音在小巷子里返回来的回音，
在这里感觉好象特别重。往西是一家小馆子，往东是一扇大门，门口有幅对联，
不过好象是西域的文字，不认识是上面写着些什么。
LONG );
    set( "exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"shiban02",
    "west" : __DIR__"shop",
]) );
    set( "outdoors", "西域" );
    setup();
}

int valid_leave( object me, string dir )
{
    if( dir == "east" ) 
     return notify_fail("这里的大门是紧锁的，好象很久没有人居住了。\n");
    return :: valid_leave(me,dir);
}
