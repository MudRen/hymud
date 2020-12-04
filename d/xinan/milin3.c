
#define X_TASK_KILL_XINGHU          ( 1 << 12 )

#include <room.h>

inherit ROOM;



void create()
{
    set("short", "����");
    set("long", @LONG
��������ӳ����쳣ï�ܣ����������У����ò���������������ǰ����Ҷ��
֦��ͷ�������ܲ�͸������֣���������ϥ��ĳ��ݣ��������߷��ڲݴ��С�ǰ
��̤����·�ܿ�ͱ��³�����֦Ҷ��ס�ˡ�
    ���ܵ��ó�ܶ࣬��ʱ������Χ���衣
LONG
    );
    set("exits", ([
        "west"     : __DIR__"milin1",
        "east"     : __DIR__"xiao_shancun",
        "north"    : __DIR__"milin2",
        "south"    : __DIR__"milin2",
    ]));
    setup();
}

int valid_leave( object ppl, string arg )
{
    int mark = ppl->GetMark( "xing" );

    if ( mark & X_TASK_KILL_XINGHU && arg == "north" )
    {
        ppl->move( __DIR__"xiaowu" );
        return notify_fail("");
    }
    else
    {
        return ::valid_leave( ppl, arg );
    }
}
