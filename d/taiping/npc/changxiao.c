#include <ansi.h>
#include <command.h> 
inherit NPC; 
void create()
{ 
        set_name("��Ц",({"chang xiao","chang","xiao"}));
        set("nickname","����");
        set("title",WHT"�Ĵ�����"NOR);
        set("long", "
�����Ϲ���Ц�ݣ��Ͱ���Ц�ݣ���ò����һ���������ò����ʹ�����˹ٷ�����Ҳ
���ԵúͰ����ס���˭�뵽������һ���ˣ������ģ����Ľ������ȶ��߻��ݶ�����
���겻����ʮ���꣬����ݹ�������ʮ�꣬���������ϵ���ȴ�ѹ�ǧ��ƽ��ÿ���գ�
����һ�������������ϡ�֪����Щ�µ��ˣ��ǲ����Ծ������Ͱ����ף�\n");
        set("age",47);
        set("combat_exp", 9000000);
                
        set("resistance/gin",30);
        set("resistance/kee",50);
        set("resistance/sen",30);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
        set("defense_type",random(2)+1);        
        set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10:     "\n��Ц����������ĳ���˵��ʺ�֮����������һ��Ѫ���ˣ�\n",
        ]) ); 

        
        setup();
   carry_object(__DIR__"obj/o_cloth2")->wear();
        carry_object(__DIR__"obj/o_sword")->wield();
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
