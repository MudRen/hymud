// mroom02.c   ���
// Ffox 98-4-30 10:09

inherit ROOM;

void create()
{
    set( "short", "���");
    set( "long", @LONG
�����˵�һ����ӣ����￪���ţ��ſ������������ʯ��·�����صĻ�����
����סլ�����Ǻܽ��������������һ�����ӣ�����һ���󿻡������ӵ�������
һ�����ˣ��ر�ÿ͡�
LONG );
    set( "exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"shiban03",
]) );
    set( "objects", ([
    __DIR__"npc/huosan" : 1,
]) );
    setup();
}

