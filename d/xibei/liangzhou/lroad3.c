//lroad3.c

inherit ROOM;

void create()
{
        set("short","ɳ��·");
        set("long", @LONG
���뿪��������,��һ��·,������Զ�����е�������, �㷢����ǰ��
��Զ����������,��Ȼ¶��һ�Ǻ�ɫ��ɽǽ.�����е͵͵���֮������
��.
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "south"         :       __DIR__ "center",
                "north"         :       __DIR__ "shanmen",
                ])
        );
//      replace_program(ROOM);
        setup();
}

