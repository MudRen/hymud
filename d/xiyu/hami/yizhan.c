// yizhan.c   ��վ
// Ffox 98-4-30 10:09

inherit ROOM;

void create()
{
    set( "short", "��վ");
    set( "long", @LONG
�����ǹ����˷��üĴ���ƥ�ĵط������ڹٷ�������
LONG );
    set( "exits", ([ /* sizeof() == 2 */
    "south" : __DIR__"shiban01",
]) );
    set( "objects", ([
    __DIR__"npc/yizhang" : 1,
]) );
    setup();
}

