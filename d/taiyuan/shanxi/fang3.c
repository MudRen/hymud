 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�᷿");
        set("long", @long
һ����һ���̻Ի͵��᷿����Ƕ�˾޴������������������
Ӱ���䶯��ÿһ��������䡣�������Ǵ��������������壬�ı���
�졢�ڡ���Ϊ��ɫ�������ϣ��ɴ��ڻ��һ����˻������������Ѱ�
�׵ľ��£����ز��Ĵ�ռ���˷��������֮һ��
long
        );
        set("exits", ([ /* sizeof() == 4 */
                //"northeast":__DIR__"fang3",
                "southwest":__DIR__"hyuan",
               // "east":__DIR__"hyuan",
                //"west":__DIR__"hyuan",
                //"north":__DIR__"tang",


   ]));
        set("item_desc", ([
                "bed": "һ������Ĵ󴲣�˯��ȥһ���������\n",
                "��": "һ������Ĵ󴲣�˯��ȥһ���������\n",
        ]) );
        set("objects", ([
      
                                __DIR__"npc/xiaofan4" : 1,
                        ]) );



        set("no_dazuo",1);
        //set("no_study",1);
        set("no_magic",1);
//        set("NONPC",1);
      //set("valid_startroom", 1); 
        set("indoors", "shanxi");
  //      set("no_death_penalty",1);
set("coor/x",-490);
        set("coor/y",-320);
        set("coor/z",100);
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
      gin = (int) me->query("eff_jing");
      kee = (int) me->query("eff_qi");
      sen = (int) me->query("eff_jing");
      me->set("jing", gin);
      me->set("qi", kee);
      me->set("jing", sen);
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