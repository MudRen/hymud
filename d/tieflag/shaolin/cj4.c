 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�ؾ�¥");
        set("long", @LONG
ר���о�����а���书�������Ƕ���������ǿ����������Ϊа����
�������ٳɶ��������������ħ�����������һ�㲻����������������
��˵�о�а���书�ˣ����Ǽ����ⶾ������鼮���������о�����Ȼ��
ѧ֮�������һ�ģ����������ˣ����������ô�о�а���书������
����
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"cj5",
  "down": __DIR__"cj3",
]));
        set("objects", ([
                __DIR__"obj/slayedman1" : 1,
                __DIR__"obj/slayedman2" : 2,
                __DIR__"obj/slayedman1" : 1,
                "/clone/weapon/gangjian":    2,
       ]) );
        set("no_fly",1);
        set("coor/x",-210);
        set("coor/y",360);
        set("coor/z",100);
        setup();
        create_door("down", "ľ��", "up", DOOR_CLOSED); 
}
void init()
{
        this_player()->apply_condition("unknown",
                (int)this_player()->query_condition("unknown")
                + random(3)+3);
}        
