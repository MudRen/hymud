// This program is a part of NT mudlib
// boss ģ��

#include <ansi.h>


inherit BOSS;

int big_blowing();

void create()
{
	set_name(HIG "������" NOR, ({ "jinyin she", "yinhui", "yin she", "she" }) );
	set("race", "Ұ��");
	set("gender", "����");
	set("age", 20);
	set("long", 
HIG"����һ��ȫ����̣������֮�����������ľ�������ȫ��ɢ���ű���ɫ�Ĺ�â��\n\n"NOR);

        set("dex",100);
        set("con",100);
        set("int",100);
        set("str",100);

        set("combat_exp", 150000000);
        set("level", 15);
        set("qi", 2500000);
        set("max_qi", 2500000);
        set("jing", 2500000);
        set("max_jing", 2500000);
        set("neili", 3000000);
        set("max_neili", 3000000);
        set("jiali", 15000);

        set("chat_chance", 5);
        set("chat_msg", ({
                HIB "һ�Ŷ��̾��˹������������ճɻң�\n" NOR,
                HIB "������ͻȻ�³�һ�ű��̵Ķ��̣�\n" NOR,
        }));

 set_skill("dodge", 1200);
      set_skill("force", 1200);
      set_skill("unarmed", 1200);
      set_skill("dragon",1250);
      set_skill("spells",1250);
     set_skill("magic-old",1250);
      map_skill("unarmed", "dragon");

     set_skill("taiji-shengong",1250);
      map_skill("force", "taiji-shengong");

      map_skill("dodge", "dragon");
      map_skill("spells", "magic-old");
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
    (: perform_action, "unarmed.penhuo" :),
    (: perform_action, "unarmed.tuwu" :),
    (: perform_action, "unarmed.yaoyao" :),
                (: big_blowing :),
        }));
set_temp("apply/dodge", 200);
        set_temp("apply/attack", 200);
        set_temp("apply/damage", 6600);
        set_temp("apply/armor", 6600);
        set_temp("apply/defence",200);
        
        // ��Ʒ����
	        set("bonus", random(100000)+5000);
	set("killer_reward", ([
                "FI&/clone/box/gbox"   :   10000,
                "RI&10"   :   8000,
                "GE&3"   :  8000,
               "KS&3"   :   8000,
                "BL&3"   :  8000,
                "RI&60"   :   5000,
                "GE&6"   :  5000,
                "JD&7"   :  5000,
                "YC&4"   :  5000,
                "WG&4"   :  5000,
                "KS&7"   :  500,
                "BL&8"   :  500,
                "YW&5"   :  500,
                "YA&5"   :  500,
                "TW&480"   :  1000,
                "TA&480"   :  1000,
"TZ&0"   :  600,
	]));

        setup();
        carry_object("/clone/money/gold")->set_amount(200);
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

int big_blowing()
{
        message_vision(HIB "$N" HIB "���������һ������ȫ���������Ĺ�â��"
                       "�����߸��ʹ��˼�������\n" NOR, this_object());
if (this_object()->is_busy()) this_object()->start_busy(1);
        remove_call_out("hurting");
        call_out("hurting", random(2) + 1);
        return 1;
}

int hurting()
{
        int dam, i , num;
        object *inv;
        
        message_vision(HIB "$N" HIB "�³�һ�ɱ��̵Ķ��̣������������������˹�ȥ������\n" NOR,
                       this_object());
                       
        inv = all_inventory(environment(this_object()));        

        num = sizeof(inv);       
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        
        dam = 28000 / num;
        
        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object())
                {
                        dam -= inv[i]->query_temp("apply/reduce_poison");
                        if (dam <0) dam = 0;
                        inv[i]->start_busy(2);
                        inv[i]->receive_wound("qi", dam);
                        inv[i]->receive_wound("jing", dam/2);
                        COMBAT_D->report_status(inv[i], 1);
                }
        }
        return 1;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
        int damage;
        if (me->is_busy()) me->start_busy(1);
        
        damage = 5000 + random(5000);
        damage -= ob->query_temp("apply/reduce_cold");
        if (damage < 0) damage = 0;
        
        ob->receive_wound("qi", damage);
        me->set("neili", me->query("max_neili"));
        return HIB "$N" HIB "��������һ���³�һ�Ŷ�����ʱ��$n"
               HIB "��֫�ܵ�������ʴ��\n" NOR;
}


