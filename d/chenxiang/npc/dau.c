 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
int tell_him();
void create()
{
        set_name("贾员外的女儿", ({ "jianu" }) );
        set("gender", "女性" );
        set("age", 15);
        set("combat_exp", 5);
        set("attitude", "friendly");
        set("per",30);
        set("chat_chance", 3);
        set("chat_msg", ({
                "贾员外的女儿问道：你是谁呀？\n",
                "贾员外的女儿道：你是不是我爹的好朋友？\n",
        }) );
        set("inquiry", ([
                "贾员外" : (: tell_him :),
                "jia" : (: tell_him:),
        ]));
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
int tell_him()
{
 object me;
 me = this_player();
 if(me->query_temp("marks/cured_jia")) {
 tell_object(me,"贾女道：我爹他是个认为＂大恩不能报＂的人，你如果对他有过大恩
的话那你就死定了，他一定会想办法杀了你的。\n");
  me->set_temp("marks/asked_jianu",1);
 } else  
 tell_object(me,"贾女道：他是我爹呀，这还用问？\n"); 
return 1; 
}      
