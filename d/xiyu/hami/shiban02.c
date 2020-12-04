// shiban02.c   青石板路
// Ffox 98-4-30 10:09

inherit ROOM;

void create()
{
    set( "short", "青石板路");
    set( "long", @LONG
一条青石板路，小镇上的狗都停止了吠叫，都躲到台阶和外屋的阴影下去了
，空气在灼热的阳光下颤抖和闪光。石板路两边是当地居民的房子，一切都显出
宁静，平和的气氛。往南是一条僻静的小巷子。
LONG );
    set( "exits", ([ /* sizeof() == 2 */
    "west" : __DIR__"shiban01",
    "east" : __DIR__"shiban03",
    "south" : __DIR__"street",
]) );
    set( "outdoors", "西域" );
    set( "objects", ([
    __DIR__"npc/kid" : 2,
]) );
    setup();
}

