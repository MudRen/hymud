#include <ansi.h>
inherit NPC;
void create()
{
        set_name("ɽ������", ({ "tufei", "shanxi tufei" }) );
        set("long","һ�������˰̼Ӻ���ļһ\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
        set("per", 1);
        set("pursuer",1);
        set("no_return",1);
        set("combat_exp", 100000+random(400000));
        set("bellicosity", 10000);
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                "ɽ�����˺ȵ�����������ҪǮ��Ҫ������\n",
                "ɽ������Ц��������ģ�ȥ���ɣ�\n",
                (: random_move :),
        }) );
        
        set("chat_chance", 60);
        set("chat_msg", ({
                (: random_move :),
        }) ); 
        set_skill("unarmed", 70+random(50));
        set_skill("blade", 70+random(50));
        set_skill("parry", 70+random(50));
        set_skill("dodge", 70+random(50));
        set_skill("move", 100+random(50)); 
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/parry", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 30+random(200));
        set_temp("apply/move", 100); 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/guiblade")->wield();
} 
void init()
{
        remove_call_out("hunting");
        if(!environment()->query("no_fight"))
        call_out("hunting",1);
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
