//Writen by lnwm (May.28.1997)
//kid.c

inherit NPC;

void create()
{
        set_name("小男孩", ({ "little kid","kid" }) );
        set("gender", "男性" );
        set("age", 14);
        set("long",
"一个淘气的小男孩，正蹲在路边兴致勃勃地玩着手里的泥巴。\n"
        );
        set("combat_exp", 200);

//        set("inquiry", ([
//        ]) );
        set("talk_limit",([
           "social_exp" : 500,
        ]));
        set("talk_msg",({
"小男孩自言自语地说：怎么最近老有不认识的人来。\n",
        }) );
        set("talk_fail_msg",({
"小男孩把泥巴捏成一个小人的形状。\n",
"小男孩抬头看了一下你，又低头玩自己手里的泥巴。\n",
        }));        
        setup();
        carry_object(__DIR__"obj/cloth1")->wear();
}






