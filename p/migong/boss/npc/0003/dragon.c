// This program is a part of NT mudlib
// boss ģ��

#include <ansi.h>

inherit BOSS;

int big_blowing();

void create()
{
	set_name(HIW "���ƾ���" NOR, ({ "cloud dragon king", "dragon king", "dragon" }) );
	set("race", "Ұ��");
	set("gender", "����");
	set("age", 20);
	set("long", 
HIC"����һ��ȫ��Өѩ�ף�������֮�������������������ȫ��ɢ���Ű���Ĺ�â��\n\n"NOR);

        set("dex",100);
        set("con",100);
        set("int",100);
        set("str",100);

        set("combat_exp", 40000000);
        set("level", 40);
        set("qi", 1780000);
        set("max_qi", 1780000);
        set("jing", 1780000);
        set("max_jing", 1780000);
        set("neili", 1780000);
        set("max_neili", 1780000);
        set("jiali", 1000);

        set("chat_chance", 5);
        set("chat_msg", ({
                HIB "һ�Ű���Ʈ������������ߣ�\n" NOR,
                HIB "���ƾ���ͻȻ�³�һ�ž�Ө�����ӣ��־��˻�ȥ��\n" NOR,
        }));

  set_temp("apply/attack", 200);
        set_temp("apply/damage", 3600);
        set_temp("apply/armor", 3600);
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
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
    (: perform_action, "unarmed.penhuo" :),
    (: perform_action, "unarmed.tuwu" :),
    (: perform_action, "unarmed.yaoyao" :),
                (: big_blowing :),
        }));

        set_temp("apply/attack", 4000+random(4000));
        set_temp("apply/unarmed_damage",4000+random(4000));
        set_temp("apply/armor", 8000+random(8000));
        set_temp("apply/add_xuruo", 80);
        set_temp("apply/reduce_damage", 80);
        set_temp("apply/reduce_busy", 20);
        set_temp("apply/add_busy", 5);
        
     set_temp("apply/add_xuruo", 60);
        set_temp("apply/reduce_damage", 80);
        set_temp("apply/reduce_busy", 20);
        set_temp("apply/add_busy", 5);
        
    set_temp("apply/attack", 200);
        set_temp("apply/damage", 3600);
        set_temp("apply/armor", 3600);
        set_temp("apply/defence",200);
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
        
        set("bonus", random(65000)+5000);
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
                "RI&10"   :   8000,
                "GE&3"   :  8000,
               "KS&3"   :   8000,
                "BL&3"   :  8000,
                "RI&30"   :   5000,
                "GE&3"   :  5000,
                "JD&4"   :  5000,
                "YC&1"   :  5000,
                "WG&1"   :  5000,
               "KS&5"   :   800,
                "BL&5"   :  800,
                "YW&3"   :  800,
                "YA&3"   :  800,
                "TW&280"   :  1000,
                "TA&280"   :  1000,
"TZ&0"   :  250,
	]));


        setup();
        carry_object("/clone/money/gold")->set_amount(300);
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
        message_vision(HIB "$N" HIB "�Ӱ��������������һ������ȫ����ҫ�۵İ�ɫ��"
                       "���������ʹ��˼�������\n" NOR, this_object());
if (this_object()->is_busy()) this_object()->start_busy(1);
        remove_call_out("hurting");
        call_out("hurting", random(2) + 1);
        return 1;
}

int hurting()
{
        int dam, i , num;
        object *inv;
        
        message_vision(HIB "$N" HIB "�³�һ�ɾ޴�����ƣ�������������������ƺ�������û������\n" NOR,
                       this_object());
                       
        inv = all_inventory(environment(this_object()));        

        num = sizeof(inv);       
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        
        dam = 26000 / num;
        
        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object())
                {
                        dam -= inv[i]->query_temp("apply/reduce_cloud");
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
        
        damage = 3000 + random(3000);
        damage -= ob->query_temp("apply/reduce_cold");
        if (damage < 0) damage = 0;
        ob->receive_damage("qi", damage);
        ob->receive_wound("qi", damage);
        me->set("neili", me->query("max_neili"));
        return HIB "$N" HIB "���𡱵�һ���³�һƬ���ƣ���ʱ��$n"
               HIB "���׺䶥��\n" NOR;
}

