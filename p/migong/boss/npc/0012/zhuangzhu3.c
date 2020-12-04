// This program is a part of NT mudlib
// boss ģ��

#include <ansi.h>

inherit BOSS;
//inherit  NPC;
//inherit  NPC;
#include "/d/migong/romnpc2.c"
int boss_attack();

void create()
{
	set_name( HIR "������" NOR, ({ "boss killer",  "boss" }) );
	set("long", HIB "��������������\n\n" NOR);
	set("title",  HIY"ʮ������������"NOR);
	set("gender",  "����");
	set("age", 30);
	set("no_get", 1);
	set("shen_type", -1);
	set("attitude", "aggressive");
	
	set("dex",100);
	set("con",100);
	set("int",100);
	set("str",100);
	
	set("combat_exp", 6800000);
	set("level", 10);
	set("qi", 390000);
	set("max_qi", 390000);
	set("jing", 390000);
	set("max_jing", 390000);
	set("neili", 390000);
	set("max_neili", 390000);
	set("neili", 90000);
	set("jiali", 300);
	
	set("chat_chance", 5);
	set("chat_msg", ({
	        HIB "ɱ��ׯׯ�������Ц������Ȼ���ˣ������������Ұɣ�\n" NOR,
	}));
	
	set_temp("apply/attack", 200);
	set_temp("apply/damage", 1000);
	set_temp("apply/armor", 1000);
	set_temp("apply/defence",200);

	set_skill("dodge", 300);
	set_skill("force", 300);
	set_skill("unarmed", 300);
	set_skill("parry", 300); 
	set_skill("sword",300);
	set_skill("sharen-sword",500);
	set_skill("changquan",500);
	set_skill("shadowsteps",500);
	set_skill("cloudforce",500);
	map_skill("force", "cloudforce");
	map_skill("sword", "sharen-sword");
	map_skill("dodge", "shadowsteps");
	map_skill("parry", "changquan");
	map_skill("unarmed", "changquan");

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
	(: perform_action, "sword.sharenruma" :),
	(: perform_action, "unarmed.yuhuan" :),
	        (: boss_attack :),
	}));
	
    set_temp("apply/reduce_damage", 40);
    set_temp("apply/reduce_busy", 10);
    set_temp("apply/add_busy", 2);
  	set("bonus", random(10000)+4000);
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
                "FI&/clone/box/gbox"   :   8000,
                "RI&10"   :   2000,
                "GE&3"   :  5000,
               "KS&3"   :   2000,
                "BL&3"   :  2000,
                "RI&10"   :   1000,
                "GE&3"   :  1000,
                "JD&4"   :  1000,
                "YC&1"   :  1000,
                "WG&1"   :  1000,
               "KS&3"   :   100,
                "BL&3"   :  100,
                "YW&3"   :  100,
                "YA&3"   :  100,
                "TW&180"   :  200,
                "TA&180"   :  200,
	"TZ&0"   :  300,
	]));
	
    setup();
    carry_object("/clone/money/gold")->set_amount(20+random(220));
	carry_object(__DIR__"obj/cloth")->wear();
	initlvl(500+random(30),0);
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

int boss_attack()
{
	if (this_object()->is_busy()) this_object()->start_busy(1);
	message_vision(HIB "$N" HIB "���������һ������ȫ������һ�㵭����"
	               "���������˺��񿴲�����ˣ���\n" NOR, this_object());
	
	remove_call_out("hurting");
	call_out("hurting", random(2) + 1);
	return 1;
}

int hurting()
{
        int dam, i , num;
        object *inv;
        
        message_vision(HIB "$N" HIB "���һ��������������ɢ���������������ƺ�����������û������\n" NOR,
                       this_object());
                       
        inv = all_inventory(environment(this_object()));        

        num = sizeof(inv);       
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        
        dam = 5000 / num;
        
        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object())
                {                        
                      dam -= inv[i]->query_temp("apply/reduce_damage");
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
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return 0;
  	damage = 200 + random(200);
	ob->receive_wound("qi", damage);
	ob->add("neili", -5*random(me->query("jiali")));
	me->set("neili", 5*random(me->query("jiali")));

	return "$N����һЦ���������$n�����д�Ѩ��"HIC "$n" HIC "�پ�ȫ��������ˮ����ѭ�׷�й������\n" NOR;
}

