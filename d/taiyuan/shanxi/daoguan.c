// Room: /huanghe/huanghe2.c
// Java. Sep 21 1998
#include <ansi.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @long
��������ɽ�ϣ���ɽ����б���⡣û������̸̸�İ���Ư�죬��
��ȴ������һ������紵�������ɼ�Ļ�ѻ���������ǳ���������
�Ĵ��ţ��ոտ���һ�ߡ������г����ľ����뿪�Ĵ���������Ư�쵭̸
�������ɢ����Լ���ڸ��˽�����ƴ���
long );
	set("exits", ([
  
//  "eastdown" : __DIR__"huanghe3",
//  "westdown" : __DIR__"huanghe2",
  "south" : __DIR__"wutai",
  
	]));
	set("objects", ([
		__DIR__"npc/qingfeng" : 1,
		__DIR__"obj/cup" : 1,
		__DIR__"obj/canqi" : 1,
		
	]));
//	set("no_clean_up", 0);
	        set("indoors", "shanxi");
	        set("item_desc", ([
                "bed": "һ����ʯ��̵Ĵ󴲣���������ͨ͸�������˰����ƴ��ͼ��ϣ�����һ�����塣\n",
                "�ƴ�": "һ����ʯ��̵Ĵ󴲣���������ͨ͸�������˰����ƴ��ͼ��ϣ�����һ�����塣\n",
        ]) );

         set("coor/x",-350);
        set("coor/y",-400);
        set("coor/z",30);
	setup();
	//replace_program(ROOM);
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
      message("vision", me->name()+"���˼��������ҵ������ʵ����ƣ��ܿ�ͽ��������硣\n", environment(me), me);
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