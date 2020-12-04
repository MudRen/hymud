// nan.c

inherit NPC;
#include <ansi.h>;
void create()
{

	set_name("�Ϻ�����", ({ "nanhai eshen", "eshen" }));
	set("gender", "����");
	set("nickname", HIG"�����ɷ"NOR);
	set("age", 34);
	set("str", 25);
	set("dex", 16);
	set("per", 21);
	set("long", "���˵�һ���Դ�������Ѱ����һ��������¶����ɭɭ�����ݣ�
һ���۾�ȴ����Բ��С��\n");
	set("combat_exp", 250000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("neili", 10000); 
	set("max_neili", 10000);
	set("max_qi", 10000);
	set("jiali", 100);

	set_skill("strike", 200);
	set_skill("claw", 200);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("sanyin-wugongzhao", 200);
	set_skill("chousui-zhang", 200);
	set_skill("huagong-dafa", 200);
	set_skill("shaolin-shenfa", 200);
	map_skill("dodge", "shaolin-shenfa");
	map_skill("force", "huagong-dafa");
	map_skill("parry", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	prepare_skill("strike", "chousui-zhang");

	setup();
	carry_object("/kungfu/class/taohua/obj/bupao")->wear();
}

void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
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
        if(!userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}                     