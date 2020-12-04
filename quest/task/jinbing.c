#include <ansi.h>
inherit NPC;
#include "/quest/givehdgift.c"
string *nm1_jp =({
"����",
});
    
string *nm2_jp =({
"��","Т","��","��","��","��","��","��","��","��","��","»","��","С","��",
"��","��","��","��","��","��","��","֮","��","��","ʱ","��","��","��","��",
"��","��","��","��","��","��","��","��","Ϊ","��","��","����",
});

void create()
{
   int i = random(sizeof(nm1_jp));
    set_name(nm1_jp[i]+nm2_jp[random(sizeof(nm2_jp))], ({"jinbing"}));
    set("gender", "����" );//�Ա��������Ӧ
        set("long",
"һ��ȫ�����ҵĽ����\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
        set("taskid", 1);
	set("nickname",HIR"���ʿ��"NOR);
 if (random(3)==0) set("nickname",HIR"���СУ"NOR);
if (random(4)==0) set("nickname",HIR"�������"NOR);
if (random(5)==0) set("nickname",HIR"���Ԫ˧"NOR);
 set("force_factor",2+random(1390));
  set("max_qi",1300+random(1690));
  set("max_jing",1300+random(1890));
  set("max_sen",1300+random(1890));
  set("max_neili",1300+random(1890));
  set("max_mana",1300+random(1890));
  set("eff_neili",1300+random(1390));
  set("neili",1300+random(1390));
        set("per", 25);
        set("age", 22);
        //set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 400000+random(8000000));
	set("bellicosity", 10000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "club.fanzhuan" :),
                (: perform_action, "club.huimaqiang" :),

        }) );
        set("chat_chance", 20);
        set("chat_msg", ({
                "��������ȵ���ɱ���ģ���\n",
                "�������Ц�������һ��Ҫ��������!\n",
                (: random_move :),
        }) );

        set_skill("unarmed", 80+random(180));
        set_skill("club", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("zhong-qiang", 380+random(180));
        
	map_skill("club", "zhong-qiang");
	map_skill("parry", "zhong-qiang");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);

        setup();

	carry_object("/d/city/obj/tiejia")->wear();
        carry_object("/quest/weiguo/jinbing/obj/changqiang")->wield();
	add_money("silver", random(50));
}
void init()
{
        remove_call_out("leave");
        call_out("leave",180);
}
void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "���·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}

int die()
{
        object ob, me, corpse,who;
        int exp;
        ob = this_object();
        who=ob;
        me = query_temp("last_damage_from");
        
if (me)
{
        message_vision(WHT"$N���һ��,�������!!���ض�����\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        //if((int)me->query("combat_exp") < 1800000)   {
exp=300+random(188);
addnl(me,"exp",exp);
me->add_temp("tjobk",1);
if (me->query_temp("tjobk",1)>=5)
{
if ((int)me->query_temp("tjoblx",1)<7)
{
if (random(2)==0)
"/adm/daemons/taskd"->give_gift3(2,who,me);
else
"/adm/daemons/taskd"->give_gift3(3,who,me);
if (me->query_temp("nhdjob2sc"))
message_vision("$Nͨ���ڵ���ʬ���ϲ��ң��õ���һ������:\n" + me->query_temp("nhdjob2sc") + "��\n", me);
}
me->set_temp("tjobstart",0);
me->set_temp("tjobk",0);
me->delete_temp("tjobstart");
me->delete_temp("tjobk");
me->clear_condition("taskjob_busy");

}
        destruct(ob);
        return 1;
}
}
