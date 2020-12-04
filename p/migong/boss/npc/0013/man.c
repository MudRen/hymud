// This program is a part of NITAN MudLIB

#include <ansi.h>
inherit BOSS;
//inherit  NPC;

string *first_name = ({ "����"});
string *first_id = ({ "hongyun"});
string *name_words = ({ "צ��", "��Ժ", "����", "��˾"});
string *id_words = ({ "zhaoya","huyuan","duozhu","zhangsi"});

void create()
{
	string name;
	int i, j;
	
	i = random(sizeof(first_name));
	name = first_name[i];
	j = random(sizeof(name_words));
	name += name_words[j];
	
	set_name(name, ({ first_id[i]+" "+id_words[j] }) );
	// random_name_color(this_object());
	
	set("gender",  "����");
	set("age", 30);
	set("no_get", 1);
	set("shen_type", -1);
	set("attitude", "aggressive");
	set("vrm_guard", 1);
	
	set("dex",60);
	set("con",60);
	set("int",60);
	set("str",60);
	
	set("combat_exp", 7000000);
	set("level", 5);
	set("qi", 30000);
	set("max_qi", 30000);
	set("jing", 30000);
	set("max_jing", 30000);
	set("neili", 30000);
	set("max_neili", 30000);
	set("neili", 20000);
	set("jiali", 200);

	set_temp("apply/attack", 200);
	set_temp("apply/attack", 200);
	set_temp("apply/damage", 500);
	set_temp("apply/armor", 500);
	set_temp("apply/defence",200);
	set_skill("dodge", 400);
	set_skill("force", 400);
	set_skill("unarmed", 400);
	set_skill("parry", 400); 
	set_skill("sword",400);
	set_skill("lefthand-sword",400);
	set_skill("shadowsteps",400);
	set_skill("cloudforce",400);
	map_skill("force", "cloudforce");
	map_skill("sword", "lefthand-sword");
	map_skill("dodge", "shadowsteps");
	set("bonus", random(280)+180);
	set("killer_reward", ([
	      "FI&/clone/box/gbox"   :   300,
	      "TW&180"   :  200,
	      "TA&180"   :  200,
	]));
	
	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
	        (: perform_action, "sword.duxin" :),     
	}) );
	
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/changjian")->wield();
}

void init()
{
	object me, ob;
	
	::init();
	if (! interactive(me = this_player()))
	      return;
	
	if( !me->is_character() || me==this_object() || !me) return;
	if(me->query("vendetta/authority")) return;
	if(!userp(me)) return;
	
	remove_call_out("kill_ob");
	call_out("kill_ob", 0, me);
}
        
mixed hit_ob(object me, object ob, int damage_bouns)
{
	int damage;
  	damage = 200 + random(200);
	ob->receive_wound("qi", damage);
	ob->start_busy(2);

	return "$NͻȻʹ��͵ѧ��ΤһЦ����������$n���õ�������������Ӱ����֪������ô��ź��ˣ�\n" NOR;
}
