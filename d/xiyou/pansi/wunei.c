// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

ʯ���������о���������֣����ռ�Ϊ��Ͱ���������������
һ��齣������һ���������Ŵ�����յ���ұ���һ��ͭ����
ȼ���������

LONG);

  set("exits", ([
        "out"    : __DIR__"shiwu",
      ]));
  set("outdoors", "xy27");
 set("isok",0);
  setup();
}

void init ()
{
  object who = this_player();

  remove_call_out("daogu_appearing");
  if (query("isok")==0 &&
      who->query("combat_exp") >= 10000 &&
      ! present("xiuhua zhen",who))
  {
    call_out("daogu_appearing",300,who,this_object());
  }
}

void daogu_appearing (object who, object where)
{
  object daogu;
  if (! who)
    return;

  if (environment(who) != where)
    return;
  set("isok",1);
  daogu = new ("/d/qujing/pansi/npc/daogu");
  daogu->move(where);
  message_vision ("$N���������������Ρ���\n",daogu);
  remove_call_out("daogu_giving");
  call_out("daogu_giving",1,daogu,who,where);
}

void daogu_giving (object daogu, object who, object where)
{
  object needle;
  if (! who ||
      environment(who) != where)
  {
    remove_call_out("daogu_disappearing");
    call_out("daogu_disappearing",1,daogu);
    return;
  }
message_vision ("$N����һö�廨�롭��\n",daogu);
  needle = new ("/d/qujing/pansi/obj/needle");
  //needle->move(daogu);
  needle->move(who);
  remove_call_out("daogu_disappearing");
  call_out("daogu_disappearing",1,daogu);
}

void daogu_disappearing (object daogu)
{
  message_vision ("$N��������������һ����ʧ����\n",daogu);
  destruct(daogu);
}
