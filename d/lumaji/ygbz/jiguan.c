#include <ansi.h>
inherit ROOM;
int do_zhuan(string arg);
int do_jiao(string arg);
int do_suo(string arg);
void create()
{
        set("short", "������");
        set("long", @LONG 
����һ�������ʮ����С��,С�����봦�и�ˮ�������ʩ��
�����и�����̣����Ͼ���һС�ش�����۵�����!
LONG );
        set("objects", ([
                 ]));

               set("exits", ([
                                
        ]));

//      set("no_clean_up", 0);
        setup();
}
void init()
{
  object me = this_player();
        add_action("do_zhuan", "zhuan");
        add_action("do_jiao", "jiao"); 
        add_action("do_suo", "suo");
}

int do_zhuan(string arg)
{
        object me;
        me = this_player();
      if( !arg || arg=="" ) return notify_fail("��Ҫסת��ʲô����!\n");
            if( arg=="����" ) {
write(HIB"ת�����̣����ϵ������������ࡣ��һ����Ȼ��ϵ������һ���\n"
HIB"���ã�ֻ������������İ����ӽ�(jiao)������\n"NOR);
             this_player()->set_temp("jiaopan", 1);
             return 1;
       }
}

int do_jiao(string arg)
{
        object me;
        me = this_player();
      if( !me->query_temp("jiaopan")) return 0;
      if( !arg || arg=="" ) return notify_fail("��Ҫ�ʶ�ʲô����!\n");
            if( arg=="����" ) {
write(HIR"ֻ������������һ��!!�����ٽʲ����ˡ�\n"NOR);
             this_player()->set_temp("suolian", 1);
 me->delete_temp("jiaopan");
             return 1;
       }
}

int do_suo(string arg)
{
        object me;
        me = this_player();
      if( !me->query_temp("suolian")) return 0;
           if( arg=="����" ) {
write(HIR""+me->name()+"æ����������!\n"NOR);
  call_out("on_qidong", 3);
   return 1;
       }
}

void on_qidong(object room)
{
message_vision(HIB"�ð����ᣬ�������Ȼ���������װ㡸¡¡������!����Ŀ������������\n"NOR, this_player());
message_vision(HIR"�ָ�������Ͷ�����������������ͬʱ�������ֳ�ͨ������������ص���\n"NOR, this_player());
        set("exits/east", __DIR__"baokudt");
this_player()->delete_temp("suolian");
 call_out("on_guanmen", 5);

}

void on_guanmen(object room)
{
      message_vision(HIG"ͻȻ�������ǵ������������ֺ�����!\n"NOR, this_player());
delete("exits/east");
}



