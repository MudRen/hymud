//lroad1.c

inherit ROOM;

void create()
{
        set("short","ɳ��·");
        set("long", @LONG
���߾������ݵĶ���,���������������������Ⱦ��ܵ�������,������
������ԭ.��˵�����Ǳ���Ҫ��,�����е�·����ƽ��,�����߹�ʱ,������
���ϵ�ɳ��.�����������ʱ,�������л�ɳ����, ����������ذ��Ķ�
�ط羰.�ϱ���������վ,��ִ�й���Ĺٲ�Ъ�ź͸�������, ��ʱ�п���
�����ڼ��۶���.
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "north"         :       __DIR__ "yizhan1",
                "south"         :       __DIR__ "tudimiao",
                "west"          :       __DIR__ "lroad2",
                "east"          :       __DIR__ "dongmen",
                ])
        );
//      replace_program(ROOM);
        setup();
}

