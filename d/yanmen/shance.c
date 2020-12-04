#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ɽ��"NOR);
        set("long",
"������ǡ����Ρ���Ӫפ�����ˣ�ԶԶ�ؿ��Կ���һ����죬������\n"
"��һ����������顸�Ρ��֣����߽�Щ�͵���Ӫ�ˣ�Ѱ���˻��ǲ�Ҫ����\n"
"�ĺã�ʡ�ñ�����ϸ��׽������\n"
);
        set("defence",120);
        set("no_fly", "1");
        set("exits", ([ /* sizeof() == 5 */   
               "south" :   __DIR__"gate",
               //"north"  : __DIR__"shibi",
               "north"  : __DIR__"CANYON7",	
        ]));    

        set("objects", ([
            "d/city/npc/wujiang" : 1,
            "d/city/npc/bing" : 5,
	]));
    
        setup();
}
              
void init()
{
      object me=this_player();

      if( me->query_temp("jun_quest/party") == "meng" )
       add_action("do_break","break");
       else
      if( me->query_temp("jun_quest/party") == "song" )
      add_action("do_repair","repair");
}

int do_repair()
{
      object room=this_object(),me=this_player();

      if( me->is_busy() )
      return notify_fail("����æ���أ�\n");

      if( room->query("defence") > 120 )
      return notify_fail("ɽ��ķ��������Ѿ�������ˣ�\n");
      else
      {
       message_vision(
       HIW"$N����һ֧������ŵ�������ɽ��ķ������£�\n"NOR,me);
       room->add("defence",random(me->query_temp("jun_quest/group")));
       me->start_busy(2+random(2));
       return 1;
      }
}

int do_break()
{
      object room=this_object(),me=this_player();

      if( me->is_busy() )        
      return notify_fail("����æ���أ�\n");

      if( room->query("defence") < 1 )
      {
       room->set("defence",0); 
       write("ɽ��ĵķ����Ѿ��������ˣ�����ȥ����\n");
       return 1; 
      }
      else
      {
       message_vision(
       HIY"$N����һ֧���Ƕ������ӽ�������ɽ��ķ������£�\n"NOR,me);
       room->add("defence",-random(me->query_temp("jun_quest/group")));
       me->start_busy(2+random(2));
       return 1;
      }
}

