#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������̫ƽ����϶ˣ�����̫ƽ��ģ�û���˲�֪���������ӵġ�С������һ
�Ⱥ��ţ����ź���һ������¥��ԶԶ�������������٣������������ﻨ����ƽ����
��������߳���������û��һ���˺�ڹ���
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"mroad5",
                "west" : __DIR__"sroad3",
        ]));
        set("outdoors", "taiping");
        set("item_desc", ([
                
        ]));
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}     
