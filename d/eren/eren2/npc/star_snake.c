#include <ansi.h>
inherit NPC;  
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 5500000);
        set("dungeon_npc","eren2");
                
        set("max_atman", 3000);
        set("atman", 3000);
        set("max_mana", 3000);
        set("mana", 3000);
        set("max_neili",4000);
        set("neili",4000);
        set("force_factor",60);
        
        set("resistance/gin",60);
        set("resistance/kee",60);
        set("resistance/sen",60);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                
        }) );
        

        set_name("�������",({"bishe"}));
           set("title",HIG"ʮ������"NOR);
        set("long", "��ʮ�����ࡰ�еġ��ߡ�������ȫ����û�й�ͷ����˫��ϸ��С���۾�
�����㣬�����ѵľ��������ߣ����ߡ�\n");
        setup();
        carry_object(__DIR__"obj/j_cloth")->wear();
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
        
        if( !ob || environment(ob) != environment() ) return;
        message_vision(CYN"$N������ӭ����˵�����ڰ����������ˣ����ǵ����Ѿ������棬
��ȥ���˰ɣ����������ס��\n"NOR,this_object());
}   
