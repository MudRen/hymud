#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
int show_me(); 
void create()
{
        set_name("大肚子的小媳妇",({"pregnant woman","woman"}));
        set("long","一个穿着一身蓝缎子衣服的小媳妇，挺着个大肚子正在和店里的伙计讨价还价。\n");
        
        set("gender","女性");
        set("attitude", "friendly");
        set("group","citizen");
        
        set("combat_exp",200000);  
        
        set("age",32);
                
        set("int",40);
        set("cor",40);
        set("cps",40);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
                
        set("max_neili",200+random(500));
        set("neili",query("max_neili"));
        set("force_factor",30);
        
        
        set("inquiry", ([
                
        ])); 
        set("death_msg",CYN"\n$N说：“天哪！这不是一尸两命么。”\n"NOR);        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10: name()+"叫道：“来人啊，强奸啦！”\n", 
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );*/
        set("chat_chance",1);
        set("chat_msg",({
                name()+"拿起一块缎子揉了揉说：“这块吧？还是那块？”\n",
           }) );                   
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
} 
void init()
{       
        object ob;
        
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_answer", "answer");
} 
void greeting(object me)
{
        if( !me || environment(me) != environment() ) return;
        if (me->query("wanma/义助小媳妇")) {
                command("xixi "+me->get_id());
                return;
        } 
        if (me->query("wanma/答小媳妇")) {
                message_vision(CYN"$N对$n说：改主意了吗？能借我吗？\n"NOR,this_object(),me);
                return;
        }
        
        message_vision(CYN"$N一把拉住$n的手说：“这位"+RANK_D->query_respect(me)+"替我出个主意吧。”\n"NOR,this_object(),me);
        message_vision(CYN"$N说：“你说我是买这红的呢，还是蓝的，或者是绿的，黄的？”\n",this_object());
        tell_object(me,HIY"（ａｎｓｗｅｒ　ｒｅｄ／ｂｌｕｅ／ｇｒｅｅｎ／ｙｅｌｌｏｗ） \n"NOR);
        me->set_temp("wanma/answer_preg",1);
} 
int do_answer(string arg)
{
        object me,ob,huoji;
        
        me=this_player();
        ob=this_object();       
        
   if(!me->query_temp("wanma/answer_preg")) {
                command("say 我又没问你，你瞎掺乎什么?");
                return 1;
        }
        
        if(arg=="blue") {
                command("say 哎呀,春风满面皆朋友,欲觅知音难上难,您可真是猜到我心坎里去了。");
                command("say 我就要这个了。");
                command("say 不过,我今儿个忘了带金子,你借我十两吧,知音难觅呀。");
                me->delete_temp("wanma/answer_preg");
                me->set("wanma/答小媳妇",1);
                return 1;       
        }
        if (arg=="yellow" || arg=="red" || arg=="green") {
                message_vision(CYN"$N想了想，摇了摇头说：“不好不好。”\n"NOR,this_object());
                message_vision(CYN"$N转过头去不搭理$n了。\n",this_object(),me);
                me->delete_temp("wanma/answer_preg");
                huoji=present("huo ji",environment(this_object()));
                if (huoji) 
                        message_vision("$N拍了拍$n的肩头说：“替女人买东西，不容易吧！”\n"NOR,huoji,me);
                return 1;
        }
        tell_object(me,"你只能回答ｒｅｄ／ｂｌｕｅ／ｇｒｅｅｎ／ｙｅｌｌｏｗ。\n");
        return 1;
} 
int accept_object(object who, object ob)
{
        if (!who->query("wanma/答小媳妇")) {
                command("say 我是规规矩矩人家出来的，怎么可以乱拿别人的钱呢？");
                return 1;
        }
        if (ob->value()>=100000) {
                command("touch "+who->get_id());
                command("say 太感谢了，你比我家那口子大方多了，我决不会忘记你的！");
                if (!who->query("wanma/义助小媳妇")) {
                        who->set("wanma/义助小媳妇",1);
                        who->add("combat_exp",1000);
                        who->add("potential",200);
                        who->add("wanma/声誉",1);
                        tell_object(who,HIW"你被奖励了！一千点实战经验，二百点潜能！\n"NOR);
                   tell_object(who,HIW"你在这个边远小镇的声誉上升了！\n"NOR);
                } 
                return 1;               
        } 
        command("say 这点钱不够买布呀。");
        command("addoil "+who->get_id());
        return 0;
}                        
                                 
