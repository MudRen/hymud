#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
int show_me(); 
void create()
{
    set_name("花满天",({"hua mantian","hua"}));
    set("title",HIW"一动不动白衣人"NOR);
    set("long","他在这里已经站了很久了，雪白的衣服上积满沙土，头发也已被染黄，可是他的脸
却是苍白的，苍白得全无一丝血色。\n");
        set("gender","男性");
        set("age",42);
        set("combat_exp", 3500000);

        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        set("reward_npc", 1);
        set("difficulty", 5);
        set("neili",1000);
        set("max_neili",1000);
        set("force_factor",30);
        
      set("combat_exp", 20000000);
        set("score", 200000);

        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("sword", 100);
	set_skill("unarmed",80);
	set_skill("changquan",200);
	set_skill("feixian-steps",200);
	set_skill("feixian-sword",250);
	set_skill("jingyiforce",200);
        map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-sword");
	map_skill("force", "jingyiforce");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "changquan");
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.tianwaifeixian" :),
        }) );

        
        set("inquiry", ([
                "万马堂" :      (: show_me :),
                "马空群" :       (: show_me :),
        ]));
        
        set("death_msg",CYN"\n$N说：功亏一篑，我不甘心啊！ \n"NOR);     
       /* set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );*/
           set("chat_chance",1);
        set("chat_msg",({
                "花满天还站在昨夜同样的地方，甚至连姿势都没有改变过。\n"
        }) );                   
        
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();  
        carry_object("/d/xinjiang/npc/obj/hua_sword")->wield();
  
    
}  
int show_me(){
        object me,ob;
        
        me=this_player();
        ob=this_object();       
        
        if (me->get_id()=="yekai" || me->get_id()=="hongxue") {
                command("puke");
                command("say 你以为名气是用面具戴出来的？");
                return 1;
        }
        
        if (me->query("wanma/声誉")<5) {
                command("hmm");
                command("say 我好像没听说过你，三老板请的人，个个都是有头有脸的人物。");
                command("say 你还是先想法子提高你的声誉再来找我吧。");
                tell_object(me,WHT"受万马堂邀请需要五点声誉，你现在在边城的声誉为"+chinese_number(me->query("wanma/声誉"))+"点。\n"NOR);
                return 1;
        }
        
        message_vision(CYN"$N对$n一拱手：“久仰阁下大名，请至北街口，万马堂有车接迎。”\n"NOR,ob,me);
        me->set("wanma/马车",1);
        return 1;
}
void die()
{
        int i;
        object killer,owner; 
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->set_temp("wanma/杀花满天_ma", 1);
        }
        
        ::die(); 

}