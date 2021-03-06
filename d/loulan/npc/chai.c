#include <ansi.h>
inherit F_MASTER;
inherit NPC;
int leave();
int show_me(); 
void create()
{
        set_name("快活王", ({ "master chai","master","chai" }) );
        set("gender", "男性" );
        set("long",
                "广额高颧，面白如玉，颔下一部长髯，光洁如缎。长眉如卧蚕，双目细而长，\n微微下垂的眉目，闪闪发着光，当中配着高高耸起而多肉的钩鼻，象征着无\n比的威权，深沉睿智，也象征着他那绝非常人可比的旺盛精力。\n");
        set("nickname", HIY"万家生佛"NOR );
        set("apprentice_available", 5);
        set("class","knight");
        create_family("快活林", 1, "塞北之王");
        set("rank_nogen",1);
        set("ranks",({"弟子","骑士","铁骑","铁骑卫",HIC"铁骑统领"NOR,RED"欢乐右使"NOR,HIR"欢乐左使"NOR,HIY"一字并肩王"NOR}));
        set("attitude", "peaceful");
        set("reward_npc", 1);
        set("difficulty", 40);
        set("age", 57);
        set("str", 100);
        set("cps", 100);
        set("int", 100);
        set("per", 10);
        set("cor", 40);
        set("agi", 80);
                
        set("combat_exp", 50000000);

        set("force", 2000);
        set("max_force", 2000);

        set("force_factor", 100);
        set_temp("apply/armor",300);
        set_temp("apply/attack", 200);
        set_temp("apply/damage", 50);
        set("chat_chance", 2);
        set("chat_msg", ({
                "快活王捋捋长髯大笑道：明日大喜礼毕，便是我柴玉关马踏中原之时！\n",
                "快活王端起夜光杯，一口饮下，长笑道：壮志饥餐胡虏肉，笑谈渴饮匈奴血。\n如今且饮这葡萄美酒，他日当喝中原人的血酒！\n",
                }) ); 

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.tiandirenmo" :),
                (: perform_action, "dodge.lianhuanbabu" :),
                (: perform_action, "blade.tiandirenmo" :),
        }) );
        set("combat_exp", 50000000);
        set("score", 200000);

        set_skill("dodge", 200);
        set_skill("parry",200);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("literate", 180);
	set_skill("unarmed",60);
	set_skill("demon-steps",500);
	set_skill("demon-strike",500);
	set_skill("demon-force",500);
	set_skill("blade",250);
	set_skill("demon-blade",550);
	set_skill("xuanyuan-axe",550);
        map_skill("dodge", "demon-steps");
	map_skill("force", "demon-force");
	map_skill("unarmed", "demon-strike");
	map_skill("blade","demon-blade");
	map_skill("axe","xuanyuan-axe");
	map_skill("parry","demon-blade");

set("pubmaster",1);
        set("max_neili", 55000);
        set("neili", 55000);
        set("force_factor", 30);
	set("max_qi",19999);
        set("max_jing",19999);
	set("eff_qi",19999);
	set("qi",19999);
	set("eff_jing",19999);
	set("jing",19999);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);
        setup();
        carry_object(__DIR__"obj/mangpao")->wear();
        carry_object(__DIR__"obj/panguaxe")->wield();
        carry_object(__DIR__"obj/lightcup");
} 
void reset()
{
        set("apprentice_available", 5);
} 
int show_me() {
        object ob,me;
        me=this_player();
        ob=this_object();
        if (me->query("class")!="knight") {
                command("say 云梦五花锦是本门之技，你胡乱打听什么？");
                return 1;
        }
        
        if (me->query("marks/云梦暗杀")) {
                command("say 为师不是早就告诉你这其中的关键了吗?");
                return 1;
        }
        
        command("say 五花锦原是苗疆下蛊之术，云梦仙子将其去芜存菁，故称云梦五花锦。");
        command("say 想我快活林的功夫天下无敌，五花锦的下蛊之术实非正统。");
        command("say 为师学得此艺后潜心钻研，悟出归鸿声断残云碧一技，可在对敌时伤人于无形。");
        command("say 不过，若你致意想学暗杀之技，为师也可传你旧日的下蛊之术。");
        command("hmm");
        command("say 但为师悟出的残云碧你不可再用，以免混淆视听，让武林之人笑我快活林无技。");
        tell_object(me,WHT"学了下蛊之术则不能用为师的残云碧，你可愿意？（accept yes or no）\n"NOR);
        me->set_temp("kuaihuo/a_sk1",1);
        return 1;
} 
int do_accept(string arg)
{
    if(!this_player()->query_temp("kuaihuo/a_sk1")) return 0;
    if( arg == "no" )
    {
        command("say 好，好徒儿，快活林的功夫靠你发扬光大了。");
        return 1;
    }
    else if( arg == "yes" )
    {
        command("say 人各有志，说不定你也能将此技发扬光大。");
        tell_object(this_player(),"你可以在暗中使用归鸿声断残云碧了。\n");
        this_player()->set("marks/云梦暗杀",1);
        return 1;
     }
    else  return 0;
}   
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) 
        {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。\n");
                else
                        call_out("do_recruit", 2, ob);
        } 
        else {
                command("say 老夫已经收够了弟子，不能再收了。\n");
        }
} 
void do_recruit(object me)
{
        if( (string)me->query("class") != "knight" )
        {
            command("say 我只收本门弟子，你还是另寻良师吧！\n");
        }
        else if (!me->query("m_success/楼兰孽缘"))
        {
                command("say 老夫大婚之后再说吧！\n");
        }
        else if(!me->query_temp("marks/knight_win_dugu"))
        {
                switch ( random(2) )
                {
                        case 0:
                                command("say 本门规矩森严，先打赢你的师傅再来找我！\n");
                                break;
                        case 1:
                                command("say 学武要循序渐进，你还是打好基础再来吧。\n");
                                break;
                }
        }
        else
        {
                command("say 你天纵英才，乃我门中希望，我一身功夫后继有人啊！呵呵！\n");
           command("recruit " + me->query("id") );
        }
} 
void init()
{       
        object me;
        ::init();
        me = this_player();
        if( interactive(me) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 0, me);
        }
        add_action("do_answer","answer");
        add_action("do_accept","accept");
} 
void greeting(object me)
{
        object *inv;
        int i;
        object ob;
        ob = this_object();
        if( userp(me))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("owner")=="方心骑" && (int)inv[i]->query("equipped"))
                        {
                                if (!me->query_temp("marks/chai_talkto_you"))
                                {
                                        message_vision(HIY"$N目光如刀，朝你望了过来．．． \n"NOR,ob);
                                        message_vision(HIY"$N颔首道：＂心骑，去告知王妃速去百花宫上妆，喜娘们都齐了，知道么？\n（answer yes or not) ＂\n"NOR,ob);
                                        me->set_temp("marks/chai_talkto_you",1);
                                }
                                else
                                {
                                        message_vision(HIY"$N问道：＂心骑，事情办得怎样？\n"NOR,ob);    
                                }
                        }
           }
        }
} 
int do_answer(string arg)
{    
        object me;
        
        me=this_player();
        if (!arg) return notify_fail("回答什么？\n");
        if (!me->query_temp("marks/chai_talkto_you")) return notify_fail("回答什么？\n");
        if (arg == "yes")
        {
                message_vision("$N毕恭毕敬躬身应声答应。\n",me);
                me->set_temp("marks/chai_get_command",1);
                return 1;
        }
        else if (arg == "no")
        {
                message_vision("$N脸上微一犹豫．．． \n",me);
                message_vision("$N脸色一沉：好大的胆，不听本王的话！你到底是何人！ ．．． \n",this_object());
                me->delete_temp("marks/chai_talkto_you");
                this_object()->kill_ob(me);
                me->kill_ob(this_object());
                return 1;
        }
        else
                return notify_fail("回答什么？\n");
} 
int accept_object(object me, object obj)
{       
        object npc;
        object book;
        object *inv;
        int i;
        int j;
        j = 0;
        npc = this_object();
        if( userp(me))
        {
                inv = all_inventory(me);
           for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("owner")=="方心骑" && (int)inv[i]->query("equipped"))
                        {
                                j = 1;
                        }
                }
        }
        if (me->query_temp("marks/knight_kill_wang") && obj->query("name") == "樟木镶金箱" && j == 1)
        {
                message_vision(HIY"$N霍然站起，看着镶金箱半晌无语．．．\n"NOR,npc);
                message_vision(HIY"$N卧蚕眉一挑，仰天狂笑道：云梦妖妇！莫当本王无知，嘿嘿．．． \n"NOR,npc);
                message_vision(HIY"$N重重拍着$n的肩膀道：好，心骑，不愧为本王急风第一骑！ ．．． ．\n这本书就是那本让当年天下武林豪杰在衡山回燕峰死伤殆尽的奇书无敌宝鉴，\n你立此大功，便拿去参研吧！ \n"NOR,npc,me);
                book = new(__DIR__"obj/book1");
                if (book) book->move(me);
                if (!me->query("m_success/楼兰孽缘"))
                {
                        me->add("score",200);
                        me->set("m_success/楼兰孽缘",1);
                }
                return 1;
        }
        else
                return notify_fail("快活王抚须微笑，默然不语。\n");     
} 
int leave() {
        if (this_player()->query("class")!="knight") return 0;
        message_vision(CYN"$N一脚踢在$n的屁股上。\n"NOR, this_object(),this_player());
        message_vision(CYN"$N说：以后你的轩辕斧使不利索可别怪我。\n"NOR,this_object(),this_player());
        message_vision(CYN"$N说：孤王的云梦五花锦也得留下。\n"NOR,this_object(),this_player());
        return 1;
}  
