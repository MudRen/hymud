 inherit NPC;
int tell_him();
void create()
{
        set_name("百里灵", ({ "zyc" }) );
        set("gender", "男性" );
        set("title","采药郎");
        set("age", 42);
        set("long", "他是一位常年隐居深山,终日与药为伴的隐世郎中。
曾经踏遍天下名山,尝尽世间百草。由于常年独居,
性情有些古怪,但于医药之道已无所不知。更是治疗
各种绝症的高手。眉宇间隐隐约约透出一丝忧伤,仿佛
在思考着什么。\n");
        set("combat_exp", 100000);
        set("attitude", "heroism");
        
        set("skill_public",1);
        set_skill("unarmed", 10);
        set_skill("parry", 10);
        set_skill("dodge", 10);
        //set_skill("herb",100);
        
        set("inquiry", ([
        "zhishang" : (: tell_him :),
        "治伤" : (: tell_him:),
        "cure" : (: tell_him :),
        ]));
        set("chat_chance", 1);
        set("chat_msg", ({
        "采药郎继续采药，似乎并没有注意你的到来。\n",
        }) );
        setup();
        add_money("coin", 1);
        carry_object("/clone/misc/cloth")->wear();
}  
int tell_him()
{
        object me;
        me =this_player();
        if(!me->query("attr_apply")) {
   message_vision("$N看着$n道：你根本没有伤到筋骨，皮外伤去买些云南白药就可以了。\n",
                        this_object(),me);
        return 1;
        } else {
        message_vision("$N看着$n道：你这伤可不轻呀！我能治但是没有寒潭蛙作药引！\n",
                        this_object(),me);
        }
} 
int recognize_apprentice(object ob)
{
        if(ob->query("free_learn/herb"))
        return 1;
        else {
                if (!random(2)) {
                command ("say 想学药道就先帮我做件事，一直听说有个黑瓷药瓮，你能不能替我找一个来？\n");
                } 
                return notify_fail("\n");
        }
} 
int accept_object(object who, object ob)
{       
        if (ob->query("name")=="黑瓷药瓮")
        {
                message_vision("$N苦笑着一摊手说：小老儿家里的黑瓷药瓮都堆成山了。\n",this_object());           
                message_vision("$N说：不过，我还需要寒潭蛙作药引，你能不能替我找一下？\n",this_object());
                return 0;
        }       
        if (ob->query("name")=="寒潭蛙")
        {
                if (who->query_temp("well_frog")) {
                        message_vision("$N笑呵呵地说：好，好。\n",this_object());               
                        message_vision("$N说：想学我的药道？没问题。\n",this_object());
                        who->set("free_learn/herb",1);
                        return 1;
                } else 
                        {
                        command("say 这不是你找到的吧，我百里灵不能要来路不明的东西。");
                        return 0;
                        }
        }        
}
