 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ɽ��");
        set("long", @LONG
��ɽ�վ�����ȥ�������̣����������߶�Ϊ���ҿ��޵�ɮ�ˣ�����
��ɽ֮���������ࡣ��ɽ�¾���Ϊ����һλ�ó�ɽˮ�Ĵ󻭼ҡ�ѩׯ��
�С�������������֮�ס����������������漣�������ɰ�ɽ��������ɽ
������ʯ������������ȥ�춼�塣
LONG
        );
    set("exits", ([ 
                "southdown" : __DIR__"mroad3",
        ]));
        set("objects", ([
                __DIR__"npc/xiaofan" : 1,
"quest/skills2/wunon/non/nontian" : 2,
        ]));     
    set("outdoors", "huangshan");
        set("coor/x",-550);
    set("coor/y",-490);
    set("coor/z",30);
        setup();
        replace_program(ROOM);
}   
