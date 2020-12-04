 inherit NPC;
#include <ansi.h>  
void create()
{
    set_name("武三爷",({"wu sanye","wu","sanye"}));
    set("title",HIR"铁掌"NOR);
    set("long","三爷姓武，名镇山，不过这儿没人敢叫他的名字，敢叫的人第二天就什么名字都叫
不出声了。武三爷什么都不干，只不过太平镇这地方有一半是他的。。\n");
    set("gender","男性");
    set("age",52);
        set("combat_exp", 9000000);
        set("attitude", "friendly");    
         
        set("max_atman", 600);
        set("atman", 600);
        set("max_mana", 600);
        set("mana", 600);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",130); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",40);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "武三爷微笑道：“你有鉴赏力，你是个聪明人。不过，聪明人都不长命。”",
                "武三爷点点头叹息着道：女人总是比较多疑的，尤其是李大娘这个女人，她一直都\n认为我要杀了她。”",
        }) );

        setup(); 
        set_skill("yijinjing",200);
        set_skill("iron-cloth",200);
        map_skill("iron-cloth","yijinjing");
        carry_object(__DIR__"obj/bluecloth2")->wear();
   
}  
void init() {
        
        object ob;
        ::init();
        add_action("do_answer","answer");
        if( interactive(ob = this_player())) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}  
void greeting(object ob) {
        
        object *inv;
        int pass;
        
        if( !ob || environment(ob) != environment()) return;
        
        if (ob->query("parrot/遇刺") && ob->query("parrot/宋妈妈家的秘密")
                && ob->query("parrot/红石的秘密") && ob->query("parrot/尸体的秘密")
                && ob->query("parrot/初见血奴"))
                pass=1;
        
        if( pass && !ob->query_temp("parrot/武三爷邀杀") && !ob->query("parrot/助三爷")) {
                message_vision(CYN"$N捧起金杯浅浅抿了一口对$n道：“你到这里来才半天，已有多少人要杀你？”\n",this_object(),ob);
                message_vision(CYN"$N又道：“其实他们只有一个人--李大娘！既然她要杀你，你杀了她，岂非
本就是天经地义的事。”\n",this_object());
                message_vision(CYN"$N慢慢的接着道：“我可以把她住所的环境，埋伏的暗卡，她的起居时刻，生
活习惯尽都告诉你，你是否要我帮这个忙？\n",this_object());
           tell_object(ob,HIY"（ａｎｓｗｅｒ　ｙｅｓ／ｎｏ） \n"NOR);
                ob->set_temp("sanye/answer_person",1);
                ob->set_temp("parrot/武三爷邀杀");
                return;
        }
}   
int do_answer(string arg)
{
        object who,key;
        int i, gotit;
        
        who=this_player();
        if(!who->query_temp("sanye/answer_person")) return 0;
        if (who->query_temp("sanye/answer_person")) {
                if(arg=="yes")
                {
                        message_vision(CYN"$N心中大喜，心照不宣地向武三爷点了点头。\n"NOR,who);
                        message_vision(CYN"$N呵呵一笑，俯身在$n耳边说了几句话！\n",this_object(),who);
                        tell_object(who,WHT"左三右五左七，可开李家庄后墙铁门。\n"NOR);
/*                      key=new(__DIR__"obj/key");
                        if (key) key->move(this_object());
                        command("give key to "+who->get_id());*/
                        who->delete_temp("sanye/answer_person");
                        who->set("parrot/助三爷",1);
                        return 1;       
                }
                if(arg=="no"){
                        message_vision(CYN"$N叹口气，道：“你说的话，好像都有点道理。”。\n"NOR,who);
                        message_vision(CYN"$N道：“只可惜我一向是个不讲理的人。”\n"NOR,who);
                        message_vision(YEL"$N迟疑一下道：“我仍希望你好好的再考虑一下。”\n"NOR,this_object());
                        who->delete_temp("answer_person");
                        who->set("parrot/助三爷",2);
                        return 1;
                }
        }
}
