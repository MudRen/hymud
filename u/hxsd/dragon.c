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
        set("age", 100);
        set("no_get", 1);
        set("shen_type", 0);
        set("attitude", "aggressive");
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("dex",100);
        set("con",100);
        set("int",100);
        set("str",100);

        set("combat_exp", 200000);
        set("level", 20);
        set("qi", 1);
        set("max_qi", 1);
        set("jing", 1);
        set("max_jing", 1);
        set("neili", 100);
        set("max_neili", 500000);
        set("neili", 500000);
        set("jiali", 2000);

        set("chat_chance", 5);
        set("chat_msg", ({
                HIB "���״���һ�����ˣ���������ߣ�\n" NOR,
                HIB "������ͻȻ�³�һ��տ�������ӣ��־��˻�ȥ��\n" NOR,
        }));

        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                (: big_blowing :),
                (: big_blowing :),	
        }));

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
      
        set_temp("apply/add_xuruo", 60);
        set_temp("apply/reduce_damage", 80);
        set_temp("apply/reduce_busy", 20);
        set_temp("apply/add_busy", 5);
        
        set("bonus", random(80000)+5000);
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
                "RI&30"   :   10000,
                "GE&3"   :  10000,
                "JD&3"   :  10000,
                "YC&1"   :  10000,
                "WG&1"   :  10000,
               "KS&3"   :  10000,
                "BL&3"   :  10000,
                "YW&2"   :  10000,
                "YA&2"   :  10000,
                "TW&280"   :  10000,
                "TA&280"   :  10000,
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
        
        dam = 20000 / num;
        
        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object())
                {
                        dam -= inv[i]->query_temp("apply/reduce_cold");
                        if (dam <0) dam = 0;
                        
                        inv[i]->receive_damage("qi", dam);
                        inv[i]->receive_damage("jing", dam/2);
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
        int reduce;
        
        damage = 2500 + random(2500);
        reduce = (int)ob->query_temp("apply/reduce_cold");
        damage = damage - damage * reduce / 100;
        if (damage < 0) damage = 0;
        ob->receive_damage("qi", damage);
        ob->receive_wound("qi", damage);
        me->set("neili", me->query("max_neili"));
        return HIB "$N" HIB "��������һ���³�һ�ں�������ʱ��$n"
               HIB "ȫ����������\n" NOR;
}

