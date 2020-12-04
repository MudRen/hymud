#include <ansi.h>

inherit "/p/migong/necropolis/necropolis_npc";

void create()
{
        string *names = ({ "����" }); 
        set_name( names[random(sizeof(names))], ({ "ghost"}));
        set("vendetta_mark", "ghost");
        set("long", "���Ǹ��������ֵ����顣\n");
        set("title", HIB "(����)" NOR); 

        set("str", 50);
        set("con", 120);
        set("dex", 22); 
        set("int", 50);
        set("max_qi", 20000);
        set("max_jing", 25000);
        set("neili", 250000);
        set("max_neili", 250000);
        set("max_jingli", 50000);
        set("attitude", "peaceful");
        //set("shen_type", -1);        
        //set("chat_chance", 2);
        //set("chat_msg", ({
        //      "���ÿն����ۿ�����˸�ſ��µ�ӫ�⡣\n"
        //}) ); 

        //set("chat_chance_combat", 50);
        //set("chat_msg_combat", ({
        //      (: do_stun() :),
        //}) ); 
        set("self_go_msg",1);
        set("arrive_msg","����Ʈ�˹�����");
        set("leave_msg","����Ʈ���ˡ�");
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :)
        }) );  
        set("combat_exp", 100000000);
        set("bellicosity", 5 );
        set("death_msg",BLU"\n$N��ʧ�����ˡ�\n\n"NOR);
        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 30);
        set_skill("parry", 30);

        set_temp("apply/attack", 1000);
        set_temp("apply/parry", 1000);
        set_temp("apply/unarmed_damage", 500);
        setup();
} 

int is_undead() {
	return 1;
}

/*
int is_ghost() {
	return 1;
}
*/

