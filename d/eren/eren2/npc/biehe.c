#include <ansi.h>
inherit NPC; 
void special_smart_fight(); 
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
        set("long", "����ü��Ŀ�㣬�����������Ц�����������˸��������Ѽ���\n");
        set("title",HIG"���ϴ���"NOR);
        set("age",46);
        set("attitude", "friendly");
        
        set("combat_exp", 10000000);
        set("dungeon_npc","eren2");
                
        set("max_atman", 5000);
        set("atman", 5000);
        set("max_mana", 5000);
        set("mana", 5000);
        set("max_neili",10000);
        set("neili",10000);
        set("force_factor",80);
        
        set("resistance/gin",60);
        set("resistance/kee",60);
        set("resistance/sen",60);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        

        set_name("�����",({"jiang biehe"}));
        setup();
   
        carry_object(__DIR__"obj/g_armor")->wear();
        carry_object(__DIR__"obj/key");
}  
        
void init() {
        
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        
}  
void greeting(object ob) {
        
        object son;
        if( !ob || environment(ob) != environment() ) return;
        if (son=present("jiang yulang",environment(ob))) {
                message_vision("$Nһ����˵��С������������֪�����´��ⲻ���ˡ�\n",this_object());
                message("vision","������˵������λ����Ī�֣�С�Ӹղ��ǿ���Ц�ġ���\n",environment(ob));
        }
}  
