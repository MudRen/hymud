// shiban01.c   ��ʯ��·
// Ffox 98-4-30 10:09

inherit ROOM;

void create()
{
    set( "short", "��ʯ��·");
    set( "long", @LONG
һ����ʯ��·��С���ϵĹ���ֹͣ�˷ͽУ����㵽̨�׺����ݵ���Ӱ��ȥ��
�����������ȵ������²��������⡣ʯ��·�����ǵ��ؾ���ķ��ӣ�һ�ж��Գ�
������ƽ�͵����ա�
LONG );
    set( "exits", ([ /* sizeof() == 2 */
    "north": __DIR__"yizhan",
    "west" : __DIR__"xiaolu02",
    "east" : __DIR__"shiban02",
]) );
    set( "outdoors", "����" );
    set( "objects", ([
    __DIR__"npc/woldman" : 1,
]) );
    setup();
}

