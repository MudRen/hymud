 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "�ٻ���");
        set("long", @LONG
���ǿ����רΪ�׷ɷɶ�����İٻ��������е���װ�εؼ����£�����עĿ
������Ŀ�Ĵ�����Ĵ����ң����СС�ġ�ϲ�������ڸ���װ֡�ϣ������Ŀ��
�����������ػ�֦��չ��ϲ��æµ����ͣ��һ����ͷʦ�������ĵ�Ϊ����׷ɷ�
��ͷ��硣
LONG
        ); 
        set("exits", ([ 
                "south" : __DIR__"eaststrt2",
        ]));
        set("indoors", "loulan");
        set("objects", ([
                  __DIR__"npc/xiniang" : 2,
                  __DIR__"npc/hairjiang" : 1,
                  __DIR__"npc/ms_wang" : 1,
        ]) ); 
        set("coor/x",-1000);
        set("coor/y",200);
        set("coor/z",-100);
        setup();
} 
void init()
{
        object me; 
        if( interactive(me = this_player()) ) 
        {
                call_out("greeting", 0, me);
        }
} 
int greeting(object me)
{
        object room; 
        if( userp(me) && !me->query_temp("marks/jade_to_zhu") )
        {
                room = find_object("/d/loulan/eaststrt2");
           if(!objectp(room)) 
                        room = load_object("/d/loulan/eaststrt2");
                message_vision(HIY"������������װ���������ӡ�������ϲ�����������İ�$N���˳���������\n"NOR,me);
                me->move(room);
        }
}       
