 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
���Ǹ�������ṩ��������С�ݵĴ��̡����̼�ª��
���������ռ䵹��ͦ����Ȼ�е㳱ʪ���������в��ٳ�
��������İ����ҹ��춴ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "enter" : __DIR__"wnewbie4",
  "out" : __DIR__"wnewbie2",


   ]));

        set("objects", ([
       
//        __DIR__"npc/bandit1" : 5,
                        ]) );



        set("no_dazuo",1);
        //set("no_study",1);
        set("no_magic",1);
        set("NONPC",1);
      //set("valid_startroom", 1); 
        set("indoors", "fy");
        set("no_death_penalty",1);
        set("coor/x",-30);
        set("coor/y",0);
        set("coor/z",-10);
        setup();
} 
void init()
{
                        add_action("do_sleep", "sleep");
}
int do_sleep(string arg)
{
   object me, obj, girl;
   int gin, kee, sen; 
   me = this_player();
   obj = this_object(); 
   if (me->is_fighting()) return 1;
   if (this_object()->query_temp("marks/taken")) {
      tell_object(me, "��������Ү��������\n");
      return 1;
   }
      else{
      message_vision("$N�����ۡ������Ƿ���ɵ��˴��ϣ�", me);
      tell_object(me, "�ܿ���;���˯�����ʡ�\n");
      message("vision", me->name()+"���˼������ҵ������ʵ����ƣ��ܿ�ͽ��������硣\n", environment(me), me);
      obj->set_temp("marks/taken", 1);
      gin = (int) me->query("eff_gin");
      kee = (int) me->query("eff_kee");
      sen = (int) me->query("eff_sen");
      me->set("gin", gin);
      me->set("kee", kee);
      me->set("sen", sen);
      me->set_temp("disable_inputs",1);
      me->set_temp("block_msg/all",1);
      me->set_temp("is_unconcious",1);
      me->set("disable_type",HIG "<˯����>"NOR); 
      call_out("wake", 10, me);
      return 1;
   }
   return 1;
} 
void wake(object me)
{
   object obj; 
   obj = this_object();
   me->delete_temp("disable_inputs");
   me->delete("disable_type");
   me->delete_temp("block_msg/all");
   me->delete_temp("is_unconcious");
   if(!me->is_ghost())
   message_vision("$N�������۾���һ�������ͦ�Ӵ�������������\n", me); 
   tell_object(me, "����þ�����˺ܶࡣ\n");
   obj->set_temp("marks/taken", 0);  
}  