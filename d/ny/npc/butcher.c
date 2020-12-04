
// butcher.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("郑屠夫", ({ "butcher", "zheng" }) );
        set("title", "镇北肉铺");
        set("gender", "男性" );
        set("age", 35);
        set("long", "你看到一个剽悍的大块头, 正在用钢刀剔牛骨。\n");
        set("str", 29);
        set("int", 14);
        set("combat_exp", 2500);
        set("attitude", "heroism");
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);



//        set("where","north");

        setup();
        add_money("silver", 12);
        add_money("coin", 500);
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
                        say( "屠夫边剔骨头边嘟囔着：真是好刀，剔得好舒服! 
\n");
                        break;
                case 1:
                        say( "屠夫摇摇头, 叹了口气说：唉, 不知那碧玉刀究竟"
                                +"比我这刀厉害几倍...\n");
                        break;
                case 2:
                        say( "屠夫咧开大嘴, 笑着道：这位"  
                                + RANK_D->query_respect(ob)
                                + "，要买肉是吗? \n");
                        break;
                case 3:
                        say( "屠夫忙着给人取肉, 似乎没注意到你进来。\n");
                        break;
        }
}

 
