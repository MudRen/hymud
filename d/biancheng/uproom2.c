 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��ի");
        set("long", @LONG
���Ⱥ���������飬��իֻ����˼������ĵط�����¥�²�ͬ��������õ÷�
�����ӣ��ı�Ĩ�Ű�����ҵ�������֮����ɫ���Ҿ���һ�ѿ��κ�һ�����ӣ�����
��д���ֵļ���ֽ��������Ŀ��������̡���Ҳ��ʽ�����ķ��ţ�����ֽ�������ģ�
��װ���̺�����ģ�Ҳ�м�ֱ�Ͷ������ϵġ�
LONG
        );
        set("exits", ([ 
                "west": __DIR__"corridor3",
                "east" : __DIR__"uproom3",
        ]));
        set("objects", ([
        ]) );
        set("wanma_discussion",1);
        set("coor/x",-1110);
        set("coor/y",320);
        set("coor/z",10);
        setup();
        //replace_program(ROOM);
}      
int valid_enter(object me)
{
        object ying,yang,di;
        object room;
        
        room=this_object(); 
        
        if(me->query("wanma/��¥")) {   
        if(!objectp(di=present("ma kongqun",room)))
                {
                        di=new(__DIR__"npc/makongqun");
                        di->move(room);
                }
                return 1;
             }
        return 1;
}