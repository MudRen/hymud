#include <ansi.h>
inherit NPC;
void smart_fight();
void smart_busy();
void smart_attack();  
void create()
{
    set_name("��Ұ", ({"tang ye","tang"}) );
        set("gender", "����" );
        set("nickname", BLU"ն��"NOR);
        set("title", "������ �̿�");
        set("long", "��Ұ��׳�ܰ����������ͷ����ϲ����һ���ײ������š�\n");
        set("attitude", "friendly");
         set("class","ninja");
         set("age", 35);
         set("cor", 25);
        set("cps", 25);
        set("combat_exp", 2200000);
    
        set_temp("apply/armor", 100);
        set("force", 1000);
        set("max_neili", 1000);
        set("force_factor", 50);
        set("reward_npc", 1);
        set("difficulty", 2);
    
        set_skill("blade", 150);
        set_skill("ittouryu", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("move", 150);
        set_skill("ghosty-steps",200);
        set_skill("unarmed",150);
        set_skill("enmeiryu",150);
        
        map_skill("blade", "ittouryu");
        map_skill("unarmed","enmeiryu");
        map_skill("dodge","ghosty-steps");
        map_skill("move","ghosty-steps");
        map_skill("parry","ittouryu");
        
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) );      
        
        switch (random(5)) {
                case 0: set("resistance/sen",30);
                        break;
                case 1: set("resistance/gin",30);
                        break;
                default: set("resistance/kee",30);
                }
        
        set("chat_chance", 1);
        set("chat_msg", ({
        "��Ұ�ƺ�һ���������Ǹ����ʣ����ҳ�����⣡��\n",
        }) ); 
        setup();
        if (!random(5)) carry_object(__DIR__"obj/stone_1");
                else add_money("gold", random(3));
        carry_object(__DIR__"obj/horseblade")->wield();
        carry_object(__DIR__"obj/whitetowel")->wear();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/betelnut");
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !interactive(ob) || environment(ob) != environment() )
                return;
   if (!ob->query("vendetta/authority")){
            message_vision("$N�ٺٵ�����������˽��������ĵ�ͷ���������ɣ�\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        return;
}  
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (enemy[i]->query_temp("weapon") && !random(3))
                        {
                                command("wield blade");
                                this_object()->smart_busy();
                        } else 
                        {       if (this_object()->query_temp("weapon"))
                                        command("say ��,�Ҳ��ñ���!");
                                command("unwield blade");
                                this_object()->smart_attack();
                                
                        } 
                }
        }
} 
smart_busy() {
        this_object()->perform_action("blade.gobankiri");
}
smart_attack() {
        this_object()->perform_action("unarmed.shiden");        
        }    
