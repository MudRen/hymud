//fuzhai_zoulang.c ����
//Hydra

inherit ROOM;

void create()
{
    set("short","����");
    set("long", @LONG
����һ�����������ȣ�ͨ����լ���񻨵�����������һ��С��԰�����ȶ���
�����һЩ����
LONG
    );
    set("outdoors","liangzhou");
    set("exits", ([ 
        "north"         :       __DIR__"fuzhai_zoulang2",
        "west"          :       __DIR__"fuzhai_dating",
    ]) );

        setup();
}

