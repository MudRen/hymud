//1997-3-10 by qyz
#include <room.h>

inherit ROOM;



void create()
{
        set("short","����̨");
        set("long",@LONG
���������ɽ�ľ������·����ţ�����ϼ���ഫΪ�Ƶ��ڵ�̳���ұ߾���
������Ԩ���ڴ˵Ǹ�һ������ɽ��Ӧ��������������������������ǰ���繰
��Ҿ���Ʊ���������ƽԶ��㡣�������������ۿ��ճ�����Ϊ��ۡ�
LONG);
        set("exits",
        ([
          "south" : __DIR__"lingzhi_yuan",
          "west" : __DIR__"xianren_qiao",
                ]));

        set("outdoors","kongdong");
        setup();
}

void reset()
{
        if( !random( 5) )
        set("objects", ([
                                __DIR__"npc/wuming" : 1,
                ]) );
        ::reset();
}
