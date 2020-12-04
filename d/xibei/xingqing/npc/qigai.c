//qigai.c

inherit NPC;

int ask_yi( object me );
void create()
{
    set_name("乞丐", ({ "qi gai" }) );
    set("gender", "男性" );
    set("age", 23);
    set("long", "一个满脸油污的中年乞丐。\n");
    set("combat_exp", 100);
    set("str", 27);
    set("force", 200);
    set("max_force", 200);
    set("force_factor", 2);
    setup();
    set("chat_chance", 50);
    set("chat_msg", ({
   "乞丐说道：好心的大爷哪～ 赏我要饭的几文钱吧～\n",
   "乞丐懒洋洋地打了个哈欠。\n",
   "乞丐突然面色一正，忧心的说道：江湖风波恶呀。。。\n",
   "乞丐伸手捉住了身上的虱子，骂道：老子身上没几两肉，全叫你们给咬糜了。 \n",
   "乞丐说道：据说在南海之中有一侠客岛，上有绝世神功.\n",
        (: random_move :)
     }) );
    set("inquiry", ([
        "易大彪" : (: ask_yi :),
    ]) );
}

int accept_object(object me, object obj)
{
     command("smile");
     command("chat 多谢这位" + RANK_D->query_respect(me)+"了, 江湖风波险恶，您这几天可要注意了呀。。。\n");
     command("say 多谢这位" + RANK_D->query_respect(me) +
               "，您好心一定会有好报的！");
     return 1;
}
int accept_fight(object me)
{
     command("say " + RANK_D->query_respect(me) +
             "饶命！小的这就离开！\n");
     return 0;
}
     
int ask_yi( object me )
{
     write("那是我们堂主.....你问这个干什么?....乞丐白了你一眼\n");
     return 1;
}
