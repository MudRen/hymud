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
	set_name( HIR "���۾�" NOR, ({ "boss killer","boss" }) );
	set("long", HIY "�����ǽ��Ϸ���������\n\n" NOR);
	
	set("gender",  "Ů��");
	set("age", 30);
	set("no_get", 1);
	set("shen_type", -1);
	set("attitude", "aggressive");
	set("title",  HIC"���Ϸ�������"NOR);
	set("per",30);
            set("dex",100);
        set("con",100);
        set("int",100);
        set("str",100);

         set("combat_exp", 70000000);
               set("level", 70);
        set("qi", 2050000);
	set("max_qi", 2050000);
	set("max_jing", 2050000);
        set("jing", 2200000);
        set("max_jing", 2200000);
	set("jiali",1000);
	set("max_neili",900000);
	set("neili",900000);
  set_temp("apply/attack", 200);
        set_temp("apply/damage", 3600);
        set_temp("apply/armor", 3600);
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
  	set("bonus", random(70000)+7000);
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
                "RI&10"   :   8000,
                "GE&4"   :  8000,
               "KS&3"   :   8000,
                "BL&3"   :  3000,
                "RI&30"   :   3000,
                "GE&3"   :  3000,
                "JD&4"   :  2000,
                "YC&1"   :  2000,
                "WG&1"   :  2000,
               "KS&5"   :   500,
                "BL&5"   :  500,
                "YW&3"   :  500,
                "YA&3"   :  500,
                "TW&180"   :  900,
                "TA&180"   :  900,
"TZ&0"   :  350,
	]));
	
    setup();
    carry_object("/clone/money/gold")->set_amount(20+random(220));
	carry_object("/clone/misc/cloth")->wear();
initlvl(990+random(130),53);
}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight"))
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

int hit_ob(object me, object ob, int damage)
{
	if (me->is_busy()) me->start_busy(1);
me->clear_condition();	

  if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
if (random(10)==0)
{
ob->apply_condition("new_poison1", 5); 
}
else if (random(9)==0)
{
ob->apply_condition("new_poison2", 5); 
}
else if (random(8)==0)
{
ob->apply_condition("new_poison3", 5); 
}
else if (random(7)==0)
{
ob->apply_condition("new_poison4", 5); 
}
else if (random(6)==0)
{
ob->apply_condition("new_poison5", 5); 
}
else if (random(5)==0)
{
ob->apply_condition("new_poison6", 5); 
}
        tell_object(ob, HIG "����ñ����еĵط�����һ��⻪��\n" NOR );
}
}
int big_blowing()
{
if (this_object()->is_busy()) this_object()->start_busy(1);
	this_object()->clear_condition();
        return 1;
}