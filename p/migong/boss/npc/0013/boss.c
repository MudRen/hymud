// This program is a part of NT mudlib
// boss ģ��

#include <ansi.h>

inherit BOSS;
//inherit  NPC;

int boss_attack();

void create()
{
	set_name( HIB "��������" NOR, ({ "hongyun laozu", "hongyun", "boss" }) );
	set("long", HIB "�����Ǻ��������ˣ������������Ʊ̿������Ʊ����ں��Ʊ������棬��"
	"�Դ������󷨣������ǳ���\n\n" NOR);
	
	set("gender",  "����");
	set("age", 60);
	set("no_get", 1);
	set("shen_type", -1);
	set("attitude", "aggressive");
	
	set("dex",150);
	set("con",150);
	set("int",150);
	set("str",150);
	
	set("combat_exp", 10000000);
	set("level", 12);
	set("qi", 660000);
	set("max_qi", 660000);
	set("jing", 660000);
	set("max_jing", 660000);
	set("neili", 300000);
	set("max_neili", 300000);
	set("neili", 300000);
	set("jiali", 500);
	
	set("chat_chance", 5);
	set("chat_msg", ({
	        HIB "��������ָ����˵���������ҵĺ�����ɣ�\n" NOR,
	}));
	
	set_temp("apply/attack", 400);
	set_temp("apply/damage", 1400);
	set_temp("apply/armor", 1500);
	set_temp("apply/defence",400);

	set_skill("dodge", 450);
	set_skill("force", 450);
	set_skill("unarmed", 450);
	set_skill("parry", 450); 
	set_skill("sword",450);
	set_skill("sharen-sword",500);
	set_skill("changquan",500);
	set_skill("shadowsteps",500);
	set_skill("cloudforce",500);
	map_skill("force", "cloudforce");
	map_skill("sword", "sharen-sword");
	map_skill("dodge", "shadowsteps");
	map_skill("parry", "changquan");
	map_skill("unarmed", "changquan");

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
	(: perform_action, "sword.sharenruma" :),
	(: perform_action, "unarmed.yuhuan" :),
	        (: boss_attack :),
	}));
	
    set_temp("apply/reduce_damage", 40);
    set_temp("apply/reduce_busy", 10);
    set_temp("apply/add_busy", 2);
  	set("bonus", random(12000)+1200);
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
                "FI&/clone/box/gbox"   :   5000,
                "RI&10"   :   5000,
                "GE&4"   :  5000,
               "KS&3"   :   3000,
                "BL&3"   :  3000,
                "RI&20"   :   1800,
                "GE&3"   :  1800,
                "JD&4"   :  1800,
                "YC&1"   :  1800,
                "WG&1"   :  1800,
               "KS&5"   :   300,
                "BL&5"   :  300,
                "YW&3"   :  200,
                "YA&3"   :  200,
                "TW&180"   :  600,
                "TA&180"   :  600,
"TZ&0"   :  300,
	]));
	
    setup();
    carry_object("/clone/money/gold")->set_amount(30+random(420));
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

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        return;
}

int boss_attack()
{
	if (this_object()->is_busy()) return 1;
	if (!this_object()->is_busy()) this_object()->start_busy(2);
	message_vision(HIB "$N" HIR "����һ�ӣ����һ�������󣡣� \n" NOR, this_object());
	
	remove_call_out("hurting");
	call_out("hurting", 0);
	return 1;
}

int hurting()
{
        int dam, i , num, busytime;
        object *inv;
        
        message_vision(HIR "����������������Ļ��Ʈ���´�Ƭ���꣬��Ƭ��ɫ���꣬һ��ɢ��"
       "�����������γ���������һ�ߴ��޴�����֮����һ�����һ𣬻���ͷ�����ն��ޱ�\n" NOR,
                       this_object());
                       
        inv = all_inventory(environment(this_object()));        

        num = sizeof(inv);       
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        
        dam = 8000 / num;
        busytime = 10 / num;
        
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
                      if (!inv[i]->is_busy()) busytime -= inv[i]->query_temp("apply/reduce_busy");
                      if (busytime>0) inv[i]->start_busy(busytime);
                }
        }
        return 1;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
	int damage;
  	damage = 400 + random(400);
	ob->receive_wound("qi", damage);

	return "$Nһȭ����$n�����д�Ѩ��"HIC "$n" HIC "ֻ��������й����Ҳ��û����������ε��ˣ�\n" NOR;
}

