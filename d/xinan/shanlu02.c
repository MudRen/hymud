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
                "southdown"     : __DIR__"shanlu01",
                "northeast"         : __DIR__"shanlu03",
        ]));
        setup();
        set("outdoors","xinan");
}
