#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����˿�ջ");
        set("long", @LONG
ǰ������һ������˫�ɵľ޻������Ź��Ŷ�ԧ��������ϵ�ż���СС�Ļ�ͭ
���塣΢���ӹ������巢������ö��Ķ�����������������Ŷ���Ĵ���������
�������֡������Ϻ���һ�������֡���ǰһ�ڴ�ף�Ϊ���������ṩ��ˮ��
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
                "west" : __DIR__"swind1",
        ]));
    set("resource/water", 1);
    set("liquid/container", "ˮ��");    
        set("objects", ([
        __DIR__"npc/waiter" : 1,
                        ]) ); 
        set("coor/x",10);
        set("coor/y",-10);
        set("coor/z",0);
        set("coor/x",10);
        set("coor/y",-10);
        set("coor/z",0);
        set("no_dazuo",1);
        set("no_study",1);
        setup();
//        replace_program(NEWBIE_HELP_ROOM);
}   
