 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�α�����");
        set("long", @LONG
Զ���ɺ���������һ�����ص�ʯ�����²�ֱ��ʸˣ��϶˿��Ʊʼ⣬�ʸ˺ͱ� 
��֮���һʯ�죬���Ե���һֻ��Ȼë�ʣ��ʼ�֮�ϸ���һ����ɣ��������ۣ��� 
����Ȼ�������ʯ������֮�����ഫ����̫�����ڴ���ʫ�����ǹ�ʯҲ������̫ 
����ʱ��������֮��ͷ�������������հ�ݣ��������¡������������α���������
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"sanhua",
        ]));
    set("objects", ([
        __DIR__"obj/meng" : 1,
    ]) );
     
    set("outdoors", "huangshan");
    set("coor/x",-600);
    set("coor/y",-500);
        set("coor/z",30);
        setup();
        replace_program(ROOM);
}
