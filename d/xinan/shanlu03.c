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
                "southwest"     : __DIR__"shanlu02",
                "northdown"         : __DIR__"shanlu04",
        ]));
        setup();
        set("outdoors","xinan");
}
