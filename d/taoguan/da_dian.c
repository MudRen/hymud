#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "���幬����");
        set("long", @LONG
����������Ľ�����������ǰ�������ϰ��Ÿ�ʽˮ��
��һ��Сͭ¯��ͭ¯�������֧�����˵��㡣������ǽ�϶�
û���κζ�����ȴ��ˢ�úܰס�����������һ������¯��
һλò�����˵ĵ�ʿ����������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "south" : __DIR__"da_yuan",
                "northwest" : __DIR__"stoneroad",
]));
        set("valid_startroom", 1);
        set("objects", ([
                __DIR__"npc/up_taoist" : 2,
            __DIR__"obj/ding_sq" : 1,
                __DIR__"npc/taolord2" : 1, 
 ]) );
        set("coor/x",-20);
        set("coor/y",2110);
        set("coor/z",80);
        setup();
}     
