#include <ansi.h>
inherit NPC;  
void create()
{
        
        set_name("万春流",({"wan chunliu","chunliu"}));
//      set("title","昆仑四鹫");
        set("nickname",HIG"神医"NOR);
        set("long", "此人便是名震江湖的“妙手回春“神医万春流，据说只要患者还有一
口气在，他就能药到病除。\n");
        set("age",45);
        set("attitude", "friendly");
        set("combat_exp", 4000000);
                        
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",1500);
        set("neili",1500);
                
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("inquiry", ([
                "七枝一叶花" : "此花极为罕见，非有机遇不能得到。",
                "flower" : "此花极为罕见，非有机遇不能得到。",
                "起死回生" : "有一种七枝一叶花，据说有起死回生之特效。",
                "qisihuisheng" : "有一种七枝一叶花，据说有起死回生之特效。",
                 "小烟" : "小烟是村里的孩子。",
                 "欧阳豆腐铺" : "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
                "欧阳丁" :  "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
                "欧阳当" :  "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
                "ouyang ding" :  "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
                "ouyang dang" :  "欧阳豆腐铺生意越来越好，快盖过哈哈酒楼了。",
                "哈哈酒楼": "哈哈酒楼当然是哈哈儿开的喽，听说他现在生意不好，正在为原料发愁呢。",
                "娇娇客栈": "娇娇客栈是屠娇娇的女儿开的。",
                "屠小娇": "娇娇客栈是屠娇娇的女儿屠小娇开的。",
                "恶人谷": "这儿就是当年的恶人谷。",
                "燕南天": "自小鱼儿与花无缺的身世真相大白后，燕大侠就离开这里了。",
                   "万春流": "正是在下。",
                "杜老爹": "杜老爹专打暗器，听说要打他的暗器，还得学好听风辨器才行。",
                "轩辕三光": "他输的只剩下那间当铺了。",
                "铁萍姑": "李大嘴的女儿，一个人住在那儿，怪可怜的。",   
        ]));
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "万春流低头沉思，好像浑没有意识到你的存在。”\n",
        }) );

        set("force_factor",60);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        
} 
void die(){
         message_vision("$N微微一凝气，脸色又恢复了红润。\n", this_object());
        "/cmds/imm/full"->main(this_object(),"");
}  
int accept_object(object who, object ob)
{       
        if (!ob->query("marks/蜘蛛恶人窟")) return 0;
        if (ob->query("name")==HIG"七枝一叶花"NOR && who->query_temp("eren/kid_result")
                && !who->query("marks/万春流"))
        {
                command("ah");
                if (!who->query("marks/万春流")) {
                        who->add("potential",1000);
                        who->add("combat_exp",10000);
                        who->set("marks/万春流",1);
                        tell_object(who,WHT"你被奖励了！一千潜能，一万经验值！\n"NOR);
                }
                message_vision("$N说:太好了，太好了。\n",this_object());
                return 1;
        }
        return 0;       
} 
/*
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !interactive(ob) || environment(ob) != environment() ){
                return;
        }
        message_vision("$N笑嘻嘻走了过来，拱手笑道：“兄台远来辛苦了。”\n", this_object() );
        return;
} 
*/ 
