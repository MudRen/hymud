 //All Rights Reserved 1998 Apstone, Inc.
inherit NPC;
#include <ansi.h>
int give_book(); 
void create()
{
        set_name("κ����", ({ "wei xing long" }) );
        set("title", MAG "����ɷ��" NOR);
        set("gender", "����" );
        set("age", 35);
//      set("str", 30);
        set("agi", 20);
        set("long",
        "�������۾���һ�����̣������������۽�һֱ�����������䳤����̫�
        ������������������Ѫ������ָ�������˺��ѷ����������̡�\n");
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("dodge",100);
        set_skill("parry",100);
	set_skill("cuff", 250);
	set_skill("force", 280);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 380);
	set_skill("strike", 250);
	set_skill("kuangfeng-jian", 380);
	set_skill("zixia-shengong", 380);
	set_skill("zixia-shengong", 380);
	set_skill("ziyunyin", 380);
	set_skill("zhengqijue", 380);
	set_skill("fanliangyi-dao", 380);
	set_skill("huashan-sword", 380);
	set_skill("hunyuan-zhang", 380);
	set_skill("lonely-sword", 380);
	set_skill("feiyan-huixiang",380);
	set_skill("literate", 200);
        set_skill("zhengqijue",380);
        set_skill("hunyuan-zhang", 380);
        set_skill("poyu-quan", 380);        
        set_skill("huashan-neigong", 380);        
        set_skill("chongling-jian", 380);
        set("fengset",1);
	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");


	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.jiushi" :),
		(: perform_action, "sword.pozhao" :),
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: perform_action, "sword.podao" :),
		(: perform_action, "sword.zongjue" :),
	}) );

        set("combat_exp", 900000);
        set("chat_chance", 2);
         set("chat_msg", ({
"κ���������������ֻҪ�����ˡ����ʮ��ʽ���������Ƕ�����̫���Ҷ����¡�\n ",
"κ��������üͷ�ֹ��ţ�����һ���������ʵ��������ʵ���飬���߶������У�\n",
 }) );
        set("inquiry",([
        "���ʮ��ʽ" : (: give_book:),
         "book" : (: give_book:)
        ]) );
        
        
        
        setup();
   carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object(__DIR__"obj/qfbook");
//      carry_object(__DIR__"obj/qfbook");
} 
int give_book()
{
        command("say �������������б������������ɣ������ȱȻ��Ȼ�����");
        if (this_player()->query_temp("marks/wei_win")) 
                this_player()->delete_temp("marks/wei_win");
        this_player()->set_temp("marks/wei",1);
        return 1;
}   
void win_enemy(object loser)
{
        message_vision("$N��м�ض�$n����һ����Ҫ�����Ϸ��������飬��������������ˡ�\n",this_object(),loser);
} 
void lose_enemy(object winner)          //modified by jusdoit at Dec 17,2001
{                                       
        object book;
        if (winner->query_temp("marks/wei")) {
                message_vision("$N��ü�����ض�$n˵�����¹�Ȼ�������������ܼ�������Ҳ����ס�ˡ�\n",this_object(),winner);
                message_vision("$N�޿��κεشӻ����ͳ�һ����ݸ�$n��\n",this_object(),winner);
                book = new(__DIR__"obj/qfbook");
                book->move(winner);
                winner->delete_temp("marks/wei");
                winner->set_temp("marks/wei_win",1);
        } else message_vision("$N��ü�����ض�$n˵�����¹�Ȼ������\n",this_object(),winner);
        
}   
void init() {
        object ob;
        ::init();
        if(interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        if( !query_heart_beat(this_object()) ) set_heart_beat(1); 
} 
void greeting(object ob) {
   
        string where;
        if(!ob || environment(ob) != environment()) {
                return;
        }
        
        switch( random(5)){
                case 0:
                        say("κ���������������ֻҪ�����ˡ����ʮ��ʽ���������Ƕ�����̫���Ҷ����¡�\n");
                        break;
                case 1:
                        say("κ��������üͷ�ֹ��ţ�����һ���������ʵ��������ʵ���飬���߶������У�\n");
                        break;
                } 
}  
int accept_fight(object me)
{
                if (!this_object()->is_fighting()) {
                        command("grin");
                        command("say �ã�����������ι�У�\n");
                        return 1;
                } else command ("say ��æ��æ��һ��һ������������ȱ���֡�");
                        return 0;
}                         
