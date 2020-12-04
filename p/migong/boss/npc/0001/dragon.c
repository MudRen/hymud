// This program is a part of NT mudlib
// boss ģ��

#include <ansi.h>

inherit BOSS;

int big_blowing();

void create()
{
        set_name( HIB "������" NOR, ({ "sea dragon king", "dragon king", "dragon" }) );
        set("long", HIB "����һ��ȫ����̣�����֮��ľ���������"
                    "����������ȫ��ɢ���ű���ɫ�Ĺ�â��\n\n" NOR);

        set("race", "Ұ��");
        set("gender", "����");
        set("age", 10);
        set("no_get", 1);
        set("shen_type", 0);
        set("attitude", "aggressive");
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("dex",100);
        set("con",100);
        set("int",100);
        set("str",100);

        set("combat_exp", 18000000);
        set("level", 20);
        set("qi", 1650000);
        set("max_qi", 1650000);
        set("jing", 1650000);
        set("max_jing", 1650000);
        set("neili", 800000);
        set("max_neili", 800000);
        set("neili", 800000);
        set("jiali", 2000);

        set("chat_chance", 5);
        set("chat_msg", ({
                HIB "���״���һ�����ˣ���������ߣ�\n" NOR,
                HIB "������ͻȻ�³�һ��տ�������ӣ��־��˻�ȥ��\n" NOR,
        }));





        set_temp("apply/attack", 200);
        set_temp("apply/damage", 4600);
        set_temp("apply/armor", 4600);
        set_temp("apply/defence",200);
      set_skill("dodge", 600);
      set_skill("force", 600);
      set_skill("unarmed", 600);
      set_skill("dragon",650);
      set_skill("spells",650);
     set_skill("magic-old",650);
      map_skill("unarmed", "dragon");
     set_skill("taiji-shengong",650);
      map_skill("force", "taiji-shengong");
      map_skill("dodge", "dragon");
      map_skill("spells", "magic-old");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
    (: perform_action, "unarmed.penhuo" :),
    (: perform_action, "unarmed.tuwu" :),
    (: perform_action, "unarmed.yaoyao" :),
                (: big_blowing :),
        }));
        set_temp("apply/add_xuruo", 60);
        set_temp("apply/reduce_damage", 80);
        set_temp("apply/reduce_busy", 20);
        set_temp("apply/add_busy", 5);
        
        set("bonus", random(50000)+5000);
// ��Ʒ���� ˵��
// ������� 10000Ϊ���,�ص�,5000Ϊ1/2����,����ԽС,����Ŀ���Խ��.
// �������йؼ����� FI ��ͷ��ʾΪ����ĳ���ض���Ʒ
// �������йؼ����� RI  ��ͷ��ʾΪ����ĳ����ָ %dΪ�ȼ�(10-60) 
// �������йؼ����� GE ��ͷ��ʾΪ����ĳ����ʯ %dΪ�ȼ�(1-8)
// �������йؼ����� JD ��ͷ��ʾΪ����ĳ��������������ʯ %dΪ�ȼ�(1-8)
// �������йؼ����� YC ��ͷ��ʾΪ����ҩ�� %dΪ��Ч����("����ȼ���Ч)
// �������йؼ����� WG ��ͷ��ʾΪ���䱦��װ�� %dΪ��Ч����
// �������йؼ����� KS ��ͷ��ʾΪ��������ÿ�ʯ %dΪ�ȼ�(1-10)
// �������йؼ����� BL ��ͷ��ʾΪ��������ò��� %dΪ�ȼ�(1-10)
// �������йؼ����� YW ��ͷ��ʾΪ���������������ʯ %dΪ�ȼ�(1-6)
// �������йؼ����� YA ��ͷ��ʾΪ��������������ʯ %dΪ�ȼ�(1-6)
// �������йؼ����� YW ��ͷ��ʾΪ���������������ʯ %dΪ�ȼ�(1-6)
// �������йؼ����� TW ��ͷ��ʾΪ����������� %dΪ�ȼ� (0-480)
// �������йؼ����� TA ��ͷ��ʾΪ���������� %dΪ�ȼ�(0-480)


	set("killer_reward", ([
                "FI&/clone/box/gbox"   :   10000,
                "RI&10"   :   9000,
                "GE&3"   :  9000,
               "KS&3"   :   9000,
                "BL&3"   :  9000,
                "RI&30"   :   4000,
                "GE&3"   :  4000,
                "JD&4"   :  4000,
                "YC&1"   :  4000,
                "WG&1"   :  4000,
               "KS&3"   :   500,
                "BL&3"   :  500,
                "YW&3"   :  500,
                "YA&3"   :  500,
                "TW&280"   :  1000,
                "TA&280"   :  1000,
"TZ&0"   :  150,
	]));
	
        setup();
        carry_object("/clone/money/gold")->set_amount(20+random(220));
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

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        return;
}

int big_blowing()
{
	      if (this_object()->is_busy()) this_object()->start_busy(1);
        message_vision(HIB "$N" HIB "�Ӻ�ˮ�����������һ������ȫ����ҫ��"
                       "����ɫ�����������ʹ��˼�������\n" NOR, this_object());

        remove_call_out("hurting");
        call_out("hurting", random(2) + 1);
        return 1;
}

int hurting()
{
        int dam, i , num;
        object *inv;
        
        message_vision(HIB "$N" HIB "�³�һ�ɾ޴�ĺ��ˣ�������������������ƺ�������û������\n" NOR,
                       this_object());
                       
        inv = all_inventory(environment(this_object()));        

        num = sizeof(inv);       
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        
        dam = 23000 / num;
        
        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object())
                {
                        dam -= inv[i]->query_temp("apply/reduce_cold");
                        if (dam <0) dam = 0;
                        
                        inv[i]->receive_damage("qi", dam);
                        inv[i]->receive_damage("jing", dam/3);
                        inv[i]->receive_wound("qi", dam);
                        inv[i]->receive_wound("jing", dam/3);
                        COMBAT_D->report_status(inv[i], 1);
                }
        }
        return 1;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
        int damage;
        int reduce;
        
        damage = 2800 + random(2800);
        reduce = (int)ob->query_temp("apply/reduce_cold");
        damage = damage - damage * reduce / 100;
        if (damage < 0) damage = 0;
        ob->receive_damage("qi", damage);
        ob->receive_wound("qi", damage/2);
        if (me->is_busy()) me->start_busy(1);
        me->set("neili", me->query("max_neili"));
        return HIB "$N" HIB "��������һ���³�һ�ں�������ʱ��$n"
               HIB "ȫ����������\n" NOR;
}

