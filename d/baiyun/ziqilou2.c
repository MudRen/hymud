 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
#include <ansi.h>
inherit ROOM; 
void create() 
{ 
        set("short", "����������¥");
        set("long", @LONG 
�����һ¥��Ӻ�ݻ�������ڻԻͣ���¥ȴ������嵭���ţ����涼�ǳ����Ĵ�
����¥�����������������̴ľ�㼸������ڵ���һ�����٣����׷���һ�������ӣ�
�������һ��ˮī����Ŀ�ݣ����������һ���ᡣ
LONG 
           ); 
        set("exits",  
           ([  
       "down" : __DIR__"ziqilou",
            ])); 
        set("objects",  
           ([  
//       __DIR__"npc/yexingshi" : 1,
        __DIR__"obj/desk" : 1,
        
            ])); 
        set("indoors", "baiyun");
        set("type","house");
        set("coor/x",0); 
        set("coor/y",-1800); 
        set("coor/z",25); 
        setup(); 
//        replace_program(ROOM); 
}       
  
void init()
{
        object me; 
        if( interactive(me = this_player()) ) 
        {
                call_out("greeting", 1, me);
        }
} 
int greeting(object me)
{
        object room; 
        if( userp(me) && me->query("age")<300 )
        {
                room = find_object("/d/baiyun/skystreet");
                if(!objectp(room)) 
                        room = load_object("/d/baiyun/skystreet");
                message_vision(MAG"Զ������ͻȻ���𣮣���$Nһ���£��Ӵ������˳�ȥ������\n"NOR,me);
                me->move(room);
           me->receive_damage("qi",5000);
                message_vision(MAG"$N��������������Զ���������ɽ���Զ������Ȼ���˸���ս������\n"NOR,me);
        }
}      
