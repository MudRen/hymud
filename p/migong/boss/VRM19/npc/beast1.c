#include <ansi.h>
inherit BOSS;

string *first_name = ({ "ˮ", "��"});
string *first_id = ({ "shenshou"});
string *name_words = ({ "����", "��"});
string *id_words = ({ "hufa"});

void create()
{
        string name;
        int i, j;
        
        i = random(sizeof(first_name));
        name = "����" + first_name[i];
        j = random(sizeof(name_words));
        name += name_words[j];

        set_name(name, ({ "shenshou hufa"}) );
        set("age", 20);
	 set("attitude", "aggressive");

        set("dex",100);
        set("con",100);
        set("int",100);
        set("str",100);
        
        set("level", 1);
        set("combat_exp", 8000000);
        set("qi", 100000);
        set("max_qi", 100000);
        set("jing", 100000);
        set("max_jing", 100000);
        set("neili", 80000);
        set("max_neili", 80000);
        set("neili", 80000);
        set("jiali", 2000);

        set_skill("unarmed", 500); 
        set_skill("dodge", 500); 
        set_skill("parry", 500); 
        set_skill("force", 500); 
	
set("vendetta/authority",1);
	set_temp("apply/attack", 100);
	set_temp("apply/damage", 600);
	set_temp("apply/armor", 600);
	set_temp("apply/defence",100);
	set_skill("dodge", 500);
	set_skill("force", 500);
	set_skill("unarmed", 500);
	set_skill("dragon",550);
	set_skill("spells",550);
	set_skill("magic-old",650);
	map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");
      map_skill("spells", "magic-old");
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
}
        
mixed hit_ob(object me, object ob, int damage_bouns)
{
        int damage;
        
        damage = 800 + random(800);
        damage -= ob->query_temp("apply/reduce_cold");
        if (damage < 0) damage = 0;
        ob->receive_wound("qi", damage);
        me->set("neili", me->query("max_neili"));
        return HIC "$N" HIC "��������һ���³�һ�ں�������ʱ��$n"
               HIC "��֫����������\n" NOR;
}

void unconcious()
{
	die();
}

