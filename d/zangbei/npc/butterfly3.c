#include <ansi.h>
inherit NPC;
int bite();
void create()
{
        set_name("高原绿蝶", ({ "butterfly" }) );
        set("race", "野兽");
        set("age", 1);
        set("long", "美丽的蝴蝶，色彩绚烂，成群结队的在花丛中飞来飞去。\n");
        set("max_qi", 200);
        set("max_jing", 200);
        set("max_qi", 200);
        set("group","butterfly");
        set("str",10);
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                100:    (: bite() :),
        ]) );  
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: bite()  :),     
        }) );
        
        set("chat_chance",2);
        set("chat_msg",({
                "彩蝶一会儿向东，一会儿向西，在花丛中翩翩起舞。\n",
        }) );   
        set("self_go_msg",1);
        set("arrive_msg","高原绿蝶飞了过来。\n");
        set("leave_msg","高原绿蝶飞开了。\n");
        set("limbs", ({ "头部","身体", "翅膀","触角", }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp",200000000);
        set_skill("dodge", 600);
        setup();
}  
void init(){
        ::init();
        add_action("do_look", "look");
}  
int do_look(string arg) {
        if(arg == "butterfly"){
                write("美丽的蝴蝶，色彩绚烂，成群结队地在花丛中飞来飞去。不过,世界
上越是美丽的东西，往往就越是危险。\n");
                write("它看起来才出生几天。\n");
                write("它长的不胖不瘦，武功看起来好象"+BLU "不堪一击"NOR+"，出手似乎极轻。\n");
                write("它精神饱满，正处于巅峰状态。\n");
                return 1;
        }
        return 0;
} 
int bite(){
        object ob,me,*enemy;
        int i;
        
        ob=this_object();
        enemy=ob->query_enemy();
        if (!random(3))
        for (i=0;i<sizeof(enemy);i++) {
                message_vision(YEL""+name()+"扑闪着翅膀，阵阵花粉香味熏得人头昏脑胀，浑无斗志。\n"NOR,enemy[i]);
                tell_object(enemy[i],HIB"你觉得昏昏欲睡。\n"NOR);
                enemy[i]->receive_wound("qi",enemy[i]->query("max_qi")/20,ob);
                COMBAT_D->report_status(enemy[i]);
        }       
        this_object()->start_busy(1);
        return 1;
} 
