#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";
//inherit "/d/taiping/npc/timeshift"; 
inherit NPC;
int show_me();
void time_greet(object ob); 
void create()
{
        set_name("�����",({"hu waigua","hu","waigua"}));
        set("title","��Ʀ");
        set("long","�����ԭ�������壬���������ϵ�һ��С��Ʀ���������������Դ��������ߣ���
�����Ǳ����͵͵�ؽ�������ϡ�\n");
        set("gender","����");
        
        set("combat_exp",5000000);  
        set("age",42);
                
        set("int",40);
        set("cor",40);
        set("cps",40);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
                
        set("max_atman",random(1000));
        set("atman",query("max_atman"));
        set("max_mana",random(500));
        set("mana",query("max_mana"));
        set("max_neili",1000+random(500));
        set("neili",query("max_neili"));
        set("force_factor",100);
        
        set("resistance/kee",random(30));
        set("resistance/gin",random(30));
        set("resistance/sen",random(30));
                
        set("inquiry", ([
                "������" :      (: show_me :),
                "protection" :  (: show_me :),
        ]));
                
        set("day_room","/d/biancheng/smallroad2");
        set("dinner_room","/d/biancheng/mianguan");
        set("shift/dinner_leave","$N���˸����������ɻ�ȥ�ˡ���˵�����뿪��\n");
        set("shift/dinner_arrive","$N����˹������˹�����\n");
        set("shift/after_dinner","$N�ٺ���Ц��������������ȥ��\n");
        set("shift/back_dinner","$N���ű������˹�����\n");
                        
        set("death_msg",CYN"\n$N˵����Ӣ�ۡ�������������\n"NOR);        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10: name()+"�е���������һȭ�����ɸ���ϣ���\n",
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );*/
        set("chat_chance",1);
        set("chat_msg",({
                "����ϵ�������ص��������ˣ���Ҫ�ᶯ���ӣ����ɻ�ɡ���\n",
        }) );                   
        
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","tigerstrike",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
    
} 
int show_me() {
        command("say ��ô����Ҳ�뽻Ǯ�����ǿ���˳�ۣ�");
        command("say ����˳�ۿ��ԣ����ʹ����ӵ�ȭͷ��Ҫ��Ҫ���Ȼ��Ȼ���");
        this_player()->set_temp("wanma/can_fight",1);
        return 1;
} 
int accept_fight(object me){
        if (!me->query_temp("wanma/can_fight")) {
                command("say �����������й���");
                return 0;
        }
        
 //����������������εġ�
/*        if (!check_health(this_object(),99) || this_object()->is_fighting()) {
                command("say ��ȺŹ�����������ȴ�������");
                return 0;
        }   */
        command("say �ã���Ӯ���ң����ͷ��������ˣ�\n");
        return 1;
}  
void win_enemy(object loser){
    command("pk "+loser->get_id());
} 
void lose_enemy(object winner){
    command("say ��ݣ�������¿�������������ơ�\n");
    winner->set_temp("wanma/ʤ��Ʀ",1);
} 
void init() {
        
        object me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                remove_call_out("shifting");
                call_out("shifting", 1, me);
        }
}  
void time_greet(object ob) {
        object *inv;
        int i;
        inv=all_inventory(environment(ob));
        if (sizeof(inv)<=1) return;
        
        for (i=0;i<sizeof(inv);i++){
                if (inv[i]->query("id")=="zhang laoshi") {
                        message_vision(YEL"$N��$n˵��������ı�����׼������ô����\n"NOR,ob,inv[i]);
                        message_vision(YEL"$n̾����������$N������Ʊ��\n"NOR,ob,inv[i]);
                }
        }
        
} 
