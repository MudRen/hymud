// sgzl

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("����ħ��", ({ "hunshi mowang", "mowang"}) );
  set("gender", "����" );
       set("long",
                "ֻ����ħ����\n
����ͷ���ڽ����ӳ�չ�������������ۣ�ӭ��Ʈ����
    �´��ź����ף�����Ƥ������̤�Ż���ѥ�������Ͻ���
    ����ʮΧ��������ɣ���ִһ�ڵ������ж�������
    ��Ϊ����ħ��������ģ����\n");
  set("age", 30);
  set("str", 30);
  set("per", 30);
  set("int", 30);
  set("attitude", "killer");
  
  set("combat_exp", 150000);
  set("daoxing", 100000);



 

  setup();
initlvl((600+random(600)),61);
  carry_object("/d/obj/armor/tongjia.c")->wear();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/obj/weapon/blade/yanblade.c")->wield();
}

void init()
{
  object ob=this_player();

  ::init();
     remove_call_out("greeting");
     call_out("greeting", 1, ob);
}

void greeting(object ob)
{
  object me=this_object();
  message_vision("$N�ȵ������������ռ�ˣ��������\n",me);
  command("kill " + ob->query("id"));
}


int accept_fight (object ob)
{
  
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}


void die()
{
  object ob = query_temp("my_killer");
  object me = this_object();
  object ma;
  object panzi;

  if (ob)
  {
  message_vision ("\n$N�ҽ�һ��������Ϊ���Ρ�\n",me);
  ma = new (__DIR__"ma");
  message_vision ("\n����ͷ����Ԫ˧���ż�ֻ�������˹���������$N��ն�����˵�����������\n",me);
  if(ob->query("dntg/huaguo")!="done")  
    {
    ma->announce_success (ob);
    panzi = new ("/d/qujing/hgs/obj/shipan");
    panzi->move(ob);
    }
  message_vision ("\n��Ԫ˧�����ں������ְ˽ŵİ�$N��ʬ�����˳�ȥ��\n",me);
  destruct (ma);
  }
  destruct(me);
}

��
