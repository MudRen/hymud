#include <ansi.h>

inherit "/p/migong/necropolis/necropolis_npc";
void do_bone_spear();
void create()
{
        string *names = ({"���÷�ʦ"}); 
        // set_name( names[random(sizeof(names))], ({ "skeleton mage","skeleton"}));
        set_name( names[random(sizeof(names))], ({ "skeleton mage" }));
        set("vendetta_mark","skeleton");
        set("long", "����һֻ��ͷ���ӡ�\n");
        set("title", HIB "(����)" NOR); 

        set("str", 50);
        set("con", 120);
        set("dex", 50); 
        set("int", 50);
        set("max_qi", 80000);
        set("max_jing", 85000);
        set("neili", 450000);
        set("max_neili", 450000);
        set("max_jingli", 50000);
        set("attitude", "peaceful");
        set("chat_chance", 1);
        set("chat_msg", ({
                "���ÿն����ۿ�����˸�ſ��µ�ӫ�⡣\n"
        }) ); 
        set("death_msg",BLU"\n$Nɢ����һ�����ͷ��\n\n"NOR);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	        (: do_bone_spear() :),
        }) ); 

        set("combat_exp", 150000000);
        set("bellicosity", 5 );
        set_skill("force", 120);
        set_skill("dodge", 120);
        set_skill("unarmed", 120);
        set_skill("staff", 120);
        set_skill("parry", 120);              
        set_temp("apply/attack", 1000);
        set_temp("apply/parry", 500);
        set_temp("apply/damage", 100);

        setup();
        carry_object(__DIR__"obj/bone_staff")->wield();
} 

int is_undead() {
	return 1;
}

void do_bone_spear() {
	object *enemies,enemy;
	enemies = query_enemy();
	if(!enemies || sizeof(enemies)==0)
		return;
	enemy = enemies[random(sizeof(enemies))];
        message_vision(HIW"\n$Nɳ�Ƶ��������������һ����ͷͻȻ����һֻ��ì����$n��\n"NOR,this_object(),enemy);
	enemy->receive_damage("qi",3000+random(3000),this_object());
	COMBAT_D->report_status(enemy);
	if (! this_object()->is_busy())
	        this_object()->start_busy(2);
}
