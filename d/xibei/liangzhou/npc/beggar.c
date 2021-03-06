//  标准乞丐    /clone/npc/beggar.c
//  By lin
//  Hydra copied from lanzhou

#include <ansi.h>
inherit NPC;
int ask_me( object );
string talk_me( object );

void create()
{
    set_name( "乞丐", ({ "qi gai", "qigai", "beggar" }) );
    set( "gender", "男性" );
    set( "combat_exp", 100 );
    set( "per", 14 );
    set( "force", 200 );
    set( "max_force", 200 );
    set( "chat_chance", 15 );
    set( "chat_msg", ({
        "乞丐说道：“好心的大爷哪～赏我要饭的几文钱吧～”\n",
        "乞丐懒洋洋地打了个哈欠。\n",
        "乞丐伸手捉住了身上的虱子，骂道：“老子身上没几两肉，全叫你们给咬糜了。”\n",
    }) );
    set("inquiry",([
        "帮忙"      :   (:ask_me:),
    ]) );
    
    set("talk_limit",([
        "hydra/can_talk_qigai"      :       1,
        "hydra/shaolin/pending_kaoyan" :    1,
    ]) );
    set("talk_msg",({
        (: talk_me :),
    }) );
    
    setup();
    carry_object( "/clone/misc/cloth" )->wear();
}

int accept_object( object ppl, object obj ) //收了东西说好话。
{
    command( "smile" );
    command( "say “多谢这位" + RANK_D->query_respect( ppl ) +
        "，您好心一定会有好报的！”" );
    return 1;
}

int accept_fight( object ppl )              //不接受挑战。
{
    command( "say “" + RANK_D->query_respect( ppl ) +
        "饶命！小的这就滚开！”\n");
    (: random_move :);
    return 0;
}

void init()
{
    object ppl = this_player();

    ::init();
}

string talk_me( object ppl )
{
    string msg;
    ppl = this_player();
    if ( ppl->query_temp("凉州/meet_qigai") ) 
    {
        tell_object(ppl,CYN"乞丐道：有什么困难大师再过来！\n"NOR);
        return "";
    }
    msg = CYN"乞丐见你过来，看了你一眼，悄悄跟你说：这位大师，我听大云\n";
    msg +=   "寺老方丈说，你正在帮张员外降服恶人，我们丐帮非常钦佩，不\n";
    msg +=   "过你要小心，那恶人比较厉害，说来惭愧，上次我们丐帮曾经栽\n";
    msg +=   "在过他的手下。\n";
    msg +=   "另外据我们丐帮凉州分舵的消息，那恶人最近两三天晚上可能会\n";
    msg +=   "向张家小姐下手。如果大师有什么困难可以找我们帮忙。\n"NOR;
    ppl -> set_temp("凉州/meet_qigai",1);
    tell_object ( ppl,msg );
    return "";
}

int ask_me( object ppl )
{
    string msg;
    ppl = this_player();
    if ( !ppl->query_temp("凉州/meet_qigai") )
    {
        return 0;
    }
    if ( ppl->query_temp("凉州/ask_qigai") )
    {
        tell_object(ppl,CYN"乞丐道：大师一切小心！\n"NOR);
        return 1;
    }
    msg = CYN"乞丐道：大师既然问起了，我有一法，不知是否可行，大师可装\n";
    msg +=   "作张家小姐，让小姐找个地方躲避起来，晚上不要睡在闺房里，\n";
    msg +=   "然后大师于晚上躺在小姐的床上，等那采花贼欲前来行凶之时，\n";
    msg +=   "大师可攻他个措手不及！\n";
    msg +=   "不过小心别打草惊蛇，如果可以的话，我丐帮会助大师一臂之力！\n"NOR;
    tell_object( ppl,msg );
    ppl->set_temp("凉州/ask_qigai",1);
    return 1;
}

