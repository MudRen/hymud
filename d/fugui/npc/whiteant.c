#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"白蚂蚁"NOR, ({ "white ant", "ant" }) );
        set("long",
                "一个穿着雪白衣裳的人，袖子又宽又长，就象是两只翅膀，人却又瘦\n又小，长不满三尺半，宽不及一尺，若是放在秤上秤一秤，决不会比\n一只兔子重多少。\n");
        set("chat_chance",2);
        set("chat_msg", ({
"白蚂蚁傲然的瞥了你一眼，负手而立，冷冷道：“当今天下，除了寥\n寥几个门派的轻功身法还可入眼，其他的在我‘蹋雪无痕白蚂蚁’眼\n里都是不值一提。”\n",
"白蚂蚁道：“除了轻功，老夫最喜欢试穿不同的衣服。听说，\n最近流行什么风云马褂，等我有空去搞一件。\n"
                                })  ); 
        set("combat_exp", 200000);
        set("max_jing",800);
        set("max_qi",1600);
        set("max_jing",800);
        set("int",35);
        set("str",30);
        set("cor",35);
        
        set_skill("dodge",150);
        set_skill("move",150);
        set_skill("unarmed",100);
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
int accept_object(object who, object ob)
{       
        object jinlian;
        if (ob->query("name")=="秋风步法秘笈") 
        {
           this_player()->set_temp("marks/白蚂蚁",1);
                write("白蚂蚁不屑的翻了翻，但愈是往下看，愈是神色凝重，喟然长叹道：\n＂秋风落叶＂果然名不虚传啊，天下第一果然不是吹的。”\n");
                command("thank "+this_player()->query("id"));
                return 1;
        }
        if (ob->query("name")=="风云马褂") 
        {
                command("spank "+this_player()->query("id"));
                this_player()->set_temp("marks/whiteant",1);
                write("白蚂蚁嘻嘻笑道：“你了解我，你了解我。”\n");
                return 1;
        }
        write("白蚂蚁冷冷道：“这种雕虫小技怎能入眼。”\n");
        return 0;
}      
