#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ľ����");
        set("long", @LONG
�����������ż�ֻ�����껹δ����Ĺ��ӣ��������һ��ͩľ����ζ��������
����������ľм���裬��ϰ�ߵ��˻�Ǻ�ô�����������֨֨�¸µľ�ľ����ƹƹ��
�ҵĶ���������ľ�����������ɱ�ɽ������Ľ�������ת������Ϣ��������������
���߹���������һ������¡�
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"sroad3",
        ]));
        set("outdoors", "taiping");
        set("item_desc", ([
                
        ]));
        set("objects", ([
                __DIR__"npc/carpenter": 1,
        ]));
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}
