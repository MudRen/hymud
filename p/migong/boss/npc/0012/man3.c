// This program is a part of NITAN MudLIB

#include <ansi.h>
inherit BOSS;
//inherit  NPC;
#include "/d/migong/romnpc2.c"
string *first_name = ({ "̫�幬", "��ʦ��", "�����", "����"});
string *first_id = ({ "taiqing", "tianshi", "xuanmiao", "qingyang"});
string *name_words = ({ "��ͽ"});
string *id_words = ({ "tu"});

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
	
	set("combat_exp", 3000000);
	set("level", 5);
	set("qi", 23000);
	set("max_qi", 23000);
	set("jing", 23000);
	set("max_jing", 23000);
	set("neili", 23000);
	set("max_neili", 23000);
	set("neili", 20000);
	set("jiali", 100);

	set_temp("apply/attack", 100);
	set_temp("apply/attack", 100);
	set_temp("apply/damage", 300);
	set_temp("apply/armor", 300);
	set_temp("apply/defence",100);
	set_skill("dodge", 200);
	set_skill("force", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200); 
	set_skill("sword",200);
	set_skill("lefthand-sword",200);
	set_skill("shadowsteps",200);
	set_skill("cloudforce",200);
	map_skill("force", "cloudforce");
	map_skill("sword", "lefthand-sword");
	map_skill("dodge", "shadowsteps");
	set("bonus", random(280)+220);
	set("killer_reward", ([
	      "FI&/clone/box/gbox"   :   300,
	      "TW&180"   :  200,
	      "TA&180"   :  200,
	]));
	

	
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
initlvl(230+random(30),0);
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
        
