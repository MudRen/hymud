#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "̽��ʫ̨");
        set("long",  
"�����е��������ٴ�����ʫ�Դʵ��źá�ֻҪ������У��ͻ���ű�ī����
�������𣬵ȵ����է�������ǣ��ܱʼ��飬����ǧ�����䡣ʫ̨���������ľ��
�ݣ�" + YEL"  
                       �����оƽ���
                       �Ĺ����ս���ͷ��
                                       ���������ھƺ�ʧ��ʱ��
"NOR
        );
        set("exits", ([ /* sizeof() == 4 */
          "south" : __DIR__"wcloud1",
          "up": __DIR__"poemp2",
]));
        set("objects", ([
        __DIR__"npc/yaren" : 1,
        __DIR__"npc/prince" : 1,
                        ]) );
        set("no_death_penalty",1);
        set("no_study",1);
        set("coor/x",-10);
        set("coor/y",1);
        set("coor/z",0);
        setup();
//        call_other( "/obj/board/poem_b", "???" );
}   
