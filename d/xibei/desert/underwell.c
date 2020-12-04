/* underwell.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980421
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980421
 */

inherit ROOM;

void create()
{
    set( "short","����" );
    set( "long",@LONG
�������һ�����ϵľ������棬������߷ǳ��ڣ���տ��Կ�������Զ�ĵ�
�������������ĸ�������ˮ��ʵ��һ�ɿݣ�������һƬƽ�����ֽ�ʵ��������
���ڶ������ǽ�ϣ�������Щ���䣬��������һ��С����
LONG
    );

    set( "outdoors","desert");
    set( "exits",([ /*sizeof() == 2 */
        "up" : __DIR__"loulan2",
    ]) );
    set( "detail",([
        "��":"һ����С�Ķ����������ܷ���(zuan)��ȥ��\n",
        "hole":"һ����С�Ķ����������ܷ���(zuan)��ȥ��\n",
    ]) );
    set( "not_startroom",1 );
    setup();
}

void init()
{
    add_action( "EnterHole","zuan" );
}

int EnterHole( string arg )
{
    object me;
    me = this_player();
    if( arg !="hole" && arg !="��" )
        return notify_fail( "��Ҫ��ʲô��\n" );
    message( "vision",me->name()+"�Ӷ������˽�ȥ����\n",environment(me),me);
    me -> move( __DIR__"oldtomb" );
    write( "��ʹ���˾������������С��������\n" );
    message( "vision",me->name()+"���˽���������\n",environment(me),me);
    return 1;
}
