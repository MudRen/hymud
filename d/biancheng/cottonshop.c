 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�޻���");
        set("long", @LONG
�׻�˵��С������˴��У�ָ�ľ������С����С�ҩ���С�ʲ���С����С���
�С�Ƥ�к�����޻��С���û�߽����ã����������������޻��������������
�ŵĴ�������д�ţ��������޻��������������󡱡��޻��е����ϰ峣�걼������
�أ���������ͽ�����ƿ��ܡ�
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"sstreet2",
        ]));
        set("objects", ([
                __DIR__"npc/bosssong":  1,
        ]) );
        set("coor/x",-1120);
        set("coor/y",160);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
