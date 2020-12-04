 // bandit.c
#include <ansi.h>
inherit NPC;
void create() {
        set_name("ͨ����", ({ "tufei", "bandit"}) );
        set("long","һ��������Ѫ�ļһ\n");
        set("attitude", "friendly");
        set("vendetta/authority",1);
        set("per", 1);
        set("str", 100);
        set("intellgent",1);
        set("pursuer",1);
        set("no_return",1);
        set("combat_exp", 100000+random(2900000));
                set("bellicosity", 10000);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
//                name()+ "�ȵ�����������ҪǮ��Ҫ������\n",
//                name()+ "��Ц����ȥ���ɣ�\n",
//                                HIR+ name()+ HIR"�󺰣��ҹ���������������˭�������Ƕ���������\n"NOR,
                                (: random_move :),
        }) );
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }) ); 
        set_skill("unarmed", 70+random(50));
        set_skill("axe", 70+random(50));
        set_skill("blade", 70+random(50));
        set_skill("hammer", 70+random(50));
        set_skill("sword", 70+random(50));
        set_skill("parry", 70+random(50));
        set_skill("dodge", 70+random(50));
        set_skill("move", 100+random(50)); 
        set("max_qi",500+random(5000));
        set("max_jing",500+random(5000));
        set("max_neili",500+random(5000));
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 30+random(200));
        set_temp("apply/move", 100); 
        setup();
      add_money("silver", 19 + random(51));
} 
void init() {
    remove_call_out("hunting");
        if(environment() && !environment()->query("no_fight")) {
        call_out("hunting",1);
        }
} 
void hunting() {
        int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
        if(ob[i]->query("class")=="bandit") continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
} 
void setup_bandit(string name, string armor, string weapon, string mark) {
        object armor_ob, weapon_ob;
        
        set("name", name);
        armor_ob = new(armor);
        if(objectp(armor_ob)) {
                armor_ob->move(this_object());
                armor_ob->wear();
        }
        weapon_ob = new(weapon);
        if(objectp(weapon_ob)) {
                weapon_ob->move(this_object());
                weapon_ob->wield();
        }
        set("area_mark", mark);
}   
