#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short","��ǹ�");
    set("long",@LONG
�������򱱶ɹ��ƺӣ��Ϳɿ���һ����̵ĳǱ���ǽ�����ɶ࣬��ש���ͣ�
��Χ�����ֻ������һ�����ţ�������д�ţ�����Ǳ������ĸ���ī���֡���
���ǳ�͢�������������ˣ��س��Ա���һƬ��Ұ������Զ�����춼ɽ����������
���ľ��ء�����Ҳ��һƬ��Ұ����Щ�������ڻ������С�
LONG);
    set("exits",([
        "west"   : __DIR__"huangye1",
        "northeast" : __DIR__"xingqing/xing0",
        "south" : "/d/lanzhou/nroad2",
    ]));

        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
                ]) );
    
    set("outdoors","xibei");
    setup();
}

