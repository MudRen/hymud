// shiban03.c   ��ʯ��·
// Ffox 98-4-30 10:09

#include <ansi.h>
inherit ROOM;

void create()
{
    set( "short", "��ʯ��·");
    set( "long", @LONG
һ����ʯ��·��С���ϵĹ���ֹͣ�˷ͽУ����㵽̨�׺����ݵ���Ӱ��ȥ��
�����������ȵ������²��������⡣ʯ��·�����ǵ��ؾ���ķ��ӣ�һ�ж��Գ�
������ƽ�͵����ա�������һƬ��԰��
LONG );
    set( "exits", ([ /* sizeof() == 2 */
    "north": __DIR__"mroom01",
    "south": __DIR__"mroom02",
    "west" : __DIR__"shiban02",
    "east" : __DIR__"guoyuan",
]) );
    set( "outdoors", "����" );
    setup();
}

int valid_leave( object me, string dir )
{
    if( dir == "east" )
      write( GRN"����أ����߽��˹�԰�������\n"NOR );
    return :: valid_leave( me, dir );
}
