/* lvzhou.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980327
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980402
 */

inherit ROOM;

void create()
{
    set( "short","����" );
    set( "long",@LONG
����ɳĮ��������ô�ͣ�����������һ���������ĵط�������ط���ʵ����
�ܴ�ֻ������������һ��ˮԴ������ƽ���羵���������ܳ�����ݣ���仹��
��һЩ��������ˮ�ǲ�Զ����ѩɽ�ϻ�ѩ�ڻ��������˴��㼯���ɵġ����̵���
ɳĮ�Ľ��ӳ����ż�����������
LONG
    );
    set( "not_startroom",1 );
    set( "exits", ([/*sizeof() == 8 */
        "north":__DIR__"shamo"+random( 9 ),
        "south":__DIR__"shamo"+random( 9 ),
        "west":__DIR__"shamo"+random( 9 ),
        "east":__DIR__"shamo"+random( 9 ),
        "southeast":__DIR__"shamo"+random( 9 ),
        "northeast":__DIR__"shamo"+random( 9 ),
        "southwest":__DIR__"shamo"+random( 9 ),
        "northwest":__DIR__"shamo"+random( 9 ),
    ]) );
    set( "outdoors","lvzhou");

    set( "item_desc",([
        "������":"�㷢����������������һ�ֻ�ɫ��ֲ�\n",
        "���":"�������ݳ��ĺ�ïʢ���������Ƿ��ܰ�(ba)һЩ��\n",
    ]) );
    set( "search_things",([
        "������":__DIR__"obj/congrong",
    ]) );
    set( "grass_remain",3 );
    setup();
}

void init()
{
    add_action( "do_drink",({ "drink","he" }) );
    add_action( "do_ba","ba" );
}

int do_drink( object me,string arg )
{
    int current_water,max_water;
    me = this_player();
    current_water = me->query( "water" );
    max_water = me->max_water_capacity();

    if( arg ) return 0;
    if( current_water >= max_water )
        return notify_fail( "�����˲�ҪǮ��ˮҲ��������ô����:-) \n" );
    message( "vision",me->name() + "���������ˮ����Ҫ���غ���������������һ��"
"����û�ȹ�ˮ�ˡ�\n",environment( me ),({ me }) );
    write( "����˺����ˮ������һ�����ֱ͸�ĵף�ˬ��������ˬ���ˡ�����\n" );
    me -> add( "water",20 );
    return 1;
}

int do_ba( string arg )
{
    object me,ob;
    me = this_player();

    if ( arg != "���" && arg != "cao" ) return 0;
    if ( ! query( "grass_remain" ) ) 
        return notify_fail( "����Ĳ��Ѿ����ι��ˡ�\n" );
    ob = new( __DIR__"obj/grass" );
    ob -> move( me );
    message_vision( "$N������������һ$n�����С�\n",me,ob );
    add( "grass_remain",-1 );
    return 1;
}
   

