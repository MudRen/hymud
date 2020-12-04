// laoban.c     老板娘
// Ffox 98-4-30 14:14
inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name( "老板娘", ({ "laoban niang", "laoban"  }) );
    set( "gender", "女性" );
    set( "age", 30 );                
    set( "long", @LONG
本地人……开馆子为生……
LONG );
    set( "attitude", "friendly" );
    set( "inquiry", ([
    "男人" : "我男人那，真是冤家，这么早就离我而去了。",
    "休息" : "在这里休息啊！一晚五两银子。",
]) );

	set("vendor_goods", ({
		"/d/xingxiu/npc/obj/yangrou",
		"/d/lanzhouchen/npc/obj/paomo",
		"/d/city/npc/obj/jiudai",
		"/d/lanzhou/npc/obj/jiouhulu",
		"/d/lanzhou/npc/obj/maoniurou",
	__DIR__"obj/putao_jiu",
	}));
    setup();
    carry_object( "/clone/misc/cloth" )->wear();       //粗布衣
}

void init()
{
    object ppl;
    ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
    call_out( "do_listen", 1 ,ppl );
}

void do_listen()
{
    write("女老板对你吆喝道：远来是客来喝一点本地的酒吧。\n");
}

int accept_object(object me, object ob)
{
    if( ob->value() >= 5000 ){
      command("say 那你就进去休息吧...... ");
      me->set_temp("hami/sleep", 4);
      }
    else command("say 平白无故地给我东西？那我就笑纳了。");
    return 1;
}

