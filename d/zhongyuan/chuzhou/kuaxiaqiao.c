// ���ݿ����� /d/city/chuzhou/kuaxiaqiao.c
// by lala, 1997-12-03

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", WHT"������"NOR);
    set("long", @LONG
������λ����¥���ϣ�����������֮һ�ĺ�����ʱ��һ����������������
�����ӿ����������Ȼ��һ�����ۣ��������踺�أ����������ã��������¡���
����Ϊ�������Ĵ󽫷�ȣ����ڵ��������ط����������š����Ʒ���
    ���ﶫ���Ƕ��У����������У����������˺ܶ࣬�������С�
LONG
    );
    set("outdoors", "yangzhou");
    set("no_kill",  "yangzhou");
    set("exits", ([
        "south"     : __DIR__"nanshi",
        "east"      : __DIR__"dongshi",
    ]));
    set("objects", ([
    ]));
    setup();
}
