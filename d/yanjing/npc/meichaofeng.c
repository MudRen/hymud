#include <ansi.h>;
inherit NPC;
void create()
{
   set_name("÷����",({"mei chaofeng","mei"}));
   set("gender","Ů��");
   set("mingwang",-5000);
   set("combat_exp",426000);
   set("title",HIR"�ڷ�˫ɷ֮[��ʬ]"NOR);
   
   set("age",46);
   set("qi",28080);
   set("max_qi",28080);
   set("food",250);
   set("water",250);
   set("neili",21080);
   set("max_neili",21080);
   set("force_factor",60);
   set("chat_chance",5);
   set("chat_msg",({
 "÷����������:������,��һ����ȥ��,������һ�����ܿ�.\n",
 "÷������������,���˿���,����ָ��ͷ���ϱȻ�������.\n",
 }));

    set_skill("claw", 320);
        set_skill("force", 280);
        set_skill("parry", 280);
        set_skill("dodge", 220);
        set_skill("jiuyin-baiguzhao", 320);
        set_skill("bibo-shengong", 290);
        set_skill("anying-fuxiang", 290);

        map_skill("force", "bibo-shengong");
        map_skill("parry", "luoying-shenjian");
        map_skill("dodge", "anying-fuxiang");
        map_skill("claw", "jiuyin-baiguzhao");
        prepare_skill("claw", "jiuyin-baiguzhao");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "claw.zhua" :),
                (: perform_action, "claw.cuijin" :),
                (: perform_action, "claw.zhua" :),
        }) );

   setup();
   add_money("silver",12);
carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
 object env;
 env=environment();
 if (ob->query("PKS")>40&&env->query("short")=="cave1")  {
	message_vision("$N����һ��������Ȼ���ˣ��������������ɣ�\n",
		this_object());
	command("guard south");
	kill_ob(ob);
	ob->fight_ob(this_object());
   }
 return;
}

void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;

who->set_temp("book521",1);
	call_out("leavet",1);
}


void leavet()
{
        object ob = this_object();
 message_vision("$N����������ȥ��\n" NOR,this_object());
        destruct(this_object());
}