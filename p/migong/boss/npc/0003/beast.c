#include <ansi.h>

inherit BOSS;
string *first_name = ({ "��", "��"});
string *first_id = ({ "wind", "cloud"});
string *name_words = ({ "����", "��"});
string *id_words = ({ "juling", "guai"});
int combatpower();

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
        
        set("age", 20);
        set("vrm_guard", 1);
        set("attitude", "aggressive");

        set("dex",100);
        set("con",100);
        set("int",100);
        set("str",100);
        
        set("combat_exp", 4000000);
        set("level", 20);
        set("qi", 60000);
        set("max_qi", 60000);
        set("jing", 60000);
        set("max_jing", 60000);
        set("neili", 50000);
        set("max_neili", 50000);
        set("jiali", 1000);

        set_skill("unarmed", 2000); 
        set_skill("dodge", 2000); 
        set_skill("parry", 2000); 
        set_skill("force", 2000); 
	
  set_skill("dodge", 500);
      set_skill("force", 500);
      set_skill("unarmed", 500);
      set_skill("dragon",550);
      set_skill("spells",550);
     set_skill("magic-old",650);
      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");
      map_skill("spells", "magic-old");
 set_temp("apply/attack", 100);
        set_temp("apply/damage", 600);
        set_temp("apply/armor", 600);
        set_temp("apply/defence",100);  
		set("bonus", random(200)+500);
        set("killer_reward", ([
                "FI&/clone/box/gbox"   :   500,
                "TW&280"   :  300,
                "TA&280"   :  300,
        ]));

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
        
        damage = 400 + random(400);
        damage -= ob->query_temp("apply/reduce_wind");
        if (damage < 0) damage = 0;
        ob->receive_wound("qi", damage);
        me->set("neili", me->query("max_neili"));
        return HIC "$N" HIC "��������һ������һ���磬��ʱ��$n"
               HIC "�������絶��һ�㡣\n" NOR;
}

