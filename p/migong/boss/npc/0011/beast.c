#include <ansi.h>
inherit BOSS;
string *first_name = ({ "С��", "С��"});
string *first_id = ({ "jin", "yin"});
string *name_words = ({ "����", "���"});
string *id_words = ({ "she", "mang"});
int combatpower();

void create()
{
        string name;
//        	mapping npc,mp,j;
	int i,j,k,a,b,c,d,e,f,temp;
        i = random(sizeof(first_name));
        name = first_name[i];
        j = random(sizeof(name_words));
        name += name_words[j];

        set_name(name, ({ first_id[i]+" "+id_words[j] }) );
        // random_name_color(this_object());
        
        set("age", 20);
        set("vrm_guard", 1);
	set("attitude", "aggressive");

        set("dex",100);
        set("con",100);
        set("int",100);
        set("str",100);
        
        set("combat_exp", 100000000);
        set("level", 10);
        set("qi", 100000);
        set("max_qi", 100000);
        set("jing", 100000);
        set("max_jing", 100000);
        set("neili", 200000);
        set("max_neili", 200000);
        set("neili", 200000);
        set("jiali", 1000);

        set_skill("unarmed", 1000); 
        set_skill("dodge", 1000); 
        set_skill("parry", 1000); 
        set_skill("force", 1000); 
	

	set_temp("apply/attack", 100);
        set_temp("apply/attack", 100);
        set_temp("apply/damage", 3600);
        set_temp("apply/armor", 3600);
        set_temp("apply/defence",100); 
 set_skill("dodge", 800);
      set_skill("force", 800);
      set_skill("unarmed", 800);
      set_skill("dragon",850);
      set_skill("spells",850);
     set_skill("magic-old",850);
      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");
      map_skill("spells", "magic-old");

if (random(18)==0)
{
set("nickname",HIY"�书�߳�"NOR);
        set_skill("spells",1000+random(1000));
        set_skill("force",1000+random(1000));
	set_skill("unarmed",1000+random(1000));
	set_skill("sword",1000+random(1000));
	set_skill("club",1000+random(1000));
	set_skill("whip",1000+random(1000));
	set_skill("throwing",1000+random(1000));
	set_skill("parry",1000+random(1000));
}
else
if (random(18)==0)
{
set("nickname",MAG"ħ��ǿ��"NOR);
      set_skill("magic-unarmed", 850+random(1300));
      set_skill("magic-sword", 850+random(1300));
      set_skill("magic-ice", 850+random(1200));
      set_skill("magic-water", 850+random(1200));
      set_skill("magic-fire", 850+random(1200));
      set_skill("magic-earth", 850+random(1200));
      set_skill("magic-light", 850+random(1200));
      set_skill("magic-dark", 850+random(1200));
}
else
if (random(18)==0)
{
set("nickname",HIB"����ḻ"NOR);
set("combat_exp",150000000+random(58000000));
}
else
if (random(18)==0)
{
set("nickname",HIR"ǿ����"NOR);
set("dex",300);
        set("jing",900000);
        set("max_jing",900000);
        set("eff_jing",900000);
        set("qi",900000);
        set("max_qi",900000);
        set("eff_qi",900000);
        set("neili",900000);
        set("max_neili",900000);
}
else
if (random(18)==0)
{
set("nickname",HIC"������ǿ"NOR);
d=188+random(188);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
}
else
if (random(18)==0)
{
set("dex",300);
        set("jing",800000);
        set("max_jing",800000);
        set("eff_jing",800000);
        set("qi",800000);
        set("max_qi",800000);
        set("eff_qi",800000);
        set("neili",800000);
        set("max_neili",800000);
      set_skill("magic-unarmed", 850+random(800));
      set_skill("magic-sword", 850+random(800));
      set_skill("magic-ice", 850+random(800));
      set_skill("magic-water", 850+random(800));
      set_skill("magic-fire", 850+random(800));
      set_skill("magic-earth", 850+random(800));
      set_skill("magic-light", 850+random(800));
      set_skill("magic-dark", 850+random(800));
        set_skill("spells",850+random(800));
        set_skill("force",850+random(800));
	set_skill("unarmed",850+random(800));
	set_skill("sword",850+random(800));
	set_skill("club",850+random(800));
	set_skill("whip",850+random(800));
	set_skill("throwing",850+random(800));
	set_skill("parry",850+random(800));
set("nickname",HIC"�����޵�"NOR);
d=188+random(188);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
}
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
    (: perform_action, "unarmed.penhuo" :),
    (: perform_action, "unarmed.tuwu" :),
    (: perform_action, "unarmed.yaoyao" :),
        }));
        set("killer_reward", ([
                "FI&/clone/box/gbox"   :   500,
                "TW&480"   :  300,
                "TA&480"   :  300,
        ]));
	set("bonus", 950);
	set_weight(500000);
       setup();
        
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
        
        damage = 880 + random(880);
        damage -= ob->query_temp("apply/reduce_poison");
        if (damage < 0) damage = 0;
        ob->receive_wound("qi", damage);
        me->set("neili", me->query("max_neili"));
        return HIC "$N" HIC "��������һ���³�һ�ڶ�������ʱ��$n"
               HIC "��֫�ܵ�������ʴ��\n" NOR;
}



