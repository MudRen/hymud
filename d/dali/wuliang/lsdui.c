// Room: lsdui.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
���ﵽ������һ��һ�ѵ���ʯ����ʯ���������ߵĻĲݣ����������˼�������
���������ϸѰ�ҵĻ����ڻĲ���ʯֻ���ƺ�������С���������죬��֪��ͨ
�����
LONG
        );
        set("exits", ([ 
            "southwest" : __DIR__"xiaolu2",
            "northeast" : "/d/dali/shennong/xiaodao4",

        ]));
        /*set("objects", ([
                __DIR__"npc/sikong_xuan" : 1, 
        ]));*/
        set("outdoors", "����");

        setup();
}

