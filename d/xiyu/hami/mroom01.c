// mroom01.c   ���
// Ffox 98-4-30 10:09

inherit ROOM;

void create()
{
    set( "short", "���");
    set( "long", @LONG
�����˵�һ����ӣ����￪���ţ��ſ������������ʯ��·�����������ƽ
ʱż��Ҳ��һ��С����ġ����صĻ����ˣ���סլ�����Ǻܽ�������������ͼ�
�����ţ�һ�����ӣ�����һ���󿻡�
LONG );
    set( "exits", ([ /* sizeof() == 2 */
    "south" : __DIR__"shiban03",
]) );
    set( "objects", ([
    __DIR__"npc/afanti" : 1,
    __DIR__"npc/nvren"  : 1,
]) );
    setup();
}

