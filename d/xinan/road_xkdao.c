//road.c.ɽ·
//date:97.10.16
//by dan

#include <room.h>
#include <ansi.h>
inherit ROOM; 



void create()
{
        set("short", HIC"ɽ·"NOR);
        set("long", @LONG
�����Ǵ�������֮���ɽ������Ȼ�������ߣ�ȴ�����������֪�δ�����
��ͷ������һ��ͨ��С�����Ţ��ɽ·��·�߾��������������������Ǿ�������
����ϵ������ϡ�����Ա���һ��СС��ɽ·��������������������ˡ��㲻��
�ļӿ��˲�����
LONG
        );
        set("exits", ([
                "north"     : __DIR__"milin4",
        ]));
        setup();
        set("outdoors","xinan");
}
