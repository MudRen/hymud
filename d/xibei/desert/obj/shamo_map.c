/* shamo_map.c
 * from XO Lib
 * a npc of desert
 * created by hydra 19980423
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980423
 */

inherit ITEM;

int LookMap( string );

void create()
{
    set_name( "ɳĮ����ͼ",({ "xinglv tu","tu","map" }) );
    set_weight( 200 );
    if( clonep() )
        set_default_object( __FILE__ );
    else 
    {
        set( "unit","��" );
        set( "long",@LONG
һ��������ô��ɳĮ��ͼ����˵�����͵�¥�����˻��˼����˵���Ѫ���ģ�
�������ڱ�ɳĮ���ɣ��н�������ʱ���ܽ�����Ĺ��ɡ�
����Բ�(cha)һ��ͼ���������ܷ����һЩ��ɳĮ�ķ�����
LONG
        );
        set( "material","paper" );
    }

    set( "no_drop",1 );
    set( "no_get",1 );
    set( "cant_sell","�����ƶ��������겻�ա�\n" );
    setup();
}


void init()
{
    add_action( "LookMap","cha" );
}

int LookMap( string arg )
{
    string south;
    object me;
    me = this_player();
    if( arg != "xinglv tu" && arg!="tu" && arg!="map" ) return 0;
    if( environment( me )->query( "outdoors" ) != "desert" )
        return notify_fail( "ͼ������ط�û�á�\n" );
    if( south = environment( me )->query_south( 1 ) )
        write( "���ͼ����ϸ����һ�£��������������Ϸ���" + south +"��\n" );
    else
        write( "������ط�ͼû���á�\n" );
    return 1;
}


