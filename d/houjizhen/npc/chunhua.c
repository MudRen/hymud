// chunhua.c
// by dicky

#include <ansi.h>
inherit NPC;
int ask_shoujuan();

void create()
{
	set_name("春花", ({"chun hua", "chunhua"}));
	set("long", "这是一个普通的农家女，长得还有几分姿色。\n");
	set("gender", "女性");
	set("attitude", "friendly");
	set("age", 20);
	set("per", 22);
	set("str", 28);
	set("con", 23);
	set("dex", 28);

	set("combat_exp", 2000);
	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
        set("inquiry", ([
		"手绢":(: ask_shoujuan :),
        ]));

	setup();

        carry_object(__DIR__"obj/skirt")->wear();
}

void init()
	{
        add_action("do_decide", "decide");
	}

int ask_shoujuan()
{
    object ob;
    ob=this_player();

    if(ob->query("gender") !="男性")
    { 
	command("say 这位"+RANK_D->query_respect(ob)+"，你也是个女性，难道不知道手绢？");
	return 1; 
    }

    if (  present("nvren shoujuan", this_player()) )
    {
	if (ob->query_temp("ganjiang/shoujuan") || ob->query_temp("ganjiang/decide") )
	{
	command("love "+ob->query("id"));
	command("say 你也知道知道奴家的事情呀，既然"+RANK_D->query_respect(ob)+"远道而来，就让奴
家为你尽最后一份力量，如果你决定(decide)了，请告诉奴家!\n");
	command("touch "+ob->query("id")+"\n");
	ob->delete_temp("ganjiang/shoujuan",1);
	ob->set_temp("ganjiang/decide",1);
	return 1;
	} 
	else
	{
	command("say 你身上怎么带有女人的手绢，是不是哪里去偷香啦？");
	command("xixi");
	return 1;
	}
    }
    else
    {
    command("say "+RANK_D->query_respect(ob)+"，管他什么手娟，坐下来陪奴家说说话嘛！\n");
    command("love "+ob->query("id"));
    }
}

int do_decide(string arg)
{
	object ob;
	object ob1;
    	ob=this_player();

        if( !this_player()->query_temp("ganjiang/decide") )
                return 0;

	if (!arg)
	{
	command("?");
	command("say 你想决定什么呀？你只需要回答yes或者no，不要浪费老娘的时间。\n");
	return 1;
	}
	
	if (arg=="yes")
	{
	ob1 = present("nvren shoujuan", ob);
	destruct(ob1);
	message_vision(
		"$N给春花一条手绢。\n\n\n"NOR
                HIR"春花带$N来到旁边的睡房，褪下衣裳，说道: 快点，我都等不急了。\n\n"NOR
                HIR"$N不禁筋骨皆酥，昏黄的灯光中一股醉人的女体幽香使$N意乱神迷。\n\n"NOR
                HIR"$N摸索着春花那让$N神往的桃花仙境，迷失在那无处不在的暗香浮动之中。\n\n"NOR
                HIR"......\n\n"NOR,
                this_player(), this_object());
	ob->unconcious();
        command("chat 又有一个男人倒在我的石榴裙下!");
	command("haha");
	command("get all from "+ob->query("id"));	
	ob->delete_temp("ganjiang/decide",1);
	return 1;
	}

	if (arg=="no")
	{
	ob1 = present("nvren shoujuan", ob);
	destruct(ob1);
	message_vision(
		"$N给春花一条手绢。\n\n",
                this_player(), this_object());
	command("say 这位"+RANK_D->query_respect(ob)+"我知道你是个好人，我是个穷苦人家的孩子，刚出
嫁到侯集一户姓王的人家，不幸去年又死了男人，实在没有办法才......\n");
	command("cry "+ob->query("id"));
	command("say 让我告诉你一个秘密，前天我去这后面的财神庙去烧香，突然
听到女孩子的叫声,当时奴家非常害怕，所以就躲到神像后面，一会一个
和尚抗着一个女孩进来了，钻到神案下面的秘道去了，如果"+RANK_D->query_respect(ob)+"心肠
好，就去救救那位女孩子吧！\n");
	ob->delete_temp("ganjiang/decide",1);
	ob->set_temp("ganjiang/heshang",1);
	return 1;
	}
	return 0;
}


