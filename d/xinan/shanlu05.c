#include <room.h>
inherit ROOM;


void create()
{
        set("short", "ɽ·");
        set("long", @LONG
��һ�����ϵ��������ǳ�ɽ���룬���������Ⱥɽ��������ɽ�ȣ���С
���������Ѷ�����ɽ�϶������α鲼�˼�����֮����Ҳż����Щɽ�����˵Ĵ�կ��
����Ұ��ʱʱ��������յ�����֮�»��
LONG
        );
        set("exits", ([
                "southeast"     : __DIR__"shanlu04",
                "northdown"         : __DIR__"shanlu06",
        ]));
        set("objects",([
        __DIR__"npc/xiaotu" : 2,
       ]));
        setup();
        set("outdoors","xinan");
}
