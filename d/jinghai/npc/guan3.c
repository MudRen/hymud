// guan3.c

inherit NPC;

int ask_wuqiling(object who);
int ask_zawuling(object who);

void create()
{
        set_name("老管事", ({ "guan shi","guan" }) );

        set("class","jinghai");
        set("title","明月寨");

        set("gender", "男性" );
        set("age", 63);
        set("long", "这是一位瘦弱得老头子，精明得很。\n");
        set("attitude", "peaceful");
        set("inquiry",([
        "武器令牌" : (: ask_wuqiling :),
        "wuqiling" : (: ask_wuqiling :),
        "杂物令牌" : (: ask_zawuling :),
        "zawuling" : (: ask_zawuling :),
]));
 
        set("combat_exp", 100000);
        set("str", 17);
        
        set_skill("unarmed",60);
        set_skill("dodge",60);
        set_skill("parry",50);
        set_skill("force",10);

        setup();
 
        carry_object("/clone/misc/cloth")->wear();
}

int ask_wuqiling(object who)
{
        object ob;
who=this_player();
        if(!who)
                return 0;

        if(who->query("class") != "jinghai")
		return 0;


	if(who->query_temp("jinghai_have_ling/wuqi"))
	{
		command("say 兵器库的令牌不是已经给过你了。\n");
		return 1;
	}

        ob = new(__DIR__"obj/wuqiling");
        ob->move(this_object());
        



        ob->set("master",who->query("id"));
	who->set_temp("jinghai_have_ling/wuqi",1);

        command("say 好吧！这个给你。");
        command("smile");
        command("give wuqi ling to "+who->query("id"));
        return 1;
}

int ask_zawuling(object who)
{
        object ob;
who=this_player();
        if(!who)
        return 0;

        if(who->query("class") != "jinghai")
		return 0;


	if(who->query_temp("jinghai_have_ling/zawu"))
	{
		command("say 杂物室的令牌不是已经给过你了。\n");
		return 1;
	}

        ob = new(__DIR__"obj/zawuling");
        ob->move(this_object());
        



        ob->set("master",who->query("id"));
	who->set_temp("jinghai_have_ling/zawu",1);

        command("say 好吧！这个给你。");
        command("smile");
        command("give zawu ling to "+who->query("id"));
        return 1;
}
