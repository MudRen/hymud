 //Created by justdoit at June 2001
//All Rights Reserved ^_^ 
 
#include <ansi.h> 
inherit ROOM; 
void create() 
{ 
    set("short", "һҶС����");
        set("long", @LONG 
һҶ��ӯ��С�ۣ�������������������죩��
LONG 
           ); 
        set("no_fight",1); 
        set("no_magic",1);       
        set("coor/x",40); 
        set("coor/y",-690); 
        set("coor/z",-20); 
        setup();            
} 
 
void init() 
{ 
    add_action("do_sail","sail"); 
} 
 
void boat_sail(int counter,object me) 
{ 
    if (me->query_skill("dodge",1) < 30 )
                { 
                  message_vision(HIB"һ�����˴�����$N���²��ȣ��������֮�У�����\n"NOR,me); 
                  delete("counter"); 
                  me->move(__DIR__"seabutton1"); 
                  return; 
                } 
        switch (counter) 
                { 
                  case 1: 
                  message_vision(HIC"��ˮ�ڽ���ʱ��������ʱ���ͳ���ʱ����ӿ��ʱ����˳������ 
��ȥ��������ӣ��ޱ��޼ʣ�һƬ���ɡ��·���Զû�о�ͷ��\n"NOR,me); 
                  break; 
                     
                  case 3: 
                  message_vision(HIC"�ƻ��ȥ����ҹ���٣�ǰ������ãã��ҹ��̧ͷ���죬������ 
�����죬��˸���ѡ��������������������˷�������ҹ���ţ� 
����������̫����Ҫ����\n"NOR,me); 
                  break; 
 
                  case 5: 
                  tell_object(me,HIC"����ʱ�֣�����֮����Լ����һ��С�������÷�������С��ȴ 
��ʮ�ֹŹ֣�С���������ƣ��������з��飬����ʮ������֮�С�\n\n"NOR);
                  delete("counter"); 
                  tell_object(me,HIY"��ƴ���������˼��£����ڵ��˰��ߡ��㻳�ż����������뿪С����̤��С����\n"NOR); 
          me->move(__DIR__"baiyundu");
                  break; 
                }  
        return; 
} 
 
int do_sail(string arg) 
{    
        object me; 
        me = this_player(); 
        if( !arg || (arg != "south") )  
        return notify_fail("��Ҫ���Ķ�����\n"); 
        if( arg=="south" )  
                { 
                  add("counter", 1); 
                  write("��������С�����ϻ�ȥ....\n"); 
                  call_out("boat_sail",0,(int)query("counter"),me); 
                } 
        return 1; 
} 
