 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
#include <ansi.h> 
inherit ROOM; 
void create() 
{ 
        set("short", "ľ����"); 
        set("long", @LONG 
һֻ��ª��ľ�����ƺ�������������������죩��
LONG 
           ); 
        set("no_fight",1); 
        set("no_magic",1);       
        set("coor/x",30); 
        set("coor/y",-690); 
        set("coor/z",-20); 
        setup();            
} 
 
void init() 
{ 
    add_action("do_sail","sail"); 
} 
 
void raft_sail(int counter,object me) 
{ 
    if (me->query_skill("dodge",1) < 50 )
                { 
message_vision(HIB"һ�����˴�����ľ����ʱ��Ϊ��Ƭ��$N������б������˾����֮�У�����\n"NOR,me);
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
                     
                  case 4: 
                  message_vision(HIC"�ƻ��ȥ����ҹ���٣�ǰ������ãã��ҹ��̧ͷ���죬������ 
�����죬��˸���ѡ��������������������˷�������ҹ���ţ� 
����������̫����Ҫ����\n"NOR,me); 
                  break; 
 
                  case 7: 
                  tell_object(me,HIC"����ʱ�֣�����֮����Լ����һ��С�������÷�������С��ȴ 
��ʮ�ֹŹ֣��������ƣ��������о�ɫ������һ�����صĸо���\n"NOR);
                  delete("counter"); 
                  tell_object(me,HIY"��ƴ���������˼��£�ľ�����ڵ��˰��ߡ��㻳�ż����������뿪ľ����̤��С����\n"NOR); 
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
                  write("��������ľ�����ϻ�ȥ....\n"); 
                  call_out("raft_sail",0,(int)query("counter"),me); 
                } 
        return 1; 
}        
