
#include <room.h>

inherit ROOM;



void create()
{
    set( "short", "С��" );
    set( "long", @LONG
һ�������е��ƾɵ�Сľ�ݣ�����ȥ�Ѿ������þ��ˡ���ΧŨ�ܵ����ӣ���
���ڸ�ס������ľ�ݣ�����������������Ϳ��������ľ�ݡ�������һ����Ƥ��
��å�̾��ţ���Χ�Ĵ���п಻����
LONG
    );
    set( "exits", ([
        "south"    : __DIR__"milin2",
    ]) );
    set( "objects", ([
        __DIR__"npc/xinghu" : 1,
    ]) );
    setup();
}
