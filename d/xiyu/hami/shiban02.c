// shiban02.c   ��ʯ��·
// Ffox 98-4-30 10:09

inherit ROOM;

void create()
{
    set( "short", "��ʯ��·");
    set( "long", @LONG
һ����ʯ��·��С���ϵĹ���ֹͣ�˷ͽУ����㵽̨�׺����ݵ���Ӱ��ȥ��
�����������ȵ������²��������⡣ʯ��·�����ǵ��ؾ���ķ��ӣ�һ�ж��Գ�
������ƽ�͵����ա�������һ��Ƨ����С���ӡ�
LONG );
    set( "exits", ([ /* sizeof() == 2 */
    "west" : __DIR__"shiban01",
    "east" : __DIR__"shiban03",
    "south" : __DIR__"street",
]) );
    set( "outdoors", "����" );
    set( "objects", ([
    __DIR__"npc/kid" : 2,
]) );
    setup();
}

