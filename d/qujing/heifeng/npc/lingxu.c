//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
          set_name("������", ({"lingxu zi", "zi"}));
          set("gender", "����");
          set("age", 30);
        set("long", "һ����߱۳��ĵ�ʿ����ò�����Ĺ�ȥ��
����ϸһ�ƣ����о�������������ĳ�ë��\n");
          set("attitude", "heroism");
   set("class", "yaomo");
   set("bellicosity", 800);
          set("per", 18);
   set("looking", "��ò�׶��������⡣");
   set("str", 25);
          set("combat_exp", 120000);
          set("combat_exp",8100000);
        set_skill("unarmed", 75);
        set_skill("dodge", 75);
        set_skill("blade", 75);
        set_skill("parry", 75);

        set("neili", 700);
        set("max_neili", 700);
        set("force_factor", 30);
        set("max_qi", 800);
        set("max_jing", 800);
        set("max_neili", 300);
        set("neili", 300);

   set_temp("apply/armor", 25);
   setup();
   initlvl((200+random(200)),26);
   carry_object("/d/obj/cloth/changpao")->wear();
   carry_object("/d/qujing/jisaiguo/obj/panzi");
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
  call_out ("move_to_cave",1,this_object());
}

void move_to_cave (object me)
{
  object where = environment(me);
  object room = load_object("/d/qujing/heifeng/cave");
  if (! where ||
    where->query("short") == "����")
    return;

  message_vision ("\n$N���ƶ�·���ӣ�\n",me);
  me->move(room);
}


