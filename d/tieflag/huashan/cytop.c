 inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�嶥�����ߴ�����ɣ����ڷ嶥���˿���ɫ��̺�ӣ�����Ũ����գ�����ʯ��
�����������롣�޷��ʱ������ʯ���ϣ��������������������ѵ�������Ȼ��
��ɽ�紵���������ּ�ֻ���������󣬴���˷�������һ����ɫ��
LONG
        );
    set("exits", ([ 
                "down" : __DIR__"chaoyang",
        ]));
        set("objects", ([
                __DIR__"obj/pineneedle" : 1,
                __DIR__"obj/pinetree" : 1,
                __DIR__"npc/songshu" : 1,
        ]));  
    set("outdoors", "huashanfy"); 
        set("coor/x",-569);
        set("coor/y",-93);
        set("coor/z",-83);
        setup();
    replace_program(ROOM);
}   
