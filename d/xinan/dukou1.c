#include <room.h>
#include <ansi.h>
inherit ROOM;


void create()
{
        set("short", "��ɳ���ɿ�");
        set("long", @LONG
��ɳ��Դ����������ɽ�£�ˮ���ļ����������������ɸߵ����£�ֻ�ڶɿ�
������һС���̲ɳ�أ�������һ����С�����۵ش���ɽ�����ɿ�Ҳ��һ
��С������ɽ�С����ϲ�ʱ�ɹ���ֻ����
LONG
        );
        set("exits", ([
                "southup"     : __DIR__"baicao_ling2",
                "north"  : __DIR__"dukou2",
        ]));
        set("item_desc", ([
                "river":  "�󽭵Ĳ��ξ�����ý��µĴ�ض�����������\n",
        ]));
        setup();
        set("outdoors","xinan");
}
void init()
{       
        write(BLU "��ˮ��ӿ���£��޴������������ľ���ս!\n" NOR);
}
