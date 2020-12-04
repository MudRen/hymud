#include <ansi.h>
inherit F_MASTER;
inherit NPC;
int leave(); 
void create()
{
        set_name("������", ({ "dugu shang","dugu" }) );
        set("gender", "����" );
        set("long",
"һ����Ͱ��ݹ���᾵������ˣ�һ�������͵�Ƥ��������Ƥ��������ϣ�\n������Ҳ���������ߣ�ÿһ�֣�ÿһ�綼Ǳ���Ų��ɲ��������գ����ǿ�\n����������ʹ֮��ʹ����������µ�һ���֡�\n"
        );
        create_family("�����", 1, "��ʹ");
        set("attitude", "peaceful");
        set("rank_nogen",1);
        set("class","knight");
        set("reward_npc", 1);
        set("difficulty", 5);
    set("ranks",({"����","��ʿ","������","����ͳ��","����ʹ",RED"������ʹ"NOR,RED"������ʹ"NOR,HIR"һ�ֲ�����"NOR}));
        set("chat_chance_combat",50);
        set("chat_msg_combat",({
        (:perform_action,"axe.guifushengong":),
        (:perform_action,"dodge.fengliu":),
                }));
        set("age", 45);
        set("str", 30);
        set("cps", 40);
        set("int", 10);
        set("per", 4);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 5500000);
        set("force_factor", 50);
        set_temp("apply/armor",50);
        set_temp("apply/damage",50);
        set("chat_chance", 1);
        set("chat_msg", ({
                "���������һ����ббƳ����һ�ۡ�\n",
        }) );
        set("combat_exp", 10000000);
        set("score", 200000);

        set_skill("dodge", 100);
        set_skill("parry",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("literate", 80);
	set_skill("unarmed",260);
	set_skill("demon-steps",500);
	set_skill("demon-strike",500);
	set_skill("demon-force",500);
	set_skill("blade",150);
	set_skill("demon-blade",550);
	set_skill("xuanyuan-axe",550);
        map_skill("dodge", "demon-steps");
	map_skill("force", "demon-force");
	map_skill("unarmed", "demon-strike");
	map_skill("blade","demon-blade");
	map_skill("axe","xuanyuan-axe");
	map_skill("parry","demon-blade");

set("pubmaster",1);
        set("max_neili", 55000);
        set("neili", 55000);
        set("force_factor", 30);
	set("max_qi",92999);
        set("max_jing",29999);
	set("eff_qi",29999);
	set("qi",29999);
	set("eff_jing",29999);
	set("jing",29999);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);
        setup();
  carry_object("clone/weapon/axe")->wield();
        carry_object(__DIR__"obj/foxcloth")->wear();
} 
void attempt_apprentice(object me)
{
        command("smile");
        command("recruit " + me->query("id") );
                return;
} 

int accept_fight(object me)
{
        if(me->query("family/family_name") == query("family/family_name") &&
           me->query("family/master_id") == query("id"))
        {
                command("say �ã���Ӯ���ң���Ϳ���ȥ����үѧϰ�ˣ�\n");
           return 1;
        }
        else
        {
                command("say ��֪С�����ط�����ǰ���󵶣����Ϸ��ѵ��һ��Ҳ�ã�\n");
                return 1;
        }
} 
void win_enemy(object loser)
{
    command("say ��������ӹ�ţ�\n");
} 
void lose_enemy(object winner)
{
    command("say �������ˡ���\n");
    winner->set_temp("marks/knight_win_dugu",1);
}  
int leave() {
        if (this_player()->query("class")!="knight") return 0;
        message_vision(CYN"$Nһ������$n��ƨ���ϡ�\n"NOR, this_object(),this_player());
        message_vision(CYN"$N˵���Ժ������ԯ��ʹ�������ɱ���ҡ�\n"NOR,this_object(),this_player());
        return 1;
}   
