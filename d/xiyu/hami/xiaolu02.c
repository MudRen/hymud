// xiaolu02   ����С·
// Ffox 98-4-30 10:09

#include <ansi.h>
inherit ROOM;

void create()
{
    set( "short", "С·");
    set( "long", @LONG
һ����ʯС·���Ѿ��ڽ�һ������С�������Զ�ĵط�������˵�ƽ����
������һɨ��Į�Ļ�ɳ���������ܵ������һƬ��䣬��ľ�����дУ�ʮ��ïʢ
�����Ǻ�����֦��Ҷï��ɫ��Ũ�ء�
LONG );
    set( "exits", ([ /* sizeof() == 2 */
    "west" : __DIR__"xiaolu01",
    "east" : __DIR__"shiban01",
]) );
    set( "outdoors", "����" );
    setup();
}

int valid_leave( object me, string dir )
{
//     if( dir == "east" )
//      write( YEL"^G^A^G^A^U^X^C^L^D^C^]^X^H^K^A^K^U^B^X^V^N^W^S^R^P^A^U^R^A^M^A^M^A^M^A^M\n"NOR );
    return :: valid_leave( me, dir );
}

