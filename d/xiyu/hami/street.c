// street   С����
// Ffox 98-4-30 10:09

inherit ROOM;

void create()
{
    set( "short", "С����");
    set( "long", @LONG
һ��Ƨ����С���ӣ���������������Եø���Ũ��һЩ��С���������·��
Ȼ����ʯ��·�棬���������淢���વ�������������С�����ﷵ�����Ļ�����
������о������ر��ء�������һ��С���ӣ�������һ�ȴ��ţ��ſ��з�������
������������������֣�����ʶ������д��Щʲô��
LONG );
    set( "exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"shiban02",
    "west" : __DIR__"shop",
]) );
    set( "outdoors", "����" );
    setup();
}

int valid_leave( object me, string dir )
{
    if( dir == "east" ) 
     return notify_fail("����Ĵ����ǽ����ģ�����ܾ�û���˾�ס�ˡ�\n");
    return :: valid_leave(me,dir);
}
