#include <ansi.h>
inherit ROOM; 
void create() 
{ 
        set("short", "ɽ�屳��"); 
        set("long", @LONG 
���ʯת������ǰͻȻһ����ɽ���ڴ���Ȼ���ʣ�һ��С·��֪��ʱ������� 
����Ϣ�����ѽ��£�Զ���������ƣ������˼ң�����������ƺ�������������Ҫ 
פ��ϸ����������ȴ����Ӱ���١� 
LONG 
        ); 
 
        set("exits", ([ /* sizeof() == 4 */ 
        "west" : __DIR__"valley2", 
        ]) ); 
 
        set("outdoors","taoyuan"); 
        set("coor/x",170); 
        set("coor/y",-30); 
        set("coor/z",0); 
        setup(); 
} 
 
void init () 
{ 
 
   add_action("do_listen", "listen"); 
   add_action("do_southeast", "southeast"); 
} 
 
int do_southeast(string arg) 
{ 
   object me, room; 
   me = this_player(); 
 
   if(me->query_temp("marks/listen")) { 
      tell_object(me, "������С·�������ǰ�������֮����\n\n"); 
      message("vision", me->name(me)+"�������ѵ�ɽ·ת�˼�ת��ʧȥ����Ӱ��\n", environment(me),me ); 
      room = find_object(__DIR__"taovillage"); 
      if(!objectp(room)) room=load_object(__DIR__"taovillage"); 
      me->move(room); 
      return 1; 
   } 
   return 0; 
} 
 
int do_listen(string arg) 
{ 
   object me, room; 
   me = this_player(); 
 
   tell_object(me,"�����������ޣ�����ϸ������������������ԼԼ�Ӷ��ϱߴ�����\n"); 
   message("vision",me->name(me)+"ͻȻס�㣬�ƺ��ڲ��������ʲô��\n", environment(me),me); 
   tell_object(me, HIG"\n����ƽ���滺��һϴ��ô�������ɱ��֮�������Ȼ���ܵ����������\n\n"NOR); 
   tell_object(me, "������ϸ���˿��Ǹ������ƺ���һ��С·���������������������֮����\n", me); 
   me->set_temp("marks/listen", 1);      
 
   return 1; 
} 
