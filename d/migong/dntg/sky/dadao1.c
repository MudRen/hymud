//sgzl

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
set("short", "�칬���");
set("long", @LONG
һ���������ֱ����չ��ȥ��ֱͨ�����š����ϲ�ʱ�߹�����
Ѳ���������ֵ��������������ݡ�
LONG );


set("magicroom",1);set("exits", ([
      "down"   : "/d/migong/lev22/dong98",
      "north"   : __DIR__"dadao2",
]));


set("objects", ([
]));


set("outdoors", "dntg");

setup();
}


void init()
{
add_action("do_swim", "swim");
}

int do_swim()
{
object who = this_player();
object horse = who->query_temp("ridee");


if(who->is_busy()||who->query_temp("pending/exercising")
||who->is_fighting()
||who->query_temp("pending/meditating"))
return notify_fail("����æ��,��������?\n");
if (! horse) 
  {
  message_vision(HIY "$N����һԾ��������ӡ�\n" NOR, who);
  who->move(__DIR__"tianhe");
  }
else 
  {
  message_vision(HIY "$N"+horse->query("ride/msg")+"��"+horse->name()+"Ծ����ӡ�\n" NOR, who,horse);
  who->move(__DIR__"tianhe");
  horse->move(__DIR__"tianhe");
  }
message_vision(HIY "$N˳�ſ��ĺ�ˮƮ�˹�����\n" NOR, who);
return 1;
}

