// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "�ӵ�");
  set ("long", @LONG

��������ĺӵס���

LONG);

  set("exits", ([
        "up"   : __DIR__"bing2",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : random(5)+3,
        __DIR__"npc/jinyu"  : 1,
      ]));
  set("outdoors", "xy16");

  setup();
}

void init ()
{
  object where = this_object ();
  object who = this_player ();

  remove_call_out("cold");
  call_out ("cold",random(10)+5,where,who);
}

void cold (object where, object who)
{
  tell_room (where, "�㶳�û�������\n");
  if (who &&
      environment(who) == where)
  {
    if (who->query("qi")> 50)
      who->add("qi",-50);
    call_out ("cold",random(10)+5,where);
  }
}

