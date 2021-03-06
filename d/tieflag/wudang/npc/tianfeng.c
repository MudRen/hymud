#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void imbue_event(object me);
void create()
{
        set_name("天枫十四郎", ({ "master tianfeng", "tianfeng", "master"}) );
        set("gender", "男性" );
        set("age", 55);
        set("nickname", CYN "伊贺忍侠" NOR);
        set("long", 
"一个面色蜡黄，浓眉高颧的乌衣老者，浑身尽是杀气。他盘膝坐在山巅之上，
衣抉下露出赤足，却将一双高齿乌木的木屐端放于前，木屐上竟又放着柄乌
鞘长刀。\n");
        create_family("一刀流", 7, "家督");
    set("rank_nogen",1);
    set("ranks",({"下忍","中忍","上忍",RED"罗刹"NOR,HIR"修罗"NOR}));
    set("rank_levels",({32000,512000,1536000,3456000 }));
        set("combat_exp", 5000000);
        set("attitude", "friendly");
        set("reward_npc", 1);
        set("difficulty", 30);
        set("neili", 2000);
        set("max_neili",2000);
        set("force_factor",60);
        
        set_skill("unarmed", 140);
        set_skill("ghosty-force", 300);
        set_skill("enmeiryu",120);
        set_skill("ittouryu",160);
        set_skill("ninjitsu",200);
        set_skill("dodge", 180);
        set_skill("ghosty-steps",200);
        set_skill("blade",160);
        set_skill("literate", 140);
        set_skill("force", 180);
        set_skill("parry", 140);
        set_skill("magic", 100);
        
        map_skill("magic", "ninjitsu");
           map_skill("unarmed", "enmeiryu");
        map_skill("blade", "ittouryu");
        map_skill("parry", "ittouryu");
        map_skill("force", "ghosty-force");
        
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.mukuha" :),
                (: perform_action,"unarmed.shiden" :),
                (: perform_action, "unarmed.shimon" :),  
                (: perform_action, "blade.gobankiri" :), 
                (: perform_action, "blade.hyakki" :), 
                           
             }) ); 
   
   
   
        set_temp("apply/damage",100);
        set("chat_chance", 1);
        set("chat_msg", ({
                        "天枫十四郎那亘古不变的死灰色的脸突然颤抖起来，哇的一声咳出口鲜血。\n",
                                })  );
        set("inquiry",  ([
                "李菊" : "菊子。。菊子。。你在哪里。。。\n",
                "南宫灵" : "我失散多年的孩子啊，有生之年如果能见他一面死也无憾啊。\n",
                "无花" : "我失散多年的孩子啊，有生之年如果能见他一面死也无憾啊。\n",
                ])              ); 
        setup();
    carry_object(__DIR__"obj/wucloth")->wear();
    carry_object(__DIR__"obj/muji")->wear();
        carry_object(__DIR__"obj/blackblade")->wield();
} 
void init()
{       object ob;
        ::init();
        add_action("do_answer","answer");
        if( interactive(ob = this_player()) && !is_fighting() ) 
        if (ob->query("天枫_quest6")&&ob->query("class")!="ninja")
        {
                remove_call_out("recruiting");
                call_out("recruiting", 1, ob);
        } 
}  
void win_enemy(object loser)
{
    message_vision(HIC "天枫十四郎仰天长叹一声，良久。。\n"NOR,loser);
    message_vision(HIR "天枫十四郎突然哇地一声喷出口鲜血，发狂一般仰天长嘶：
菊子啊，你。。。你。。在何方。。\n"NOR,loser);
        loser->set("天枫_quest1",time());
} 
void lose_enemy( object winner)
{
        object blade;
        
        winner->set("天枫_quest1","成功");
        if(blade=present("black blade",this_object()))
        {
                message_vision(HIR"天枫十四郎死灰般的眼睛突然亮了起来，双手将乌鞘长刀交给$N，
双膝跪地肃然道：你，好汉。此刀请你转交给我子灵儿。。拜托了。。\n"NOR,winner);
                blade->move(winner);
        }
                
} 
int accept_fight(object me)
{
        int count;
        object blade;
        
        if(!present("black blade",this_object())) return 0;
        if(me->query("天枫_quest1")=="成功")
        {
                message_vision(HIW"天枫十四郎问道：“我拜托你的事情，帮我做到了吗？”\n"NOR,me);
                return 0;
        }
        if(me->query("天枫_quest1")&&me->query("天枫_quest1")+600>time())
        {
                message_vision(HIR"天枫十四郎不屑的看着$N说道：“手下败将，还来做甚？”\n"NOR,me);
                return 0;
        }
   count=me->query_temp("天枫_挑战次数");
        
        if(me->query("combat_exp")<2500000||me->query("score")<15000)
        {
        if(count==0)
                message_vision(HIY"天枫十四郎霍然睁开双眸，扫了$N一眼，微叹一声，闭目无语。\n"NOR,me);
        
        else if(count==1)
                message_vision(HIY"天枫十四郎哼了一声低喝道：吾乃东瀛天枫十四郎，不战阁下这等碌碌无为之辈。\n"NOR,me);
        else if(count==2)
        {
                message_vision(HIW"天枫十四郎眉头微皱，“呛”的一声，刀光乍现。\n"NOR,me);
                kill_ob(me);
                me->delete_temp("天枫_挑战次数");
                return 2;
        }
        me->add_temp("天枫_挑战次数",1);
        return 0;
        } 
        message_vision(HIY"天枫十四郎霍然睁开双眸，目光如电盯着$N，冷冷道：你，出招！\n"NOR,me);
        return 1;
}
        
        
int accept_object(object who, object ob)
{
        if(!ob->query("saki")) return 0;
        message_vision(HIC"天枫十四郎双手紧握这瓶清酒，如获重宝。\n"NOR,who);
        call_out("be_poisoned",5+random(5),who);
        return 1;
} 
int be_poisoned(object who)
{
    message_vision(HIR"\n天枫十四郎颤抖着捧起清酒，老泪纵横，一仰而尽。\n
突然天枫十四郎浑身颤抖，大汗淋漓，凄然道：菊子，你。。你。。唉。。
这位"+RANK_D->query_respect(who)+"，吾身中奇毒，即便能逼出，也必功力尽废，但有一事想求，
不知你可否答应？\n"NOR,who);
        if(who->query("天枫_quest4")!="成功"){
                message_vision(HIR"\n谁知话音才落，$N脸色突变，一口鲜血吐了出来。\n"NOR, this_object());
                die();
           return 1;
        }
    tell_object(who,HIY"（ａｎｓｗｅｒ　ｙｅｓ／ｎｏ） \n"NOR);
        who->set_temp("answer_person",1);
        return 1;
} 
int do_answer(string arg)
{
        object skinmask,who;
        
        who=this_player();
        if(!who->query_temp("answer_person")) return 0;
        if(arg=="yes")
        {
                message_vision("$N神色凝重地点了一下头。\n",who);
                message_vision(HIB"天枫十四郎仰天狂笑道：好，我今日约战了中原一点红，你就代我
一战吧。大恩必当涌泉相报。\n"NOR,who);
                skinmask=new(__DIR__"obj/skinmask");
                skinmask->move(who);
                message_vision("天枫十四郎给$N一件装束。\n",who);
                who->set("天枫_quest5","成功");
                who->delete_temp("answer_person");
                return 1;
                
        }
        if(arg=="no"){
                message_vision(HIR"天枫十四郎凄然一笑，吐出口鲜血，倒地而亡。\n"NOR,who);
        if(!who->query("imbue/tianfeng")){
                imbue_event(who);
        }
                die();
                return 1;
        }
        return 0;
} 
void recruiting(object ob)
{
        if(ob->query("天枫_quest6")=="失败")
        {
                message_vision(HIR"天枫十四郎凄然一笑，吐出口鲜血，倒地而亡。\n"NOR,ob);
           this_object()->die();
                return;
        }
        if(ob->query("天枫_quest6")=="成功")
        {
                tell_object(ob,WHT"天枫十四郎睁开无力的双眼，微微笑道：好，我一身绝技，便任你学了。\n"NOR);
                return;
        }
} 
void attempt_apprentice(object me)
{
    if(me->query("天枫_quest6")=="成功")
    {
        command("recruit " + me->query("id") );
        return;
    }
    else
        command("sigh"); 
} 
         
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "ninja");
} 
void imbue_event(object me){
    object obj, weapon, *inv;
    string prop;
    int i;
    
    if(!interactive(me) || environment(me) != environment(this_object())) {
            return;
    }
        obj = me->query_temp("weapon");
        if(objectp(obj) && obj->query("owner")) {
                weapon = me->query_temp("weapon");
        } else { 
                inv = all_inventory(me);        
                for(i=0; i<sizeof(inv); i++) {
                        if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
                           weapon = inv[i];
                                break;
                        }
                }       
        }
        if(!objectp(weapon)){
                if(!objectp(obj)) {
                        message_vision(RED"\n几滴鲜血溅到了地上瞬间就凝成了暗红色的痕迹。。。\n"NOR, me);
                } else {
                        message_vision(HIR"\n几滴鲜血溅到了$N的" + obj->name() + HIR"上，又顺着"
                        + obj->name() + HIR"落到了地上。\n"NOR, me);    
                }
        }else{
                message_vision(HIR"\n几滴鲜血溅到了$N的"NOR + weapon->name() + 
                                HIR"上，瞬间就凝成了暗紫色的痕迹。。 \n"NOR, me);
                if(weapon->query("weapon_prop")) {
                        prop="weapon_prop/";
                }
                if(weapon->query("equipped") == "wielded") {
                        weapon->unequip();
                }
        weapon->add(prop+"strength", 5);
        weapon->add(prop+"damage", 10);
                weapon->save();
                me->set("imbue/tianfeng", 1);
                me->save();
                return;
        }
        me->set("imbue/tianfeng", 2);
        me->save();
        return;
}  
