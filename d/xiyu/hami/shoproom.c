// shoproom.c   ���
// Ffox 98-4-30 10:09

inherit ROOM;

void create()
{
    set( "short", "���");
    set( "long", @LONG
������С�ݵ���䣬����˯������Զ��ס��֮�á����ż��׵Ĵ��̣����Ƕ�
��Զ�������������˵����Ҳ�ǲ����׵��ˡ�
LONG );
    set( "sleep_room", "inn" );
    set( "exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"shop",
]) );
    setup();
}

void init()
{
    this_player()->add_temp("hami/sleep",-1);
}
