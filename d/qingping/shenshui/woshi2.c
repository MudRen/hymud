 // TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��ˮ���д���������ڣ����ڰ�ˮ�������������˽��룬�����߽�����
ƫ�ֶ������ӣ���������һ����û����ס�ģ�����Ϊ����ĵ������Ѿ�����
��ɨ��һ�������г��軪�������ϱ�����ȫ�����˿����������ˡ�
LONG
        );
        set("exits", ([ 
                    "west" : __DIR__"woshi",
           ]));
        set("item_desc", ([
                "bed": "һ������Ĵ󴲣�˯��ȥһ���������\n",
                "��": "һ������Ĵ󴲣�˯��ȥһ���������\n",
        ]) );
        set("objects", ([
                __DIR__"npc/needlegirl2" : 1,
                       ]) );
        set("coor/x",220);
        set("coor/y",12350);
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
   if (me->query("class")=="shenshui") {
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
   else {
      message_vision("$N�����ۡ������Ƿ���ɵ��˴��ϡ�\n", me);
      girl = present("gong nu", obj);
      if (!objectp(girl)) {
         girl = new(__DIR__"npc/fightgirl2");
         girl->move(obj);
         message_vision(girl->name()+"���˽������ȵ����������Ǹ������Ϣ�ĵط������Ǹ���˯���ġ��� \n", me);
         return 1;
      }
      message_vision(girl->name()+"�ȵ����������Ǹ������Ϣ�ĵط�������ʲô��?��\n", me);
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
