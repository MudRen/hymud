#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short","��Ұ");
    set("long",@LONG
һƬ�������̵����أ���������ʯ�ͻ�����ʯ���г���Щ�Ͱ���С�ݡ��ϱ�
��ƽ�ߴ�����һЩ���������ɽ�����������ǻƺӣ��ɹ��ƺӾ������ݳǡ�����
��ʱ�м�ֻҰ��ɹ����������⣬��������������Ұ�紵����Խ���Ե�������
LONG);
    set("exits",([
        "east"   : __DIR__"jincheng_guan",
        "northwest"   : __DIR__"huangye2",
        "north"   : __DIR__"huangye1",
        "south"   : __DIR__"huangye1",
//       "west" : __DIR__"huangshui1",
        "west" : __DIR__"huangye2",
    ]));
    set("outdoors","xibei");
    setup();
}

