#include <ansi.h>
#include <command.h> 
inherit NPC; 
void create()
{ 
        set_name("�����",({"li daniang","daniang","li"}));
//      set("title",WHT"�Ĵ�����"NOR);
        set("long", "����Ц���紺�����ţ������紺ݺ��ת����ı����ҵ�Ů�˸���������òҲ������
Ѫū���Ǻ��������ˣ���δ��������ȡ��������������������ѷ������֡�\n");
        set("age",27);
        set("combat_exp", 10000000);
        set("attitude", "friendly");    
        
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 600);
        set("mana", 600);
        set("max_force",2500);
        set("force",2500);
        set("force_factor",100); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set("resistance/gin",30);
        set("resistance/kee",50);
        set("resistance/sen",30);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
//      set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/lisword")->wield();
}  
/*
void init() {
        
        object ob;
        ::init();
        add_action("do_answer","answer");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}  
void greeting(object ob) {
        
        if( !ob || environment(ob) != environment() || ob->is_fighting()) return;
        call_out("ask_question_1",1,ob); 
}
*/ 
void die() {
        object me, ob, owner;
        ob=this_object();       
        message_vision(HIR"$N��Ȼ����һ��������Ц������ʮ����ħʮ��Ѫ��ħ�����ڣ����ǲ������ġ���\n"NOR,ob);
        message_vision(HIR"$N��Ȼ���ˣ������˶��������֮������֮������������ձڡ�$Nת��
������㲻�ٳ��֡�\n"NOR,ob);
        destruct(ob);
}    
